#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initData();
    connect(ui->helloWorldBtn, SIGNAL(clicked()), this, SLOT(onHelloWorldBtnClick()));
    connect(ui->cutImgButton, SIGNAL(clicked()), this, SLOT(onCutImgBtnClick()));
}
void MainWindow::initData(){
    mHelloWorldView = NULL;
    mCutImgView = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    if(mHelloWorldView != NULL){
        delete(mHelloWorldView);
    }
    if(mCutImgView != NULL){
        delete(mCutImgView);
    }
}

void MainWindow::onHelloWorldBtnClick() {
    mHelloWorldView = new CHelloWorldView();
    //this->showMinimized();
}

void MainWindow::onCutImgBtnClick() {
    this->showMinimized();
    mCutImgView = new CPhotoShopView();
    mCutImgView->mDialog->setStyleSheet("background-color: green");
}
