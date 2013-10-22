// SketcherView.h : CSketcherView 类的接口
//


#pragma once


class CSketcherView : public CView
{
protected: // 仅从序列化创建
	CSketcherView();
	DECLARE_DYNCREATE(CSketcherView)

// 属性
public:
	CSketcherDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CSketcherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);

private:
  unsigned int m_DrawTrigger;
  CPoint m_StartPoint;
  CPoint m_EndPoint;
  unsigned int m_CalledTimes_OnMouseMove;
};

#ifndef _DEBUG  // SketcherView.cpp 中的调试版本
inline CSketcherDoc* CSketcherView::GetDocument() const
   { return reinterpret_cast<CSketcherDoc*>(m_pDocument); }
#endif

