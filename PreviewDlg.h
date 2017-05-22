#pragma once

// CPreViewDlg 对话框

#include "resource.h"

class CPreviewDlg : public CDialog
{
	DECLARE_MESSAGE_MAP()
	DECLARE_DYNAMIC(CPreviewDlg)

public:
	int					m_nType;
	bool				m_bEnableClose;
	CRect				m_PaintRect;   //绘图区
	CPoint              m_ptOrigin;	   //绘图起点
	BOOL                m_bScroll;  //正在滚动视图
	int					m_nPicWidth;
	int					m_nPicHeight;
	LONG				m_nPicLength;

	CPreviewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPreviewDlg();

	virtual BOOL OnInitDialog();
	
	void Refresh()
	{
		Invalidate();
	}

	afx_msg void OnPaint();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDestroy();

	// 对话框数据
	enum { IDD = IDD_DLG_PREVIEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
