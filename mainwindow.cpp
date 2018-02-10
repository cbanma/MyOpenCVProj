#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initData();
    connect(ui->helloWorldBtn, SIGNAL(clicked()), this, SLOT(onHelloWorldBtnClick()));
}
void MainWindow::initData(){
    mHelloWorldView = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    if(mHelloWorldView != NULL){
        delete(mHelloWorldView);
    }
}

void MainWindow::onHelloWorldBtnClick() {
    mHelloWorldView = new CHelloWorldView();
    this->showMinimized();
}
