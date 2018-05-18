/***************************************************************
 * Name:      CameraView.cpp
 * Purpose:   Defines Camera capture and displays
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#include "CameraView.h"

CameraView::CameraView(wxFrame *parent, wxWindowID winid) : wxPanel(parent, winid, wxPoint(0, 0), wxSize(640, 480))
{
    m_p_cap = NULL;
    m_p_picture = NULL;
    m_width = 640;
    m_height = 480;
    m_is_display = false;
    m_timer = new wxTimer(this, -1);
    Connect(wxEVT_TIMER, wxTimerEventHandler(CameraView::OnTimer));
    Connect(wxEVT_PAINT, wxPaintEventHandler(CameraView::OnPaint));
}

CameraView::~CameraView()
{
    delete m_timer;
}

void CameraView::OnPaint(wxPaintEvent &event)
{
    if (!m_is_display)
    {
        return;
    }

    cv::Mat capture;
    if (m_p_cap->read(capture))
    {
        bool foundFace = this->m_Detector.DetectAndDisplay(&capture);

        //if you only want to refresh and display face, then please add check the value of foundFace.

        bool ret = SetPicture(capture);
        if (!ret)
        {
            wxPuts(wxT("Error: can't get picture data."));
            return;
        }

        wxImage image(m_width, m_height, m_p_picture, true);
        wxBitmap current_capture(image);

        wxBufferedPaintDC dc(this);
        dc.DrawBitmap(current_capture, wxPoint(0, 0));

        //here, you can add image compare and save.
    }
}

void CameraView::OnTimer(wxTimerEvent &event)
{
    Refresh(false);
}

void CameraView::Stop()
{
    if (m_is_display)
    {
        m_timer->Stop();
        m_is_display = false;
        delete m_p_cap;
        delete[] m_p_picture;
    }
    Refresh();
}

void CameraView::Start()
{
    if (m_is_display)
    {
        m_is_display = false;
        delete m_p_cap;
        delete[] m_p_picture;
    }

    m_p_cap = new cv::VideoCapture(0);
    if (!m_p_cap->isOpened())
    {
        wxPuts(wxT("Camera Open Error!"));
        delete m_p_cap;
        return;
    }

    m_p_picture = new unsigned char[m_width * m_height * 3];

    wxPuts(wxT("Camera Open Success!"));
    m_is_display = true;

    //((wxFrame*)GetParent())->SetSize(wxSize(m_width, m_height));

    m_timer->Start(1000 / 30);
}

bool CameraView::SetPicture(cv::Mat &mat)
{
    if (mat.rows != m_height)
        return false;
    if (mat.cols != m_width)
        return false;


    if (NULL == m_p_picture)
        return false;

    for (int i = 0; i < m_width * m_height * 3 - 2; i += 3)
    {
        m_p_picture[i] = mat.data[i + 2];
        m_p_picture[i + 1] = mat.data[i + 1];
        m_p_picture[i + 2] = mat.data[i];
    }
    return true;
}

void CameraView::OnEraseBackground(wxEraseEvent &event)
{

}
