//
// Created by CGQ on 2018/2/10.
//

#ifndef MYOPENCVPROJS_CSHOWIMAGEVIEW_H_CGQ
#define MYOPENCVPROJS_CSHOWIMAGEVIEW_H_CGQ
#include "../BaseView/CBaseView.h"


class CHelloWorldView :public CBaseView{
    Q_OBJECT
public:

    CHelloWorldView();
    void initView();
private slots:
    void onBtnClick();

};


#endif //MYOPENCVPROJS_CSHOWIMAGEVIEW_H_CGQ
