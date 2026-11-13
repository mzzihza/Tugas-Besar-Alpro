object Form2: TForm2
  Left = 701
  Top = 168
  Width = 449
  Height = 496
  Caption = 'Form2'
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
    Width = 369
    Height = 369
    Caption = 'GroupBox1'
    TabOrder = 0
    object Label1: TLabel
      Left = 112
      Top = 32
      Width = 112
      Height = 13
      Caption = 'Form Input Stok Barang'
    end
    object Label2: TLabel
      Left = 16
      Top = 80
      Width = 68
      Height = 13
      Caption = 'Nama Barang:'
    end
    object Label3: TLabel
      Left = 16
      Top = 120
      Width = 42
      Height = 13
      Caption = 'Kategori:'
    end
    object Label4: TLabel
      Left = 16
      Top = 160
      Width = 51
      Height = 13
      Caption = 'Stok (unit):'
    end
    object Label5: TLabel
      Left = 16
      Top = 200
      Width = 32
      Height = 13
      Caption = 'Harga:'
    end
    object Edit1: TEdit
      Left = 104
      Top = 72
      Width = 233
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 104
      Top = 112
      Width = 233
      Height = 21
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 104
      Top = 152
      Width = 233
      Height = 21
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 104
      Top = 192
      Width = 233
      Height = 21
      TabOrder = 3
    end
    object Button1: TButton
      Left = 32
      Top = 288
      Width = 113
      Height = 33
      Caption = 'SIMPAN'
      TabOrder = 4
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 184
      Top = 288
      Width = 137
      Height = 33
      Caption = 'HAPUS'
      TabOrder = 5
      OnClick = Button2Click
    end
  end
end
