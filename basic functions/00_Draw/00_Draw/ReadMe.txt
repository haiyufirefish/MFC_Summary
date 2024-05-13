================================================== ==============================
     MICROSOFT basic class library: 02_Draw project overview
================================================== =============================

The Application Wizard has created this 02_Draw application for you. This application not only demonstrates the basic use of Microsoft foundation classes, but also serves as a starting point for writing your applications.

This document outlines the contents of each file that makes up the 02_Draw application.

02_Draw.vcxproj
     This is the main project file for a VC++ project generated using the AppWizard. It contains information about the version of Visual C++ that generated the file, as well as information about the platform, configuration, and project features selected using the AppWizard.

02_Draw.vcxproj.filters
     This is a VC++ project filter file generated using the Application Wizard. It contains information about the association between project files and filters. In the IDE, this association allows files with similar extensions to be displayed in groups under specific nodes. For example, ".cpp" files are associated with the "Source Files" filter.

02_Draw.h
     This is the main header file for the application.
     This includes other project-specific headers (including Resource.h) and declares the CMy02_DrawApp application class.

02_Draw.cpp
     This is the main application source file containing the application class CMy02_DrawApp.

02_Draw.rc
     This is a list of all Microsoft Windows resources used by the program. It includes icons, bitmaps, and cursors stored in the RES subdirectory. This file can be edited directly in Microsoft Visual C++. Project resources are included in 2052.

res\02_Draw.ico
     This is the icon file used as the application icon. This icon is included in the main resource file 02_Draw.rc.

res\My02_Draw.rc2
     This file contains resources that are not editable in Microsoft Visual C++. You should place all resources that are not editable by the resource editor in this file.

///////////////////////////////////////////////////// //////////////////////////////

For the main frame window:
     This project contains a standard MFC interface.

MainFrm.h, MainFrm.cpp
     These files contain the frame class CMainFrame, which is derived from
     CFrameWnd and controls all SDI frame functionality.

res\Toolbar.bmp
     This bitmap file is used to create tiled images for toolbars.
     The initial toolbar and status bar are constructed in the CMainFrame class. Use the Resource Editor to edit this toolbar bitmap and update the IDR_MAINFRAME TOOLBAR array in 02_Draw.rc to add the toolbar buttons.
///////////////////////////////////////////////////// //////////////////////////////

The AppWizard creates a document type and a view:

02_DrawDoc.h, 02_DrawDoc.cpp - Documentation
     These files contain the CMy02_DrawDoc class. Edit these files to add special document data and enable file saving and loading (via CMy02_DrawDoc::Serialize).

02_DrawView.h, 02_DrawView.cpp - Document View
     These files contain the CMy02_DrawView class.
     The CMy02_DrawView object is used to view CMy02_DrawDoc objects.




///////////////////////////////////////////////////// //////////////////////////////

Other functions:

ActiveX control
     The application includes support for using ActiveX controls.

Print and print preview support
     AppWizard generates code to handle printing, print setup, and print preview commands by calling member functions in the CView class from the MFC library.

///////////////////////////////////////////////////// //////////////////////////////

Other standard documents:

StdAfx.h, StdAfx.cpp
     These files are used to generate a precompiled header (PCH) file named 02_Draw.pch and a precompiled type file named StdAfx.obj.

Resource.h
     This is a standard header file that can be used to define new resource IDs. Microsoft Visual C++ will read and update this file.

02_Draw.manifest
Windows XP uses an application manifest file to describe application dependencies for a specific version of a side-by-side assembly. The loader uses this information to load the corresponding assembly from the assembly cache and protect it from access by the application. The application manifest may be included for redistribution as an external .manifest file installed in the same folder as the application executable, or it may be included in the executable as a resource.
///////////////////////////////////////////////////// //////////////////////////////

Other notes:

The AppWizard uses "TODO:" to indicate portions of the source code that should be added or customized.

If your application uses MFC from a shared DLL, you will need to redistribute the MFC DLL. If your application is in a language that is different from the locale of the operating system, you also need to redistribute the corresponding localized resource mfc110XXX.DLL.
For more information on the above topics, see the section on redistributing Visual C++ applications in the MSDN documentation.

///////////////////////////////////////////////////// //////////////////////////////