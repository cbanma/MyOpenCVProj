#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void showImage(string name,Mat & srcImage){
    imshow(name, srcImage);
}

Mat initImage(){
    Mat  srcImage = imread("show.png");
    //showImage("init image",srcImage);
    return srcImage;
}


Mat roiImage(Mat & srcImage){
    Rect roiRect(240,300,620,480);
    Mat roiMat(srcImage,roiRect);
    //showImage ("roiImage",roiMat);

    return roiMat;
}

void rangeImage(Mat & srcImage){
    Mat roiMat2 = srcImage(Range::all(), Range(240, 620+240));
    //showImage ("roiImage2",roiMat2);
}

void sobelImage(Mat & srcImage){
    Sobel(srcImage,srcImage,CV_8U,1,1);
    //showImage ("sobelImage",srcImage);
}

int main() {
    Mat  srcImage = initImage();

    Mat roiMat = roiImage(srcImage);
    rangeImage(srcImage);
    sobelImage(roiMat);
    showImage ("roiImage",srcImage);
    waitKey(0);
    return 0;
}
