
// 03_EditorView.cpp : CMy03_EditorView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "03_Editor.h"
#endif

#include "03_EditorDoc.h"
#include "03_EditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03_EditorView

IMPLEMENT_DYNCREATE(CMy03_EditorView, CView)

BEGIN_MESSAGE_MAP(CMy03_EditorView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy03_EditorView 构造/析构

CMy03_EditorView::CMy03_EditorView()
: m_point(0)
, str(_T(""))
{
	// TODO:  在此处添加构造代码

}

CMy03_EditorView::~CMy03_EditorView()
{
}

BOOL CMy03_EditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03_EditorView 绘制

void CMy03_EditorView::OnDraw(CDC* /*pDC*/)
{
	CMy03_EditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy03_EditorView 打印

BOOL CMy03_EditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03_EditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy03_EditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy03_EditorView 诊断

#ifdef _DEBUG
void CMy03_EditorView::AssertValid() const
{
	CView::AssertValid();
}

void CMy03_EditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03_EditorDoc* CMy03_EditorView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03_EditorDoc)));
	return (CMy03_EditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy03_EditorView 消息处理程序

//窗口创建后自动调用
int CMy03_EditorView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	//获取字体信息
	CClientDC dc(this);

	TEXTMETRIC tm; //字体信息结构体

	dc.GetTextMetrics(&tm);


	//继承与CWnd
	CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight); //创建插入符

	ShowCaret(); //显示




	return 0;
}


void CMy03_EditorView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	SetCaretPos(point); //移动插入符

	//保存点击坐标
	m_point = point;

	str = TEXT("");
	str.Empty();


	CView::OnLButtonDown(nFlags, point);
}

//点击键盘，启动调用
void CMy03_EditorView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);

	


	if (nChar == VK_RETURN) //换行
	{
		str.Empty();
		//获取字体信息，


		TEXTMETRIC tm; //字体信息结构体

		dc.GetTextMetrics(&tm);

		m_point.y = m_point.y + tm.tmHeight;

	}
	else if (nChar == VK_BACK) //退格
	{
		//获取背景图
		COLORREF color = dc.GetBkColor();
		/*auto a = dc.GetBkColor();*/

		//设置写字的颜色
		COLORREF oldColor = dc.SetTextColor(color);

		//白色重写一次
		dc.TextOutW(m_point.x, m_point.y, str);

		//去掉最后一个字符
		str = str.Left(str.GetLength() - 1);
		

		//恢复原来颜色
		dc.SetTextColor(oldColor);
	}
	else
	{
		str += (TCHAR)nChar;
	}

	CFont font;
	font.CreatePointFont(160, _T("Arial")); // Change the font size here (160 is 16pt)

	// Select the font into the device context
	CFont* pOldFont = dc.SelectObject(&font);

	CSize size = dc.GetTextExtent(str); //获取字符串长度
	int x = m_point.x + size.cx;
	//int x = m_point.x + size.cx;
	int y = m_point.y;

	SetCaretPos(CPoint(x, y));

	dc.TextOutW(m_point.x, m_point.y, str);

	dc.SelectObject(pOldFont);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
