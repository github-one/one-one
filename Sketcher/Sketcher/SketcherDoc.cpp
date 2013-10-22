// SketcherDoc.cpp : CSketcherDoc ���ʵ��
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


// CSketcherDoc ����/����

CSketcherDoc::CSketcherDoc()
: m_Element(LINE),m_Color(BLACK)
{
	// TODO: �ڴ����һ���Թ������
}

CSketcherDoc::~CSketcherDoc()
{
}

BOOL CSketcherDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CSketcherDoc ���л�

void CSketcherDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CSketcherDoc ���

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


// CSketcherDoc ����

void CSketcherDoc::OnColorBlack()
{
  // TODO: �ڴ���������������
  m_Color = BLACK;
}

void CSketcherDoc::OnColorRed()
{
  // TODO: �ڴ���������������
  m_Color = RED;
}

void CSketcherDoc::OnColorGreen()
{
  // TODO: �ڴ���������������
  m_Color = GREEN;
}

void CSketcherDoc::OnColorBlue()
{
  // TODO: �ڴ���������������
  m_Color = BLUE;
}

void CSketcherDoc::OnElementLine()
{
  // TODO: �ڴ���������������
  m_Element = LINE;
}

void CSketcherDoc::OnElementRectangle()
{
  // TODO: �ڴ���������������
  m_Element = RECTANGLE;
}

void CSketcherDoc::OnElementCircle()
{
  // TODO: �ڴ���������������
  m_Element = CIRCLE;
}

void CSketcherDoc::OnElementCurve()
{
  // TODO: �ڴ���������������
  m_Element = CURVE;
}

void CSketcherDoc::OnUpdateColorBlack(CCmdUI *pCmdUI)
{
  // TODO: �ڴ������������û����洦��������
  pCmdUI->SetCheck( BLACK == m_Color );
}

void CSketcherDoc::OnUpdateColorRed(CCmdUI *pCmdUI)
{
  // TODO: �ڴ������������û����洦��������
  pCmdUI->SetCheck( RED == m_Color );
}

void CSketcherDoc::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
  // TODO: �ڴ������������û����洦��������
  pCmdUI->SetCheck( GREEN == m_Color );
}

void CSketcherDoc::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
  // TODO: �ڴ������������û����洦��������
  pCmdUI->SetCheck( BLUE == m_Color );
}

void CSketcherDoc::OnUpdateElementLine(CCmdUI *pCmdUI)
{
  // TODO: �ڴ������������û����洦��������
  pCmdUI->SetCheck( LINE == m_Element );
}

void CSketcherDoc::OnUpdateElementRectangle(CCmdUI *pCmdUI)
{
  // TODO: �ڴ������������û����洦��������
  pCmdUI->SetCheck( RECTANGLE == m_Element );
}

void CSketcherDoc::OnUpdateElementCircle(CCmdUI *pCmdUI)
{
  // TODO: �ڴ������������û����洦��������
    pCmdUI->SetCheck( CIRCLE == m_Element );
}

void CSketcherDoc::OnUpdateElementCurve(CCmdUI *pCmdUI)
{
  // TODO: �ڴ������������û����洦��������
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