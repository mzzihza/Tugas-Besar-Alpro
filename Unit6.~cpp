//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------






void __fastcall TForm6::Button1Click(TObject *Sender)
{
 
    String namaBarang = Edit1->Text.Trim();
    int tambahan = 0;
 
    // 1. Validasi input
    if (namaBarang.IsEmpty() || Edit2->Text.Trim().IsEmpty())
    {
        ShowMessage("Nama barang dan jumlah stok harus diisi!");
        return;
    }
 
    if (!TryStrToInt(Edit2->Text.Trim(), tambahan) || tambahan <= 0)
    {
        ShowMessage("Jumlah stok harus berupa angka lebih dari 0!");
        return;
    }
 
    // 2. Cari label nama barang di groupbox kanan
    //    (label yang tulisannya sama dengan nama yang diinput,
    //     tidak termasuk label di groupbox input sebelah kiri)
    TLabel *labelNama = NULL;
    for (int i = 0; i < ComponentCount; i++)
    {
        TLabel *lbl = dynamic_cast<TLabel*>(Components[i]);
        if (lbl != NULL &&
            lbl->Parent != Edit1->Parent &&
            SameText(lbl->Caption.Trim(), namaBarang))
        {
            labelNama = lbl;
            break;
        }
    }
 
    if (labelNama == NULL)
    {
        ShowMessage("Barang \"" + namaBarang + "\" tidak ditemukan di daftar stok!");
        return;
    }
 
    // 3. Cari label jumlah pada baris yang sama
    //    (posisi Top hampir sama, dan paling kanan)
    TLabel *labelJumlah = NULL;
    for (int i = 0; i < ComponentCount; i++)
    {
        TLabel *lbl = dynamic_cast<TLabel*>(Components[i]);
        if (lbl != NULL &&
            lbl != labelNama &&
            lbl->Parent == labelNama->Parent &&
            abs(lbl->Top - labelNama->Top) <= 5 &&
            lbl->Left > labelNama->Left)
        {
            if (labelJumlah == NULL || lbl->Left > labelJumlah->Left)
                labelJumlah = lbl;
        }
    }
 
    if (labelJumlah == NULL)
    {
        ShowMessage("Label jumlah untuk barang ini tidak ditemukan!");
        return;
    }
 
    // 4. Tambahkan stok lama dengan stok baru
    int stokLama = StrToIntDef(labelJumlah->Caption, 0);
    labelJumlah->Caption = IntToStr(stokLama + tambahan);
 
    // 5. Kosongkan input supaya siap dipakai lagi
    Edit1->Clear();
    Edit2->Clear();
    Edit1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject *Sender)
{
    String namaBarang = Edit1->Text.Trim();
    int kurang = 0;
 
    // 1. Validasi input
    if (namaBarang.IsEmpty() || Edit2->Text.Trim().IsEmpty())
    {
        ShowMessage("Nama barang dan jumlah stok harus diisi!");
        return;
    }
 
    if (!TryStrToInt(Edit2->Text.Trim(), kurang) || kurang <= 0)
    {
        ShowMessage("Jumlah stok harus berupa angka lebih dari 0!");
        return;
    }
 
    // 2. Cari label nama barang di groupbox kanan
    //    (label yang tulisannya sama dengan nama yang diinput,
    //     tidak termasuk label di groupbox input sebelah kiri)
    TLabel *labelNama = NULL;
    for (int i = 0; i < ComponentCount; i++)
    {
        TLabel *lbl = dynamic_cast<TLabel*>(Components[i]);
        if (lbl != NULL &&
            lbl->Parent != Edit1->Parent &&
            SameText(lbl->Caption.Trim(), namaBarang))
        {
            labelNama = lbl;
            break;
        }
    }
 
    if (labelNama == NULL)
    {
        ShowMessage("Barang \"" + namaBarang + "\" tidak ditemukan di daftar stok!");
        return;
    }
 
    // 3. Cari label jumlah pada baris yang sama
    //    (posisi Top hampir sama, dan paling kanan)
    TLabel *labelJumlah = NULL;
    for (int i = 0; i < ComponentCount; i++)
    {
        TLabel *lbl = dynamic_cast<TLabel*>(Components[i]);
        if (lbl != NULL &&
            lbl != labelNama &&
            lbl->Parent == labelNama->Parent &&
            abs(lbl->Top - labelNama->Top) <= 5 &&
            lbl->Left > labelNama->Left)
        {
            if (labelJumlah == NULL || lbl->Left > labelJumlah->Left)
                labelJumlah = lbl;
        }
    }
 
    if (labelJumlah == NULL)
    {
        ShowMessage("Label jumlah untuk barang ini tidak ditemukan!");
        return;
    }
 
    // 4. Pastikan stok cukup, lalu kurangi
    int stokLama = StrToIntDef(labelJumlah->Caption, 0);
 
    if (kurang > stokLama)
    {
        ShowMessage("Stok tidak cukup! Stok " + namaBarang + " saat ini hanya " +
                    IntToStr(stokLama) + ".");
        return;
    }
 
    labelJumlah->Caption = IntToStr(stokLama - kurang);
 
    // 5. Kosongkan input supaya siap dipakai lagi
    Edit1->Clear();
    Edit2->Clear();
    Edit1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button3Click(TObject *Sender)
{
Form5->Show();
Form6->Hide();
}
//---------------------------------------------------------------------------
