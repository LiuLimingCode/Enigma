#pragma once


// TipDlg 对话框

class TipDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TipDlg)

public:
	TipDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TipDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIP_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
