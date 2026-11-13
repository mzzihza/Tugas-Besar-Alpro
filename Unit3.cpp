//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

extern double hargaProduk;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
    // Validasi: semua kolom harus terisi
    if (Trim(Edit1->Text) == "" || Trim(Edit2->Text) == "" ||
        Trim(Edit3->Text) == "" || Trim(Edit4->Text) == "")
    {
        ShowMessage("Semua data harus diisi terlebih dahulu!");
        return;
    }

    // Ambil harga layanan sebagai angka
    double hargaLayanan;
    try
    {
        hargaLayanan = StrToFloat(Edit3->Text);
    }
    catch (EConvertError &e)
    {
        ShowMessage("Harga layanan harus berupa angka!");
        return;
    }

    // Kirim data dari Form3 ke TLabel di Form4
    Form4->Label6->Caption = Edit1->Text;                                     // Pelanggan
    Form4->Label7->Caption = Edit2->Text;                                     // Layanan
    Form4->Label8->Caption = "Rp " + FloatToStr(hargaLayanan);                // Harga Layanan
    Form4->Label12->Caption = FloatToStr(hargaProduk + hargaLayanan); // Total
    Form4->Label15->Caption = Edit4->Text;   // Antrian ke- (ganti LabelXX dengan nama labelnya)

    // Pindah ke Form4 setelah semua data terkirim
    Form3->Hide();
    Form4->Show();
}
//---------------------------------------------------------------------------

