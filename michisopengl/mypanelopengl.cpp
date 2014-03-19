#include <QDebug>
#include "GL/glu.h"
#include <cmath>
#include <iostream>
#include "kkk.h"
using namespace std;

MyPanelOpenGL::MyPanelOpenGL(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    timer=NULL;
    r=0;
    x=-0.9;
    y=-0.9;
}

void MyPanelOpenGL::initializeGL()
{
    init(world);
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void MyPanelOpenGL::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //    static float i(0.01),j(0.007);

    for(int i=0; i<max_row; i++)
    {
        for(int j=0; j<max_col; j++)
        {
        if(world[i][j] == 1)
            glColor3f(1.9f, 0.0f, 0.0f);
        else
            glColor3f(0.0f, 1.9f, 0.0f);

        glBegin(GL_QUADS);
          glVertex2f(x,y);                           //top left hand corner
          glVertex2f(x+(2/max_col), y);             //top right hand corner
          glVertex2f(x, y+(2/max_row));             //bottom left hand corner
          glVertex2f(x+(2/max_col), y+(2/max_row)); //bottom right hand corner
        glEnd();
        }
    }
}


void MyPanelOpenGL::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
    case Qt::Key_Down:
        run();
        break;
    case Qt::Key_Up:
        stop();
        break;
    case Qt::Key_N:
        GetNextGen(world, world2);
        break;
    case Qt::Key_R:
        Random(world);
        break;
    case Qt::Key_C:
        clearSet(world);
        break;
    case Qt::Key_S:
        savefile(world);
        break;
    }
}

void MyPanelOpenGL::run()
{
    if(!timer)
    {
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(process()));
        timer->start(100);
    }
}

void MyPanelOpenGL::stop()
{
    if(timer)
    {
        delete timer;
        timer = NULL;
    }
}

void MyPanelOpenGL::process()
{
    readfile(world);
    GetNextGen(world, world2);
    repaint();
    updateGL();
}


void MyPanelOpenGL::resizeGL(int width, int height)
{
    glViewport( 0, 0, (GLint)width,(GLint) height );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45.0f,(GLfloat)width/(GLfloat)height,1.0f, 50.0f );

}
