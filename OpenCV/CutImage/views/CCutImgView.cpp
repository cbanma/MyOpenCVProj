//
// Created by CGQ on 2018/6/30.
//

#include "CCutImgView.h"
#include "../opencv/cutImage.hpp"

CCutImgView::CCutImgView() {
    initView();
    if(mDialog != NULL) {
        mDialog->show();
    }

    mBaseOpenCV = new  cutImage();
}

void CCutImgView::initView() {
    createButton("原始图片",0,0);
    createButton("剪切图片",150,0);
}

void CCutImgView::onBtnClick() {
    QString buttonName = sender()->objectName();
    string strName = buttonName.toStdString();
    cout << "KeyBtnClick:"<< strName <<endl;

    switch(CUtils::hash_(strName.data())){
        case "原始图片"_hash:
            mBaseOpenCV->showImage();
            break;
        case "剪切图片"_hash:
            break;
        default:
            cout << "Default..." << endl;
    }
}
