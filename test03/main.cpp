
#include<iostream>
#include"show.h"
// #include "opencv2/opencv.hpp"
#include<string>

int main()
{
	std::string filename = "/home/user/Infer_Lib/mnn_demo/test1.jpg";
	std::vector<std::vector<float>>  results;
	std::string mnnfile = "./mnn_demo/mnn_model/yolov5n.mnn";

	imgShow(filename);
	// cv::Mat img = cv::imread(filename);

	// cv::imshow("show", img);
	// cv::waitKey(0);
	return 0;
}