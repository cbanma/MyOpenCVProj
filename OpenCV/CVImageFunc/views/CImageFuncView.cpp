//
// Created by CGQ on 2018/6/30.
//
#include "CImageFuncView.h"
#include "OpenCV/CVImageFunc/opencv/CVImageFunc.hpp"
#include "OpenCV/CVImageFunc/opencv/CCVCallBack.hpp"
CVImageFunc * g_cvImageFunc;
CVCallBack * g_cvCallBack;

CImageFuncView::CImageFuncView() {
    initView();
    if(mDialog != NULL) {
        mDialog->show();
    }

    g_cvImageFunc = new CVImageFunc();
    g_cvCallBack = new CVCallBack();

}

void CImageFuncView::initView() {
    createButton("图像腐蚀",0,0);
    createButton("图像模糊",120,0);
    createButton("边缘检测",240,0);
    createButton("创建图片",360,0);
    createButton("回调函数",0,80);
}

void CImageFuncView::onBtnClick() {
    QString buttonName = sender()->objectName();
    string strName = buttonName.toStdString();
    cout << "KeyBtnClick:"<< strName <<endl;

    switch(CUtils::hash_(strName.data())){
        case "图像腐蚀"_hash:
            g_cvImageFunc->showErodeImage();
            break;
        case "图像模糊"_hash:
            g_cvImageFunc->showBlurImage(10,10);
            break;
        case "边缘检测"_hash:
            g_cvImageFunc->showCannyImage();
            break;
        case "创建图片"_hash:
            g_cvImageFunc->showCreateImage();
            break;
        case "回调函数"_hash:
            g_cvCallBack->createImageWithCallBack();
            break;
        default:
            cout << "Default..." << endl;
            break;
    }
}

CImageFuncView::~CImageFuncView() {
    CBaseView::~CBaseView();
    if(g_cvImageFunc){
        delete (g_cvImageFunc);
    }
    if(g_cvCallBack){
        delete (g_cvCallBack);
    }
}
