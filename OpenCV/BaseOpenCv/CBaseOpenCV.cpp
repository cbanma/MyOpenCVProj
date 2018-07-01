//
// Created by CGQ on 2018/6/30.
//

#include "CBaseOpenCV.h"


string CBaseOpenCV::getResPath() {
    return "../res/image/";
}

void CBaseOpenCV::showImage(string name,Mat & srcImage){
    imshow(name, srcImage);
    waitKey(0);
    if( cvWaitKey(27) <= 0 ){
        cv::destroyWindow(name);
    }
}

Mat CBaseOpenCV::initImage(bool bIsShow){
    Mat  srcImage = imread(getResPath() + "show.png");
    if(bIsShow) {
        showImage("init image", srcImage);
    }
    return srcImage;
}


Mat CBaseOpenCV::roiImage(Mat & srcImage,bool bIsShow) {
    Rect roiRect(350, 240, 760, 820);
    Mat roiMat(srcImage, roiRect);
    if (bIsShow) {
        showImage("roiImage", roiMat);
    }

    return roiMat;
}

void CBaseOpenCV::rangeImage(Mat & srcImage,bool bIsShow){
    Mat roiMat2 = srcImage(Range::all(), Range(240, 620+240));
    if(bIsShow) {
        showImage("roiImage2", roiMat2);
    }
}

void CBaseOpenCV::sobelImage(Mat & srcImage, bool bIsShow) {
    Sobel(srcImage, srcImage, CV_8U, 1, 1);
    if (bIsShow) {
        showImage("sobelImage", srcImage);
    }
}


void CBaseOpenCV::showImage(){
    initImage(true);
    waitKey(0);
}

void CBaseOpenCV::showRoiMage(){
    Mat  srcImage = initImage(false);
    Mat roiMat = roiImage(srcImage,true);
    waitKey(0);
}

void CBaseOpenCV::showRangeMage(){
    Mat  srcImage = initImage(false);
    Mat roiMat = roiImage(srcImage, false);
    rangeImage(srcImage,true);
}

void CBaseOpenCV::showSobelMage(){
    Mat  srcImage = initImage(false);
    Mat roiMat = roiImage(srcImage, false);
    sobelImage(roiMat, true);
}

void CBaseOpenCV::showSobelMageFull(){
    Mat  srcImage = initImage(false);
    Mat roiMat = roiImage(srcImage, false);
    rangeImage(srcImage, false);
    sobelImage(roiMat, false);
    showImage ("roiImage",srcImage);
}

