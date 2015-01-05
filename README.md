shiny-lana
==========

I am building an application to record multimedia files for ongoing processing.

My current issue is that the [QMediaRecorder](http://doc.qt.io/qt-5/qmediarecorder.html) does not apparently save the video file onto the local drive - I have temporarily hard-coded the file to be saved as `banana.mov` into the users root folder.


Development environment OSX 10.10 with Qt5.4 (the same issue is also happening on a Windows 8.1 machine using Qt5.3)

This code is based on the camera example, with additional debug code added when trying to identify and reproduce the issue.

While investigating, the [QMediaRecorder::​supportedAudioCodecs](http://doc.qt.io/qt-5/qmediarecorder.html#supportedAudioCodecs) and
[QMediaRecorder::supportedVideoCodecs](http://doc.qt.io/qt-5/qmediarecorder.html#supportedVideoCodecs) both return empty lists.

The debug output is as follows:

```
Status change SIGNAL 'The recorder is initializing.'
Output location file:~/banana.mov
2015 01 05 14:59:58.111 Number of supported AUDIO Codecs 0
2015 01 05 14:59:58.111 Number of Audio sample rates 0
2015 01 05 14:59:58.111 Number of Video Codecs 0
2015 01 05 14:59:58.111 Number of Video Frame Rates 0
2015 01 05 14:59:58.111 Number of Containers 0
Location Changed SIGNAL 'file:~/banana.mov'
State change SIGNAL 'The recording is requested.'
Recording should have started
2015 01 05 14:59:58.111 Number of supported AUDIO Codecs 0
2015 01 05 14:59:58.111 Number of Audio sample rates 0
2015 01 05 14:59:58.111 Number of Video Codecs 0
2015 01 05 14:59:58.111 Number of Video Frame Rates 0
2015 01 05 14:59:58.111 Number of Containers 0
Status change SIGNAL 'Recording is requested but not active yet.'
```

