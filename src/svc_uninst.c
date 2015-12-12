/*
 * svc_uninst.c
 *
 *  Created on: 12 дек. 2015 г.
 *      Author: serge78rus
 */

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#include <windows.h>

#include "svc.h"

int ServiceUninstall()
{
	LOG("ServiceUninstall()\n")
	printf("Uninstalling service \"%s\" ...\n", SERVICE_NAME);

	SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_ALL_ACCESS);
	if (!hSCManager) {
		LOG("Error: OpenSCManager()\n")
		fprintf(stderr, "Error: Can't open Service Control Manager");
		return -1;
	}
	SC_HANDLE hService = OpenService(hSCManager, SERVICE_NAME,
			SERVICE_STOP | DELETE);
	if (!hService) {
		LOG("Error: OpenService()\n")
		fprintf(stderr, "Error: Can't open service");
		CloseServiceHandle(hSCManager);
		return -1;
	}
	BOOL res = DeleteService(hService);
	CloseServiceHandle(hService);
	CloseServiceHandle(hSCManager);

	if (res) {
		printf("Service \"%s\" uninstalled OK\n", SERVICE_NAME);
	} else {
		LOG("Error: DeleteService()\n")
		fprintf(stderr, "Error: Can't delete service");
	}

	LOG("~ServiceUninstall()\n")
	return 0;
}
