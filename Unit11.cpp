//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit11.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;
//---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button1Click(TObject *Sender)
{
try {
        // 1. Ambil nilai harga dari Label1
        // Pastikan isi Label1->Caption hanya berupa angka murni (tanpa huruf/simbol seperti "Rp")
        double harga = StrToFloat(Label9->Caption);

        // 2. Ambil nilai uang yang dibayarkan dari TEdit1
        double bayar = StrToFloat(Edit1->Text);

        // 3. Bersihkan ListBox terlebih dahulu agar data sebelumnya tidak menumpuk
        ListBox1->Clear();

        // 4. Proses logika pembayaran
        if (bayar < harga) {
            // Jika uang bayar kurang dari harga
            ListBox1->Items->Add("Uang pembayaran kurang!");
        } else {
            // Jika uang pas atau lebih, hitung kembalian
            double kembalian = bayar - harga;

            // Tampilkan hasil kembalian ke dalam ListBox1
            ListBox1->Items->Add("Kembalian: " + FloatToStr(kembalian));
        }
    }
    catch (const Exception &e) {
        // Mencegah error / program crash jika Edit1 kosong atau diisi huruf
        ShowMessage("Pastikan input jumlah bayar dan harga berupa angka yang valid!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button2Click(TObject *Sender)
{
Form5->Show();
Form11->Hide();
}
//---------------------------------------------------------------------------
