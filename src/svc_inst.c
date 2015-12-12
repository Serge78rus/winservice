/*
 * svc_inst.c
 *
 *  Created on: 12 дек. 2015 г.
 *      Author: serge78rus
 */

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#include <windows.h>

#include "svc.h"

int ServiceInstall(TCHAR *path)
{
	LOG("ServiceInstall()\n")
	printf("Installing service \"%s\" ...\n", SERVICE_NAME);

	SC_HANDLE hSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
  if(!hSCManager) {
		LOG("Error: OpenSCManager()\n")
 		fprintf(stderr, "Error: Can't open Service Control Manager");
    return -1;
  }

  SC_HANDLE hService = CreateService(
     hSCManager,
		 SERVICE_NAME,
		 DISPLAY_NAME,
     SERVICE_ALL_ACCESS,
     SERVICE_WIN32_OWN_PROCESS,
     SERVICE_START_MODE,
     SERVICE_ERROR_NORMAL,
		 path,
     NULL, NULL, NULL, NULL, NULL
  );

  if(!hService) {
		LOG("Error: CreateService()\n")
   int err = GetLastError();
    switch(err) {
      case ERROR_ACCESS_DENIED:
      	fprintf(stderr, "Error: ERROR_ACCESS_DENIED");
        break;
      case ERROR_CIRCULAR_DEPENDENCY:
      	fprintf(stderr, "Error: ERROR_CIRCULAR_DEPENDENCY");
        break;
      case ERROR_DUPLICATE_SERVICE_NAME:
      	fprintf(stderr, "Error: ERROR_DUPLICATE_SERVICE_NAME");
        break;
      case ERROR_INVALID_HANDLE:
      	fprintf(stderr, "Error: ERROR_INVALID_HANDLE");
        break;
      case ERROR_INVALID_NAME:
      	fprintf(stderr, "Error: ERROR_INVALID_NAME");
        break;
      case ERROR_INVALID_PARAMETER:
      	fprintf(stderr, "Error: ERROR_INVALID_PARAMETER");
        break;
      case ERROR_INVALID_SERVICE_ACCOUNT:
      	fprintf(stderr, "Error: ERROR_INVALID_SERVICE_ACCOUNT");
        break;
      case ERROR_SERVICE_EXISTS:
      	fprintf(stderr, "Error: ERROR_SERVICE_EXISTS");
        break;
      default:
      	fprintf(stderr, "Error: Undefined");
    }
    CloseServiceHandle(hSCManager);
    return -1;
  }
  CloseServiceHandle(hService);
  CloseServiceHandle(hSCManager);

	printf("Service \"%s\" installed OK\n", SERVICE_NAME);

	LOG("~ServiceInstall()\n")
	return 0;
}

