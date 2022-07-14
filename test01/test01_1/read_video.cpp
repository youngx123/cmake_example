#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
        std::string videoName = "/home/user/xyoung/Infer_Lib/CmakeDemo/test06/HighwayIII_Original_sequence.avi";
        cv::VideoCapture cap;
        cv::Mat frame;
        frame= cap.open(videoName);

       double fps =  cap.get(cv::CAP_PROP_FPS);
        if(!cap.isOpened())
        {
                printf("can not open ...\n");
                return -1;
        }
        cv::namedWindow("output", CV_WINDOW_AUTOSIZE);
        int num = 1;
        while (cap.read(frame))
        {
                std::string showstr = std::to_string(num);
                cv::putText(frame, showstr, cv::Point(50,100),1,2, cv::Scalar(255,0,0));
                cv::imshow("output", frame);
                cv::waitKey((int)(1000/fps));
                num ++;
        }
        cap.release();
        return 0;
}