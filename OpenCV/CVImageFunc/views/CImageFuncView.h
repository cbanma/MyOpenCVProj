//
// Created by CGQ on 2018/6/30.
//

#ifndef MYOPENCVPROJS_CTESTVIEW_H
#define MYOPENCVPROJS_CTESTVIEW_H

#include "OpenCV/BaseView/CBaseView.h"

class CImageFuncView :public CBaseView{
Q_OBJECT
public:
    CImageFuncView();
    ~CImageFuncView();
    void initView();

private slots:
    void onBtnClick();
};

#endif //MYOPENCVPROJS_CTESTVIEW_H
