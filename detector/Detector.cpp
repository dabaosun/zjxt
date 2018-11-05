/***************************************************************
 * Name:      Detector.cpp
 * Purpose:   Defines camera detection on face , eye , etc
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#include "Detector.h"
#include "../config/Config.h"

Detector* Detector::m_pInstance = new Detector();

Detector::Garbo Detector::garbo;

Detector::Detector()
{
	//ctor
	//this->eyes_cascade_name="./data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
	//this->face_cascade_name="./data/haarcascades/haarcascade_frontalface_default.xml";

	m_Recognizer = std::make_shared<FaceRecognizer>(*this,
		"model/seeta_fd_frontal_v1.0.bin",
		"model/seeta_fa_v1.1.bin",
		"model/seeta_fr_v1.0.bin");
	m_Recognizer->Initialize();
}

Detector::~Detector()
{

}

bool Detector::LoadCascadeClassifier()
{
	return this->face_cascade.load(face_cascade_name) && this->eyes_cascade.load(eyes_cascade_name);
}

bool Detector::DetectAndDisplay(Mat* frame)
{
	std::vector<cv::Rect> faces;
	Mat frame_gray;

	cvtColor(*frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	//-- Detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(60, 60));
	std::vector<cv::Rect> eyes;

	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(*frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);

		Mat faceROI = frame_gray(faces[i]);

		//-- In each face, detect eyes
		eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

		for (size_t j = 0; j < eyes.size(); j++)
		{
			Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
			int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
			circle(*frame, eye_center, radius, Scalar(255, 0, 0), 4, 8, 0);
		}
	}

	return eyes.size() > 0;

}

bool Detector::DetectAndComparseWithSDK(const std::shared_ptr<cv::Mat>& frame, const std::shared_ptr<char>& pImgBuf, long bufLen, float& score)
{
	std::shared_ptr<int> points = std::make_shared<int>();
	if (this->DetectFace(*frame, points) > 0) {
		std::string pwd = Config::GetInstance()->GetPwd();
		std::string bmpfile(pwd + "/certcard.bmp");
		cv::Mat  certcardMat = cv::imread(bmpfile);
		score = this->CompareFace(*frame, certcardMat);
		return true;
	}
	return false;
}

void Detector::HandleMessage(TFaceRecognizerEvent type, void* data)
{

}

int Detector::DetectFace(cv::Mat srcMat, std::shared_ptr<int> points)
{
	seeta::ImageData imgdata(srcMat.cols, srcMat.rows, srcMat.channels());
	imgdata.data = srcMat.data;

	int* tmp = NULL;	
	int count = this->m_Recognizer->DetectFaces(imgdata, tmp);
	points.reset(tmp);
	return count;
}

float Detector::CompareFace(cv::Mat srcMat, cv::Mat dstMat)
{
	seeta::ImageData src_imgdata(srcMat.cols, srcMat.rows, srcMat.channels(),srcMat.data);
	seeta::ImageData dest_imgdata(dstMat.cols, dstMat.rows, dstMat.channels(), dstMat.data);

	return this->m_Recognizer->CalcSimilarity(src_imgdata, dest_imgdata);
}