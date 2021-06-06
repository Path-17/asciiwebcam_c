
/*
    Text detection model: https://github.com/argman/EAST
    Download link: https://www.dropbox.com/s/r2ingd0l3zt8hxs/frozen_east_text_detection.tar.gz?dl=1
    Text recognition models can be downloaded directly here:
    Download link: https://drive.google.com/drive/folders/1cTbQ3nuZG-EKWak6emD_s8_hHXWz7lAr?usp=sharing
    and doc/tutorials/dnn/dnn_text_spotting/dnn_text_spotting.markdown
    How to convert from pb to onnx:
    Using classes from here: https://github.com/meijieru/crnn.pytorch/blob/master/models/crnn.py
    import torch
    from models.crnn import CRNN
    model = CRNN(32, 1, 37, 256)
    model.load_state_dict(torch.load('crnn.pth'))
    dummy_input = torch.randn(1, 1, 32, 100)
    torch.onnx.export(model, dummy_input, "crnn.onnx", verbose=True)
    For more information, please refer to doc/tutorials/dnn/dnn_text_spotting/dnn_text_spotting.markdown and doc/tutorials/dnn/dnn_OCR/dnn_OCR.markdown
*/
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