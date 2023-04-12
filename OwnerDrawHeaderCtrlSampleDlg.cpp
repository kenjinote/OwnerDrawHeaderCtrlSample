
// OwnerDrawHeaderCtrlSampleDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "OwnerDrawHeaderCtrlSample.h"
#include "OwnerDrawHeaderCtrlSampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COwnerDrawHeaderCtrlSampleDlg ダイアログ




COwnerDrawHeaderCtrlSampleDlg::COwnerDrawHeaderCtrlSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COwnerDrawHeaderCtrlSampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COwnerDrawHeaderCtrlSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_MyListCtrl);
}

BEGIN_MESSAGE_MAP(COwnerDrawHeaderCtrlSampleDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// COwnerDrawHeaderCtrlSampleDlg メッセージ ハンドラー

BOOL COwnerDrawHeaderCtrlSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);

	if (pListCtrl)
	{
		LVCOLUMN    lvColumn = { 0 };
		lvColumn.mask = LVCF_WIDTH | LVCF_TEXT;
		lvColumn.cx = 128;
		lvColumn.pszText =  _T("ヘッダー");
		pListCtrl->InsertColumn(0, &lvColumn);

		LVITEM       lvItem = { 0 };
		lvItem.mask = LVIF_TEXT;
		lvItem.pszText = _T("アイテム");
		pListCtrl->InsertItem(&lvItem);

		CHeaderCtrl* pHeaderCtrl = pListCtrl->GetHeaderCtrl();
		if ( pHeaderCtrl )
		{
			m_MyHeaderCtrl.SubclassWindow( pHeaderCtrl->m_hWnd );
			HDITEM hdItem;
			for ( int i = 0; i < m_MyHeaderCtrl.GetItemCount(); ++i )
			{
				m_MyHeaderCtrl.GetItem( i, &hdItem );
				hdItem.fmt |= HDF_OWNERDRAW;
				m_MyHeaderCtrl.SetItem( i, &hdItem );
			}
		}
	}

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void COwnerDrawHeaderCtrlSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR COwnerDrawHeaderCtrlSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

