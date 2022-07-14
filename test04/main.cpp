
#include<iostream>
#include"show.h"
#include<string>

int main()
{
	std::string filename = "/home/user/xyoung/Infer_Lib/CmakeDemo/test1.jpg";
	std::vector<std::vector<float>>  results;
	std::string mnnfile = "./mnn_demo/mnn_model/yolov5n.mnn";

	imgShow(filename);
	// cv::Mat img = cv::imread(filename);

	// cv::imshow("show", img);
	// cv::waitKey(0);
	return 0;
}