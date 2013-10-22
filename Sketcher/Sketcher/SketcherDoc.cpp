// SketcherDoc.cpp : CSketcherDoc 类的实现
//

#include "stdafx.h"
#include "Sketcher.h"

#include "SketcherDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSketcherDoc

IMPLEMENT_DYNCREATE(CSketcherDoc, CDocument)

BEGIN_MESSAGE_MAP(CSketcherDoc, CDocument)
  ON_COMMAND(ID_COLOR_BLACK, &CSketcherDoc::OnColorBlack)
  ON_COMMAND(ID_COLOR_RED, &CSketcherDoc::OnColorRed)
  ON_COMMAND(ID_COLOR_GREEN, &CSketcherDoc::OnColorGreen)
  ON_COMMAND(ID_COLOR_BLUE, &CSketcherDoc::OnColorBlue)
  ON_COMMAND(ID_ELEMENT_LINE, &CSketcherDoc::OnElementLine)
  ON_COMMAND(ID_ELEMENT_RECTANGLE, &CSketcherDoc::OnElementRectangle)
  ON_COMMAND(ID_ELEMENT_CIRCLE, &CSketcherDoc::OnElementCircle)
  ON_COMMAND(ID_ELEMENT_CURVE, &CSketcherDoc::OnElementCurve)
  ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, &CSketcherDoc::OnUpdateColorBlack)
  ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CSketcherDoc::OnUpdateColorRed)
  ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CSketcherDoc::OnUpdateColorGreen)
  ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CSketcherDoc::OnUpdateColorBlue)
  ON_UPDATE_COMMAND_UI(ID_ELEMENT_LINE, &CSketcherDoc::OnUpdateElementLine)
  ON_UPDATE_COMMAND_UI(ID_ELEMENT_RECTANGLE, &CSketcherDoc::OnUpdateElementRectangle)
  ON_UPDATE_COMMAND_UI(ID_ELEMENT_CIRCLE, &CSketcherDoc::OnUpdateElementCircle)
  ON_UPDATE_COMMAND_UI(ID_ELEMENT_CURVE, &CSketcherDoc::OnUpdateElementCurve)
END_MESSAGE_MAP()


// CSketcherDoc 构造/析构

CSketcherDoc::CSketcherDoc()
: m_Element(LINE),m_Color(BLACK)
{
	// TODO: 在此添加一次性构造代码
}

CSketcherDoc::~CSketcherDoc()
{
}

BOOL CSketcherDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CSketcherDoc 序列化

void CSketcherDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CSketcherDoc 诊断

#ifdef _DEBUG
void CSketcherDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSketcherDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSketcherDoc 命令

void CSketcherDoc::OnColorBlack()
{
  // TODO: 在此添加命令处理程序代码
  m_Color = BLACK;
}

void CSketcherDoc::OnColorRed()
{
  // TODO: 在此添加命令处理程序代码
  m_Color = RED;
}

void CSketcherDoc::OnColorGreen()
{
  // TODO: 在此添加命令处理程序代码
  m_Color = GREEN;
}

void CSketcherDoc::OnColorBlue()
{
  // TODO: 在此添加命令处理程序代码
  m_Color = BLUE;
}

void CSketcherDoc::OnElementLine()
{
  // TODO: 在此添加命令处理程序代码
  m_Element = LINE;
}

void CSketcherDoc::OnElementRectangle()
{
  // TODO: 在此添加命令处理程序代码
  m_Element = RECTANGLE;
}

void CSketcherDoc::OnElementCircle()
{
  // TODO: 在此添加命令处理程序代码
  m_Element = CIRCLE;
}

void CSketcherDoc::OnElementCurve()
{
  // TODO: 在此添加命令处理程序代码
  m_Element = CURVE;
}

void CSketcherDoc::OnUpdateColorBlack(CCmdUI *pCmdUI)
{
  // TODO: 在此添加命令更新用户界面处理程序代码
  pCmdUI->SetCheck( BLACK == m_Color );
}

void CSketcherDoc::OnUpdateColorRed(CCmdUI *pCmdUI)
{
  // TODO: 在此添加命令更新用户界面处理程序代码
  pCmdUI->SetCheck( RED == m_Color );
}

void CSketcherDoc::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
  // TODO: 在此添加命令更新用户界面处理程序代码
  pCmdUI->SetCheck( GREEN == m_Color );
}

void CSketcherDoc::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
  // TODO: 在此添加命令更新用户界面处理程序代码
  pCmdUI->SetCheck( BLUE == m_Color );
}

void CSketcherDoc::OnUpdateElementLine(CCmdUI *pCmdUI)
{
  // TODO: 在此添加命令更新用户界面处理程序代码
  pCmdUI->SetCheck( LINE == m_Element );
}

void CSketcherDoc::OnUpdateElementRectangle(CCmdUI *pCmdUI)
{
  // TODO: 在此添加命令更新用户界面处理程序代码
  pCmdUI->SetCheck( RECTANGLE == m_Element );
}

void CSketcherDoc::OnUpdateElementCircle(CCmdUI *pCmdUI)
{
  // TODO: 在此添加命令更新用户界面处理程序代码
    pCmdUI->SetCheck( CIRCLE == m_Element );
}

void CSketcherDoc::OnUpdateElementCurve(CCmdUI *pCmdUI)
{
  // TODO: 在此添加命令更新用户界面处理程序代码
    pCmdUI->SetCheck( CURVE == m_Element );
}

int CSketcherDoc::GetColor()
{
  return m_Color;
}

int CSketcherDoc::GetElement()
{
  return m_Element;
}