// SketcherView.cpp : CSketcherView ���ʵ��
//

#include "stdafx.h"
#include "Sketcher.h"

#include "SketcherDoc.h"
#include "SketcherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSketcherView

IMPLEMENT_DYNCREATE(CSketcherView, CView)

BEGIN_MESSAGE_MAP(CSketcherView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
  ON_WM_LBUTTONDOWN()
  ON_WM_LBUTTONUP()
  ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CSketcherView ����/����

CSketcherView::CSketcherView(): m_DrawTrigger(0)
{
	// TODO: �ڴ˴���ӹ������

}

CSketcherView::~CSketcherView()
{
}

BOOL CSketcherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSketcherView ����

void CSketcherView::OnDraw(CDC* pDC)
{
	CSketcherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
  pDC->MoveTo(50,50);
  pDC->LineTo(50,200);
  pDC->LineTo(150,200);
  pDC->LineTo(150,50);
  pDC->LineTo(50,50);

/*
  CPen aPen;
  aPen.CreatePen(PS_DOT, 1, RGB(0,0,255));

  CPen *pOldPen = pDC->SelectObject(&aPen); // Select aPen and save the old one.

  // pDC->Arc(300,50,400,100,400,75,350,50);
  pDC->Arc(300,100,500,300,300,100,500,100);

  CBrush aBrush(HS_DIAGCROSS,RGB(255,0,0));
  CBrush *pOldBrush = (CBrush*)pDC->SelectObject(&aBrush);

  CRect aRect(100,100,200,150);
  pDC->Ellipse(aRect);

  pDC->SelectObject(pOldPen);
  pDC->SelectObject(pOldBrush);
*/

}


// CSketcherView ��ӡ

BOOL CSketcherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSketcherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSketcherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CSketcherView ���

#ifdef _DEBUG
void CSketcherView::AssertValid() const
{
	CView::AssertValid();
}

void CSketcherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSketcherDoc* CSketcherView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSketcherDoc)));
	return (CSketcherDoc*)m_pDocument;
}
#endif //_DEBUG


// CSketcherView ��Ϣ�������

void CSketcherView::OnLButtonDown(UINT nFlags, CPoint point)
{
  // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
  //MessageBox(L"Left Button pressed");

  if ( (nFlags & MK_LBUTTON) && (m_DrawTrigger == 0)) {
    m_DrawTrigger = 1;
    m_StartPoint = point;
    m_CalledTimes_OnMouseMove = 0;
  }

  CView::OnLButtonDown(nFlags, point);
}

void CSketcherView::OnLButtonUp(UINT nFlags, CPoint point)
{
  // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

  if ( m_DrawTrigger == 2 ) {
    m_DrawTrigger = 0;
    
    CClientDC aDC(this);
    TCHAR sz[128]= {0};
    //wsprintf(sz, _T("Called Times of OnMoveMouse is %d"), m_CalledTimes_OnMouseMove);
    _stprintf_s(sz, _T("Called Times of OnMoveMouse is %08d"), m_CalledTimes_OnMouseMove);
    aDC.TextOutW(0,0,sz);
    // The format "%08d" will prevent last display length is bigger.

    m_CalledTimes_OnMouseMove = 0;

    CSketcherDoc* pDoc = GetDocument();
	  ASSERT_VALID(pDoc);
	  if (!pDoc)
		  return;
    
    TCHAR szColor[32] = {0};
    TCHAR szElement[32] = {0};
    
    switch(pDoc->GetColor()) {
      case RED:  
        wcscat_s(szColor,L"red");   // û���ҵ����ʵ�_T���庯��
        break;

      case GREEN:  
        wcscat_s(szColor,L"green");
        break;

      case BLUE:  
        wcscat_s(szColor,L"blue");
        break;

      case BLACK:  
        wcscat_s(szColor,L"black");
        break;
  
      default:
        wcscat_s(szColor,L"unknow");
        break;
    }

    switch( pDoc->GetElement() ) {
      case LINE:
        wcscat_s(szElement,L"line");
        break;
      case RECTANGLE:
        wcscat_s(szElement,L"rectangle");
        break;
      case CIRCLE:
        wcscat_s(szElement,L"circle");
        break;
      case CURVE:
        wcscat_s(szElement,L"curve");
        break;
      default:
        wcscat_s(szElement,L"unknow");
        break;          
    }

    TCHAR sz1[128] = {0};

    _stprintf_s(sz1, _T("Color is %s, and Element is %s              "), szColor, szElement); 
    // The last spaces is to override last characters.
    aDC.TextOutW(0,30,sz1);
  }

  CView::OnLButtonUp(nFlags, point);
}

void CSketcherView::OnMouseMove(UINT nFlags, CPoint point)
{
  // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
  if (nFlags & MK_LBUTTON) {
    
    m_CalledTimes_OnMouseMove ++;

    CClientDC aDC(this);
    CRect aRect(m_StartPoint, m_EndPoint);

    switch (m_DrawTrigger) {
      case 1:
        m_DrawTrigger = 2;
        m_EndPoint = point;
        aRect.SetRect(m_StartPoint,m_EndPoint);
        aDC.Rectangle(aRect);
        break;

      case 2:
        aDC.SetROP2(R2_NOTXORPEN);
        aDC.Rectangle(aRect);
    
        m_EndPoint = point;
        aRect.SetRect(m_StartPoint, m_EndPoint);
        aDC.Rectangle(aRect); 
        break;

      default:
        break;
      }
  }
    
  CView::OnMouseMove(nFlags, point);
}
