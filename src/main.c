/*
 ============================================================================
 Name        : svc.c
 Author      : Serge L. Ryadkow AKA Serge78rus
 Version     :	0.1.1
 Copyright   : (C) 2015 by Serge L. Ryadkow
 Description : Template project for writing Windows services

 Based on code from http://www.codeproject.com/Articles/499465/Simple-Windows-Service-in-Cplusplus
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#include <windows.h>

#include "svc.h"

int _tmain(int argc, TCHAR *argv[])
{
	OPEN_TRACE()
	TRACE("\n-------------------------\n")
	TRACE("main()\n")
	if (argc == 1) {
		SERVICE_TABLE_ENTRY sTable[2];
		ZeroMemory (sTable, sizeof(sTable));
		sTable[0].lpServiceName = SERVICE_NAME;
		sTable[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTION)ServiceMain;
		TRACE("StartServiceCtrlDispatcher()\n")
		if (StartServiceCtrlDispatcher(sTable) == FALSE) {
			TRACE("Error: StartServiceCtrlDispatcher()\n")
			ServiceHelp();
			return GetLastError();
		}
	} else if (!strcmp(argv[1], _T("--install")) || !strcmp(argv[1], _T("-i"))) {
		return ServiceInstall(argv[0]);
	} else if (!strcmp(argv[1], _T("--uninstall")) || !strcmp(argv[1], _T("-u"))) {
		return ServiceUninstall();
	} else if (!strcmp(argv[1], _T("--start"))) {
		return ServiceStart();
	} else if (!strcmp(argv[1], _T("--stop"))) {
		return ServiceStop();
	} else if (!strcmp(argv[1], _T("--help")) || !strcmp(argv[1], _T("-h"))) {
		ServiceHelp();
	} else {
		ServiceHelp();
	}
	TRACE("~main()\n")
	CLOSE_TRACE()
	return 0;
}


