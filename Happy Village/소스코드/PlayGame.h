#pragma once
#include "Unit.h"
#include <vector>
#include <string>
#include "UnitTime.h"


// PlayGame 대화 상자

class PlayGame : public CDialog
{
	DECLARE_DYNAMIC(PlayGame)

public:
	PlayGame(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~PlayGame();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual void OnCancel();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CRect m_client;
	int cardNum;
	std::vector<Unit> card_info;
	std::vector<Unit> unit1, unit2;
	std::vector<UnitTime> e_u;
	int e_u_info;
	int e_u_n;
	Unit hand[4];
	int deck[10];
	int castle1, castle2;
	int cost;
	int pop, e_pop;
	int wait[15] = { 0 };
	int wait2[15] = { 0 };
	int move[15] = { 0 };
	int move2[15] = { 0 };
	int playtime;
	int bit(int code);
	string u_n;
	int u_stage;
	int u_pack;
	int u_card[26][2];
	int stage; // 스테이지 정보, 오엉준에게 받아야 함
	int timerflag;
};
