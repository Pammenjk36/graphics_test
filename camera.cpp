/* 
 * File:   camera.cpp
 * Author: jad
 * 
 * Created on April 7, 2013, 12:31 AM
 */

#include "camera.h"
#include <GL/glu.h>

camera::camera(float posX, float posY, float posZ, float locX, float locY, float locZ, float oriX, float oriY, float oriZ)
{
    setPos(posX,posY,posZ);
    setLoc(locX,locY,locZ);
    setOri(oriX,oriY,oriZ);
    gluLookAt(l_posX,l_posY,l_posZ,l_locX,l_locY,l_locZ,l_oriX,l_oriY,l_oriZ);
}

void camera::setLoc(float locX, float locY, float locZ)
{
    l_locX = locX;
    l_locY = locY;
    l_locZ = locZ;
}

void camera::setOri(float oriX, float oriY, float oriZ)
{
    l_oriX = oriX;
    l_oriY = oriY;
    l_oriZ = oriZ;
}

void camera::setPos(float posX, float posY, float posZ)
{
    l_posX = posX;
    l_posY = posY;
    l_posZ = posZ;
}