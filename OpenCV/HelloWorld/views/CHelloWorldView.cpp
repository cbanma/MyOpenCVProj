//
// Created by CGQ on 2018/2/10.
//

#include <sys/socket.h>
#include "CHelloWorldView.h"
#include "OpenCV/HelloWorld/opencv/showImage.hpp"
#include "utils.hpp"


CHelloWorldView::CHelloWorldView() : CBaseView() {
    initView();
    if(mDialog != NULL) {
        mDialog->show();
    }

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
        case "退出程序"_hash:
            exit(0);
            break;
        default:
            cout << "Default..." << endl;
    }
}
