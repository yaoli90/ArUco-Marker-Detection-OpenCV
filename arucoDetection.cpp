#include "arucoDetection.h"

void arucoMarker::createArucoMarkers(const std::string dir) {
	cv::Mat outputMarker;
	for (int i = 0; i < 50; i++) {
		cv::aruco::drawMarker(this->markerDictionary, i, 500, outputMarker, 1);
		std::string imageName = dir + "\\4x4Marker_" + std::to_string(i) + ".png";
		cv::imwrite(imageName, outputMarker);
	}
}

void arucoMarker::detectArucoMarkers(cv::Mat& frame, const cv::Mat& cameraMatrix, const cv::Mat& distCoefficients, const float arucoSquareSizeMM) {
	if (this->cameraMatrix.empty())
		this->cameraMatrix = cameraMatrix;
	if (this->distCoefficients.empty())
		this->distCoefficients = distCoefficients;
	if (this->arucoSquareSizeMM == 0)
		this->arucoSquareSizeMM = arucoSquareSizeMM;

	cv::aruco::detectMarkers(frame, this->markerDictionary, this->markerCorners, this->markerIDs);
	cv::aruco::estimatePoseSingleMarkers(this->markerCorners, this->arucoSquareSizeMM, this->cameraMatrix, this->distCoefficients, this->rvecs, this->tvecs);
	for (unsigned i = 0; i < markerIDs.size(); i++)
		cv::aruco::drawAxis(frame, this->cameraMatrix, this->distCoefficients, this->rvecs[i], this->tvecs[i], 50.0f);
}


