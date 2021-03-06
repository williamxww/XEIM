/* 此软件名称为 XEIM 飞鸽传书，受 GPL 开源协议保护，任何违反本协议的人我们将尽最大努力追究其法律责任。
XEIM 飞鸽传书官方网站：http://www.freeeim.com/xeim/
XEIM 飞鸽传书官方网站：http://bbs.freeeim.com/
*/
// xsvr.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "xsvr.h"
#include "xsvrDlg.h"

/*#include <vld.h>*/

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXsvrApp

BEGIN_MESSAGE_MAP(CXsvrApp, CWinApp)
	//{{AFX_MSG_MAP(CXsvrApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXsvrApp construction

CXsvrApp::CXsvrApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CXsvrApp object

CXsvrApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CXsvrApp initialization

BOOL CXsvrApp::InitInstance()
{
	OleInitialize(NULL);
	AfxEnableControlContainer();

	InitializeCriticalSection(& g_cs);

	CFileFind fFind;
	CStdioFile file;
	char buf[MAX_PATH];
	GetProgramDirectory(buf);
	CString fileName;
	fileName.Format("%s%s", buf, "sys.log");
	if (! fFind.FindFile(fileName))
	{
	//	AfxMessageBox("File don't existed.");
		file.Open(fileName, CFile::modeCreate|CFile::modeWrite|CFile::shareDenyNone, NULL);
	}

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CXsvrDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

void CXsvrApp::Lock()
{
//	EnterCriticalSection(& g_cs);
}

void CXsvrApp::Unlock()
{
//	LeaveCriticalSection(& g_cs);
}
