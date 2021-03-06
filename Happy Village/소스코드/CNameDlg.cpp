// CNameDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "main.h"
#include "CNameDlg.h"
#include "afxdialogex.h"
#include "mainDlg.h"
#include <fstream>
#include <string>
#include <iostream>

// CNameDlg 대화 상자

IMPLEMENT_DYNAMIC(CNameDlg, CDialog)

CNameDlg::CNameDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_NAMEDLG, pParent)
{

}

CNameDlg::~CNameDlg()
{
}

void CNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_nameEdit);

}


BEGIN_MESSAGE_MAP(CNameDlg, CDialog)
END_MESSAGE_MAP()


// CNameDlg 메시지 처리기


BOOL CNameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CmainDlg* parent =
		(CmainDlg*)AfxGetMainWnd();
	parent->ShowWindow(SW_HIDE);



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CNameDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_nameEdit.GetWindowTextW(m_name);
	if (m_name.GetLength() >= 1 && m_name.GetLength() <= 12) {
		CmainDlg* parent =
			(CmainDlg*)GetParent();
		parent->m_name = m_name;
		std::string str = std::string(CT2CA(m_name.operator LPCWSTR()));
		std::ofstream outfile("userinfo.txt");
		outfile << str << std::endl << 11 << std::endl << 0;
		outfile << std::endl << 100000 << " " << 1;
		outfile << std::endl << 100001 << " " << 1;
		outfile << std::endl << 100002 << " " << 1;
		outfile << std::endl << 100003 << " " << 1;
		outfile << std::endl << 100004 << " " << 1;
		outfile << std::endl << 100005 << " " << 1;
		outfile << std::endl << 100006 << " " << 1;
		outfile << std::endl << 101000 << " " << 1;
		outfile << std::endl << 101001 << " " << 1;
		outfile << std::endl << 101002 << " " << 1;
		outfile << std::endl << 101003 << " " << 0;
		outfile << std::endl << 101004 << " " << 0;
		outfile << std::endl << 101005 << " " << 0;
		outfile << std::endl << 101006 << " " << 0;
		outfile << std::endl << 102000 << " " << 0;
		outfile << std::endl << 102001 << " " << 0;
		outfile << std::endl << 102002 << " " << 0;
		outfile << std::endl << 102003 << " " << 0;
		outfile << std::endl << 102004 << " " << 0;
		outfile << std::endl << 102005 << " " << 0;
		outfile << std::endl << 102006 << " " << 0;
		outfile << std::endl << 103000 << " " << 0;
		outfile << std::endl << 103001 << " " << 0;
		outfile << std::endl << 103002 << " " << 0;
		outfile << std::endl << 103003 << " " << 0;
		outfile << std::endl << 103004 << " " << 0;

		
		outfile.close();


		CDialog::OnOK();
	}
	else {
		return;
	}
}


void CNameDlg::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	//CDialog::OnCancel();
}


BOOL CNameDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_ESCAPE) return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}
