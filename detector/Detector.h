/***************************************************************
 * Name:      Detector.h
 * Purpose:   Defines camera detection on face , eye , etc
 * Author:    sunzhenbao (suzhenbao@live.com)
 * Copyright: sunzhenbao ()
 * License:
 **************************************************************/

#ifndef DETECTOR_H
#define DETECTOR_H

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

class Detector
{
    public:
        static pthread_mutex_t mutex;
        static Detector* GetInstance();

        virtual ~Detector();

        bool LoadCascadeClassifier();
        bool DetectAndDisplay( Mat* frame );

    protected:

    private:

        static Detector* m_instance;
        string face_cascade_name,eyes_cascade_name;
        CascadeClassifier face_cascade;
        CascadeClassifier eyes_cascade;

        Detector();
};

#endif // DETECTOR_H
