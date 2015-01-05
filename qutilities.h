#ifndef QUTILITIES_H
#define QUTILITIES_H

// Utilities to interrogate Qt Classes and Objects

#include <QString>
#include <QMediaRecorder>
#define QStringToCHAR(x) (char*) (x.toLocal8Bit().data())

QString MediaRecorderStatusToQString(QMediaRecorder::Status);
QString MediaRecorderStateToQString(QMediaRecorder::State);
void LogMediaRecorderVideoEncoder(QVideoEncoderSettings);
void dumpMediaRecorder(QMediaRecorder*qmr);


#endif // QUTILITIES_H
