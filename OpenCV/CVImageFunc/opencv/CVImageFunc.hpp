//
// Created by CGQ on 2018/2/8.
//

#ifndef MYOPENCVPROJS_EASYCV_H
#define MYOPENCVPROJS_EASYCV_H
#include <iostream>
#include "../../BaseOpenCv/CBaseOpenCV.h"
using namespace std;


class CVImageFunc :public CBaseOpenCV{
public:
    CVImageFunc(){
        window_name = "测试画面";
    }

    Mat initImage(bool bIsShow){
        Mat  srcImage = imread(getResPath() + "cat.jpg");
        if(bIsShow) {
            showImage("init image", srcImage);
        }
        return srcImage;
    }


    Mat getErodeImage(){
        Mat srcImage = initImage(false);
        //返回指定形状的的元素
        Mat element = getStructuringElement(MORPH_ELLIPSE, Size(20, 20));
        Mat destImage ;
        erode(srcImage, destImage, element);
        return destImage;
    }

    Mat getBlurImage(int width,int height){
        Mat srcImage = initImage(false);
        Mat destImage ;
        //均值滤波操作
        blur(srcImage, destImage, Size(width,height));
        return destImage;
    }

    Mat getCannyImage(){
        Mat srcImage = initImage(false);
        Mat destImage,edge,grayImage;

        //create a image same size of initImage  with Rect
        destImage.create(srcImage.size(),srcImage.type());

        //转换为灰度图片
        cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);

        blur(grayImage, edge, Size(3, 3));
        Canny(edge, edge, 3, 9, 3);

        return  edge;

    }

    Mat createImage() {
        Mat mat(600, 1200, CV_8UC4);
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                Vec4b &rgba = mat.at<Vec4b>(i, j);
                rgba[0] = UCHAR_MAX;
                rgba[1] = saturate_cast<uchar>((float(mat.cols - j)) / ((float) mat.cols) * UCHAR_MAX);
                rgba[2] = saturate_cast<uchar>((float(mat.rows - i)) / ((float) mat.rows) * UCHAR_MAX);
                rgba[3] = saturate_cast<uchar>(0.5 * rgba[1] + rgba[2]);
            }
        }

        vector<int> compression_params;
        compression_params.push_back(IMWRITE_PNG_COMPRESSION);
        compression_params.push_back(9);
        try {
            imwrite("alpha.png", mat, compression_params);
            return mat;
        }
        catch (runtime_error &ex) {
            return mat;
        }
    }

    void showErodeImage(){
        Mat initImages = initImage(false);
        Mat erodeImage =getErodeImage();
        Mat mergeImage = mergeImg(initImages, erodeImage);
        showImage("图像腐蚀", mergeImage);
    }

    void showBlurImage(int width,int height){
        Mat initImages = initImage(false);
        Mat blurImage =getBlurImage(width,height);
        Mat mergeImage = mergeImg(initImages, blurImage);
        showImage("图像模糊", mergeImage);
    }

    void showCannyImage(){
        Mat initImages = initImage(false);
        Mat tempImage =getCannyImage();
        //Mat mergeImage = mergeImg(initImages, tempImage);
        //todo
        showImage("边缘检测", tempImage);
    }

    void showCreateImage(){
        Mat image = createImage();
        showImage("创建图片", image);
    }
};

#endif //MYOPENCVPROJS_EASYCV_H
