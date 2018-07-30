//---------------------------------------------------------------------------

#ifndef mUnitH
#define mUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
#include <math.h>
#include <Math.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include "About.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TbioForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel;
        TTimer *TimerPaint;
        TImage *Image;
        TStatusBar *StatusBar;
        TMainMenu *Menu;
        TMenuItem *File1;
        TPanel *GroupPanel;
        TGroupBox *Group;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TMenuItem *Exit1;
        TMenuItem *ABout1;
        TMenuItem *N1;
        TTrackBar *trckSun;
        TLabel *Label4;
        TTrackBar *trckMut;
        TLabel *Label5;
        TTimer *TimerStat;
        TSpeedButton *btnStart;
        TSpeedButton *btnPause;
        TSpeedButton *btnReinit;
        TSpeedButton *btnAdd1;
        TSpeedButton *btnDel1;
        TSpeedButton *btnDel2;
        TSpeedButton *btnAdd2;
        TSpeedButton *btnDel3;
        TSpeedButton *btnAdd3;
        TLabel *Label6;
        TSpeedButton *btnHeal;
        TSpeedButton *btnKill;
        TTrackBar *trckPop;
        TLabel *Label7;
        TEdit *edName;
        TLabel *Label8;
        TShape *Shape;
        void __fastcall TimerPaintTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btnAdd1Click(TObject *Sender);
        void __fastcall btnAdd2Click(TObject *Sender);
        void __fastcall btnAdd3Click(TObject *Sender);
        void __fastcall btnDel1Click(TObject *Sender);
        void __fastcall btnDel2Click(TObject *Sender);
        void __fastcall btnDel3Click(TObject *Sender);
        void __fastcall ABout1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall trckSunChange(TObject *Sender);
        void __fastcall trckMutChange(TObject *Sender);
        void __fastcall TimerStatTimer(TObject *Sender);
        void __fastcall ImageMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall ImageMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall ImageMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall btnStartClick(TObject *Sender);
        void __fastcall btnPauseClick(TObject *Sender);
        void __fastcall btnReinitClick(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall btnHealClick(TObject *Sender);
        void __fastcall btnKillClick(TObject *Sender);
        void __fastcall edNameChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TbioForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TbioForm *bioForm;
//---------------------------------------------------------------------------
#endif
