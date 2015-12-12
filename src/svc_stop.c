/*
 * svc_stop.c
 *
 *  Created on: 12 дек. 2015 г.
 *      Author: serge78rus
 */

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#include <windows.h>

#include "svc.h"

int ServiceStop()
{
	LOG("ServiceStop()\n")
	printf("Stopping service \"%s\" ...\n", SERVICE_NAME);

	SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!hSCManager) {
		LOG("Error: OpenSCManager()\n")
		fprintf(stderr, "Error: Can't open Service Control Manager");
		return -1;
	}
	SC_HANDLE hService = OpenService(hSCManager, SERVICE_NAME, SERVICE_STOP);
	if (!hService) {
		LOG("Error: OpenService()\n")
		fprintf(stderr, "Error: Can't open service");
		CloseServiceHandle(hSCManager);
		return -1;
	}
	SERVICE_STATUS ss;
	BOOL res = ControlService(hService, SERVICE_CONTROL_STOP, &ss);
	/*todo wait status*/
	CloseServiceHandle(hService);
	CloseServiceHandle(hSCManager);

	if (res) {
		printf("Service \"%s\" stopped OK\n", SERVICE_NAME);
	} else {
		LOG("Error: ControlService()\n")
		fprintf(stderr, "Error: Can't stop service");
	}

	LOG("~ServiceStop()\n")
	return 0;
}

