/*
 * svc.h
 *
 *  Created on: 12 дек. 2015 г.
 *      Author: serge78rus
 */

#ifndef SVC_H_
#define SVC_H_

#define SERVICE_NAME  _T("My Sample Service")
//#define USE_THREAD
#define LOG_FILE "c:\\winservice.log"

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

#ifdef USE_THREAD
DWORD WINAPI ServiceWorkerThread(LPVOID lpParam);
#endif

#ifdef LOG_FILE
FILE *g_LogFile;
#define OPEN_LOG() g_LogFile = fopen(LOG_FILE, "a");
#define CLOSE_LOG() fclose(g_LogFile);
#define LOG(msg) {fprintf(g_LogFile, msg); fflush(g_LogFile);}
#else
#define OPEN_LOG()
#define CLOSE_LOG()
#define LOG(msg)
#endif

#ifdef  __cplusplus
}
#endif

#endif /* SVC_H_ */
