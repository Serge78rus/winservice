/*
 * svc_start.c
 *
 *  Created on: 12 дек. 2015 г.
 *      Author: serge78rus
 */

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#include <windows.h>

#include "svc.h"

int ServiceStart()
{
	TRACE("ServiceStart()\n")
	printf("Starting service \"%s\" ...\n", SERVICE_NAME);

	SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!hSCManager) {
		TRACE("Error: OpenSCManager()\n")
		fprintf(stderr, "Error: Can't open Service Control Manager");
		return -1;
	}
	SC_HANDLE hService = OpenService(hSCManager, SERVICE_NAME, SERVICE_START);
	if (!hService) {
		TRACE("Error: OpenService()\n")
		fprintf(stderr, "Error: Can't open service");
		CloseServiceHandle(hSCManager);
		return -1;
	}
	BOOL res = StartService(hService, 0, NULL);
	/*todo wait status*/
	CloseServiceHandle(hService);
	CloseServiceHandle(hSCManager);

	if (res) {
		printf("Service \"%s\" started OK\n", SERVICE_NAME);
	} else {
		TRACE("Error: StartService()\n")
		fprintf(stderr, "Error: Can't start service");
	}

	TRACE("~ServiceStart()\n")
	return 0;
}

