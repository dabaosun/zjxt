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
//#include <windows.h>

using namespace std;
using namespace cv;

class Detector
{
    public:
        static Detector* GetInstance(){
			return m_pInstance;
		};

        bool LoadCascadeClassifier();
        bool DetectAndDisplay( Mat* frame );
		bool DetectAndComparseWithSDK(const std::shared_ptr<cv::Mat>& frame, const std::shared_ptr<char>& pImgBuf, long bufLen, float& score);

		bool CalcFeatureMatch(Mat* srcFame, Mat* dstFrame);

    protected:

    private:
        string face_cascade_name,eyes_cascade_name;
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
};

#endif // DETECTOR_H
