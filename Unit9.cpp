//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit5.h"
#include "Unit10.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button1Click(TObject *Sender)
{
Form5->Show();
Form9->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button2Click(TObject *Sender)
{
 Form10->Show();
 Form9->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Button3Click(TObject *Sender)
{
    // 1. Cari label header "Total" di list Riwayat
    TLabel *hTotal = NULL;
    for (int i = 0; i < ComponentCount; i++)
    {
        TLabel *lbl = dynamic_cast<TLabel*>(Components[i]);
        if (lbl != NULL && SameText(lbl->Caption.Trim(), "Total"))
        {
            hTotal = lbl;
            break;
        }
    }

    if (hTotal == NULL)
    {
        ShowMessage("Header kolom Total tidak ditemukan!");
        return;
    }

    // 2. Hitung jumlah transaksi dan total pendapatan dari kolom Total
    //    (hanya baris yang sudah terisi)
    int jumlahTransaksi = 0;
    int totalPendapatan = 0;
    for (int i = 0; i < ComponentCount; i++)
    {
        TLabel *lbl = dynamic_cast<TLabel*>(Components[i]);
        if (lbl != NULL &&
            lbl != hTotal &&
            lbl->Parent == hTotal->Parent &&
            lbl->Top > hTotal->Top &&
            abs(lbl->Left - hTotal->Left) <= 5 &&
            !lbl->Caption.Trim().IsEmpty())
        {
            jumlahTransaksi++;
            totalPendapatan += StrToIntDef(lbl->Caption.Trim(), 0);
        }
    }

    if (jumlahTransaksi == 0)
    {
        ShowMessage("Riwayat masih kosong, belum ada transaksi!");
        return;
    }

    // 3. Tampilkan ke form Rekap Penghasilan (Form10)
    Form10->Label2->Caption = IntToStr(jumlahTransaksi);   // Total Transaksi
    Form10->Label4->Caption = IntToStr(totalPendapatan);   // Total Pendapatan        
}
//---------------------------------------------------------------------------
