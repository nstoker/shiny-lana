#include "qutilities.h"
#include "Logging.h"

QString MediaRecorderStatusToQString(QMediaRecorder::Status status)
{
    QString rv="";

    switch(status)
    {
    case QMediaRecorder::UnavailableStatus: //	0
    {
        rv="The recorder is not available or not supported by connected media object.";
        break;
    }
    case QMediaRecorder::UnloadedStatus:	//1
    {
        rv="The recorder is avilable but not loaded.";
        break;
    }

    case QMediaRecorder::LoadingStatus: // 2
    {
        rv="The recorder is initializing.";
        break;
    }

    case QMediaRecorder::LoadedStatus: // 3
    {
        rv="The recorder is initialized and ready to record media.";
        break;
    }

    case QMediaRecorder::StartingStatus: // 4
    {
        rv="Recording is requested but not active yet.";
        break;
    }

    case QMediaRecorder::RecordingStatus: // 5
    {
        rv="Recording is active.";
        break;
    }

    case QMediaRecorder::PausedStatus: // 6
    {
        rv="Recording is paused.";
        break;
    }

    case QMediaRecorder::FinalizingStatus: // 7
    {
        rv="Recording is stopped with media being finalized.";
        break;
    }

    }

    return rv;
}


QString MediaRecorderStateToQString(QMediaRecorder::State state)
{
    QString rv="";
    switch(state)
    {
    case QMediaRecorder::StoppedState:	//0
    {
        rv="The recorder is not active.";
        break;
    }
    case QMediaRecorder::RecordingState: //	1
    {
        rv="The recording is requested.";
        break;
    }
    case QMediaRecorder::PausedState: //	2
    {
        rv="The recorder is paused.";
        break;
    }
    }

    return rv;
}

QString getEncodingMode(QMultimedia::EncodingMode mode)
{
    Q_UNUSED(mode);
    return "";
}

void LogMediaRecorderVideoEncoder(QVideoEncoderSettings qve)
{
    // Dump the encoder settings
    LogMsg((char*)" %i:%s Entry",__LINE__,__PRETTY_FUNCTION__);
    if(qve.isNull())
        LogMsg((char*)"Video encoder is null!");
    else
    {
        LogMsg((char*)"Video encoder is not null");
        LogMsg((char*)"bitRate : %i",qve.bitRate());
        LogMsg((char*)"codec   : %s", QStringToCHAR(qve.codec()));
        LogMsg((char*)"encodingMode : %s ",QStringToCHAR(getEncodingMode(qve.encodingMode())));
        LogMsg((char*)"encodingOption ..");
        LogMsg((char*)"encodingOptions ..");
        LogMsg((char*)"frameRate  : %f", qve.frameRate());
    }
}

void dumpMediaRecorder(QMediaRecorder *r)
{
    // Dump the supported resolutions
    if(!r)
    {
        LogMsg((char*)"WELL AND TRUELY BROKEN %i:%s: The QMediaRecorder object is not set",__LINE__,__PRETTY_FUNCTION__);
        return;
    }

    LogMsg((char*)"Number of supported AUDIO Codecs %i",r->supportedAudioCodecs().count());
    foreach(const QString &codecName, r->supportedAudioCodecs())
    {
        LogMsg((char*)"/t/t %s %s",QStringToCHAR(codecName) , QStringToCHAR(r->audioCodecDescription(codecName)));
    }

    LogMsg((char*)"Number of Audio sample rates %i",r->supportedAudioSampleRates().count());
    foreach (int sampleRate, r->supportedAudioSampleRates()) {
        LogMsg((char*)"\t\t%i",sampleRate);
    }

    LogMsg((char*)"Number of Video Codecs %i",r->supportedVideoCodecs().count());
    foreach(const QString &codecName,r->supportedVideoCodecs()){
        LogMsg((char*)"\t\t%s %s", QStringToCHAR(codecName) , QStringToCHAR(r->videoCodecDescription(codecName)));
    }

    LogMsg((char*)"Number of Video Frame Rates %i",r->supportedFrameRates().count());
    QList<qreal>supportedFrameRates=r->supportedFrameRates();
    qreal rate;
    foreach(rate, supportedFrameRates){
        LogMsg((char*)"\t\t%f",rate) ;
    }
    LogMsg((char*)"Number of Containers %i",r->supportedContainers().count());
    foreach(const QString &format, r->supportedContainers()){
        LogMsg((char*)"\t\t%s %s",QStringToCHAR(format) , QStringToCHAR(r->containerDescription(format)));
    }

}
