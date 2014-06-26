// FileUtilsDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CFileUtilsDlg 对话框
class CFileUtilsDlg : public CDialog
{
// 构造
public:
	CFileUtilsDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CFileUtilsDlg(void);

// 对话框数据
	enum { IDD = IDD_FILEUTILS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	CString m_csFilePath;
	HANDLE m_hFile;

	// 设置年月日时分秒控件内容
	void SetEditFromTime(CEdit*, CEdit*, CEdit*, CEdit*, CEdit*, CEdit*, FILETIME*);
	// 获取年月日时分秒空间内容
	BOOL GetTimeFromEdit(CEdit*, CEdit*, CEdit*, CEdit*, CEdit*, CEdit*, FILETIME*);

	// 检查时间合法性
	BOOL ValidateTime(SYSTEMTIME *);

	void ShowFileTime();

	// 生成的消息映射函数
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
