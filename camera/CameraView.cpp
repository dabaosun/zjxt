/***************************************************************
 * Name:      CameraView.cpp
 * Purpose:   Defines Camera capture and displays
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#include "CameraView.h"
#include <fstream>
#include <iostream>  

#include "../detector/Detector.h"
#include "../imgstorage/ImgStorage.h"
#include "../config/Config.h"

CameraView::CameraView(wxFrame *parent, wxWindowID winid) : wxPanel(parent, winid, wxPoint(0, 0), wxSize(640, 480))
{
    m_p_picture = NULL;
    m_timer.reset(new wxTimer(this, -1));

    m_width = 640;
    m_height = 480;
    m_is_display = false;

    Connect(wxEVT_TIMER, wxTimerEventHandler(CameraView::OnTimer));
    Connect(wxEVT_PAINT, wxPaintEventHandler(CameraView::OnPaint));

}

CameraView::~CameraView()
{

}

void CameraView::OnPaint(wxPaintEvent& event)
{
    if (!m_is_display)
    {
        return;
    }

    cv::Mat capture;
    if (m_p_cap->read(capture))
    {
		bool ret = SetPicture(capture);
        if (!ret)
        {
            wxPuts(wxT("Error: can't get picture data."));
            return;
        }
		//this->NotifyCapture(capture);
        wxImage image(m_width, m_height, m_p_picture.get(), true);
        wxBitmap current_capture(image);

        wxBufferedPaintDC dc(this);
        dc.DrawBitmap(current_capture, wxPoint(0, 0));
    }
}

void CameraView::OnTimer(wxTimerEvent & event)
{
    Refresh(false);
}

void CameraView::Stop()
{
    if (m_is_display)
    {
        m_timer->Stop();
        m_is_display = false;
    }
    Refresh();
}

wxImage wx_from_mat(Mat &img) {
	Mat im2;
	if (img.channels() == 1) { cvtColor(img, im2, CV_GRAY2RGB); }
	else if (img.channels() == 4) { cvtColor(img, im2, CV_BGRA2RGB); }
	else { cvtColor(img, im2, CV_BGR2RGB); }
	long imsize = im2.rows*im2.cols*im2.channels();
	wxImage wx(im2.cols, im2.rows, (unsigned char*)malloc(imsize), false);
	unsigned char* s = im2.data;
	unsigned char* d = wx.GetData();
	for (long i = 0; i < imsize; i++) { d[i] = s[i]; }
	
	return wx;
}

byte * matToBytes(Mat image)
{
	int size = image.total() * image.elemSize();
	byte * bytes = new byte[size];  // you will have to delete[] that later
	std::memcpy(bytes, image.data, size * sizeof(byte));
	return bytes;
}

void CameraView::Start()
{
    if (m_is_display)
    {
        m_is_display = false;
    }
	int index = Config::GetInstance()->GetData().camera.index;
    m_p_cap.reset(new cv::VideoCapture(index));
    if (!m_p_cap->isOpened())
    {
        wxPuts(wxT("Camera Open Error!"));
        return;
    }

    m_p_picture.reset(new unsigned char[m_width * m_height * 3]);
    wxPuts(wxT("Camera Open Success!"));
    m_is_display = true;

    //((wxFrame*)GetParent())->SetSize(wxSize(m_width, m_height));

    m_timer->Start(1000 / 30);
}

bool CameraView::SetPicture(const cv::Mat& mat)
{
    if (mat.rows != m_height)
        return false;
    if (mat.cols != m_width)
        return false;


    if (NULL == m_p_picture)
        return false;

    for (int i = 0; i < m_width * m_height * 3 - 2; i += 3)
    {
        m_p_picture.get()[i] = mat.data[i + 2];
        m_p_picture.get()[i + 1] = mat.data[i + 1];
        m_p_picture.get()[i + 2] = mat.data[i];
    }
    return true;
}

void CameraView::OnEraseBackground(wxEraseEvent &event)
{

}

void CameraView::RegisterListener(ICameraListener * listener)
{
	if (NULL != listener)
	{
		std::unique_lock<std::mutex> lck(this->m_mtxListeners);
		this->m_listeners.push_back(listener);
	}
}

void CameraView::RemoveListener(ICameraListener * listener)
{
	if ((NULL != listener) && (m_listeners.size()>0))
	{
		std::unique_lock<std::mutex> lck(this->m_mtxListeners);
		this->m_listeners.remove(listener);
	}
}

void CameraView::NotifyCapture(const cv::Mat& capture)
{
	for (auto& elem : this->m_listeners) {
		elem->UpdateCapture(capture);
	}
}
