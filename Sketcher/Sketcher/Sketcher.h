// Sketcher.h : Sketcher 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号

const unsigned int RED = 1U;
const unsigned int GREEN = 2U;
const unsigned int BLUE = 3U;
const unsigned int BLACK = 4U;

const unsigned int LINE = 101U;
const unsigned int RECTANGLE = 102U;
const unsigned int CIRCLE = 103U;
const unsigned int CURVE = 104U;

// CSketcherApp:
// 有关此类的实现，请参阅 Sketcher.cpp

class CSketcherApp : public CWinApp
{
public:
	CSketcherApp();


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSketcherApp theApp;