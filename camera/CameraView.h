/***************************************************************
 * Name:      CameraView.h
 * Purpose:   Defines Camera capture and displays
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#ifndef CAMERAVIEW_H
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
#include "./CameraObserver.h"

class CameraView : public wxPanel
{
public:
    CameraView(wxFrame *parent, wxWindowID winid = wxID_ANY);
    ~CameraView();
    void OnPaint(wxPaintEvent& event);
    void OnEraseBackground(wxEraseEvent &event);
    void OnTimer(wxTimerEvent & event);
    void Stop();
    void Start();
    bool SetPicture(const cv::Mat& mat);

    std::unique_ptr<cv::VideoCapture> m_p_cap;
    std::unique_ptr<wxTimer> m_timer;
    std::unique_ptr<unsigned char> m_p_picture;

	void RegisterObserver(ICameraObserver* observer);
	void RemoveObserver(ICameraObserver* observer);
	int m_width;
	int m_height;
	bool m_is_display;
private:
    std::list<ICameraObserver*> m_observers;
	std::mutex m_mtxObservers;




};
#endif // CAMERAVIEW_H
