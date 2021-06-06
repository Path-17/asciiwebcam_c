
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

const int fps = 20;

int main(int argc, char** argv){

    cv::Mat frame;

    cv::VideoCapture vid(0);
    vid.set(cv::CAP_PROP_FPS, 30);

    if(!vid.isOpened()){
        return -1;
    }
    while(vid.read(frame)){
        std::cout << frame.shape << std::endl;
        cv::imshow("Webcam", frame);
        cv::waitKey(33);
    }

    return 0;
}