/***************************************************************
 * Name:      Detector.h
 * Purpose:   Defines camera detection on face , eye , etc
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#ifndef DETECTOR_H
#define DETECTOR_H
#include <string>
#include <memory>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <FaceRecognizer.h>
#include <windows.h>

using namespace std;
using namespace cv;

class Detector : public IFaceRecognizerObserver
{
    public:
        static Detector* GetInstance(){
			return m_pInstance;
		};

        bool DetectFace(Mat& frame, Mat& face);
		bool ComparseFace(const cv::Mat& face, const std::shared_ptr<char>& pImgBuf, long bufLen, float& score);
    
	private:
        CascadeClassifier face_cascade;
        CascadeClassifier eyes_cascade;

		static Detector* m_pInstance;
        Detector();
		virtual ~Detector();

		class Garbo

		{
		public:
			~Garbo()
			{
				if (Detector::m_pInstance)
				{
					delete Detector::m_pInstance;
				}
			}
		};

		static Garbo garbo;
		bool bInitSDK;

		std::shared_ptr<FaceRecognizer> m_Recognizer;
		bool LoadCascadeClassifier();
		void HandleMessage(TFaceRecognizerEvent type, void* data = NULL);
};

#endif // DETECTOR_H
