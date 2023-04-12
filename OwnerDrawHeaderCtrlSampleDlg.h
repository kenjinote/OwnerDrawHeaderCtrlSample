
// OwnerDrawHeaderCtrlSampleDlg.h : ヘッダー ファイル
//

#pragma once

#include "MyHeaderCtrl.h"

// COwnerDrawHeaderCtrlSampleDlg ダイアログ
class COwnerDrawHeaderCtrlSampleDlg : public CDialogEx
{
// コンストラクション
public:
	COwnerDrawHeaderCtrlSampleDlg(CWnd* pParent = NULL);	// 標準コンストラクター

// ダイアログ データ
	enum { IDD = IDD_OWNERDRAWHEADERCTRLSAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	CMyHeaderCtrl m_MyHeaderCtrl;
	CListCtrl m_MyListCtrl;
};
