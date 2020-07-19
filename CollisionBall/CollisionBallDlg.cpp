
// CollisionBallDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CollisionBall.h"
#include "CollisionBallDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CCollisionBallDlg::CCollisionBallDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COLLISIONBALL_DIALOG, pParent), white(RGB(255, 255, 255)), black(RGB(0, 0, 0))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCollisionBallDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCollisionBallDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CCollisionBallDlg message handlers

BOOL CCollisionBallDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCollisionBallDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CCollisionBallDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCollisionBallDlg::DrawBall(Ball ball)
{
	CClientDC dc(this);
	CBrush *brush;
	brush = dc.SelectObject(&black);
	dc.Ellipse(ball.xPos - ball.r, ball.yPos - ball.r, ball.xPos + ball.r, ball.yPos + ball.r);
	dc.SelectObject(brush);

}

void CCollisionBallDlg::DrawWall(Wall wall)
{
	CClientDC dc(this);
	CBrush *brush;
	brush = dc.SelectObject(&black);
	
	dc.Rectangle(wall.xPos, wall.yPos, wall.xPos + wall.width, wall.yPos + wall.height);
	dc.SelectObject(brush);
}

bool CCollisionBallDlg::Collision(Ball ball)
{
	for (int i = 0; i < MAX_WALL; i++)
	{
		double x1 = m_walls[i].xPos;
		double y1 = m_walls[i].yPos;
		double x2 = m_walls[i].xPos + m_walls[i].width;
		double y2 = m_walls[i].yPos + m_walls[i].height;
		if (ball.xPos-ball.r >= x2 || x1 >= ball.xPos+ball.r)
			return true;

		// If one rectangle is above other 
		if (ball.yPos-ball.r <= y2 || y1 <= ball.yPos + ball.r)
			return true;
	}
	return false;
}

void CCollisionBallDlg::DestroyWall(Wall wall)
{
	
}

void CCollisionBallDlg::ControlBall(Ball ball)
{
	// Create Ball

	// Create Wall

	// Control Ball: Collision, Destroy Wall, 
	while (true)
	{

	}

	// Destroy all
	return;
}