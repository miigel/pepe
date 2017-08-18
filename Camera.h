#ifndef CAMERA_H
#define CAMERA_H

#include "defines.h"

class Camera
{
    public:
        void followPoint(double x, double y, bool smartFollow=0, int lborder=0, int rborder=0, int tborder=0, int bborder=0);
        double x();
        double y();
    protected:
    private:
        double x_ = 0;
        double y_ = 0;
};

#endif // CAMERA_H
