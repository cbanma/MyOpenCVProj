//
// Created by CGQ on 2018/6/30.
//

#ifndef MYOPENCVPROJS_CBASEOPENCV_H
#define MYOPENCVPROJS_CBASEOPENCV_H

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class CBaseOpenCV {
public:
    string getResPath();
    void showImage(string name,Mat & srcImage);
    Mat initImage(bool bIsShow);
    Mat roiImage(Mat & srcImage,bool bIsShow);
    void rangeImage(Mat & srcImage,bool bIsShow);
    void sobelImage(Mat & srcImage, bool bIsShow);

    virtual  void showImage();
    virtual  void showRoiMage();
    virtual  void showRangeMage();
    virtual  void showSobelMage();
    virtual  void showSobelMageFull();
};


#endif //MYOPENCVPROJS_CBASEOPENCV_H
