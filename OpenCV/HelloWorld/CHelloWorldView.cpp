//
// Created by CGQ on 2018/2/10.
//

#include <sys/socket.h>
#include "CHelloWorldView.h"
#include "./showImage.hpp"
#include "utils.hpp"


CHelloWorldView::CHelloWorldView() {
    initView();
    mDialog->show();
}



void CHelloWorldView::initView() {
    createDialog();
    createButton("原始图片",0,0);
    createButton("showRoiImage",150,0);
    createButton("showRangeMage",300,0);

    createButton("showSobelMage",0,50);
    createButton("showSobelMageFull",150,50);
}



void CHelloWorldView::createDialog() {
    mDialog =new QDialog;
    mDialog->setFixedSize(500,500);
    //mDialog->setModal(true);≈
}


void CHelloWorldView::createButton(QString name, int x, int y) {
    QPushButton * showImageBtn;
    showImageBtn = new QPushButton(name,mDialog);
    showImageBtn->setObjectName(name);
    showImageBtn->move(x,y);
    connect(showImageBtn, SIGNAL(clicked()), this, SLOT(onBtnClick()));
}

void CHelloWorldView::onBtnClick()
{
    QString buttonName = sender()->objectName();
    string strName = buttonName.toStdString();
    cout << "KeyBtnClick:"<< strName <<endl;

    switch(hash_(strName.data())){
        case "原始图片"_hash:
            showImage();
            break;
        case "showRoiImage"_hash:
            showRoiMage();
            break;
        case "showRangeMage"_hash:
            showRangeMage();
            break;
        case "showSobelMage"_hash:
            showSobelMage();
            break;
        case "showSobelMageFull"_hash:
            showSobelMageFull();
            break;
        default:
            cout << "Default..." << endl;
    }
}


