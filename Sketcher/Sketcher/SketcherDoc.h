// SketcherDoc.h : CSketcherDoc 类的接口
//


#pragma once


class CSketcherDoc : public CDocument
{
protected: // 仅从序列化创建
	CSketcherDoc();
	DECLARE_DYNCREATE(CSketcherDoc)

// 属性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CSketcherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnColorBlack();
  afx_msg void OnColorRed();
  afx_msg void OnColorGreen();
  afx_msg void OnColorBlue();
  afx_msg void OnElementLine();
  afx_msg void OnElementRectangle();
  afx_msg void OnElementCircle();
  afx_msg void OnElementCurve();

  afx_msg void OnUpdateColorBlack(CCmdUI *pCmdUI);
  afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
  afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
  afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
  afx_msg void OnUpdateElementLine(CCmdUI *pCmdUI);
  afx_msg void OnUpdateElementRectangle(CCmdUI *pCmdUI);
  afx_msg void OnUpdateElementCircle(CCmdUI *pCmdUI);
  afx_msg void OnUpdateElementCurve(CCmdUI *pCmdUI);

private:
  // Record the active element
  unsigned int m_Element;
  // Record the active color
  unsigned int m_Color;
  
public:
  int GetColor();
  int GetElement();
};


