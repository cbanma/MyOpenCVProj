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
#include "../../res/text/textDef.h"
#include "../BaseOpenCv/CBaseOpenCV.h"

class CBaseView :public QObject{
public:
    CBaseView();
    virtual ~CBaseView();


    void initData();
    void createDialog();
    void createButton(QString name,int x = 0,int y = 0);

    void releaseCv();
    virtual void initView() = 0;
    virtual void onBtnClick() = 0;
    QDialog *mDialog;
    CBaseOpenCV *mBaseOpenCV;
};


#endif //MYOPENCVPROJS_CBASEVIEW_H
