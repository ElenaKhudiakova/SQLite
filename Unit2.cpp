//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"

#include <string>
#include <string.h>
#include "sqlite3.h"

TForm2 *Form2;
char* intToStr(int data);
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
   VirtualStringTree1->NodeDataSize = sizeof(TreeNodeStruct);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	/*
	VirtualStringTree1->Clear();
	VirtualStringTree1->BeginUpdate();

	for (int  i = 0; i < 100;i++)
	{
		PVirtualNode entryNode = VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);
		TreeNodeStruct *nodeData = (TreeNodeStruct*)VirtualStringTree1->GetNodeData(entryNode);
		nodeData->Id = i;
		nodeData->FileName = u"���� ����� ";
		nodeData->FileName += UnicodeString(i);
	};

	VirtualStringTree1->EndUpdate();
	*/
	VirtualStringTree1->Clear();
	sqlite3* DataBase;

	//�������� ��
	int openResult = sqlite3_open16(L"..\\..\\DataBase\\Test2.db", &DataBase);
	const char *errmsg;
	sqlite3_stmt *pStatement;

	//���������� �������
	int result = sqlite3_prepare16_v2(DataBase, L"Select * FROM main.history ORDER BY id ASC", -1, &pStatement, NULL);

	if( result != SQLITE_OK)
	{
		errmsg = sqlite3_errmsg(DataBase);
	}
	else
	{
		errmsg = "DONE";
	};

	//���������� �������
	for (int  i = 0;;i++)
	{
		result = sqlite3_step(pStatement);
		if(result == SQLITE_DONE)
			break;
		else if (result != SQLITE_ROW)
		{
			//��������� ������
		}

		int TimeStamp = sqlite3_column_int(pStatement,1);
		int ChatId = sqlite3_column_int(pStatement,2);
		int SenderAlias = sqlite3_column_int(pStatement,3);
		wchar_t *wstr = (wchar_t*)sqlite3_column_text16(pStatement,4);

		PVirtualNode entryNode = VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);
		TreeNodeStruct *nodeData = (TreeNodeStruct*)VirtualStringTree1->GetNodeData(entryNode);

		nodeData->TimeStamp = TimeStamp;
		nodeData->ChatId = ChatId;
		nodeData->SenderAlias = SenderAlias;
		nodeData->Message = wstr;


	};

	sqlite3_finalize(pStatement);

	sqlite3_close(DataBase);


}
//---------------------------------------------------------------------------
void __fastcall TForm2::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
	if(!Node)return;
	TreeNodeStruct *nodeData = (TreeNodeStruct*)VirtualStringTree1->GetNodeData(Node);
	switch(Column)
	{
		case 0:
		{
			CellText = UnicodeString(nodeData->Id); break;
		}
		case 1:
		{
			CellText = UnicodeString(nodeData->Message); break;
		}
		case 2:
		{
			CellText = UnicodeString(nodeData->TimeStamp); break;
		}
		case 3:
		{
			CellText = UnicodeString(nodeData->ChatId); break;
		}
		case 4:
		{
			CellText = UnicodeString(nodeData->SenderAlias); break;
		}

	};
}
//---------------------------------------------------------------------------

void __fastcall TForm2::VirtualStringTree1AddToSelection(TBaseVirtualTree *Sender,
          PVirtualNode Node)
{
	TreeNodeStruct *nodeData = (TreeNodeStruct*)VirtualStringTree1->GetNodeData(Node);

	PVirtualNode selectedNode = VirtualStringTree1->FocusedNode;
	unsigned int selectedNodeIndex = selectedNode->Index;


	Label2->Caption = nodeData->ChatId;
	Label4->Caption = nodeData->SenderAlias;

	if (!selectedNode){
	//������
	};
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
  VirtualStringTree1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
	PVirtualNode selectedNode = VirtualStringTree1->FocusedNode;
	VirtualStringTree1->DeleteNode(selectedNode);

	int selectedNodeIndex = selectedNode->Index;
	int delIndex;
	sqlite3* DataBase;
	sqlite3_stmt *pStatement;
	const char *errmsg;
	int openResult = sqlite3_open16(L"..\\..\\DataBase\\Test2.db", &DataBase);
	char *sqlStr;

	selectedNodeIndex = selectedNodeIndex + 1;
	char *buf = intToStr(selectedNodeIndex);

	sqlStr = "DELETE FROM main.history WHERE id = ";
	char *res = strcat(sqlStr,buf);
	int deleteRes =  sqlite3_exec(DataBase, res,NULL, NULL ,NULL);

	//sqlite3_finalize(pStatement);

	sqlite3_close(DataBase);
}
//---------------------------------------------------------------------------
char* intToStr(int data) {
    std::string strData = std::to_string(data);

    char* temp = new char[strData.length() + 1];
    strcpy(temp, strData.c_str());

   return temp;
}
