
// CollisionBallDlg.h : header file
//

#pragma once

#define MAX_WALL 64
#define MAX_WIDTH WALL 100
#define MAX_HEIGHT WALL 100
#define MAX_R 20
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

struct Ball {
	double xPos;
	double yPos;
	double r;
};

struct Wall {
	double xPos;
	double yPos;
	double width;
	double height;
};

// CCollisionBallDlg dialog
class CCollisionBallDlg : public CDialogEx
{
// Construction
public:
	CCollisionBallDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COLLISIONBALL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CBrush white, black;
	Wall m_walls[MAX_WALL]; // mang chua danh sach cac wall trong cua so
	void DrawBall(Ball ball);
	void DrawWall(Wall wall);
	bool Collision(Ball ball); // Kiem tra gia tri ball co dang va cham voi wall trong mang m_walls hay khong
	void DestroyWall(Wall wall);
	void ControlBall(Ball ball);
};
