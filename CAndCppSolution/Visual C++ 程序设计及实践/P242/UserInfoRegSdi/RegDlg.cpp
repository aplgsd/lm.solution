// RegDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "UserInfoRegSdi.h"
#include "RegDlg.h"


// CRegDlg 对话框

IMPLEMENT_DYNCREATE(CRegDlg, CDHtmlDialog)

CRegDlg::CRegDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CRegDlg::IDD, CRegDlg::IDH, pParent)
{

}

CRegDlg::~CRegDlg()
{
}

void CRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
}

BOOL CRegDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

BEGIN_MESSAGE_MAP(CRegDlg, CDHtmlDialog)
END_MESSAGE_MAP()

BEGIN_DHTML_EVENT_MAP(CRegDlg)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()



// CRegDlg 消息处理程序

HRESULT CRegDlg::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;
}

HRESULT CRegDlg::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}

void CRegDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDHtmlDialog::OnOK();

	DestroyWindow();  // 销毁对话框
}

void CRegDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDHtmlDialog::OnCancel();

	DestroyWindow();  // 销毁对话框 
}

void CRegDlg::PostNcDestroy()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDHtmlDialog::PostNcDestroy();

	delete this;  // 删除对话框所占的动态内存 
}
