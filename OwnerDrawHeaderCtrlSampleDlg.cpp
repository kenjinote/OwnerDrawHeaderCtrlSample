
// OwnerDrawHeaderCtrlSampleDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "OwnerDrawHeaderCtrlSample.h"
#include "OwnerDrawHeaderCtrlSampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COwnerDrawHeaderCtrlSampleDlg �_�C�A���O




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


// COwnerDrawHeaderCtrlSampleDlg ���b�Z�[�W �n���h���[

BOOL COwnerDrawHeaderCtrlSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�

	// TODO: �������������ɒǉ����܂��B
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);

	if (pListCtrl)
	{
		LVCOLUMN    lvColumn = { 0 };
		lvColumn.mask = LVCF_WIDTH | LVCF_TEXT;
		lvColumn.cx = 128;
		lvColumn.pszText =  _T("�w�b�_�[");
		pListCtrl->InsertColumn(0, &lvColumn);

		LVITEM       lvItem = { 0 };
		lvItem.mask = LVIF_TEXT;
		lvItem.pszText = _T("�A�C�e��");
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

	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
}

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void COwnerDrawHeaderCtrlSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR COwnerDrawHeaderCtrlSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

