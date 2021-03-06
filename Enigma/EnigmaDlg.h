
// EnigmaDlg.h: 头文件
//

#pragma once

#include <vector>

typedef struct  {
	CString name;
	CString unit;
} password;

// CEnigmaDlg 对话框
class CEnigmaDlg : public CDialogEx
{
// 构造
public:
	CEnigmaDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ENIGMA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void PassWordChange(CString & _p, CString _c);
	void RotorChange(int & index, CString _p);
	void RotorReChange(int & index, CString _p);
	void PassWordChangeOnce(CString & _p);
	CString DoCrypt(CString _p);
	bool CryptInit(void);
	void CEnigmaDlg::InitSet(CString _p);
	void DoConnect(CString & _p);
	void CryptOutput(CString & _p);
	DECLARE_MESSAGE_MAP()
public:
	const CString _Base = _T("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890 `~!@#$%^&*()-_=+\\|]}[{;:,<.>?/\'\"");
#define NUM_PASSWORD	6
	const password _A = { _T("A"), _T("}[{4567890QAZWS;:,<XEDCRFVT.>?/\'\"GBqp `~!woeiru@#$%tyalskd)-_=jfhgzmxnc+\\|bv123]YHNUJMI^&*(KOLP") };
	const password _B = { _T("B"), _T("qe)-_=tuoa#$%bmwryip^&*(sfhkx+\\|vn098;:,<7654dgjlzc@321QWERT]}[{YUIOPASD.>?/\'\"FGHJKLZXCVB `~!NM") };
	const password _C = { _T("C"), _T("QE)-_=TUOADGJLZCBMWRY<p]}87654xcvbIPSFHK^&*(XVN0{321qwer[/\'\"klz@#$%asdfghj.>?9+\\|tyuio;:, `~!nm") };
	const password _D = { _T("D"), _T("QP `~!WOEIRUG)-_=+\\|345TYALSKDJFH678ZMXNCBV12;:,<90qagby@ujmi^&*zws.>?/\'\"#$%hnxedc]}[{rfvt(kolp") };
	const password _E = { _T("E"), _T("QP `678;-fvtgby@.>?/\'\"#$0qazwsn~!WO:,<9NC[{rx+\\_=ZMX%h|345ujmi^&*(edc]}SKDJFHG)EIRUTYALBV12kolp") };
	const password _F = { _T("F"), _T("QP `~!WOE6sxedc]}[qvSKD9-_=ZMtgby@.>?/\'\"#$%hnu0\\|345)jmi^&*(koazXNCB78;:,<wV12+JFHGIRUTYAL{rflp") };
	CString _pass[4];//解密时的密码
	CString _reflex;
	bool _start = false;
#define NUM_ROTOR		4
	CComboBox m_comborotor1;
	CComboBox m_comborotor2;
	CComboBox m_comborotor3;
	CComboBox m_comborotor4;
	CComboBox* _comborotor[NUM_ROTOR] = { &m_comborotor1, &m_comborotor2, &m_comborotor3, &m_comborotor4 };
	afx_msg void OnCbnDropdownComborotor1();
	afx_msg void OnCbnDropdownComborotor2();
	afx_msg void OnCbnDropdownComborotor3();
	afx_msg void OnCbnDropdownComborotor4();
	void RotorSetCurSel(CComboBox & _combo);
	CComboBox m_listrotor1;
	CComboBox m_listrotor2;
	CComboBox m_listrotor3;
	CComboBox m_listrotor4;
	CComboBox* _listrotor[NUM_ROTOR] = { &m_listrotor1, &m_listrotor2, &m_listrotor3, &m_listrotor4 };
	afx_msg void OnCbnEditchangeListrotor1();
	afx_msg void OnCbnEditchangeListrotor2();
	afx_msg void OnCbnEditchangeListrotor3();
	afx_msg void OnCbnEditchangeListrotor4();
	CString m_decrypt;
	CString m_encrypt;
	afx_msg void OnBnClickedButtonencrypt();
	afx_msg void OnBnClickedButtondecrypt();
	afx_msg void OnBnClickedButtontip();
	void ConnectSetCurSel(CComboBox & _combo);
	void ConnectSetString(CComboBox & _combo);
#define NUM_CONNECT		12
	CComboBox m_connect1;
	CComboBox m_connect2;
	CComboBox m_connect3;
	CComboBox m_connect4;
	CComboBox m_connect5;
	CComboBox m_connect6;
	CComboBox m_connect7;
	CComboBox m_connect8;
	CComboBox m_connect9;
	CComboBox m_connect10;
	CComboBox m_connect11;
	CComboBox m_connect12;
	CComboBox* _connect[NUM_CONNECT] = { &m_connect1, &m_connect2, &m_connect3, &m_connect4, &m_connect5,
		&m_connect6, &m_connect7, &m_connect8, &m_connect9, &m_connect10, &m_connect11, &m_connect12 };
	std::vector<char> _connectch;
	afx_msg void OnCbnEditchangeComboConnect1();
	afx_msg void OnCbnEditchangeComboConnect2();
	afx_msg void OnCbnEditchangeComboConnect3();
	afx_msg void OnCbnEditchangeComboConnect4();
	afx_msg void OnCbnEditchangeComboConnect5();
	afx_msg void OnCbnEditchangeComboConnect6();
	afx_msg void OnCbnEditchangeComboConnect7();
	afx_msg void OnCbnEditchangeComboConnect8();
	afx_msg void OnCbnEditchangeComboConnect9();
	afx_msg void OnCbnEditchangeComboConnect10();
	afx_msg void OnCbnEditchangeComboConnect11();
	afx_msg void OnCbnEditchangeComboConnect12();
	afx_msg void OnCbnDropdownComboconnect1();
	afx_msg void OnCbnDropdownComboconnect2();
	afx_msg void OnCbnDropdownComboconnect3();
	afx_msg void OnCbnDropdownComboconnect4();
	afx_msg void OnCbnDropdownComboconnect5();
	afx_msg void OnCbnDropdownComboconnect6();
	afx_msg void OnCbnDropdownComboconnect7();
	afx_msg void OnCbnDropdownComboconnect8();
	afx_msg void OnCbnDropdownComboconnect9();
	afx_msg void OnCbnDropdownComboconnect10();
	afx_msg void OnCbnDropdownComboconnect11();
	afx_msg void OnCbnDropdownComboconnect12();
};
