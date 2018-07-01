//
// Created by CGQ on 2018/6/30.
//
//https://blog.csdn.net/c80486/article/details/51867128
#include "CPhotoShopView.h"
#include "OpenCV/CPhotoShop/opencv/CCutImage.hpp"
#include "OpenCV/CPhotoShop/opencv/CRotateImg.hpp"
CCutImage *g_pCutImage;
CRotateImg *g_pRotateImg;

CPhotoShopView::CPhotoShopView() {
    initView();
    if(mDialog != NULL) {
        mDialog->show();
    }
    g_pCutImage = new CCutImage();
    g_pRotateImg = new CRotateImg();

}

void CPhotoShopView::initView() {
    createButton("原始图片",0,0);
    createButton("图片剪切",120,0);
    createButton("图片旋转",240,0);
}

void CPhotoShopView::onBtnClick() {
    QString buttonName = sender()->objectName();
    string strName = buttonName.toStdString();
    cout << "KeyBtnClick:"<< strName <<endl;

    switch(CUtils::hash_(strName.data())){
        case "原始图片"_hash:
            g_pCutImage->showImage();
            break;
        case "图片剪切"_hash:
            //(dynamic_cast<CCutImage*> (mBaseOpenCV))->showCutImageView();
            g_pCutImage->showCutImageView();
            break;
        case "图片旋转"_hash:
            g_pRotateImg->showRoateImage();
            break;
        default:
            cout << "Default..." << endl;
    }
}

CPhotoShopView::~CPhotoShopView() {
    CBaseView::~CBaseView();
    if(g_pCutImage){
        delete (g_pCutImage);
    }

    if(g_pRotateImg){
        delete (g_pRotateImg);
    }
}
