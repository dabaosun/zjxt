#ifndef CAMERAVIEW_H
#define CAMERAVIEW_H

//#include "../SigninApp.h"
#include <wx/timer.h>
#include <wx/panel.h>
#include <opencv2/highgui.hpp>

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

    cv::VideoCapture *m_p_cap;
    unsigned char *m_p_picture;
    int m_width;
    int m_height;
    bool m_is_display;
    wxTimer *m_timer;
};
#endif // CAMERAVIEW_H
