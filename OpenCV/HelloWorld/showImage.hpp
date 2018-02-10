//
// Created by CGQ on 2018/2/8.
//

#ifndef MYOPENCVPROJS_SHOWIMAGE_H
#define MYOPENCVPROJS_SHOWIMAGE_H

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void showImage(string name,Mat & srcImage){
    imshow(name, srcImage);
    waitKey(0);
    if( cvWaitKey(27) <= 0 ){
        cv::destroyWindow(name);
    }
}

Mat initImage(bool bIsShow){
    Mat  srcImage = imread("show.png");
    if(bIsShow) {
        showImage("init image", srcImage);
    }
    return srcImage;
}


Mat roiImage(Mat & srcImage,bool bIsShow) {
    Rect roiRect(240, 300, 620, 480);
    Mat roiMat(srcImage, roiRect);
    if (bIsShow) {
        showImage("roiImage", roiMat);
    }

    return roiMat;
}

void rangeImage(Mat & srcImage,bool bIsShow){
    Mat roiMat2 = srcImage(Range::all(), Range(240, 620+240));
    if(bIsShow) {
        showImage("roiImage2", roiMat2);
    }
}

void sobelImage(Mat & srcImage, bool bIsShow) {
    Sobel(srcImage, srcImage, CV_8U, 1, 1);
    if (bIsShow) {
        showImage("sobelImage", srcImage);
    }
}

//int showImage() {
//    Mat  srcImage = initImage();
//
//    Mat roiMat = roiImage(srcImage);
//    rangeImage(srcImage);
//    sobelImage(roiMat);
//    showImage ("roiImage",srcImage);
//    waitKey(0);
//    return 0;
//}

void showImage(){
    initImage(true);
    waitKey(0);
}

void showRoiMage(){
    Mat  srcImage = initImage(false);
    Mat roiMat = roiImage(srcImage,true);
    waitKey(0);
}

    void showRangeMage(){
    Mat  srcImage = initImage(false);
    Mat roiMat = roiImage(srcImage, false);
    rangeImage(srcImage,true);
}

void showSobelMage(){
    Mat  srcImage = initImage(false);
    Mat roiMat = roiImage(srcImage, false);
    sobelImage(roiMat, true);
}

void showSobelMageFull(){
    Mat  srcImage = initImage(false);
    Mat roiMat = roiImage(srcImage, false);
    rangeImage(srcImage, false);
    sobelImage(roiMat, false);
    showImage ("roiImage",srcImage);
}

#endif //MYOPENCVPROJS_SHOWIMAGE_H
