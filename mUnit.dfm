object bioForm: TbioForm
  Left = 192
  Top = 114
  Width = 640
  Height = 441
  Caption = 'Synthetic Evolution'
  Color = clBtnFace
  Constraints.MinHeight = 441
  Constraints.MinWidth = 128
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = Menu
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel: TPanel
    Left = 0
    Top = 0
    Width = 512
    Height = 368
    Align = alClient
    AutoSize = True
    Color = 10526880
    TabOrder = 0
    object Image: TImage
      Left = 1
      Top = 1
      Width = 510
      Height = 366
      Align = alClient
      AutoSize = True
      OnMouseDown = ImageMouseDown
      OnMouseMove = ImageMouseMove
      OnMouseUp = ImageMouseUp
    end
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 368
    Width = 632
    Height = 19
    Panels = <
      item
        Width = 64
      end
      item
        Width = 64
      end
      item
        Width = 64
      end
      item
        Width = 320
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object GroupPanel: TPanel
    Left = 512
    Top = 0
    Width = 120
    Height = 368
    Align = alRight
    Caption = 'GroupPanel'
    TabOrder = 2
    object Group: TGroupBox
      Left = 1
      Top = 1
      Width = 118
      Height = 366
      Align = alClient
      Caption = 'Options'
      TabOrder = 0
      DesignSize = (
        118
        366)
      object Label1: TLabel
        Left = 56
        Top = 52
        Width = 40
        Height = 13
        Caption = 'Predator'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 56
        Top = 76
        Width = 57
        Height = 13
        Caption = 'Herbivorous'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clOlive
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 56
        Top = 28
        Width = 24
        Height = 13
        Caption = 'Plant'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGreen
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 8
        Top = 124
        Width = 105
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = 'Sun Energy'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label5: TLabel
        Left = 8
        Top = 180
        Width = 105
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = 'Mutation Rate'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object btnStart: TSpeedButton
        Left = 21
        Top = 334
        Width = 25
        Height = 25
        Hint = 'Go'
        Anchors = [akLeft, akBottom]
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          33333333333333333333777777777777777333FFFFFFFFFFFFF3700000000000
          007337777777777777F370F777777777707337F33333333337F370F333333333
          707337F3333F333337F370F333033333707337F3337FF33337F370F333003333
          707337F33377FF3337F370F333000333707337F333777FF337F370F333000033
          707337F33377773337F370F333000333707337F33377733337F370F333003333
          707337F33377333337F370F333033333707337F33373333337F370F333333333
          707337F33333333337F370FFFFFFFFFFF07337FFFFFFFFFFF7F3700000000000
          0073377777777777773377777777777777733333333333333333}
        NumGlyphs = 2
        OnClick = btnStartClick
      end
      object btnPause: TSpeedButton
        Left = 45
        Top = 334
        Width = 25
        Height = 25
        Hint = 'Pause'
        Anchors = [akLeft, akBottom]
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          33333333333333333333777777777777777333FFFFFFFFFFFFF3700000000000
          007337777777777777F370F777777777707337F33333333337F370F333333333
          707337F33333333337F370F333333333707337F333FF3FF337F370F330030033
          707337F3377F77F337F370F330030033707337F3377F77F337F370F330030033
          707337F3377F77F337F370F330030033707337F3377F77F337F370F330030033
          707337F33773773337F370F333333333707337F33333333337F370F333333333
          707337F33333333337F370FFFFFFFFFFF07337FFFFFFFFFFF7F3700000000000
          0073377777777777773377777777777777733333333333333333}
        NumGlyphs = 2
        OnClick = btnPauseClick
      end
      object btnReinit: TSpeedButton
        Left = 69
        Top = 334
        Width = 25
        Height = 25
        Hint = 'Start Over'
        Anchors = [akLeft, akBottom]
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          33333333333333333333777777777777777333FFFFFFFFFFFFF3700000000000
          007337777777777777F370F777777777707337F33333333337F370F333333333
          707337F33333333337F370F333333333707337F3333F3FF337F370F333030033
          707337F3337F77F337F370F330030033707337F3377F77F337F370F300030033
          707337F3777F77F337F370F330030033707337F3377F77F337F370F333030033
          707337F33373773337F370F333333333707337F33333333337F370F333333333
          707337F33333333337F370FFFFFFFFFFF07337FFFFFFFFFFF7F3700000000000
          0073377777777777773377777777777777733333333333333333}
        NumGlyphs = 2
        OnClick = btnReinitClick
      end
      object btnAdd1: TSpeedButton
        Left = 5
        Top = 21
        Width = 25
        Height = 25
        Hint = 'Go'
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          33337777777777777773700000000000007370F777777777707370F333333333
          707370F333333333707370F333303333707370F333303333707370F330000033
          707370F333303333707370F333303333707370F333333333707370F333333333
          707370FFFFFFFFFFF07370000000000000737777777777777773}
        OnClick = btnAdd1Click
      end
      object btnDel1: TSpeedButton
        Left = 29
        Top = 21
        Width = 25
        Height = 25
        Hint = 'Go'
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          33337777777777777773700000000000007370F777777777707370F333333333
          707370F333333333707370F333333333707370F333333333707370F330000033
          707370F333333333707370F333333333707370F333333333707370F333333333
          707370FFFFFFFFFFF07370000000000000737777777777777773}
        OnClick = btnDel1Click
      end
      object btnAdd2: TSpeedButton
        Left = 5
        Top = 45
        Width = 25
        Height = 25
        Hint = 'Go'
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          33337777777777777773700000000000007370F777777777707370F333333333
          707370F333333333707370F333303333707370F333303333707370F330000033
          707370F333303333707370F333303333707370F333333333707370F333333333
          707370FFFFFFFFFFF07370000000000000737777777777777773}
        OnClick = btnAdd2Click
      end
      object btnAdd3: TSpeedButton
        Left = 5
        Top = 69
        Width = 25
        Height = 25
        Hint = 'Go'
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          33337777777777777773700000000000007370F777777777707370F333333333
          707370F333333333707370F333303333707370F333303333707370F330000033
          707370F333303333707370F333303333707370F333333333707370F333333333
          707370FFFFFFFFFFF07370000000000000737777777777777773}
        OnClick = btnAdd3Click
      end
      object btnDel2: TSpeedButton
        Left = 29
        Top = 45
        Width = 25
        Height = 25
        Hint = 'Go'
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          33337777777777777773700000000000007370F777777777707370F333333333
          707370F333333333707370F333333333707370F333333333707370F330000033
          707370F333333333707370F333333333707370F333333333707370F333333333
          707370FFFFFFFFFFF07370000000000000737777777777777773}
        OnClick = btnDel2Click
      end
      object btnDel3: TSpeedButton
        Left = 29
        Top = 69
        Width = 25
        Height = 25
        Hint = 'Go'
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          33337777777777777773700000000000007370F777777777707370F333333333
          707370F333333333707370F333333333707370F333333333707370F330000033
          707370F333333333707370F333333333707370F333333333707370F333333333
          707370FFFFFFFFFFF07370000000000000737777777777777773}
        OnClick = btnDel3Click
      end
      object Label6: TLabel
        Left = 56
        Top = 98
        Width = 31
        Height = 13
        Alignment = taCenter
        Caption = 'Health'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object btnHeal: TSpeedButton
        Left = 5
        Top = 93
        Width = 25
        Height = 25
        Hint = 'Go'
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          33337777777777777773700000000000007370F777777777707370F333333333
          707370F333333333707370F333303333707370F333303333707370F330000033
          707370F333303333707370F333303333707370F333333333707370F333333333
          707370FFFFFFFFFFF07370000000000000737777777777777773}
        OnClick = btnHealClick
      end
      object btnKill: TSpeedButton
        Left = 29
        Top = 93
        Width = 25
        Height = 25
        Hint = 'Go'
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          04000000000080000000130B0000130B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          33337777777777777773700000000000007370F777777777707370F333333333
          707370F333333333707370F333333333707370F333333333707370F330000033
          707370F333333333707370F333333333707370F333333333707370F333333333
          707370FFFFFFFFFFF07370000000000000737777777777777773}
        OnClick = btnKillClick
      end
      object Label7: TLabel
        Left = 5
        Top = 236
        Width = 105
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = 'Start Population'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label8: TLabel
        Left = 5
        Top = 292
        Width = 105
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = 'Name Tag'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Shape: TShape
        Left = 17
        Top = 295
        Width = 7
        Height = 7
        Brush.Color = clSilver
        Shape = stCircle
      end
      object trckSun: TTrackBar
        Left = 6
        Top = 144
        Width = 105
        Height = 33
        Min = 2
        Orientation = trHorizontal
        Frequency = 1
        Position = 6
        SelEnd = 7
        SelStart = 5
        TabOrder = 0
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = trckSunChange
      end
      object trckMut: TTrackBar
        Left = 5
        Top = 200
        Width = 105
        Height = 33
        Max = 8
        Orientation = trHorizontal
        Frequency = 1
        Position = 4
        SelEnd = 5
        SelStart = 3
        TabOrder = 1
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = trckMutChange
      end
      object trckPop: TTrackBar
        Left = 5
        Top = 256
        Width = 105
        Height = 33
        Max = 250
        Min = 25
        Orientation = trHorizontal
        Frequency = 25
        Position = 25
        SelEnd = 0
        SelStart = 0
        TabOrder = 2
        TickMarks = tmBottomRight
        TickStyle = tsAuto
      end
      object edName: TEdit
        Left = 9
        Top = 310
        Width = 100
        Height = 16
        AutoSize = False
        BevelInner = bvSpace
        BevelKind = bkFlat
        BevelOuter = bvRaised
        BorderStyle = bsNone
        Enabled = False
        TabOrder = 3
        OnChange = edNameChange
      end
    end
  end
  object TimerPaint: TTimer
    Interval = 40
    OnTimer = TimerPaintTimer
    Left = 472
    Top = 8
  end
  object Menu: TMainMenu
    Left = 440
    Top = 8
    object File1: TMenuItem
      Caption = 'File'
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
    object N1: TMenuItem
      Caption = '?'
      object ABout1: TMenuItem
        Caption = 'About...'
        OnClick = ABout1Click
      end
    end
  end
  object TimerStat: TTimer
    Interval = 250
    OnTimer = TimerStatTimer
    Left = 472
    Top = 40
  end
end
