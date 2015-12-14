/*
 * svc.h
 *
 *  Created on: 12 дек. 2015 г.
 *      Author: serge78rus
 */

#ifndef SVC_H_
#define SVC_H_

#define SERVICE_NAME  _T("MySampleService")
#define DISPLAY_NAME  _T("My Sample Service")
#define SERVICE_AUTOSTART
//#define USE_THREAD
//#define TRACE_FILE "c:\\winservice.log"


#ifdef SERVICE_AUTOSTART
#define SERVICE_START_MODE SERVICE_AUTO_START
#else
#define SERVICE_START_MODE SERVICE_DEMAND_START
#endif

#ifdef  __cplusplus
extern "C" {
#endif

//global variables
SERVICE_STATUS g_ServiceStatus;
SERVICE_STATUS_HANDLE g_StatusHandle;
HANDLE g_ServiceStopEvent;

VOID WINAPI ServiceMain(DWORD argc, LPTSTR *argv);
VOID WINAPI ServiceCtrlHandler(DWORD CtrlCode);
int ServiceInstall(TCHAR *path);
int ServiceUninstall();
int ServiceStart();
int ServiceStop();
void ServiceHelp();

#ifdef USE_THREAD
DWORD WINAPI ServiceWorkerThread(LPVOID lpParam);
#endif

#ifdef TRACE_FILE
FILE *g_LogFile;
#define OPEN_TRACE() g_LogFile = fopen(TRACE_FILE, "a");
#define CLOSE_TRACE() fclose(g_LogFile);
#define TRACE(msg) {fprintf(g_LogFile, msg); fflush(g_LogFile);}
#else
#define OPEN_TRACE()
#define CLOSE_TRACE()
#define TRACE(msg)
#endif

#ifdef  __cplusplus
}
#endif

#endif /* SVC_H_ */
