#include "paint_window.h"

PaintWindow::PaintWindow(QWidget *parent)
    : QWidget(parent), image_(QImage(500, 500, QImage::Format_RGB16)) {}

void PaintWindow::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QRect square(0, 0, this->width(), this->height());
  painter.drawImage(square, this->image_);
}

void PaintWindow::DrawMaze(Controller *controller) {
  this->ClearPaintWindow();
  QPainter painter(&image_);
  painter.setPen(QPen(Qt::white, 2));
  this->DrawFrame(painter);
  int width = 500.0 / controller->GetColsMaze();
  int height = 500.0 / controller->GetRowsMaze();
  for (int i = 0; i < controller->GetRowsMaze(); i++) {
    for (int j = 0; j < controller->GetColsMaze(); j++) {
      int x_0 = width * j;
      int y_0 = height * i;
      int x_1 = width * (j + 1);
      int y_1 = height * (i + 1);

      if (controller->CheckRightBorderMaze(i, j))
        painter.drawLine(x_1, y_0, x_1, y_1);

      if (controller->CheckBottomBorderMaze(i, j))
        painter.drawLine(x_0, y_1, x_1, y_1);
    }
  }
  update();
}

void PaintWindow::DrawFrame(QPainter &painter) {
  painter.drawLine(0, 0, 500, 0);
  painter.drawLine(0, 500, 0, 0);
  painter.drawLine(500, 0, 500, 500);
  painter.drawLine(0, 500, 500, 500);
}

void PaintWindow::ClearPaintWindow() {
  image_.fill(Qt::black);
  update();
}

void PaintWindow::DrawCave(Controller *controller) {
  QPainter painter(&image_);
  image_.fill(Qt::white);
}
