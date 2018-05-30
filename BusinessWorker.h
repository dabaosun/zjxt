#pragma once

#include <wx/thread.h>
#include <mutex>
#include <opencv2/highgui.hpp>
#include "./certcard/CertCardObserver.h"
#include "./camera/CameraObserver.h"
#include "ProgressThread.h"

class BusinessWorker : public CertCardObserver, ICameraObserver
{
public:
	BusinessWorker();
	~BusinessWorker();

	void CertCardAuthed();
	void UpdateCertCardInfo(std::shared_ptr<CertCardInfo> info);
	std::shared_ptr<CertCardInfo> m_cardinfo;
	std::unique_ptr<std::thread> m_thread;
	std::shared_ptr<cv::Mat> m_capture;
private:


};

