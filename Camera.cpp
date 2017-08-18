#include "Camera.h"


void Camera::followPoint(double x, double y, bool smartFollow, int lborder, int rborder, int tborder, int bborder)
{
    if (smartFollow)
    {
        //follow the point only if it gets too far from camera
        if (x_ - x > CAMERA_X_FOLLOW_RANGE) x_ = x + CAMERA_X_FOLLOW_RANGE;
        if (x - x_ > CAMERA_X_FOLLOW_RANGE) x_ = x - CAMERA_X_FOLLOW_RANGE;
        if (y_ - y > CAMERA_Y_FOLLOW_RANGE) y_ = y + CAMERA_Y_FOLLOW_RANGE;
        if (y - y_ > CAMERA_Y_FOLLOW_RANGE) y_ = y - CAMERA_Y_FOLLOW_RANGE;

        //prevent camera from going outside the map borders
        if (x_ < lborder + SCREENWIDTH/2) x_ = lborder + SCREENWIDTH/2;
        if (x_ > rborder - SCREENWIDTH/2) x_ = rborder - SCREENWIDTH/2;
        if (y_ < tborder + SCREENHEIGHT/2) y_ = tborder + SCREENHEIGHT/2;
        if (y_ > bborder - SCREENHEIGHT/2) y_ = bborder - SCREENHEIGHT/2;

    } else
    {
        x_ = x;
        y_ = y;
    }
}

double Camera::x()
{
    return x_;
}

double Camera::y()
{
    return y_;
}
