#ifndef MAINWINDOW_H_CGQ
#define MAINWINDOW_H_CGQ

#include <QMainWindow>
#include "OpenCV/HelloWorld/views/CHelloWorldView.h"
#include "OpenCV/CPhotoShop/views/CPhotoShopView.h"
#include "OpenCV/CVImageFunc/views/CImageFuncView.h"

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
    CPhotoShopView *mCutImgView;
    CImageFuncView *mTestView;

public slots:
    void onHelloWorldBtnClick();
    void onCutImgBtnClick();
    void onTestBtnClick();
    void initData();
};

#endif // MAINWINDOW_H_CGQ
