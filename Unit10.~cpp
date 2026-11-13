//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit10.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Button1Click(TObject *Sender)
{
Form5->Show();
Form10->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Button2Click(TObject *Sender)
{
    int pendapatan = 0;
    int modal      = 0;

    // 1. Ambil total pendapatan (Label4) dan total modal (Label6)
    if (!TryStrToInt(Label4->Caption.Trim(), pendapatan))
    {
        ShowMessage("Total pendapatan belum ada! Tekan tombol "
                    "\"Tambah ke Rekap Penghasilan\" di Riwayat dulu.");
        return;
    }

    if (!TryStrToInt(Label6->Caption.Trim(), modal))
    {
        ShowMessage("Total modal harus berupa angka!");
        return;
    }

    // 2. Hitung laba bersih = pendapatan - modal
    int laba = pendapatan - modal;

    // 3. Tampilkan di label Laba Bersih
    Label8->Caption = IntToStr(laba);        
}
//---------------------------------------------------------------------------
