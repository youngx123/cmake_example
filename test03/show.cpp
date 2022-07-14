

#include "show.h"

void imgShow(std::string filename)
{
	cv::Mat img = cv::imread(filename);

	cv::imshow("show", img);
	cv::waitKey(0);
}