object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 411
  ClientWidth = 852
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 134
    Top = 256
    Width = 76
    Height = 24
    Caption = 'ID '#1095#1072#1090#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 233
    Top = 256
    Width = 21
    Height = 24
    Caption = 'ID'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 64
    Top = 305
    Width = 145
    Height = 23
    Caption = 'ID '#1086#1090#1087#1088#1072#1074#1080#1090#1077#1083#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 234
    Top = 304
    Width = 21
    Height = 24
    Caption = 'ID'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 64
    Top = 48
    Width = 377
    Height = 185
    AccessibleName = #1048#1084#1103' '#1092#1072#1081#1083#1072
    Header.AutoSizeIndex = 0
    Header.Height = 17
    Header.MainColumn = 1
    Header.Options = [hoColumnResize, hoDrag, hoShowSortGlyphs, hoVisible]
    TabOrder = 0
    OnAddToSelection = VirtualStringTree1AddToSelection
    OnGetText = VirtualStringTree1GetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Options = [coAllowClick, coDraggable, coEnabled, coParentBidiMode, coParentColor, coResizable, coShowDropMark, coAllowFocus, coEditable, coStyleColor]
        Position = 0
        Text = #1048#1076#1077#1085#1090#1080#1092#1080#1082#1072#1090#1086#1088
        Width = 110
      end
      item
        Position = 1
        Text = #1057#1086#1073#1097#1077#1085#1080#1077
        Width = 118
      end
      item
        Position = 2
        Text = #1042#1088#1077#1084#1077#1085#1085#1072#1103' '#1086#1090#1084#1077#1090#1082#1072
        Width = 156
      end>
  end
  object Button1: TButton
    Left = 488
    Top = 84
    Width = 81
    Height = 41
    Caption = #1047#1072#1087#1086#1083#1085#1077#1085#1080#1077
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 608
    Top = 84
    Width = 81
    Height = 41
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 488
    Top = 148
    Width = 201
    Height = 49
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1091#1102' '#1079#1072#1087#1080#1089#1100
    TabOrder = 3
    OnClick = Button3Click
  end
end
