/***************************************************************
 * Name:      Detector.cpp
 * Purpose:   Defines camera detection on face , eye , etc
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#include "Detector.h"

Detector* Detector::m_instance = new Detector();
Detector::Detector()
{
    //ctor
    this->eyes_cascade_name="./data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
    this->face_cascade_name="./data/haarcascades/haarcascade_frontalface_default.xml";
	InitSDK();
}

Detector::~Detector()
{
    //dtor
	DelSDK();
}

Detector* Detector::GetInstance()
{
	return m_instance; 
}

bool Detector::LoadCascadeClassifier()
{
    return this->face_cascade.load(face_cascade_name) && this->eyes_cascade.load(eyes_cascade_name);

}

bool Detector::DetectAndDisplay( Mat* frame )
{
    std::vector<Rect> faces;
    Mat frame_gray;

    cvtColor( *frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(60, 60) );
    std::vector<Rect> eyes;

    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( *frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

        Mat faceROI = frame_gray( faces[i] );

        //-- In each face, detect eyes
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );

        for ( size_t j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( *frame, eye_center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
        }
    }

    return eyes.size()>0;
    //-- Show what you got
    //imshow( window_name, frame );
    //return frame;
}

bool Detector::DetectAndDisplayWithSDK(Mat* frame)
{
	FaceCheckInfo fileFace1;//分配要检查人脸信息结构
	memset(&fileFace1, 0, sizeof(FaceCheckInfo));//初始化结构
	return DetectFace(frame->data, frame->cols * frame->rows * frame->elemSize1(), &fileFace1) && fileFace1.nFacesize >0;//从图片中检出人脸信息
}


bool Detector::CalcFeatureMatch(Mat* srcFame, Mat* dstFrame)
{
	FaceCheckInfo face1;//分配要检查人脸信息结构
	memset(&face1, 0, sizeof(FaceCheckInfo));//初始化结构
	DetectFace(srcFame->data, srcFame->cols * srcFame->rows * srcFame->elemSize1(), &face1);

	FaceCheckInfo face2;//分配要检查人脸信息结构
	memset(&face2, 0, sizeof(FaceCheckInfo));//初始化结构
	DetectFace(dstFrame->data, dstFrame->cols * dstFrame->rows * srcFame->elemSize1(), &face2);

	float pFxd;
	CalcModel(&face1.faceModelInfo[0], &face2.faceModelInfo[0],&pFxd);
	return 0;
}