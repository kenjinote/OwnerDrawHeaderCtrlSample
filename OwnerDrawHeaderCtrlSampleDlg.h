
// OwnerDrawHeaderCtrlSampleDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once

#include "MyHeaderCtrl.h"

// COwnerDrawHeaderCtrlSampleDlg �_�C�A���O
class COwnerDrawHeaderCtrlSampleDlg : public CDialogEx
{
// �R���X�g���N�V����
public:
	COwnerDrawHeaderCtrlSampleDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^�[

// �_�C�A���O �f�[�^
	enum { IDD = IDD_OWNERDRAWHEADERCTRLSAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g


// ����
protected:
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	CMyHeaderCtrl m_MyHeaderCtrl;
	CListCtrl m_MyListCtrl;
};
