#ifndef __ICAMERAOBSERVER__
#define __ICAMERAOBSERVER__

#include <memory>
#include <opencv2/highgui.hpp>

class ICameraObserver {

public:
	virtual ~ICameraObserver() {};
	virtual void UpdateCapture(std::shared_ptr<cv::Mat> capture) = 0;
};


#endif //__ICAMERAOBSERVER__