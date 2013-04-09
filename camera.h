/* 
 * File:   camera.h
 * Author: jad
 *
 * Created on April 7, 2013, 12:31 AM
 */

#ifndef CAMERA_H
#define	CAMERA_H

class camera 
{
private:
    float l_posX;
    float l_posY;
    float l_posZ;
    float l_locX;
    float l_locY;
    float l_locZ;
    float l_oriX;
    float l_oriY;
    float l_oriZ;

public:
    camera(float posX, float posY, float posZ, float locX, float locY, float locZ, float oriX, float oriY, float oriZ);//Constructor
    
    void setPos(float posX, float posY, float posZ);
    void setLoc(float locX, float locY, float locZ);
    void setOri(float oriX, float oriY, float oriZ);  
    
};

#endif	/* CAMERA_H */

