//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OnKeyPress(TObject *Sender)
{
    // Cek kolom kosong
    if (Edit1->Text.Trim() == "" || Edit2->Text.Trim() == "")
    {
        MessageDlg("Username dan Password tidak boleh kosong!",
                   mtWarning, TMsgDlgButtons() << mbOK, 0);
        Edit1->SetFocus();
        return;
    }

    // Cek login (ganti username & password sesuai keinginan)
    if (Edit1->Text == "admin" && Edit2->Text == "12345")
    {
        ShowMessage("Login berhasil! Selamat datang, Admin.");
        Edit1->Clear();
        Edit2->Clear();
        //Form2->Show();
        //Form1->Hide();
        Form5->Show();
        Form1->Hide();
    }
    else
    {
        MessageDlg("Username atau Password salah!",
                   mtError, TMsgDlgButtons() << mbOK, 0);
        Edit2->Clear();
        Edit2->SetFocus();
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
    // Tekan Enter di kolom password = klik tombol Masuk
    if (Key == VK_RETURN)
    {
        Key = 0;
        Button1->Click();
    }
}
//---------------------------------------------------------------------------
