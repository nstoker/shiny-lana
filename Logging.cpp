/*

Module Name:

    Logging.cpp

Abstract:

	Implementation of the logging functions

*/

//#include "stdafx.h"
#include "Logging.h"
#include "stdio.h"
#include "stdarg.h"
#include "string.h"
#include <cstdarg>
#include <iostream>
#include <QFile>
#include <QIODevice>
#include <QDateTime>
#include <QDataStream>

//defined in stdafx.h
#define _USE_LOGGING
#ifdef _USE_LOGGING

// FIXME! CRITICAL_SECTION crit;
bool initcr = false;
QString __log_file_name;


void LogMsg(QString & message, ...)
{
    LogMsg((char*)QStringToTCHAR(message));
}

void LogMsg(char *message, ...)
{
    va_list va;
    va_start(va,message);
    __log_file_name="fred.log";

    try {
        //QFile file(__log_file_name);
        //if(file.open(QIODevice::Append | QIODevice::Text))
        {
           // Build up the string to write
           QString msg;
           msg =QDateTime::currentDateTimeUtc().toString("yyyy MM dd hh:mm:ss.zzz ");
           msg+= QString().vsprintf(message,va);
          // QDataStream out(&file);
           std::cout<< msg.toStdString()<<std::endl;
           //out << msg.toLocal8Bit()<<"\n";
           //file.close();
        }
	} catch (...) { }
    va_end(va);
}




#endif // _USE_LOGGING
