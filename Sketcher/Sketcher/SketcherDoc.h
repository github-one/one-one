// SketcherDoc.h : CSketcherDoc ��Ľӿ�
//


#pragma once


class CSketcherDoc : public CDocument
{
protected: // �������л�����
	CSketcherDoc();
	DECLARE_DYNCREATE(CSketcherDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CSketcherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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


