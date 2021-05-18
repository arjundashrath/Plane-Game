#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED



#endif // PLANE_H_INCLUDED
void fan(){
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(1,1,0.7);
        glutSolidSphere(0.8,30,30);
    glPopMatrix();

    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0,0,0);
        glRotated(5,0,1,0);
        glScaled(0.5,2.5,0.05);
        glutSolidSphere(1,30,30);
    glPopMatrix();

    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(0,0,0);
        glRotated(-5,0,1,0);
        glRotated(90,0,0,1);
        glScaled(0.5,2.5,0.05);
        glutSolidSphere(1,30,30);
    glPopMatrix();

}

void plane(){

    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;


    glColor3d(1,1,1);                                      //BODY
    glPushMatrix();
        glTranslated(0,0,0);
        glScaled(3,0.3,0.3);
        glutSolidSphere(1,30,30);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(2,0.1,0);
        glScaled(0.3,0.3,0.6);
        glRotated(40,0,1,0);
        glutSolidSphere(0.45,30,30);
    glPopMatrix();
                                                           //RIGHT WING
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,1);
        glRotated(-50,0,1,0);
        glScaled(0.7,0.1,3);
        glRotated(25,0,1,0);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(-0.1,-0.15,1.5);
        glRotated(90,0,1,0);
        glPushMatrix();
           glTranslated(0,0,0.5);
            glRotated(10*a,0,0,1);
            glScaled(0.1,0.1,0.1);
            fan();
        glPopMatrix();
        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

    glColor3d(0.8,1,0);
    glPushMatrix();
        glTranslated(0.2,-0.15,0.9);
        glRotated(90,0,1,0);

                                                                    //FAN
        glPushMatrix();
           glTranslated(0,0,0.5);
            glRotated(10*a,0,0,1);
            glScaled(0.1,0.1,0.1);
            fan();
        glPopMatrix();

        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

                                                                   //LEFT WING
    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,-1);
        glRotated(50,0,1,0);
        glScaled(0.7,0.1,3);
        glRotated(-25,0,1,0);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0.8,1,0);
    glPushMatrix();
        glTranslated(-0.3,-0.15,-1.5);
        glRotated(90,0,1,0);
        glPushMatrix();
           glTranslated(0,0,0.5);
            glRotated(10*a,0,0,1);
            glScaled(0.1,0.1,0.1);
            fan();
        glPopMatrix();
        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

    glColor3d(0.8,1,0);
    glPushMatrix();
        glTranslated(0.2,-0.15,-0.9);
        glRotated(90,0,1,0);
        glPushMatrix();
           glTranslated(0,0,0.5);
            glRotated(10*a,0,0,1);
            glScaled(0.1,0.1,0.1);
            fan();
        glPopMatrix();
        glScaled(0.1,0.1,0.9);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-2.8,0,0);
        glScaled(0.8,0.5,0.3);

                                                              //RIGHT FIN
        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(0.4,0,1.5);
            glRotated(-30,0,1,0);
            glScaled(0.6,0.1,2);
            glRotated(10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();

                                                              //LEFT FIN
        glColor3d(0,0,0);
        glPushMatrix();
            glTranslated(0.4,0,-1.5);
            glRotated(30,0,1,0);
            glScaled(0.6,0.1,2);
            glRotated(-10,0,1,0);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();

                                                                 //TAIL
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(-2.7,0.5,0);
        glRotated(45,0,0,1);
        glScaled(0.8,2,0.1);
        glRotated(-20,0,0,1);
        glutSolidCube(0.5);
    glPopMatrix();

   glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(-2.95,0.85,0);
        glRotated(90,0,1,0);
        glScaled(0.05,0.05,0.6);
        glutSolidTorus(0.5,0.5,50,50);
    glPopMatrix();


                                                                 //FANS

    glPushMatrix();
        glTranslated(-2.95,0,0);
        glScaled(0.2,0.1,0.1);
        glRotated(-10*a,0,0,1);
        glRotated(90,1,0,0);
        fan();
    glPopMatrix();
}
