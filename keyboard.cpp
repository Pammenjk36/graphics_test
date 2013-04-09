/*Source file for keyboard and mouse inputs*
 *Abstract functions for handling movement and 
 * running glutPostRedislay
 *
 * Author Jad K Pamment
 * 6/4/13
 */
#include <GL/glut.h>
#include <GL/glu.h>
#include "physics.h"

using namespace std;

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27: exit(0);
        case 'a': moveLeft();
        case 'w': moveForward();
        case 's': moveBack();
        case 'd': moveRight();
    }

}


