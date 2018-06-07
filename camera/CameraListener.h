/***************************************************************
* Name:      CameraListener.h
* Purpose:   Camera listener interface define.
* Author:    sunzhenbao (suzhenbao@live.com)
* Copyright: sunzhenbao ()
* License:
**************************************************************/

#ifndef __ICAMERAOBLISTENER__
#define __ICAMERAOBLISTENER__

#include <memory>
#include <opencv2/highgui.hpp>

class ICameraListener {

public:
	virtual ~ICameraListener() {};
	virtual void UpdateCapture(const std::shared_ptr<cv::Mat> & capture) = 0;
};


#endif //__ICAMERAOBLISTENER__