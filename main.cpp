/* 
 * File:   main.cpp
 * Author: jad
 *
 * Created on March 20, 2013, 12:20 AM
 */

#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "keyboard.h"
#include "camera.h"
#include "physics.h"

using namespace std;



void handleResize(int w, int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
    /*glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);*/
}

void setup() {
    /*Empty Setup Function*/
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    /*Initializing library*/
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    
}

//--Draws a grid of lines on the floor plane -------------------------------
void drawFloor(){

    glNormal3f(0., 1., 0.);   //Common normal for all vertices

	for(float i = -50; i <= 50; i ++)
	{
		glBegin(GL_LINES);
                glColor3f(i*0.1,i*0.2,i*0.3);
			glVertex3f(-50, 0, i);
			glVertex3f(50, 0, i);
			glVertex3f(i, 0, -50);
			glVertex3f(i, 0, 50);
		glEnd();
	}
}

void sphereBuild(int ams)
{
    for(int i=1;i<ams;i++)
    {
        glPushMatrix();
        glScalef(1.0,1.0,1.0);
        glTranslatef(-1*i,0.0,-1*i);
        glTranslatef(0.0,1.1,0.0);
        glColor3f(i*0.1,i*0.2,i*0.3);
        glutSolidSphere(1.0,15,15);
        glPopMatrix();
    }
}


void display() {
    /*Empty Display Function*/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    float lightPos[4]={0.,10.0,10.0,1.0};
    /*Draw camera here - write replacement file  */
    /*gluLookAt(0.0,2.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);*/
    camera cameraA(0.0,1.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
    /*lighting setup*/
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    /*Draw object*/
    sphereBuild(10);
    drawFloor();
    
    glFlush();
    
    glutSwapBuffers();
}

int main(int argc, char *argv[]) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800,600);
    glutCreateWindow("No Pain");
    
    setup(); //Initialize rendering/set handler functions
    glutDisplayFunc(display);
    //handleKeypress - included using keyboard.h
    glutKeyboardFunc(handleKeypress);
    
    glutReshapeFunc(handleResize);
    glutMainLoop(); //Run Main loop
    
    return 0;
}


