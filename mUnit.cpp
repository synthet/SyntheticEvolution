//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TbioForm *bioForm;
//---------------------------------------------------------------------------
__fastcall TbioForm::TbioForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
enum type {bPlant, bBeast, bEater};
//Класс ДНК
class DNA {
public:
 float g[8];
 DNA() {
  for(int i=0;i<8;i++)
   g[i] = random(101)/100.0;
 };
 void Mutate(int pow) {
  for(int i=0;i<8;i++)
  {
   g[i] += pow*(random(11)-5)/200.0;
   if (g[i]<0.0) g[i]=0.0;
   if (g[i]>1.0) g[i]=1.0;
  }
 };
 int Roll(int ev) {
  int ln[8];
  ln[0] = floor(g[0]*100.0);
  for(int i=1;i<ev;i++)
   ln[i]=ln[i-1] + floor(100.0*g[i]);
  int rl = random(ln[ev-1]);
  int rz = 0;
  for(int i=0;i<ev;i++)
   if (rl >= ln[i]) rz++;
  return rz;
 };
 TColor Color(type Tp) {
  TColor clr;
  switch (Tp) {
   case bPlant: clr=clGreen; break;
   case bEater: clr=clOlive; break;
   case bBeast: clr=clMaroon; break;
  };
  int R = GetRValue(clr);
  int G = GetGValue(clr);
  int B = GetBValue(clr);
  if(R<223) R+=floor(g[0]*32);
  if(G<223) G+=floor(g[2]*32);
  if(B<223) B+=floor(g[4]*32);
  if(R>32)  R-=floor(g[1]*32);
  if(G>32)  G-=floor(g[3]*32);
  if(B>32)  B-=floor(g[5]*32);
  return (TColor)RGB(R,G,B);
 };
};
//Класс Существо
class Bio {
private:
protected:
 float Health;
 TColor clr;
 int size;
 int x;
 int y;
 float dx;
 float dy;
 int angle;
 int Sur;
public:
 AnsiString Name;
 float fx;
 float fy;
 bool Dead;
 DNA dna;
 void Paint(Graphics::TBitmap* bmp, bool slct) {
  if (slct)
   bmp->Canvas->Brush->Color = clBlue;
  else
   bmp->Canvas->Brush->Color = clr;
  bmp->Canvas->Pen->Color=(TColor)0x333333;
  bmp->Canvas->Ellipse(x-size/2,y-size/2,x+size-size/2,y+size-size/2);
 };
 virtual type Type()= 0;
 void Near(int _x, int _y, float _h, bool rnd) {
   if ((random(100)>90) && (rnd))
   {
    x = _x + random(101)-50;
    y = _y + random(101)-50;
   }
   else
   {
    x = _x + random(2*size+1)-size;
    y = _y + random(2*size+1)-size;
   }
   fx = x;
   fy = y;
   Health = _h;
   angle = random(361);
   clr = dna.Color(Type());
 };
 void Coord(int Width, int Height) {
  x = random(Width);
  y = random(Height);
  fx = x;
  fy = y;
  angle = random(361);
 };
 void Grow(float Nrg) {
  Health+=Nrg;
 };
 void Angle(float phi) {
  angle = phi;
 };
 AnsiString Info() {
  AnsiString Tp = "";
  switch (Type()) {
   case bPlant: Tp = "[Plant]"; break;
   case bEater: Tp = "[Herbivorous]"; break;
   case bBeast: Tp = "[Predator]"; break;
  };
  return Tp+" - Health: "+FloatToStr(ceil(Health))+
        " <"+x+";"+y+">";
 };
 TColor Color() {
  return clr;
 };
 virtual void Move(int Width, int Height)=0;
 virtual void Dir()=0;
 virtual void Eat(Bio * Food)=0;
 virtual void Life(float Sun) = 0;
 virtual Bio * Repro(int Mut) = 0;
 virtual void Size() = 0;
};
//Класс Растение
class Plant : public Bio {
private:
public:
 Plant () {
   clr = clGreen;
   size = 5;
   Health = 50.0;
   Dead = false;
   Sur = 0;
   Name = "";
 };
 type Type() {
  return bPlant;
 };
 void Life(float Sun) {
  Grow(0.2*Sun-Sur);
  if (Health<=0.0) Dead = true;
  Sur = 0;
 };
 void Move(int Width, int Height) {
   if (((x-Width)>10) || ((y-Height)>10))
    Grow(-10);
   if ((x<-10) || (y<-10))
    Grow(-10);
 };
 void Dir() {
  //Nothing to do
 };
 void Eat(Bio * Food) {
  if ((abs(Food->fx - fx)<=size) && (abs(Food->fy - fy)<=size)
        && (Food->Type() == bEater)) Food->Eat(this);
  else
  if ((abs(Food->fx - fx)<=1.25*size) && (abs(Food->fy - fy)<=1.25*size)
        && (Food->Type() == bPlant)) Sur++;
 };
 Bio * Repro(int Mut) {
 if (dna.Roll(4))
  if (Health >= 100.0)
  {
   Bio * Brn = new Plant();
   Health = dna.g[3]*Health;
   Brn->dna.Mutate(Mut);
   Brn->Near(x,y,(1-dna.g[3])*Health,true);
   Brn->Name = Name;
   return Brn;
  }
  return NULL;
 };
 void Size() {
  size = Health/25+5;
 };
};
//Класс Животное
class Animal : public Bio {
private:
protected:
public:
 void Move(int Width, int Height) {
  dx = cos(DegToRad(angle));
  dy = sin(DegToRad(angle));
  if (random(100*(dna.g[0]+1)) > 25)
  {
   fx+=dx;
   fy+=dy;
   Health-=(0.125+0.01*Sur);
  }
  x=floor(fx);
  y=floor(fy);
  if (fx<=0) fx = Width-size;
  if (fy<=0) fy = Height-size;
  if (fx>=Width) fx = size;
  if (fy>=Height) fy = size;
 };
 void Life(float Sun) {
  if (Health<=0.0) Dead = true;
  Sur = 0;
 };
};
//Класс Травоядное
class Eater : public Animal {
public:
 Eater () {
   clr = clOlive;
   size = 6;
   Health = 200.0;
   Dead = false;
   Sur = 0;
   Name = "";
 };
 type Type() {
  return bEater;
 };
 void Dir() {
  int dr = -1;
  if (random(200*(dna.g[7]+1)) > 199)
   dr = dna.Roll(8);
  switch (dr) {
   case 1: angle+= 30; break;
   case 2: angle-= 30; break;
   case 3: angle+= 45; break;
   case 4: angle-= 45; break;
   case 5: angle+= 60; break;
   case 6: angle-= 60; break;
  };
  angle%=361;
 };
 void Eat(Bio * Food) {
  float Dmg = random(1001)/100.0;
  if ((abs(Food->fx - fx)<=size) && (abs(Food->fy - fy)<=size))
  switch (Food->Type()) {
   case bPlant: Food->Grow(-Dmg); Grow(1.0*Dmg); break;
   case bBeast: Food->Eat(this); break;
   case bEater: Sur++; break;
  }
 };
 Bio * Repro(int Mut) {
 if ((dna.Roll(6)) || (dna.Roll(3)))
  if (Health >= 600.0)
  {
   Bio * Brn = new Eater();
   Health = 200;
   Brn->dna.Mutate(Mut);
   Brn->Near(x,y,200,false);
   Brn->Name = Name;
   return Brn;
  }
  return NULL;
 };
 void Size() {
  size = Health/33;
  if (size<4) size=4;
 };
};
//Класс Хищный
class Beast : public Animal {
public:
 Beast () {
   clr = clMaroon;
   size = 7;
   Health = 150.0;
   Dead = false;
   Sur = 0;
   Name = "";
 };
 type Type() {
  return bBeast;
 };
 void Dir() {
  int dr = -1;
  if (random(125*(dna.g[7]+1)) > 124)
   dr = dna.Roll(8);
  switch (dr) {
   case 1: angle+= 15; break;
   case 2: angle-= 15; break;
   case 3: angle+= 30; break;
   case 4: angle-= 30; break;
   case 5: angle+= 45; break;
   case 6: angle-= 45; break;
  };
  angle%=361;
 };
 void Eat(Bio * Food) {
  float Dmg1 = random(1001)/25.0;
  float Dmg2 = random(1001)/25.0;
  if ((abs(Food->fx - fx)<=1.25*size) && (abs(Food->fy - fy)<=1.25*size))
  switch (Food->Type()) {
   case bEater: Food->Grow(-2*Dmg1); Grow(0.85*Dmg2); break;
   case bBeast: Food->Grow(-0.1*dna.g[1]*Dmg1);
                Grow(-0.1*Food->dna.g[2]*Dmg2);
                Sur++; break;
  }
 };
 Bio * Repro(int Mut) {
 if ((dna.Roll(5)) || (dna.Roll(2)))
  if (Health >= 400.0)
  {
   Bio * Brn = new Beast();
   Health = 125;
   Brn->dna.Mutate(Mut);
   Brn->Near(x,y,100,false);
   Brn->Name = Name;
   return Brn;
  }
  return NULL;
 };
 void Size() {
  size = Health/22;
  if (size<5) size=5;
 };
};
//Класс Био-Ареал
class BioSystem {
 private:
 int Width;
 int Height;
 Bio **bio;
 int count;
 int size;
 float sun;
 int mut;
 int pln_count;
 int prd_count;
 int hrb_count;
 int slct;
 int light;
 int maxl;
 int itr;
 public:
 ~BioSystem() {
  delete [] bio;
  delete bio;
 };
 BioSystem(int _Width, int _Height, int pop) {
  count = pop;
  size = pop;
  slct = -1;
  light = 160;
  maxl = 160;
  itr =0;
  Width = _Width;
  Height =  _Height;
  bio = new Bio*[count];
  for(int i=0;i<count;i++)
  {
   if (i%9>=6)
    bio[i] = new Plant();
   if (i%9==5)
    bio[i] = new Beast();
   if (i%9<=4)
    bio[i] = new Eater();
   bio[i]->Coord(Width, Height);
  }
 };
 void Delete(int i) {
  if (slct == i) slct = -1;
  if (i != count)
   bio[i] = bio[count-1];
  count--;
 };
 void Kill(type Tp) {
  if (slct>-1)
   if (bio[slct]->Type() == Tp) {
    Delete(slct);
    return;
   }
   for(int i=0;i<count;i++)
    if (bio[i]->Type() == Tp) {
     Delete(i);
     break;
    }
 };
 void IncLen(){
  size+=100;
  Bio **tmp = new Bio*[size];
  CopyMemory(tmp,bio,4*(size-100));
  delete [] bio;
  delete bio;
  bio = tmp;
 };
 void Add(type Tp) {
  count++;
  if (count>size) IncLen();
  switch (Tp) {
   case bPlant: bio[count-1] = new Plant(); break;
   case bEater: bio[count-1] = new Eater(); break;
   case bBeast: bio[count-1] = new Beast(); break;
  };
  bio[count-1]->Coord(Width, Height);
 };
 void Born(Bio * Brn) {
  count++;
  if (count>size) IncLen();
  bio[count-1] = Brn;
 };
 void Paint(Graphics::TBitmap* bmp) {
  maxl = 64+16*sun;
  if (light<maxl) light++;
  else if (light>maxl) light--;
  bmp->Canvas->Brush->Color=(TColor)RGB(light,light,light);
  bmp->Canvas->Rectangle(0,0,bmp->Width,bmp->Height);
  for(int i=0;i<count;i++)
  {
   if (i == slct)
    bio[i]->Paint(bmp, true);
   else
    bio[i]->Paint(bmp, false);
  }
 };
 void Counter(type Tp) {
  switch (Tp) {
   case bPlant: pln_count++; break;
   case bEater: hrb_count++; break;
   case bBeast: prd_count++; break;
  };
 };
 void Envr(int j) {
  for(int i=j+1;i<count;i++)
  {
   bio[j]->Eat(bio[i]);
  }
 };
 void Evol() {
  float nrg = sun;
  if (count>250) nrg/=(count/250);
  pln_count = 0;
  hrb_count = 0;
  prd_count = 0;
  itr++;
  for(int i=0;i<count;i++)
  {
   bio[i]->Move(Width, Height);
   bio[i]->Dir();
   Envr(i);
   Bio * Brn;
   Brn = bio[i]->Repro(mut);
   if (Brn!=NULL)
    Born(Brn);
   bio[i]->Life(nrg);
   Counter(bio[i]->Type());
   if (itr>9) bio[i]->Size();
   if (bio[i]->Dead) Delete(i);
  }
  if (itr>9) itr=0;
 };
 void Sun(int _sun) {
  sun = _sun;
 };
 void Mut(int _mut) {
  mut = _mut;
 };
 AnsiString Count() {
  return "Individuals: "+IntToStr(count);
 };
 AnsiString plnCount() {
  return "PLN: "+IntToStr(pln_count);
 };
 AnsiString prdCount() {
  return "PRD: "+IntToStr(prd_count);
 };
 AnsiString hrbCount() {
  return "HRB: "+IntToStr(hrb_count);
 };
 bool Select(int _x, int _y) {
  bool rzlt = false;
  for(int i=0;i<count;i++)
  if ((abs(bio[i]->fx-_x)<=5) && (abs(bio[i]->fy-_y)<=5)) {
   slct = i; rzlt = true; break;
  }
  else slct = -1;
  return rzlt;
 };
 AnsiString Info() {
  if (slct>-1)
   return bio[slct]->Info();
  else
  return "";
 };
 void Move(int _x, int _y) {
  if (slct>-1) {
   bio[slct]->fx = _x;
   bio[slct]->fy = _y;
  }
 };
 void Resize(int _Width, int _Height) {
  Width = _Width;
  Height =  _Height;
 };
 void AddHealth(int Hl) {
  if (slct>-1)
   bio[slct]->Grow(Hl);
 };
 void Mutate() {
  if (slct>-1)
   bio[slct]->dna.Mutate(random(8)+1);
 }
 AnsiString GetName() {
  if (slct>-1)
   return bio[slct]->Name;
  else
   return "";
 };
 void SetName(AnsiString name) {
  if (slct>-1)
   bio[slct]->Name = name;
 };
 TColor Color() {
  if (slct>-1)
   return bio[slct]->Color();
  else
   return clSilver;
 };
};
//Глобальные переменные------------------------------------------------------
BioSystem * Areal;
bool click = false;
bool reinit = false;
//Таймер---------------------------------------------------------------------
void __fastcall TbioForm::TimerPaintTimer(TObject *Sender)
{
 Graphics::TBitmap* bmp=new Graphics::TBitmap;
 bmp->Width = Image->Width;
 bmp->Height = Image->Height;
 Image->Picture->Bitmap->Width=bmp->Width;
 Image->Picture->Bitmap->Height=bmp->Height;
 Areal->Paint(bmp);
 Areal->Evol();
 BitBlt(Image->Canvas->Handle,0,0,bmp->Width,bmp->Height,
        bmp->Canvas->Handle,0,0,cmSrcCopy);
 Image->Refresh();
 bmp->Free();
}
//Создание формы-------------------------------------------------------------
void __fastcall TbioForm::FormCreate(TObject *Sender)
{
 Panel->DoubleBuffered = true;
 randomize();
 Areal = new BioSystem(Image->Width,Image->Height,trckPop->Position);
 trckSunChange(NULL);
 trckMutChange(NULL);
}
//Кнопки---------------------------------------------------------------------
void __fastcall TbioForm::btnAdd1Click(TObject *Sender)
{
 Areal->Add(bPlant);
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::btnAdd2Click(TObject *Sender)
{
 Areal->Add(bBeast);
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::btnAdd3Click(TObject *Sender)
{
 Areal->Add(bEater);
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::btnDel1Click(TObject *Sender)
{
 Areal->Kill(bPlant);
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::btnDel2Click(TObject *Sender)
{
 Areal->Kill(bBeast);
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::btnDel3Click(TObject *Sender)
{
 Areal->Kill(bEater);
}
//---------------------------------------------------------------------------

void __fastcall TbioForm::ABout1Click(TObject *Sender)
{
 AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::Exit1Click(TObject *Sender)
{
 Close();
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::trckSunChange(TObject *Sender)
{
 Areal->Sun(trckSun->Position);
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::trckMutChange(TObject *Sender)
{
 Areal->Mut(trckMut->Position);
}
//Статистика-----------------------------------------------------------------
void __fastcall TbioForm::TimerStatTimer(TObject *Sender)
{
 StatusBar->Panels->Items[0]->Text = Areal->plnCount();
 StatusBar->Panels->Items[1]->Text = Areal->prdCount();
 StatusBar->Panels->Items[2]->Text = Areal->hrbCount();
 StatusBar->Panels->Items[3]->Text = Areal->Info();
 StatusBar->Panels->Items[4]->Text = Areal->Count();
}
//Обработка мыши-------------------------------------------------------------
void __fastcall TbioForm::ImageMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if (Areal->Select(X,Y)) {
  edName->Enabled = true;
 }
 else {
  edName->Enabled = false;
 }
 edName->Text = Areal->GetName();
 Shape->Brush->Color = Areal->Color();
 click = true;
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::ImageMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 click = false;
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::ImageMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
 if (click) Areal->Move(X,Y);
}
//Старт симуляции------------------------------------------------------------
void __fastcall TbioForm::btnStartClick(TObject *Sender)
{
 if (reinit) {
  trckSunChange(NULL);
  trckMutChange(NULL);
  reinit = false;
 }
 TimerPaint->Enabled = true;
 TimerStat->Enabled = true;
}
//Пауза----------------------------------------------------------------------
void __fastcall TbioForm::btnPauseClick(TObject *Sender)
{
 TimerPaint->Enabled = false;
}
//Остановка симуляции--------------------------------------------------------
void __fastcall TbioForm::btnReinitClick(TObject *Sender)
{
 TimerPaint->Enabled = false;
 TimerStat->Enabled = false;
 reinit = true;
 for(int i=0;i<5;i++)
  StatusBar->Panels->Items[i]->Text="";
 Graphics::TBitmap* bmp=new Graphics::TBitmap;
 bmp->Width = Image->Width;
 bmp->Height = Image->Height;
 bmp->Canvas->Brush->Color=(TColor)0xA0A0A0;
 bmp->Canvas->Rectangle(0,0,bmp->Width,bmp->Height);
 BitBlt(Image->Canvas->Handle,0,0,bmp->Width,bmp->Height,
        bmp->Canvas->Handle,0,0,cmSrcCopy);
 Image->Refresh();
 bmp->Free();
 delete Areal;
 Areal = new BioSystem(Image->Width,Image->Height,trckPop->Position);
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::FormResize(TObject *Sender)
{
 Areal->Resize(Image->Width,Image->Height);
 StatusBar->Panels->Items[3]->Width = StatusBar->Width - 312;
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::btnHealClick(TObject *Sender)
{
 Areal->AddHealth(10);
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::btnKillClick(TObject *Sender)
{
 Areal->AddHealth(-10);
}
//---------------------------------------------------------------------------
void __fastcall TbioForm::edNameChange(TObject *Sender)
{
 if (StatusBar->Panels->Items[3]->Text != "")
  Areal->SetName(edName->Text);
}
//---------------------------------------------------------------------------



