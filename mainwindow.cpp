#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(captureScreenBtn()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::captureScreenBtn() {
    static volatile bool clickedFlag = false;
    if (clickedFlag) {
        return;
    } else {
        clickedFlag = true;
        captureScreen();
        clickedFlag = false;
    }
}

void MainWindow::captureScreen() {

    QList<QScreen *> screens = QGuiApplication::screens();
    QScreen * primaryScreen = QGuiApplication::primaryScreen();

    int numberOfScreens = screens.length();

    QPixmap pixMap = primaryScreen->grabWindow(0, 0, 0);
/*
    QSize monitorSize;
    monitorSize.setWidth(GetSystemMetrics(SM_CXSCREEN));
    monitorSize.setHeight(GetSystemMetrics(SM_CYSCREEN));

    HWND hDesktopWindow = GetDesktopWindow();
    HDC hDesktopDC = GetDC(hDesktopWindow);
    HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
    HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC, monitorSize.width(), monitorSize.height());
    SelectObject(hCaptureDC, hCaptureBitmap);

    BitBlt(hCaptureDC, 0, 0, monitorSize.width(), monitorSize.height(), hDesktopDC, 0, 0, SRCCOPY|CAPTUREBLT);

    QPixmap pixMap = QPixmap::fr
*/
    qDebug() << "Number of screens: " << numberOfScreens;
    qDebug() << "Screen Size: " << pixMap.size();


    // Cleanup
//    ReleaseDC(hDesktopWindow, hDesktopDC);
//    DeleteDC(hCaptureDC);

    ui->viewWidget->updateImage(pixMap);
}
