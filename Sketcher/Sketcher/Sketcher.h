// Sketcher.h : Sketcher Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

const unsigned int RED = 1U;
const unsigned int GREEN = 2U;
const unsigned int BLUE = 3U;
const unsigned int BLACK = 4U;

const unsigned int LINE = 101U;
const unsigned int RECTANGLE = 102U;
const unsigned int CIRCLE = 103U;
const unsigned int CURVE = 104U;

// CSketcherApp:
// �йش����ʵ�֣������ Sketcher.cpp

class CSketcherApp : public CWinApp
{
public:
	CSketcherApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSketcherApp theApp;