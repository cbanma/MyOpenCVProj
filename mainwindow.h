#ifndef MAINWINDOW_H_CGQ
#define MAINWINDOW_H_CGQ

#include <QMainWindow>
#include "OpenCV/HelloWorld/CHelloWorldView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CHelloWorldView *mHelloWorldView;

public slots:
    void onHelloWorldBtnClick();
    void initData();
};

#endif // MAINWINDOW_H_CGQ
