# ArUco Marker Detection OpenCV

This project implements basic ArUco marker detection based on [ArUco library](http://www.uco.es/investiga/grupos/ava/node/26), a popular library for detection of square fiducial markers developed by Rafael Munoz and Sergio Garrido:

> S. Garrido-Jurado, R. Muñoz-Salinas, F. J. Madrid-Cuevas, and M. J. Marín-Jiménez. 2014. "Automatic generation and detection of highly reliable fiducial markers under occlusion". Pattern Recogn. 47, 6 (June 2014), 2280-2292. DOI=10.1016/j.patcog.2014.01.005

## Getting Started

Library installation refer the tutorial [Building and Installing OpenCV with Extra Modules on Windows 7 64-bit](https://putuyuwono.wordpress.com/2015/04/23/building-and-installing-opencv-3-0-on-windows-7-64-bit/).

Camera calibration refer [camera calibration opencv](https://github.com/yaoli90/camera-calibration-opencv).

## Create ArUco Markers

```cpp
arucoMarker markers;
markers.createArucoMarkers();
```
Create a fold "arucoMarkers", then run the function

```cpp
void createArucoMarkers(const std::string dir = "arucoMarkers");
```

You can change the marker library below to get simple or more complicated markers.
```cpp
cv::Ptr<cv::aruco::Dictionary> markerDictionary =
cv::aruco::getPredefinedDictionary(cv::aruco::PREDEFINED_DICTIONARY_NAME::DICT_4X4_50);
```


Print the generated markers and measure the size in millimeters.

## Detect ArUco Markers

```cpp
cv::FileStorage cameraCalibrationStream("cam_.xml", cv::FileStorage::READ);
cv::Mat K, D;
cv::Size imageSize;
cameraCalibrationStream["K"] >> K;
cameraCalibrationStream["D"] >> D;
cameraCalibrationStream["imageSize"] >> imageSize;
 ```

