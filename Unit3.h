//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit1;
        TLabel *Label3;
        TEdit *Edit2;
        TLabel *Label4;
        TEdit *Edit3;
        TLabel *Label5;
        TEdit *Edit4;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
