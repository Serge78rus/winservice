/*
 * svc_thrd.c
 *
 *  Created on: 12 дек. 2015 г.
 *      Author: serge78rus
 */

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#include <windows.h>

#include "svc.h"

#ifdef USE_THREAD

DWORD WINAPI ServiceWorkerThread(LPVOID lpParam)
{
	TRACE("ServiceWorkerThread()\n")
	//  Periodically check if the service has been requested to stop
	while (WaitForSingleObject(g_ServiceStopEvent, 0) != WAIT_OBJECT_0) {
		/*
		 * Perform main service function here
		 */

		//  Simulate some work by sleeping
		Sleep(3000);
	}

	TRACE("~ServiceWorkerThread()\n")
	return ERROR_SUCCESS;
}

#endif
