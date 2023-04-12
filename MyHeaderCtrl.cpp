// MyHeaderCtrl.cpp : ŽÀ‘•ƒtƒ@ƒCƒ‹
//

#include "stdafx.h"
#include "OwnerDrawHeaderCtrlSample.h"
#include "MyHeaderCtrl.h"


// CMyHeaderCtrl

IMPLEMENT_DYNAMIC(CMyHeaderCtrl, CHeaderCtrl)

CMyHeaderCtrl::CMyHeaderCtrl()
{

}

CMyHeaderCtrl::~CMyHeaderCtrl()
{
}

BEGIN_MESSAGE_MAP(CMyHeaderCtrl, CHeaderCtrl)
END_MESSAGE_MAP()

void CMyHeaderCtrl::DrawItem(_In_ LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	OutputDebugString(TEXT("OnDrawItem\r\n"));

	TCHAR szItemText[64];
	HDITEM hdItem = {0};
	hdItem.mask = HDI_TEXT;
	hdItem.pszText = szItemText;
	hdItem.cchTextMax = sizeof(szItemText) / sizeof(TCHAR);
	Header_GetItem(lpDrawItemStruct->hwndItem, lpDrawItemStruct->itemID, &hdItem);
	TextOut(lpDrawItemStruct->hDC, lpDrawItemStruct->rcItem.left + 2, lpDrawItemStruct->rcItem.top + 2, szItemText, lstrlen(szItemText));
}
