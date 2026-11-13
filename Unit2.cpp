//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
// data barang disimpan di array
AnsiString dataTeks[100][2];        // array 2D: kolom 0 = nama barang, kolom 1 = kategori
int stokBarang[100];               // array 1D
double hargaBarang[100];        //  array 1D
int jumlahBarang = 0;              // banyaknya barang yang tersimpan
double hargaProduk = 0;            //harga produk terakhir, dipakai Form3 untuk menghitung total
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// prosedur untuk mengosongkan semua kolom
void KosongkanForm()
{
    Form2->Edit1->Clear();
    Form2->Edit2->Clear();
    Form2->Edit3->Clear();
    Form2->Edit4->Clear();
    Form2->Edit1->SetFocus();
}
//---------------------------------------------------------------------------
// fungsi untuk mencari barang, hasilnya nomor urut barang di array (-1 kalau tidak ada)
int CariBarang(AnsiString namaDicari)
{
    for (int nomor = 0; nomor < jumlahBarang; nomor++)
    {
        if (dataTeks[nomor][0] == namaDicari)
            return nomor;
    }
    return -1;
}
//----------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
// cek apakah ada kolom yang kosong
    if (Edit1->Text == "" || Edit2->Text == "" || Edit3->Text == "" ||
        Edit4->Text == "")
    {
        ShowMessage("Semua data harus diisi!");
        return;
    }

    // ambil data dari kolom input
    AnsiString namaInput = Edit1->Text;
    AnsiString kategoriInput = Edit2->Text;
    int stokInput = StrToInt(Edit3->Text);
    double hargaInput = StrToFloat(Edit4->Text);

    int nomorBarang = CariBarang(namaInput);

    if (nomorBarang == -1)
    {
        // barang baru
        dataTeks[jumlahBarang][0] = namaInput;
        dataTeks[jumlahBarang][1] = kategoriInput;
        stokBarang[jumlahBarang] = stokInput;
        hargaBarang[jumlahBarang] = hargaInput;
        jumlahBarang++;
    }
    else
    {
        // barang sudah ada, stok ditambah
        stokBarang[nomorBarang] = stokBarang[nomorBarang] + stokInput;
        hargaBarang[nomorBarang] = hargaInput;
    }

    // simpan harga produk untuk dihitung di Form3
    hargaProduk = hargaInput;

    // tampilkan ke Form4 (hanya Produk Digunakan)
    Form4->Label9->Caption = namaInput + " (" + kategoriInput + ")";

    ShowMessage("Data berhasil disimpan");
    KosongkanForm();
    Form3->Show();
    Form2->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
AnsiString namaYangDihapus = Edit1->Text;
    int nomorBarang = CariBarang(namaYangDihapus);

    if (nomorBarang == -1)
    {
        ShowMessage("Barang tidak ditemukan!");
    }
    else
    {
        // geser data di belakangnya ke depan
        for (int nomor = nomorBarang; nomor < jumlahBarang - 1; nomor++)
        {
            dataTeks[nomor][0] = dataTeks[nomor + 1][0];
            dataTeks[nomor][1] = dataTeks[nomor + 1][1];
            stokBarang[nomor] = stokBarang[nomor + 1];
            hargaBarang[nomor] = hargaBarang[nomor + 1];
        }
        jumlahBarang--;
        ShowMessage("Data berhasil dihapus");
        KosongkanForm();
    }
}
//---------------------------------------------------------------------------

