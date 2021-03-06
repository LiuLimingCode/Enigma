
// EnigmaDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Enigma.h"
#include "EnigmaDlg.h"
#include "TipDlg.h"
#include <vector>
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CEnigmaDlg 对话框



CEnigmaDlg::CEnigmaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ENIGMA_DIALOG, pParent)
	, m_decrypt(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICONENIGMA);
}

void CEnigmaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOROTOR1, m_comborotor1);
	DDX_Control(pDX, IDC_COMBOROTOR2, m_comborotor2);
	DDX_Control(pDX, IDC_COMBOROTOR3, m_comborotor3);
	DDX_Control(pDX, IDC_COMBOROTOR4, m_comborotor4);
	DDX_Control(pDX, IDC_LISTROTOR1, m_listrotor1);
	DDX_Control(pDX, IDC_LISTROTOR2, m_listrotor2);
	DDX_Control(pDX, IDC_LISTROTOR3, m_listrotor3);
	DDX_Control(pDX, IDC_LISTROTOR4, m_listrotor4);
	DDX_Text(pDX, IDC_EDITDECRYPT, m_decrypt);
	DDX_Text(pDX, IDC_EDITENCRYPT, m_encrypt);
	DDX_Control(pDX, IDC_COMBOCONNECT1, m_connect1);
	DDX_Control(pDX, IDC_COMBOCONNECT2, m_connect2);
	DDX_Control(pDX, IDC_COMBOCONNECT3, m_connect3);
	DDX_Control(pDX, IDC_COMBOCONNECT4, m_connect4);
	DDX_Control(pDX, IDC_COMBOCONNECT5, m_connect5);
	DDX_Control(pDX, IDC_COMBOCONNECT6, m_connect6);
	DDX_Control(pDX, IDC_COMBOCONNECT7, m_connect7);
	DDX_Control(pDX, IDC_COMBOCONNECT8, m_connect8);
	DDX_Control(pDX, IDC_COMBOCONNECT9, m_connect9);
	DDX_Control(pDX, IDC_COMBOCONNECT10, m_connect10);
	DDX_Control(pDX, IDC_COMBOCONNECT11, m_connect11);
	DDX_Control(pDX, IDC_COMBOCONNECT12, m_connect12);
}

BEGIN_MESSAGE_MAP(CEnigmaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_DROPDOWN(IDC_COMBOROTOR1, &CEnigmaDlg::OnCbnDropdownComborotor1)
	ON_CBN_DROPDOWN(IDC_COMBOROTOR2, &CEnigmaDlg::OnCbnDropdownComborotor2)
	ON_CBN_DROPDOWN(IDC_COMBOROTOR3, &CEnigmaDlg::OnCbnDropdownComborotor3)
	ON_CBN_DROPDOWN(IDC_COMBOROTOR4, &CEnigmaDlg::OnCbnDropdownComborotor4)
	ON_CBN_EDITCHANGE(IDC_LISTROTOR1, &CEnigmaDlg::OnCbnEditchangeListrotor1)
	ON_CBN_EDITCHANGE(IDC_LISTROTOR2, &CEnigmaDlg::OnCbnEditchangeListrotor2)
	ON_CBN_EDITCHANGE(IDC_LISTROTOR3, &CEnigmaDlg::OnCbnEditchangeListrotor3)
	ON_CBN_EDITCHANGE(IDC_LISTROTOR4, &CEnigmaDlg::OnCbnEditchangeListrotor4)
	ON_BN_CLICKED(IDC_BUTTONENCRYPT, &CEnigmaDlg::OnBnClickedButtonencrypt)
	ON_BN_CLICKED(IDC_BUTTONDECRYPT, &CEnigmaDlg::OnBnClickedButtondecrypt)
	ON_BN_CLICKED(IDC_BUTTONTIP, &CEnigmaDlg::OnBnClickedButtontip)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT1, &CEnigmaDlg::OnCbnEditchangeComboConnect1)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT2, &CEnigmaDlg::OnCbnEditchangeComboConnect2)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT3, &CEnigmaDlg::OnCbnEditchangeComboConnect3)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT4, &CEnigmaDlg::OnCbnEditchangeComboConnect4)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT5, &CEnigmaDlg::OnCbnEditchangeComboConnect5)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT6, &CEnigmaDlg::OnCbnEditchangeComboConnect6)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT7, &CEnigmaDlg::OnCbnEditchangeComboConnect7)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT8, &CEnigmaDlg::OnCbnEditchangeComboConnect8)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT9, &CEnigmaDlg::OnCbnEditchangeComboConnect9)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT10, &CEnigmaDlg::OnCbnEditchangeComboConnect10)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT11, &CEnigmaDlg::OnCbnEditchangeComboConnect11)
	ON_CBN_EDITCHANGE(IDC_COMBOCONNECT12, &CEnigmaDlg::OnCbnEditchangeComboConnect12)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT1, &CEnigmaDlg::OnCbnDropdownComboconnect1)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT2, &CEnigmaDlg::OnCbnDropdownComboconnect2)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT3, &CEnigmaDlg::OnCbnDropdownComboconnect3)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT4, &CEnigmaDlg::OnCbnDropdownComboconnect4)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT5, &CEnigmaDlg::OnCbnDropdownComboconnect5)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT6, &CEnigmaDlg::OnCbnDropdownComboconnect6)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT7, &CEnigmaDlg::OnCbnDropdownComboconnect7)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT8, &CEnigmaDlg::OnCbnDropdownComboconnect8)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT9, &CEnigmaDlg::OnCbnDropdownComboconnect9)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT10, &CEnigmaDlg::OnCbnDropdownComboconnect10)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT11, &CEnigmaDlg::OnCbnDropdownComboconnect11)
	ON_CBN_DROPDOWN(IDC_COMBOCONNECT12, &CEnigmaDlg::OnCbnDropdownComboconnect12)
END_MESSAGE_MAP()


// CEnigmaDlg 消息处理程序

BOOL CEnigmaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	for (int temp = 0; temp < _Base.GetLength(); ++temp)
	{
		CString str;
		str.Format(_T(" (%d)"), temp);
		str = _Base.Mid(temp, 1) + str;

		for (int tempr = 0; tempr < NUM_ROTOR; ++tempr)
			_listrotor[tempr]->AddString(str);
		for (int tempc = 0; tempc < NUM_CONNECT; ++tempc)
			_connect[tempc]->AddString(str);
	}

	for (int tempr = 0; tempr < NUM_ROTOR; ++tempr)
		_listrotor[tempr]->LimitText(1);
	for (int tempc = 0; tempc < NUM_CONNECT; ++tempc)
	{
		_connect[tempc]->LimitText(1);
		_connect[tempc]->SetCurSel(tempc / 2);
	}

	for (int temp = 0; temp < _Base.GetLength(); ++temp)
	{
		_reflex += _Base.Mid(_Base.GetLength() - temp - 1, 1);
	}

	((CButton *)GetDlgItem(IDC_CHECKDATATIP))->SetCheck(1);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEnigmaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CEnigmaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CEnigmaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CEnigmaDlg::PassWordChange(CString &_p, CString _c)
{
	int index;
	CString str;
	index = _p.Find(_c);
	str = _p.Right(_Base.GetLength() - index);
	_p.Delete(index, _Base.GetLength() - index);
	_p = str + _p;
}

void CEnigmaDlg::RotorChange(int &index, CString _p)
{
	for (int temp = 0; temp < _Base.GetLength(); temp++)
	{
		if (_Base[temp] == _p[index])
		{
			index = temp;
			break;
		}
	}
}

void CEnigmaDlg::RotorReChange(int &index, CString _p)
{
	int temp;
	for (temp = 0; temp < _Base.GetLength(); temp++)
	{
		if (_p[temp] == index)
		{
			break;
		}
	}
	index = (int)_Base[temp];
}

void CEnigmaDlg::PassWordChangeOnce(CString &_p)
{
	CString str;
	str = _p.Right(_Base.GetLength() - 1);
	_p.Delete(1, _Base.GetLength() - 1);
	_p = str + _p;
}

CString CEnigmaDlg::DoCrypt(CString _p)//数据处理
{
	CString str;
	CString _temppass[4] = { _pass[0], _pass[1], _pass[2], _pass[3] };
	int index;
	while (_p.GetLength())
	{
		int temp;
		for (temp = 0; temp < _Base.GetLength(); ++temp)
		{
			if (_Base.Mid(temp, 1) == _p.Left(1))
			{
				index = temp;
				break;
			}
		}
		if (temp == _Base.GetLength())
		{
			str += _p.Left(1);
			_p.Delete(0);
			continue;
		}

		for (int temp = 0; temp < 4; temp++)//转子正向 
		{
			RotorChange(index, _pass[temp]);
		}

		index = _reflex[index];//反射

		for (int temp = 3; temp >= 0; temp--)//转子反向 
		{
			RotorReChange(index, _pass[temp]);
		}

		str += (char)index;

		PassWordChangeOnce(_pass[0]);
		if (_pass[0] != _temppass[0]) PassWordChangeOnce(_pass[1]);
		if (_pass[1] != _temppass[1]) PassWordChangeOnce(_pass[2]);
		if (_pass[2] != _temppass[2]) PassWordChangeOnce(_pass[3]);

		_p.Delete(0);
	}
	return str;
}

bool CEnigmaDlg::CryptInit(void)
{
	CString str;
	password _temppassword[6] = { _A, _B, _C, _D, _E, _F };
	CString _tempchange[4];
	bool flag_rotor = true;
	bool flag_connect = true;

	for (int temp = 0; temp < NUM_ROTOR; ++temp)
	{
		if (_listrotor[temp]->GetCurSel() == -1)
		{
			flag_rotor = false;
			break;
		}
		if (_comborotor[temp]->GetCurSel() == -1)
		{
			flag_rotor = false;
			break;
		}
	}

	for (int temp = 0; temp < NUM_CONNECT; ++temp)
	{
		if (_connect[temp]->GetCurSel() == -1)
		{
			flag_connect = false;
			break;
		}
	}

	if (flag_rotor == false || flag_connect == false)
	{
		MessageBox(_T("请正确设置转子和接线板！"));
		return false;
	}

	for (int _temp = 0; _temp < 4; ++_temp)//对应ABCDEF的顺序
	{
		_listrotor[_temp]->GetWindowTextW(str);
		_tempchange[_temp] = str.Left(1);
		_comborotor[_temp]->GetWindowTextW(str);
		for (int temp = 0; temp < NUM_PASSWORD; ++temp)
		{
			if (str == _temppassword[temp].name)
			{
				_pass[_temp] = _temppassword[temp].unit;
				break;
			}
		}
	}

	for (int temp = 0; temp < 4; ++temp)//计算pass数组
	{
		PassWordChange(_pass[temp], _tempchange[temp]);
	}

	_connectch.clear();
	for (int temp = 0; temp < NUM_CONNECT; ++temp)
	{
		_connect[temp]->GetWindowTextW(str);
		_connectch.push_back((char)str[0]);
	}

	for (int __temp = -2; __temp < 3; ++__temp)
	{
		for (int _temp, temp = 0; temp < NUM_CONNECT / 2; ++temp)
		{
			if (_connectch[2 * temp] + __temp < 0x20 || _connectch[2 * temp] + __temp > 0x7E) continue;
			if (_connectch[2 * temp + 1] + __temp < 0x20 || _connectch[2 * temp + 1] + __temp > 0x7E) continue;
			for (_temp = 0; _temp < (int)_connectch.size(); ++_temp)
			{
				if (_connectch[2 * temp] + __temp == _connectch[_temp]) break;
				if (_connectch[2 * temp + 1] + __temp == _connectch[_temp]) break;
			}
			if (_temp == (int)_connectch.size())
			{
				_connectch.push_back(_connectch[2 * temp] + __temp);
				_connectch.push_back(_connectch[2 * temp + 1] + __temp);
			}
		}
	}
	return true;
}

void CEnigmaDlg::InitSet(CString _p)
{
	CString str, _string;
	for (int temp = 0; temp < NUM_ROTOR; ++temp)//设置转子号
	{
		str = _p[0];
		_string.Format(_T(" (%d)"), _Base.Find(str));
		_listrotor[temp]->SelectString(0, str + _string);
		_p.Delete(0);
	}
	while ((char)_p[0] < 0x21 || (char)_p[0] > 0x7E) _p.Delete(0);

	for (int temp = 0; temp < NUM_ROTOR; ++temp)//设置转子顺序
	{
		str = _p[0];
		_comborotor[temp]->SelectString(0, str);
		_p.Delete(0);
	}
	while ((char)_p[0] < 0x21 || (char)_p[0] > 0x7E) _p.Delete(0);

	for (int temp = 0; temp < NUM_CONNECT / 2; ++temp)
	{
		str = _p[0];
		_string.Format(_T(" (%d)"), _Base.Find(str));
		_connect[2 * temp]->SelectString(0, str + _string);
		_p.Delete(0, 2);
		str = _p[0];
		_string.Format(_T(" (%d)"), _Base.Find(str));
		_connect[2 * temp + 1]->SelectString(0, str + _string);
		_p.Delete(0, 3);
	}

	UpdateData(TRUE);
}

void CEnigmaDlg::DoConnect(CString & _p)
{
	std::vector<int> vec1, vec2;
	int val = -1, num = _p.GetLength();
	for (int temp = 0; temp < (int)_connectch.size() / 2; ++temp)
	{
		while (1)
		{
			val = _p.Find(_connectch[2 * temp], val + 1);
			if (val == -1) break;
			else vec1.push_back(val);
		}

		while (1)
		{
			val = _p.Find(_connectch[2 * temp + 1], val + 1);
			if (val == -1) break;
			else vec2.push_back(val);
		}

		while (vec1.size())
		{
			_p.Delete(vec1.back());
			_p = _p.Left(vec1.back()) + _connectch[2 * temp + 1] + _p.Right(num - vec1.back() - 1);
			vec1.pop_back();
		}
		while (vec2.size())
		{
			_p.Delete(vec2.back());
			_p = _p.Left(vec2.back()) + _connectch[2 * temp] + _p.Right(num - vec2.back() - 1);
			vec2.pop_back();
		}
	}
}

void CEnigmaDlg::CryptOutput(CString & _p)
{
	CString str, _string = _T("");
	if (((CButton *)GetDlgItem(IDC_CHECKDATATIP))->GetCheck())
	{
		for (int temp = 0; temp < NUM_ROTOR; ++temp)
		{
			_listrotor[temp]->GetWindowTextW(str);
			_string += str.Left(1);
		}
		_string += _T("  ");
		for (int temp = 0; temp < NUM_ROTOR; ++temp)
		{
			_comborotor[temp]->GetWindowTextW(str);
			_string += str.Left(1);
		}
		_string += _T("\r\n");
		for (int temp = 0; temp < NUM_CONNECT / 2; ++temp)
		{
			_connect[2 * temp]->GetWindowTextW(str);
			_string += str.Left(1);
			_string += _T("-");
			_connect[2 * temp + 1]->GetWindowTextW(str);
			_string += str.Left(1);
			_string += _T("  ");
		}
		_string += _T("\r\n\r\n");
		_p = _string + _p;
	}
}

void CEnigmaDlg::OnBnClickedButtonencrypt()//加密
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(!CryptInit()) return;
	DoConnect(m_decrypt);
	m_encrypt = DoCrypt(m_decrypt);
	CryptOutput(m_encrypt);
	m_decrypt = "";
	UpdateData(FALSE);
}

void CEnigmaDlg::OnBnClickedButtondecrypt()//解密
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (((CButton *)GetDlgItem(IDC_CHECKDATATIP))->GetCheck())
	{
		InitSet(m_encrypt);
		m_encrypt.Delete(0, 46);
	}
	if (!CryptInit()) return;
	m_decrypt = DoCrypt(m_encrypt);
	DoConnect(m_decrypt);
	m_encrypt = "";
	UpdateData(FALSE);
}

void CEnigmaDlg::OnCbnDropdownComborotor1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str[3], _string;
	m_comborotor1.GetWindowTextW(_string);
	m_comborotor1.ResetContent();
	m_comborotor2.GetWindowTextW(str[0]);
	m_comborotor3.GetWindowTextW(str[1]);
	m_comborotor4.GetWindowTextW(str[2]);

	for (int temp, _temp = 0; _temp < NUM_PASSWORD; _temp++)
	{
		for (temp = 0; temp < NUM_ROTOR - 1; temp++)
		{
			if (str[temp] == CString((char)('A' + _temp)))
			{
				break;
			}
		}
		if (temp == NUM_ROTOR - 1) m_comborotor1.AddString(CString((char)('A' + _temp)));
	}
	m_comborotor1.SelectString(0, _string);
}

void CEnigmaDlg::OnCbnDropdownComborotor2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str[3], _string;
	m_comborotor2.GetWindowTextW(_string);
	m_comborotor2.ResetContent();
	m_comborotor1.GetWindowTextW(str[0]);
	m_comborotor3.GetWindowTextW(str[1]);
	m_comborotor4.GetWindowTextW(str[2]);

	for (int temp, _temp = 0; _temp < NUM_PASSWORD; _temp++)
	{
		for (temp = 0; temp < NUM_ROTOR - 1; temp++)
		{
			if (str[temp] == CString((char)('A' + _temp)))
			{
				break;
			}
		}
		if (temp == NUM_ROTOR - 1) m_comborotor2.AddString(CString((char)('A' + _temp)));
	}
	m_comborotor2.SelectString(0, _string);
}

void CEnigmaDlg::OnCbnDropdownComborotor3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str[3], _string;
	m_comborotor3.GetWindowTextW(_string);
	m_comborotor3.ResetContent();
	m_comborotor1.GetWindowTextW(str[0]);
	m_comborotor2.GetWindowTextW(str[1]);
	m_comborotor4.GetWindowTextW(str[2]);

	for (int temp, _temp = 0; _temp < NUM_PASSWORD; _temp++)
	{
		for (temp = 0; temp < NUM_ROTOR - 1; temp++)
		{
			if (str[temp] == CString((char)('A' + _temp)))
			{
				break;
			}
		}
		if (temp == NUM_ROTOR - 1) m_comborotor3.AddString(CString((char)('A' + _temp)));
	}
	m_comborotor3.SelectString(0, _string);
}

void CEnigmaDlg::OnCbnDropdownComborotor4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str[3], _string;
	m_comborotor4.GetWindowTextW(_string);
	m_comborotor4.ResetContent();
	m_comborotor1.GetWindowTextW(str[0]);
	m_comborotor2.GetWindowTextW(str[1]);
	m_comborotor3.GetWindowTextW(str[2]);

	for (int temp, _temp = 0; _temp < NUM_PASSWORD; _temp++)
	{
		for (temp = 0; temp < NUM_ROTOR - 1; temp++)
		{
			if (str[temp] == CString((char)('A' + _temp)))
			{
				break;
			}
		}
		if (temp == NUM_ROTOR - 1) m_comborotor4.AddString(CString((char)('A' + _temp)));
	}
	m_comborotor4.SelectString(0, _string);
}

void CEnigmaDlg::RotorSetCurSel(CComboBox & _combo)
{
	int index = 0;
	CString str;
	_combo.GetWindowTextW(str);
	index = _Base.Find(str);
	_combo.SetCurSel(index);
}

void CEnigmaDlg::OnCbnEditchangeListrotor1()
{
	// TODO: 在此添加控件通知处理程序代码
	RotorSetCurSel(m_listrotor1);
}

void CEnigmaDlg::OnCbnEditchangeListrotor2()
{
	// TODO: 在此添加控件通知处理程序代码
	RotorSetCurSel(m_listrotor2);
}

void CEnigmaDlg::OnCbnEditchangeListrotor3()
{
	// TODO: 在此添加控件通知处理程序代码
	RotorSetCurSel(m_listrotor3);
}

void CEnigmaDlg::OnCbnEditchangeListrotor4()
{
	// TODO: 在此添加控件通知处理程序代码
	RotorSetCurSel(m_listrotor4);
}

void CEnigmaDlg::OnBnClickedButtontip()
{
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;             // 用于保存DoModal函数的返回值   

	TipDlg tipDlg;           // 构造对话框类CTipDlg的实例   
	nRes = tipDlg.DoModal();  // 弹出对话框   
}

void CEnigmaDlg::ConnectSetCurSel(CComboBox & _combo)
{
	int coindex, index = -1;
	CString str, _string = _T("");

	ConnectSetString(_combo);
	for (coindex = 0; coindex < NUM_CONNECT; ++coindex)
	{
		if (&_combo == _connect[coindex]) break;
	}
	_combo.GetWindowTextW(str);

	int temp;
	CString _str;
	for (temp = 0; temp < NUM_CONNECT; ++temp)
	{
		if (temp / 2 == coindex / 2) continue;
		_connect[temp]->GetWindowTextW(_str);
		_str = _str.Left(1);
		if (_str == str) break;
	}

	if (temp != NUM_CONNECT)
	{
		_combo.SetCurSel(-1);
	}
}

void CEnigmaDlg::OnCbnEditchangeComboConnect1()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect1);
}

void CEnigmaDlg::OnCbnEditchangeComboConnect2()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect2);
}

void CEnigmaDlg::OnCbnEditchangeComboConnect3()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect3);
}

void CEnigmaDlg::OnCbnEditchangeComboConnect4()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect4);
}

void CEnigmaDlg::OnCbnEditchangeComboConnect5()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect5);
}

void CEnigmaDlg::OnCbnEditchangeComboConnect6()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect6);
}

void CEnigmaDlg::OnCbnEditchangeComboConnect7()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect7);
}

void CEnigmaDlg::OnCbnEditchangeComboConnect8()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect8);
}

void CEnigmaDlg::OnCbnEditchangeComboConnect9()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect9);
}

void CEnigmaDlg::OnCbnEditchangeComboConnect10()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect10);
}

void CEnigmaDlg::OnCbnEditchangeComboConnect11()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect11);
}

void CEnigmaDlg::OnCbnEditchangeComboConnect12()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetCurSel(m_connect12);
}

void CEnigmaDlg::ConnectSetString(CComboBox & _combo)
{
	int coindex = 0;
	CString _string;
	_combo.GetWindowTextW(_string);
	_combo.ResetContent();
	for (coindex = 0; coindex < NUM_CONNECT; ++coindex)
	{
		if (_connect[coindex] == &_combo) break;
	}
	
	CString str;
	for (int _temp = 0; _temp < _Base.GetLength(); ++_temp)
	{
		int temp;
		for (temp = 0; temp < NUM_CONNECT; ++temp)
		{
			if (temp / 2 == coindex / 2) continue;
			_connect[temp]->GetWindowTextW(str);
			if (str.Left(1) == _Base.Mid(_temp, 1)) break;
		}

		if (temp == NUM_CONNECT)
		{
			str.Format(_T(" (%d)"), _temp);
			_combo.AddString(_Base.Mid(_temp, 1) + str);
		}
	}
	str.Format(_T(" (%d)"), _Base.Find(_string));
	_combo.SelectString(0, _string + str);
}

void CEnigmaDlg::OnCbnDropdownComboconnect1()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect1);
}

void CEnigmaDlg::OnCbnDropdownComboconnect2()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect2);
}

void CEnigmaDlg::OnCbnDropdownComboconnect3()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect3);
}

void CEnigmaDlg::OnCbnDropdownComboconnect4()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect4);
}

void CEnigmaDlg::OnCbnDropdownComboconnect5()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect5);
}

void CEnigmaDlg::OnCbnDropdownComboconnect6()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect6);
}

void CEnigmaDlg::OnCbnDropdownComboconnect7()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect7);
}

void CEnigmaDlg::OnCbnDropdownComboconnect8()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect8);
}

void CEnigmaDlg::OnCbnDropdownComboconnect9()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect9);
}

void CEnigmaDlg::OnCbnDropdownComboconnect10()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect10);
}

void CEnigmaDlg::OnCbnDropdownComboconnect11()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect11);
}

void CEnigmaDlg::OnCbnDropdownComboconnect12()
{
	// TODO: 在此添加控件通知处理程序代码
	ConnectSetString(m_connect12);
}
