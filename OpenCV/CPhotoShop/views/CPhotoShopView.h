//
// Created by CGQ on 2018/6/30.
//

#ifndef MYOPENCVPROJS_CCUTIMGVIEW_H
#define MYOPENCVPROJS_CCUTIMGVIEW_H

#include "OpenCV/BaseView/CBaseView.h"

class CPhotoShopView :public CBaseView{
Q_OBJECT
public:
    CPhotoShopView();
    ~CPhotoShopView();
    void initView();

private slots:
    void onBtnClick();
};

#endif //MYOPENCVPROJS_CCUTIMGVIEW_H
