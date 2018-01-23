#include "arucoDetection.h"

void main() {

	cv::FileStorage cameraCalibrationStream("cam_.xml", cv::FileStorage::READ);
	cv::Mat K, D;
	cv::Size imageSize;
	cameraCalibrationStream["K"] >> K;
	cameraCalibrationStream["D"] >> D;
	cameraCalibrationStream["imageSize"] >> imageSize;

	arucoMarker markers;
	//markers.createArucoMarkers();

	cv::VideoCapture cap(0);
	cv::Mat frame;
	cap.set(CV_CAP_PROP_FRAME_WIDTH, imageSize.width);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, imageSize.height);
	cv::namedWindow("Webcam", CV_WINDOW_AUTOSIZE);

	while (cap.isOpened()) {
		cap >> frame;
		markers.detectArucoMarkers(frame,K,D, 63.5f);
		cv::imshow("Webcam", frame);
		cv::waitKey(10);
	}
	return;
}