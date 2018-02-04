#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QOpenGLWidget>
#include <QPixmap>
#include <QPainter>

class ImageViewer : public QOpenGLWidget
{
public:
    ImageViewer(QWidget * parent=nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~ImageViewer();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(const int & w, const int & h);

public slots:
    void updateImage(QPixmap );

private:
    QPixmap m_raw_image;
    QPixmap m_display_image;

    void updateImageDimensions();

};

#endif // IMAGEVIEWER_H
