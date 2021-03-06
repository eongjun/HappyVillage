// CResultDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "main.h"
#include "CResultDlg.h"
#include "afxdialogex.h"
#include "CDogPigDlg.h"

// CResultDlg 대화 상자

IMPLEMENT_DYNAMIC(CResultDlg, CDialog)

CResultDlg::CResultDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_OPENDLG, pParent)
{

}

CResultDlg::~CResultDlg()
{
}

void CResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_getCard[0]);
	DDX_Control(pDX, IDC_BUTTON2, m_getCard[1]);
	DDX_Control(pDX, IDC_BUTTON3, m_getCard[2]);
	DDX_Control(pDX, IDC_BUTTON4, m_getCard[3]);
	DDX_Control(pDX, IDC_BUTTON5, m_getCard[4]);


}


BEGIN_MESSAGE_MAP(CResultDlg, CDialog)
	ON_WM_WINDOWPOSCHANGING()
END_MESSAGE_MAP()


// CResultDlg 메시지 처리기


void CResultDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CDogPigDlg* parent =
		(CDogPigDlg*)GetParent();
	CString cs;
	for (int i = 0; i < 5; i++) {
		m_getCard[i].GetWindowTextW(cs);
		for (int j = 0; j < 26; j++) {
			if (cs.Compare(parent->m_cardName[j]) == 0) {
				if (parent->m_card[j][1] < 10) {
					parent->m_card[j][1]++;
				}
			}

		}
	}

	std::ofstream outfile("userinfo.txt");
	outfile << parent->name << std::endl << parent->stage << std::endl << parent->packCnt;
	for (int i = 0; i < 26; i++) {
		outfile << std::endl << parent->m_card[i][0] << " " << parent->m_card[i][1];
	}

	outfile.close();

	((CDogPigDlg*)GetParent())->m_dlg = NULL;

	this->DestroyWindow();
	//	CDialog::OnOK();
}


void CResultDlg::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	((CDogPigDlg*)GetParent())->m_dlg = NULL;

	this->DestroyWindow();
	//CDialog::OnCancel();
}


void CResultDlg::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	delete this;
	CDialog::PostNcDestroy();
}


BOOL CResultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CString str[5];
	CDogPigDlg* parent =
		(CDogPigDlg*)GetParent();

	int random;
	CString Str;
	srand(time(NULL));

	for (int i = 0; i < 5; i++) {
		random = rand() % 26 + 1;
		Str.Format(_T("%d번 카드"), random);
		m_getCard[i].SetWindowTextW(Str);
	}


	for (int i = 0; i < 5; i++) {
		m_getCard[i].GetWindowTextW(str[i]);
	}
	TRACE(str[0]);
	TRACE(str[1]);
	TRACE(str[2]);
	TRACE(str[3]);
	TRACE(str[4]);


	for (int i = 0; i < 5; i++) {
		if (str[i].Compare(_T("1번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP210, IDB_BITMAP210, IDB_BITMAP210, IDB_BITMAP210);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("2번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP211, IDB_BITMAP211, IDB_BITMAP211, IDB_BITMAP211);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("3번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP212, IDB_BITMAP212, IDB_BITMAP212, IDB_BITMAP212);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("4번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP213, IDB_BITMAP213, IDB_BITMAP213, IDB_BITMAP213);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("5번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP214, IDB_BITMAP214, IDB_BITMAP214, IDB_BITMAP214);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("6번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP215, IDB_BITMAP215, IDB_BITMAP215, IDB_BITMAP215);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("7번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP216, IDB_BITMAP216, IDB_BITMAP216, IDB_BITMAP216);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("8번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP217, IDB_BITMAP217, IDB_BITMAP217, IDB_BITMAP217);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("9번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP218, IDB_BITMAP218, IDB_BITMAP218, IDB_BITMAP218);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("10번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP219, IDB_BITMAP219, IDB_BITMAP219, IDB_BITMAP219);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("11번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP220, IDB_BITMAP220, IDB_BITMAP220, IDB_BITMAP220);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("12번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP221, IDB_BITMAP221, IDB_BITMAP221, IDB_BITMAP221);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("13번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP222, IDB_BITMAP222, IDB_BITMAP222, IDB_BITMAP222);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("14번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP223, IDB_BITMAP223, IDB_BITMAP223, IDB_BITMAP223);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("15번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP224, IDB_BITMAP224, IDB_BITMAP224, IDB_BITMAP224);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("16번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP225, IDB_BITMAP225, IDB_BITMAP225, IDB_BITMAP225);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("17번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP226, IDB_BITMAP226, IDB_BITMAP226, IDB_BITMAP226);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("18번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP227, IDB_BITMAP227, IDB_BITMAP227, IDB_BITMAP227);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("19번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP228, IDB_BITMAP228, IDB_BITMAP228, IDB_BITMAP228);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("20번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP229, IDB_BITMAP229, IDB_BITMAP229, IDB_BITMAP229);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("21번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP230, IDB_BITMAP230, IDB_BITMAP230, IDB_BITMAP230);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("22번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP231, IDB_BITMAP231, IDB_BITMAP231, IDB_BITMAP231);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("23번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP232, IDB_BITMAP232, IDB_BITMAP232, IDB_BITMAP232);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("24번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP233, IDB_BITMAP233, IDB_BITMAP233, IDB_BITMAP233);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("25번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP234, IDB_BITMAP234, IDB_BITMAP234, IDB_BITMAP234);
			m_getCard[i].SizeToContent();
		}
		else if (str[i].Compare(_T("26번 카드")) == 0) {
			m_getCard[i].LoadBitmaps(IDB_BITMAP235, IDB_BITMAP235, IDB_BITMAP235, IDB_BITMAP235);
			m_getCard[i].SizeToContent();
		}
	}


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CResultDlg::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
	CDialog::OnWindowPosChanging(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect rect;
	((CDogPigDlg*)GetParent())->GetWindowRect(rect);
	this->MoveWindow(rect.left - 202, rect.bottom, 810, 300);
	lpwndpos->flags |= SWP_NOMOVE;
}


BOOL CResultDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->wParam == VK_ESCAPE) return TRUE;

	return CDialog::PreTranslateMessage(pMsg);
}
