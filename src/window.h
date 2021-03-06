#ifndef WINDOW_H
#define WINDOW_H

#include "mainwindow.h"

class Window
{
public:
    Window();
    Ui::MainWindow *ui;

    void setQualityList();
    void setVideoDetails(QString url);
    void reset();
    void resetProgress();
    void setFilename();
    void lockAllControls(bool status);
    void setTheme();
    void setStylesheet();
    void updateConversionButton();
    void toggleConversionButton();
    void setPlayerHtml();
    void setLoaderHtml();
    void openUrlInPlayer(QString url);
    void setLightMode(MainWindow *mw);
    void detectMode(MainWindow *mw);
    bool isModeLight();
};

extern Window win;

#endif // WINDOW_H
