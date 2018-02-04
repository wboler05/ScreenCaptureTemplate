#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QImage>
#include <QDebug>
#include <QScreen>

#include <windows.h>
#include <Winuser.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void captureScreenBtn();

private:
    Ui::MainWindow *ui;

    void captureScreen();
};

#endif // MAINWINDOW_H
