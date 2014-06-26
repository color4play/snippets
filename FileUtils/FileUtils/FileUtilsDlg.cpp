// FileUtilsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FileUtils.h"
#include "FileUtilsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileUtilsDlg �Ի���




CFileUtilsDlg::CFileUtilsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileUtilsDlg::IDD, pParent)
	, m_csFilePath("")
	, m_hFile(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CFileUtilsDlg::~CFileUtilsDlg(void)
{
	if (m_hFile != NULL) {
		CloseHandle(m_hFile);
	}
}

void CFileUtilsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PATH, m_cPath);
	DDX_Control(pDX, IDC_EDIT2, m_cCreateTimeYear);
	DDX_Control(pDX, IDC_EDIT3, m_cModifyTimeYear);
	DDX_Control(pDX, IDC_EDIT4, m_cAccessTimeYear);
	DDX_Control(pDX, IDC_EDIT5, m_cCreateTimeMonth);
	DDX_Control(pDX, IDC_EDIT6, m_cModifyTimeMonth);
	DDX_Control(pDX, IDC_EDIT7, m_cAccessTimeMonth);
	DDX_Control(pDX, IDC_EDIT8, m_cCreateTimeDay);
	DDX_Control(pDX, IDC_EDIT9, m_cModifyTimeDay);
	DDX_Control(pDX, IDC_EDIT10, m_cAccessTimeDay);
	DDX_Control(pDX, IDC_EDIT11, m_cCreateTimeHour);
	DDX_Control(pDX, IDC_EDIT12, m_cModifyTimeHour);
	DDX_Control(pDX, IDC_EDIT13, m_cAccessTimeHour);
	DDX_Control(pDX, IDC_EDIT14, m_cCreateTimeMinute);
	DDX_Control(pDX, IDC_EDIT15, m_cModifyTimeMinute);
	DDX_Control(pDX, IDC_EDIT16, m_cAccessTimeMinute);
	DDX_Control(pDX, IDC_EDIT17, m_cCreateTimeSecond);
	DDX_Control(pDX, IDC_EDIT18, m_cModifyTimeSecond);
	DDX_Control(pDX, IDC_EDIT19, m_cAccessTimeSecond);
	DDX_Control(pDX, IDC_APPLY, m_btnApply);
}

BEGIN_MESSAGE_MAP(CFileUtilsDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DROPFILES()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_SCAN, &CFileUtilsDlg::OnBnClickedScan)
	ON_BN_CLICKED(IDC_APPLY, &CFileUtilsDlg::OnBnClickedApply)
END_MESSAGE_MAP()


// CFileUtilsDlg ��Ϣ�������

BOOL CFileUtilsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	DragAcceptFiles(TRUE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


void CFileUtilsDlg::OnDropFiles(HDROP hDropInfo)
{
	m_btnApply.EnableWindow(FALSE);
	int DropCount = DragQueryFile(hDropInfo, -1, NULL, 0);
	if (DropCount == 1) {
		size_t pathLength = DragQueryFile(hDropInfo, 0, NULL, 0) + 1;
		LPWSTR buffer = m_csFilePath.GetBufferSetLength(pathLength);
		DragQueryFile(hDropInfo, 0, buffer, pathLength);
		if (!m_csFilePath.IsEmpty()) {
			ShowFileTime();
		}
	}

	DragFinish(hDropInfo);
	CDialog::OnDropFiles(hDropInfo);
	return;
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFileUtilsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();

		// ���������ֳ���
		m_cCreateTimeYear.SetLimitText(4);
		m_cCreateTimeYear.SetLimitText(4);
		m_cModifyTimeYear.SetLimitText(4);
		m_cAccessTimeYear.SetLimitText(4);
		// ��������ʱ���볤��
		m_cCreateTimeMonth.SetLimitText(2);
		m_cModifyTimeMonth.SetLimitText(2);
		m_cAccessTimeMonth.SetLimitText(2);
		m_cCreateTimeDay.SetLimitText(2);
		m_cModifyTimeDay.SetLimitText(2);
		m_cAccessTimeDay.SetLimitText(2);
		m_cCreateTimeHour.SetLimitText(2);
		m_cModifyTimeHour.SetLimitText(2);
		m_cAccessTimeHour.SetLimitText(2);
		m_cCreateTimeMinute.SetLimitText(2);
		m_cModifyTimeMinute.SetLimitText(2);
		m_cAccessTimeMinute.SetLimitText(2);
		m_cCreateTimeSecond.SetLimitText(2);
		m_cModifyTimeSecond.SetLimitText(2);
		m_cAccessTimeSecond.SetLimitText(2);

	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFileUtilsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFileUtilsDlg::OnBnClickedScan()
{
	m_btnApply.EnableWindow(FALSE);
	CFileDialog dlgFile(
			TRUE, 
			NULL, 
			NULL, 
			OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
			L"�����ļ� (*.*)||");
	dlgFile.DoModal();
	m_csFilePath = dlgFile.GetPathName();
	if (m_csFilePath.IsEmpty()) {
		return;
	}

	ShowFileTime();
}

void CFileUtilsDlg::ShowFileTime()
{
	if (m_hFile != NULL) {
		CloseHandle(m_hFile);
		m_hFile = NULL;
	}

	m_hFile = ::CreateFile(
		m_csFilePath.GetBuffer(),
		GENERIC_ALL,
		NULL,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (m_hFile == INVALID_HANDLE_VALUE) {
		AfxMessageBox(L"���ļ�ʧ��");
		m_hFile = NULL;
		return;
	}

	FILETIME ftCreate, ftWrite, ftAccess;

	if (!GetFileTime(m_hFile, &ftCreate, &ftAccess, &ftWrite)) {
		AfxMessageBox(L"��ȡ�ļ�ʱ��ʧ��");
		CloseHandle(m_hFile);
		m_hFile = NULL;
		return;
	}

	SetEditFromTime(
		&m_cCreateTimeYear,
		&m_cCreateTimeMonth,
		&m_cCreateTimeDay,
		&m_cCreateTimeHour,
		&m_cCreateTimeMinute,
		&m_cCreateTimeSecond,
		&ftCreate);
	SetEditFromTime(
		&m_cModifyTimeYear,
		&m_cModifyTimeMonth,
		&m_cModifyTimeDay,
		&m_cModifyTimeHour,
		&m_cModifyTimeMinute,
		&m_cModifyTimeSecond,
		&ftWrite);
	SetEditFromTime(
		&m_cAccessTimeYear,
		&m_cAccessTimeMonth,
		&m_cAccessTimeDay,
		&m_cAccessTimeHour,
		&m_cAccessTimeMinute,
		&m_cAccessTimeSecond,
		&ftAccess);

	m_cPath.SetWindowText(m_csFilePath);
	m_btnApply.EnableWindow(TRUE);
};

void CFileUtilsDlg::SetEditFromTime(
		CEdit *pYear,
		CEdit *pMonth,
		CEdit *pDay,
		CEdit *pHour,
		CEdit *pMinute,
		CEdit *pSecond,
		FILETIME *ft)
{
	SYSTEMTIME stUTC, stLocal;
	CString str;

	FileTimeToSystemTime(ft, &stUTC);
	SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

	str.Format(L"%d", stLocal.wYear);
	pYear->SetWindowText(str.GetBuffer());
	str.Format(L"%02d", stLocal.wMonth);
	pMonth->SetWindowText(str.GetBuffer());
	str.Format(L"%02d", stLocal.wDay);
	pDay->SetWindowText(str.GetBuffer());
	str.Format(L"%02d", stLocal.wHour);
	pHour->SetWindowText(str.GetBuffer());
	str.Format(L"%02d", stLocal.wMinute);
	pMinute->SetWindowText(str.GetBuffer());
	str.Format(L"%02d", stLocal.wSecond);
	pSecond->SetWindowText(str.GetBuffer());
}
void CFileUtilsDlg::OnBnClickedApply()
{
	FILETIME ftCreate, ftWrite, ftAccess;
	BOOL bTmp;
	bTmp = GetTimeFromEdit(
				&m_cCreateTimeYear,
				&m_cCreateTimeMonth,
				&m_cCreateTimeDay,
				&m_cCreateTimeHour,
				&m_cCreateTimeMinute,
				&m_cCreateTimeSecond,
				&ftCreate);
	if (!bTmp) {
		AfxMessageBox(L"���봴��ʱ��Ƿ�!");
		return;
	}

	bTmp = GetTimeFromEdit(
		&m_cModifyTimeYear,
		&m_cModifyTimeMonth,
		&m_cModifyTimeDay,
		&m_cModifyTimeHour,
		&m_cModifyTimeMinute,
		&m_cModifyTimeSecond,
		&ftWrite);
	if (!bTmp) {
		AfxMessageBox(L"�����޸�ʱ��Ƿ�!");
		return;
	}

	bTmp = GetTimeFromEdit(
		&m_cAccessTimeYear,
		&m_cAccessTimeMonth,
		&m_cAccessTimeDay,
		&m_cAccessTimeHour,
		&m_cAccessTimeMinute,
		&m_cAccessTimeSecond,
		&ftAccess);
	if (!bTmp) {
		AfxMessageBox(L"�������ʱ��Ƿ�!");
		return;
	}

	if (!SetFileTime(m_hFile, &ftCreate, &ftAccess, &ftWrite)) {
		AfxMessageBox(L"�����ļ�ʱ��ʧ��");
		return;
	}

	AfxMessageBox(L"���óɹ�");
	return;
}

BOOL CFileUtilsDlg::ValidateTime(SYSTEMTIME *st)
{
	if (st->wHour > 23) {
		return FALSE;
	}
	if (st->wMinute > 59) {
		return FALSE;
	}
	if (st->wSecond > 59) {
		return FALSE;
	}
	if (st->wMonth > 12) {
		return FALSE;
	}

	// 31���·�
	if (st->wMonth == 1 &&
		  st->wMonth == 3 &&
		  st->wMonth == 5 &&
		  st->wMonth == 7 &&
		  st->wMonth == 8 &&
		  st->wMonth == 10 &&
		  st->wMonth == 12) {
		if (st->wDay > 31) {
			return FALSE;
		}
	} 
	// 30���·�
	else if (st->wMonth != 2) {
		if (st->wDay > 30) {
			return FALSE;
		}
	}
	// 2�·�
	else {
		// ����
		if ((st->wYear % 4 == 0 && st->wYear % 100 != 0) ||
			  (st->wYear % 400 == 0)) {
			if (st->wDay > 29) {
				return FALSE;
			}
		}
		// ƽ��
		else {
			if (st->wDay > 28) {
				return FALSE;
			}
		}
	}

	return TRUE;
}

BOOL CFileUtilsDlg::GetTimeFromEdit(
		CEdit *pYear,
		CEdit *pMonth,
		CEdit *pDay,
		CEdit *pHour,
		CEdit *pMinute,
		CEdit *pSecond,
		FILETIME *ft)
{
	SYSTEMTIME stUTC, stLocal;
	WORD wTmp;
	CString str;

	GetLocalTime(&stLocal);

	pYear->GetWindowText(str); 
	wTmp = _wtoi(str.GetBuffer());
	stLocal.wYear = wTmp;
	pMonth->GetWindowText(str);
	wTmp = _wtoi(str.GetBuffer());
	stLocal.wMonth = wTmp;
	pDay->GetWindowText(str);
	wTmp = _wtoi(str.GetBuffer());
	stLocal.wDay = wTmp;
	pHour->GetWindowText(str);
	wTmp = _wtoi(str.GetBuffer());
	stLocal.wHour = wTmp;
	pMinute->GetWindowText(str);
	wTmp = _wtoi(str.GetBuffer());
	stLocal.wMinute = wTmp;
	pSecond->GetWindowText(str);
	wTmp = _wtoi(str.GetBuffer());
	stLocal.wSecond = wTmp;

	if (!ValidateTime(&stLocal)) {
		return FALSE;
	}
	
	TzSpecificLocalTimeToSystemTime(NULL, &stLocal, &stUTC);
	SystemTimeToFileTime(&stUTC, ft);
	return TRUE;
}