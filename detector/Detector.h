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
        Detector();
        virtual ~Detector();

        bool DetectAndDisplay( Mat* frame );

    protected:

    private:
        string face_cascade_name,eyes_cascade_name;
        CascadeClassifier face_cascade;
        CascadeClassifier eyes_cascade;

};

#endif // DETECTOR_H
