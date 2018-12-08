/***************************************************************
 * Name:      CameraView.h
 * Purpose:   Defines Camera capture and displays
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#ifndef CAMERAVIEW_H_
#define CAMERAVIEW_H
#include <memory>
#include <list>
#include <mutex>
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/event.h>
#include <wx/timer.h>
#include <wx/panel.h>
#include <opencv2/highgui.hpp>
#include "./CameraListener.h"

class CameraView : public wxPanel
{
public:
    CameraView(wxWindow *parent, wxWindowID winid = wxID_ANY);
    ~CameraView();
    void OnPaint(wxPaintEvent& event);
    void OnEraseBackground(wxEraseEvent &event);
    void OnTimer(wxTimerEvent & event);
    void CloseCamera();
    bool OpenCamera();
    bool SetPicture(const cv::Mat& mat);

    std::unique_ptr<cv::VideoCapture> m_p_cap;
    std::unique_ptr<wxTimer> m_timer;
    std::unique_ptr<unsigned char> m_p_picture;

	void RegisterListener(ICameraListener * listener);
	void RemoveListener(ICameraListener * listener);
	int m_width;
	int m_height;
	bool m_is_display;
private:
    std::list<ICameraListener*> m_listeners;
	std::mutex m_mtxListeners;
	void NotifyCapture(const cv::Mat& capture);
};
#endif // CAMERAVIEW_H
