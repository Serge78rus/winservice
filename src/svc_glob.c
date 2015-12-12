/*
 * svc_glob.c
 *
 *  Created on: 12 дек. 2015 г.
 *      Author: serge78rus
 */

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#include <windows.h>

#include "svc.h"

SERVICE_STATUS g_ServiceStatus = {0};
SERVICE_STATUS_HANDLE g_StatusHandle = NULL;
HANDLE g_ServiceStopEvent = INVALID_HANDLE_VALUE;

#ifdef LOG_FILE
FILE *g_LogFile;
#endif
