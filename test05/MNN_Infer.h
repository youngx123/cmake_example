#include<opencv2/opencv.hpp>

#include "MNN/Interpreter.hpp"
#include "MNN/Tensor.hpp"
#include "MNN/MNNDefine.h"
#include "MNN/ImageProcess.hpp"

#include <sstream>
#include <iomanip>
#include<string>
#include<vector>
void detection( std::string files, cv::Mat imgfile,std::vector<std::vector<float>> &results);
void runSession(std::shared_ptr<MNN::Interpreter> model, MNN::Session *session, cv::Mat &image,
                cv::Mat &org_image, float scaleh,float scalew, std::vector<std::vector<float>> &results);
