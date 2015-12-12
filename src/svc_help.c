/*
 * svc_help.c
 *
 *  Created on: 12 дек. 2015 г.
 *      Author: serge78rus
 */

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#include <windows.h>

#include "svc.h"

void ServiceHelp()
{
	printf(
			"\n Usage:\n"
			"<exename> <command>\n"
			"commands:\n"
			"  -i, --install         Install service\n"
			"  -u, --uninstall       Uninstall service\n"
			"      --start           Start service\n"
			"      --stop            Stop service\n"
			"  -h  --help            This help screen\n"
			);
}
