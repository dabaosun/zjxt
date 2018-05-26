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
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/event.h>
#include <wx/timer.h>
#include <wx/panel.h>
#include <opencv2/highgui.hpp>
#include "../detector/Detector.h"

class CameraView : public wxPanel
{
public:
    CameraView(wxFrame *parent, wxWindowID winid = wxID_ANY);
    ~CameraView();
    void OnPaint(wxPaintEvent &event);
    void OnEraseBackground(wxEraseEvent &event);
    void OnTimer(wxTimerEvent &event);
    void Stop();
    void Start();
    bool SetPicture(cv::Mat &mat);

    std::shared_ptr<cv::VideoCapture> m_p_cap;
    std::unique_ptr<wxTimer> m_timer;
    std::shared_ptr<unsigned char> m_p_picture;

    Detector* m_Detector;
    int m_width;
    int m_height;
    bool m_is_display;
};
#endif // CAMERAVIEW_H
