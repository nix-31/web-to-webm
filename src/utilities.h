#ifndef UTILITIES_H
#define UTILITIES_H

#include "mainwindow.h"
#include "downloader.h"
#include "converter.h"

#include <QMainWindow>
#include <QProcess>
#include <QSettings>

#ifdef _WIN32
    #define SYSTEM 0
#elif __APPLE__
    #define SYSTEM 1
#else
    #define SYSTEM 2
#endif

class Utilities : public QObject
{
    Q_OBJECT

public:
    Utilities();

    QSettings settings;

    QString getBinaryName();
    QString getVideoTitle(QString url);
    QString getVideoID(QString url);
    QString getVideoQuality();
    QString getFileName();
    QString ffmpegBinaryName();
    QString getCurrentRawFilename();
    QString getCurrentFilename();
    QString execBinary(QString bin, int multiline);
    QString prepareUrl(QString url);
    QString getDefaultFilename();

    bool checkUrl();
    void setCommons();
    void startConversionProcess();
    void killProcesses();
    void addToLog(QString line, bool display = true);
    void removeRawVideo();
    void configInit();
    void configSetValue(QString k, QString v);
    void configSetValueIfBlank(QString k, QString v);
    void showFileInDirectory();
    void configSaveAll();
    void configLoadAll();
    void loadVideo(QString url);

    QString configGetValue(QString k);
    bool configGetValueBool(QString k);

    bool checkBinaries();

    int getTrimmedVideoDuration();
    QTime parseTime(QString s);

    int currentDuration;
    bool pathChanged;
    bool killed;

    QString defaultFilename;
    QString currentID;
    QString currentVideoUrl;
    QString currentSavePath;
    QString currentFileName;
    QString log;

    QVector<QVector <QString> > createQualityList(QString url);
    QVector<QVector <QString> > currentQualityList;

    QProcess *downloadProcess;
    QProcess *conversionProcess;

    Downloader download;
    Converter convert;

};

extern Utilities utils;

#endif // UTILITIES_H
