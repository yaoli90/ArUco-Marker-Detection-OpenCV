#ifndef ARUCODETECTION_H
#define ARUCODETECTION_H
#include <opencv2/aruco.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>

class arucoMarker {
public:
	cv::Mat cameraMatrix;
	cv::Mat distCoefficients;
	float arucoSquareSizeMM = 0;

	std::vector<int> markerIDs;
	std::vector<cv::Vec3d> rvecs, tvecs;
	cv::Ptr<cv::aruco::Dictionary> markerDictionary = cv::aruco::getPredefinedDictionary(cv::aruco::PREDEFINED_DICTIONARY_NAME::DICT_4X4_50);

	void createArucoMarkers(const std::string dir = "arucoMarkers");
	void detectArucoMarkers(cv::Mat& frame, const cv::Mat& cameraMatrix, const cv::Mat& distCoefficients, const float arucoSquareSizeMM);
private:
	std::vector<std::vector<cv::Point2f>> markerCorners;
};

#endif

