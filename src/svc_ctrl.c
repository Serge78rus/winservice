/*
 * svc_ctrl.c
 *
 *  Created on: 12 дек. 2015 г.
 *      Author: serge78rus
 */

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#include <windows.h>

#include "svc.h"

VOID WINAPI ServiceCtrlHandler(DWORD CtrlCode)
{
	LOG("ServiceCtrlHandler()\n")
	switch (CtrlCode) {
		case SERVICE_CONTROL_STOP:
		case SERVICE_CONTROL_SHUTDOWN:
			if (g_ServiceStatus.dwCurrentState != SERVICE_RUNNING)
				break;

			/*
			 * Perform tasks necessary to stop the service here
			 */

			g_ServiceStatus.dwControlsAccepted = 0;
			g_ServiceStatus.dwCurrentState = SERVICE_STOP_PENDING;
			g_ServiceStatus.dwWin32ExitCode = 0;
			g_ServiceStatus.dwCheckPoint = 4;

			if (SetServiceStatus(g_StatusHandle, &g_ServiceStatus) == FALSE) {
				LOG("Error: SetServiceStatus()\n")
			}

			// This will signal the main thread or worker thread to start shutting down
			SetEvent(g_ServiceStopEvent);

			break;

		default:
			break;
	}
	LOG("~ServiceCtrlHandler()\n")
}
