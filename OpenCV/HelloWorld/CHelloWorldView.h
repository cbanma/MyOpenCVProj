//
// Created by CGQ on 2018/2/10.
//

#ifndef MYOPENCVPROJS_CSHOWIMAGEVIEW_H_CGQ
#define MYOPENCVPROJS_CSHOWIMAGEVIEW_H_CGQ
#include <QDialog>
#include <QObject>
#include <QPushButton>

class CHelloWorldView :public QObject{
    Q_OBJECT
public:
    typedef void (*BTN_CB)();

    QDialog *mDialog;
    CHelloWorldView();
    void initView();
    void createDialog();
    void createButton(QString name,int x = 0,int y = 0);
private slots:
    void onBtnClick();

};


#endif //MYOPENCVPROJS_CSHOWIMAGEVIEW_H_CGQ
