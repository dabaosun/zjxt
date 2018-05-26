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

void CameraView::OnPaint(wxPaintEvent &event)
{
    if (!m_is_display)
    {
        return;
    }

    cv::Mat capture;
    if (m_p_cap->read(capture))
    {
        //bool foundFace = this->m_Detector->DetectAndDisplay(&capture);
		bool foundFace = Detector::GetInstance()->DetectAndDisplayWithSDK(&capture);

        //if you only want to refresh and display face, then please add check the value of foundFace.
        bool ret = SetPicture(capture);
        if (!ret)
        {
            wxPuts(wxT("Error: can't get picture data."));
            return;
        }

        wxImage image(m_width, m_height, m_p_picture.get(), true);
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
	FaceCheckInfo fileFace1;//分配要检查人脸信息结构
	memset(&fileFace1, 0, sizeof(FaceCheckInfo));//初始化结构
	fileFace1.bNeedPhoto = TRUE;

	Mat mat1, mat2;
	mat1 = imread("d:\\2.jpg");
	cvtColor(mat1, mat2, CV_RGB2BGR);
	byte* data1 = matToBytes(mat1);
	byte* data2 = matToBytes(mat2);

	int result = DetectFace(data1, mat1.total() * mat1.elemSize(), &fileFace1) && fileFace1.nFacesize >0;
	int result1 = DetectFace(data2, mat2.total() * mat2.elemSize(), &fileFace1) && fileFace1.nFacesize >0;
	
/*
	char * buffer;
	long size;
	ifstream in("D:\\2.jpg", ios::in | ios::binary | ios::ate);
	size = in.tellg();
	in.seekg(0, ios::beg);
	buffer = new char[size];
	in.read(buffer, size);
	in.close();
	result = DetectFace((BYTE*)buffer, size, &fileFace1) && fileFace1.nFacesize >0;
	delete[] buffer;

*/
    if (m_is_display)
    {
        m_is_display = false;
    }

    m_p_cap.reset(new cv::VideoCapture(0));
    if (!m_p_cap->isOpened())
    {
        wxPuts(wxT("Camera Open Error!"));
        return;
    }

    this->m_Detector = Detector::GetInstance();
    if (!this->m_Detector->LoadCascadeClassifier())
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
        m_p_picture.get()[i] = mat.data[i + 2];
        m_p_picture.get()[i + 1] = mat.data[i + 1];
        m_p_picture.get()[i + 2] = mat.data[i];
    }
    return true;
}

void CameraView::OnEraseBackground(wxEraseEvent &event)
{

}
