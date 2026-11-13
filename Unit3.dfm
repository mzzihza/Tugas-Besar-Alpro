object Form3: TForm3
  Left = 301
  Top = 192
  Width = 358
  Height = 500
  Caption = 'Form3'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 24
    Top = 16
    Width = 289
    Height = 337
    Caption = 'GroupBox1'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 32
      Width = 54
      Height = 13
      Caption = 'Alur Antrian'
    end
    object Label2: TLabel
      Left = 48
      Top = 56
      Width = 109
      Height = 13
      Caption = 'Input Nama Pelanggan'
    end
    object Label3: TLabel
      Left = 48
      Top = 104
      Width = 41
      Height = 13
      Caption = 'Layanan'
    end
    object Label4: TLabel
      Left = 48
      Top = 152
      Width = 73
      Height = 13
      Caption = 'Harga Layanan'
    end
    object Label5: TLabel
      Left = 48
      Top = 208
      Width = 83
      Height = 13
      Caption = 'Masuk ke Antrian'
    end
    object Edit1: TEdit
      Left = 48
      Top = 72
      Width = 201
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 48
      Top = 128
      Width = 201
      Height = 21
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 48
      Top = 176
      Width = 201
      Height = 21
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 48
      Top = 232
      Width = 201
      Height = 21
      TabOrder = 3
    end
    object Button1: TButton
      Left = 88
      Top = 272
      Width = 113
      Height = 41
      Caption = 'Lanjut'
      TabOrder = 4
      OnClick = Button1Click
    end
  end
end
