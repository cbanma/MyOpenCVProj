//
// Created by CGQ on 2018/2/10.
//

#include <sys/socket.h>
#include "CHelloWorldView.h"
#include "OpenCV/HelloWorld/opencv/showImage.hpp"


CHelloWorldView::CHelloWorldView() : CBaseView() {
    initView();
    if(mDialog != NULL) {
        mDialog->show();
    }
    mBaseOpenCV = new showImage();

}



void CHelloWorldView::initView() {
    createButton("原始图片",0,0);
    createButton("showRoiImage",150,0);
    createButton("showRangeMage",300,0);

    createButton("showSobelMage",0,50);
    createButton("showSobelMageFull",150,50);
    createButton("退出程序",400,460);

}

void CHelloWorldView::onBtnClick()
{
    QString buttonName = sender()->objectName();
    string strName = buttonName.toStdString();
    cout << "KeyBtnClick:"<< strName <<endl;

    switch(CUtils::hash_(strName.data())){
        case "原始图片"_hash:
            mBaseOpenCV->showImage();
            break;
        case "showRoiImage"_hash:
            mBaseOpenCV->showRoiMage();
            break;
        case "showRangeMage"_hash:
            mBaseOpenCV->showRangeMage();
            break;
        case "showSobelMage"_hash:
            mBaseOpenCV->showSobelMage();
            break;
        case "showSobelMageFull"_hash:
            mBaseOpenCV->showSobelMageFull();
        case "退出程序"_hash:
            exit(0);
        default:
            cout << "Default..." << endl;
            break;
    }
}
