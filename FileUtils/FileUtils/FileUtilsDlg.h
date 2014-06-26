// FileUtilsDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CFileUtilsDlg �Ի���
class CFileUtilsDlg : public CDialog
{
// ����
public:
	CFileUtilsDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CFileUtilsDlg(void);

// �Ի�������
	enum { IDD = IDD_FILEUTILS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	CString m_csFilePath;
	HANDLE m_hFile;

	// ����������ʱ����ؼ�����
	void SetEditFromTime(CEdit*, CEdit*, CEdit*, CEdit*, CEdit*, CEdit*, FILETIME*);
	// ��ȡ������ʱ����ռ�����
	BOOL GetTimeFromEdit(CEdit*, CEdit*, CEdit*, CEdit*, CEdit*, CEdit*, FILETIME*);

	// ���ʱ��Ϸ���
	BOOL ValidateTime(SYSTEMTIME *);

	void ShowFileTime();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDropFiles(HDROP);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedScan();
	afx_msg void OnBnClickedApply();
protected:
	CEdit m_cPath;
	CEdit m_cCreateTimeYear;
	CEdit m_cModifyTimeYear;
	CEdit m_cAccessTimeYear;
	CEdit m_cCreateTimeMonth;
	CEdit m_cModifyTimeMonth;
	CEdit m_cAccessTimeMonth;
	CEdit m_cCreateTimeDay;
	CEdit m_cModifyTimeDay;
	CEdit m_cAccessTimeDay;
	CEdit m_cCreateTimeHour;
	CEdit m_cModifyTimeHour;
	CEdit m_cAccessTimeHour;
	CEdit m_cCreateTimeMinute;
	CEdit m_cModifyTimeMinute;
	CEdit m_cAccessTimeMinute;
	CEdit m_cCreateTimeSecond;
	CEdit m_cModifyTimeSecond;
	CEdit m_cAccessTimeSecond;
	CButton m_btnApply;
};
