#pragma once


// CMyHeaderCtrl

class CMyHeaderCtrl : public CHeaderCtrl
{
	DECLARE_DYNAMIC(CMyHeaderCtrl)

public:
	CMyHeaderCtrl();
	virtual ~CMyHeaderCtrl();

protected:
	DECLARE_MESSAGE_MAP()

	virtual void DrawItem(_In_ LPDRAWITEMSTRUCT lpDrawItemStruct);
};


