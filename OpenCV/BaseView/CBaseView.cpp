//
// Created by CGQ on 2018/2/12.
//

#include "CBaseView.h"

CBaseView::CBaseView() {
    initData();
    createDialog();
}

void CBaseView::createDialog() {
    mDialog =new QDialog;
    mDialog->setFixedSize(500,500);
    //mDialog->setModal(true);
}

CBaseView::~CBaseView() {
    if(mDialog != NULL) {
        delete (mDialog);
    }
}


void CBaseView::createButton(QString name, int x, int y) {
    QPushButton * showImageBtn;
    showImageBtn = new QPushButton(name,mDialog);
    showImageBtn->setObjectName(name);
    showImageBtn->move(x,y);
    connect(showImageBtn, SIGNAL(clicked()), this, SLOT(onBtnClick()));
}

void CBaseView::initData() {
    mDialog = NULL;
    mBaseOpenCV = NULL;
}

void CBaseView::releaseCv() {
    if(mBaseOpenCV != NULL){
        delete (mBaseOpenCV);
    }
}

