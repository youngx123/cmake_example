
#include<iostream>
#include <string>
#include<vector>
#include "opencv2/opencv.hpp"
#include "MNN_Infer.h"

int main()
{
	std::string filename = "/home/user/xyoung/Infer_Lib/CmakeDemo/test1.jpg";
	std::vector<std::vector<float>>  results;
	std::string mnnfile = "/home/user/xyoung/Infer_Lib/CmakeDemo/test05/mnn_model/yolov5n.mnn";

	cv::Mat InputImage = cv::imread(filename);
	detection(mnnfile, InputImage, results);
	return 0;
}