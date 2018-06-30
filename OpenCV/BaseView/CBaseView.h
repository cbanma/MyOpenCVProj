//
// Created by CGQ on 2018/2/12.
//

#ifndef MYOPENCVPROJS_CBASEVIEW_H
#define MYOPENCVPROJS_CBASEVIEW_H
#include <QDialog>
#include <QObject>
#include <QPushButton>
#include <QPainter>
#include "CUtils.hpp"
#include "../BaseOpenCv/CBaseOpenCV.h"

class CBaseView :public QObject{
public:
    CBaseView();
    ~CBaseView();


    void initData();
    void createDialog();
    void createButton(QString name,int x = 0,int y = 0);

    virtual void initView() = 0;
    virtual void onBtnClick() = 0;
    QDialog *mDialog;
    CBaseOpenCV *mBaseOpenCV;
};


#endif //MYOPENCVPROJS_CBASEVIEW_H
