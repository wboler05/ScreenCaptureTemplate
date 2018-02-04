#include "imageviewer.h"

#include <QDebug>

ImageViewer::ImageViewer(QWidget * parent, Qt::WindowFlags f) :
    QOpenGLWidget(parent,f)
{

}

ImageViewer::~ImageViewer() {
}

void ImageViewer::initializeGL() {

}

void ImageViewer::paintGL() {
    if (!m_display_image.isNull()) {
        QPainter painter(this);
        painter.drawPixmap(rect(), m_display_image);
    } else {
        qWarning() << "Image is null, homie: ImageViewer::paintGL()";
    }
}

void ImageViewer::resizeGL(const int & w, const int & h) {
    (void)w;(void)h;
    updateImageDimensions();
}

void ImageViewer::updateImage(QPixmap img) {
    m_raw_image = img;
    updateImageDimensions();
}

void ImageViewer::updateImageDimensions() {
    if (!m_raw_image.isNull()) {
        m_display_image = m_raw_image.scaled(width(), height());
        update();
    } else {
        qWarning() << "Image is null, homie: updateImageDimensions()";
    }
}
