/*

Module Name:

    Logging.h

Abstract:

	Declaration of the logging functions

*/

//---------------------------------------------------------------------------

#ifndef LoggingH
#define LoggingH

#include <QString>
// FIXME! #include "Windows.h"
//#include "winHACK.h"

//---------------------------------------------------------------------------
#ifdef _DEBUG 
#define Log {LogMsg(
#define ELog );}
#else
#define Log
#define ELog ;
#endif

#define QStringToCHAR(x) (char*) (x.toLocal8Bit().data())
#define QStringToTCHAR(x) (wchar_t*) x.utf16()

extern QString __log_file_name;

//---------------------------------------------------------------------------
void LogMsg(QString & message, ...);
void LogMsg(char *message, ...);
void LogMsg(wchar_t *message, ...);
//---------------------------------------------------------------------------
#endif
