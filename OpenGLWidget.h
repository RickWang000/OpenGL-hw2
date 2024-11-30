#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H


#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include <QTimer>
#include "Camera.h"


class CoreFunctionWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit CoreFunctionWidget(QWidget* parent = nullptr);
    ~CoreFunctionWidget();

signals:
    void projection_change();
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void keyPressEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    int mouse_x, mouse_y;

private:
    GLuint loadCubemap(std::vector<std::string> faces);
    void setupShaders();
    void setupTextures();
    void setupVertices();
    void setupCube(GLuint &VAO, GLuint &VBO, float size, QVector3D color);

    QOpenGLShaderProgram shaderProgram;
    QOpenGLShaderProgram skyboxShaderProgram;
    QOpenGLShaderProgram cubeShaderProgram;

    GLuint VBO, VAO, EBO, texture1, texture2;
    GLuint skyboxVAO, skyboxVBO, skyboxTexture;
    GLuint cube1VAO, cube1VBO;
    GLuint cube2VAO, cube2VBO;

    QVector3D cubePosition;
    QVector3D cubeVelocity;
    float deltaTime;
    QElapsedTimer timer;
    QTimer updateTimer;

    Camera cam;
public:
    bool use_perspective = true;
};


#endif // OPENGLWIDGET_H
