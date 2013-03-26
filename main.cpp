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

using namespace std;

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27: //Esc Key
            exit(0);
    }
    
}

void handleResize(int w, int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(double)w/(double)h,1.0,200.0);
}

void setup() {
    /*Empty Setup Function*/
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f,1.0f,1.0f,0.0f);
}

void display() {
    /*Empty Display Function*/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /*Draw commands here*/
    glColor3f(1.0,0.5,0.6);
    
    
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
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutMainLoop(); //Run Main loop
    
    return 0;
}


