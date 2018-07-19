//
// Created by CGQ on 2018/2/8.
//

#ifndef MYOPENCVPROJS_CVCALLBACK_H
#define MYOPENCVPROJS_CVCALLBACK_H
#include <iostream>
#include "../../BaseOpenCv/CBaseOpenCV.h"
using namespace std;


class CVCallBack :public CBaseOpenCV{
public:
    CVCallBack(){
        window_name = "callback";
    }

    Mat initImage(bool bIsShow = false){
        Mat  srcImage = imread(getResPath() + "cat.jpg");
        if(bIsShow) {
            showImage("init image", srcImage);
        }
        return srcImage;
    }

    static void onTrackBar(int position,void * data){
        cout<<"onTrackBar "<<position<<" "<<endl;
        Mat  srcImage = imread("../res/image/cat.jpg");

        int pos = getTrackbarPos("滑动条", window_name);
        if(position == 0 ){
            return;
        }
        for (int i = 0; i < srcImage.rows; ++i) {
            for (int j = 0; j < srcImage.cols; ++j) {
                Vec4b &rgba = srcImage.at<Vec4b>(i, j);
                rgba[0] = saturate_cast<uchar>(255-rgba[0]*position);
                rgba[1] = saturate_cast<uchar>(255-rgba[1]*position);
                rgba[2] = saturate_cast<uchar>(255-rgba[2]*position);
                rgba[3] = saturate_cast<uchar>(255-rgba[3]*position);
            }
        }

        imshow(window_name, srcImage);
    }

    void createImageWithCallBack(){
        int trackBarValue = 1;
        int maxTrackBarNumber = 100;
        namedWindow(window_name,1);
        char trackBarName[50] = "滑动条";

        setMouseCallback(window_name,onMouseEvent,NULL);


        createTrackbar(trackBarName, window_name, &trackBarValue,maxTrackBarNumber,onTrackBar);
        onTrackBar(trackBarValue,0);
        waitKey(0);
    }

    static void onMouseEvent(int event,int x,int y,int flags,void *param){
        //cout<<"onMouseEvent "<<"event "<<event<<endl;
        switch (event)
        {
            case EVENT_MOUSEMOVE:
                cout<<"鼠标移动"<<endl;
                break;
            case EVENT_FLAG_LBUTTON:
                cout<<"左键压下"<<endl;
                break;
            case EVENT_LBUTTONUP:
                cout<<"左键抬起"<<endl;
                break;
            case EVENT_FLAG_RBUTTON:
                cout<<"右键压下"<<endl;
                break;
            case EVENT_RBUTTONUP:
                cout<<"右键抬起"<<endl;
                break;
        }
    }
};

#endif //MYOPENCVPROJS_CVCALLBACK_H
