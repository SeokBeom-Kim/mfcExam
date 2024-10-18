
// glim1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "glim1.h"
#include "glim1Dlg.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// #pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cglim1Dlg 대화 상자



Cglim1Dlg::Cglim1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GLIM1_DIALOG, pParent)
	, x1(0)
	, y1(0)
	, x2(0)
	, y2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cglim1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, x1);
	DDX_Text(pDX, IDC_EDIT3, y1);
	DDX_Text(pDX, IDC_EDIT4, x2);
	DDX_Text(pDX, IDC_EDIT5, y2);
}

BEGIN_MESSAGE_MAP(Cglim1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cglim1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cglim1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cglim1Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Cglim1Dlg 메시지 처리기

BOOL Cglim1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cglim1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Cglim1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Cglim1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cglim1Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	if(!m_image) // Draw 재클릭시 발생하는 오류 방지
		m_image.Create(nWidth, -nHeight, nBpp);

	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	
	memset(fm, 0xff, nWidth * nHeight);

	radius = 100;


	UpdateData(true);
	drawCircle(fm, x1, y1, radius, 80);
	UpdateDisplay();
}


void Cglim1Dlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray) {
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2; j++) {
		for (int i = x; i < x + nRadius * 2; i++) {
			if(isInCircle(i, j, nCenterX, nCenterY, nRadius))
				if (validPos(i, j))
					fm[j * nPitch + i] = nGray;
		}
	}
}

bool Cglim1Dlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius) {
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius * nRadius) {
		bRet = true;
	}

	return bRet;
}

void Cglim1Dlg::UpdateDisplay() {

	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}


void Cglim1Dlg::moveCircle() {
	UpdateData(true);
	static int nSttX = x1;
	static int nSttY = y1;

	for (int i = 0; i < 10; i++) {
		int nGray = 80;
		int nRadius = radius;
		int nCenterX = nSttX + nRadius;
		int nCenterY = nSttY + nRadius;
		int nWidth = m_image.GetWidth();
		int nHeight = m_image.GetHeight();
		int nPitch = m_image.GetPitch();
		unsigned char* fm = (unsigned char*)m_image.GetBits();

		memset(fm, 0xff, nWidth * nHeight);

		for (int j = nSttY; j < nSttY + nRadius * 2; j++) {
			for (int i = nSttX; i < nSttX + nRadius * 2; i++) {
				if (isInCircle(i, j, nCenterX, nCenterY, nRadius))
					if (validPos(i, j))
						fm[j * nPitch + i] = nGray;
			}
		}
		Sleep(10);


		CString filename;
		filename.Format(_T("./%d.jpg"), i);

		m_image.Save(filename);

		nSttX += (x2 - x1) / 10;
		nSttY += (y2 - y1) / 10;
		UpdateDisplay();
	}

	nSttX = x1;
	nSttY = y1;
}


void Cglim1Dlg::OnBnClickedButton2()
{
	moveCircle();	
}

BOOL Cglim1Dlg::validPos(int x, int y) {
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	CRect rect(0, 0, nWidth, nHeight);

	return rect.PtInRect(CPoint(x, y));
}


void Cglim1Dlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	if (m_image != NULL)
		m_image.Destroy();

	CString str = _T("Images(*.jpg)|*.jpg|");
	CFileDialog dlg(TRUE, _T("*.dat"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, str, this);

	if (dlg.DoModal() == IDOK)
	{
		m_image.Load(dlg.GetPathName());
		
		unsigned char* fm = (unsigned char*)m_image.GetBits();

		int nWidth = m_image.GetWidth();
		int nHeight = m_image.GetHeight();
		// int nPitch = m_image.GetPitch();
		int nPitch = m_image.GetPitch();
		CRect rect(0, 0, nWidth, nHeight);

		int nTh = 0x80;
		int nSumX = 0;
		int nSumY = 0;
		int nCount = 0;


		for (int j = rect.top; j < rect.bottom; j++) {
			for (int i = rect.left; i < rect.right; i++) {
				if (fm[j * nPitch + i] > nTh) {

					nSumX += i;
					nSumY += j;
					nCount++;
				}
			}
		}
		

		if (nCount > 0) {
			double dCenterX = (double)nSumX / nCount;
			double dCenterY = (double)nSumY / nCount;

			for (int j = dCenterY; j < dCenterY + 10; j++) {
				for (int i = dCenterX; i < dCenterX + 10; i++) {
					fm[j * nPitch + i] = 0;
				}
			}
		}

		UpdateDisplay();
	}
}


