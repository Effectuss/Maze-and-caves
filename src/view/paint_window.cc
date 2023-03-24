#include "paint_window.h"

PaintWindow::PaintWindow(QWidget *parent) : QWidget(parent), image_() {
  image_ = QImage(500, 500, QImage::Format_RGB16);
}

void PaintWindow::DrawMaze() {
  QPainter painter(&image_);
  image_.fill(Qt::red);
  painter.setPen(QPen(Qt::white, 2));
  painter.drawLine(0, 1, 500, 1);
  painter.drawLine(1, 500, 1, 0);
  painter.drawLine(500, 0, 500, 500);
  painter.drawLine(0, 500, 500, 500);
  painter.drawLine(0, 0, 500, 500);
  update();
}

void PaintWindow::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QRect rect(0, 0, width(), this->height());
  painter.drawImage(rect, this->image_);
  qDebug() << "asd l";
}
