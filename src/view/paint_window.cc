#include "paint_window.h"

PaintWindow::PaintWindow(QWidget *parent)
    : QWidget(parent), image_(QImage(500, 500, QImage::Format_RGB16)) {
  image_.fill(Qt::white);
}

void PaintWindow::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QRect square(0, 0, this->width(), this->height());
  painter.drawImage(square, this->image_);
}

void PaintWindow::DrawMaze(Controller *controller) {
  this->ClearPaintWindow();
  QPainter painter(&image_);
  painter.setPen(QPen(Qt::black, 2));
  this->DrawMazeFrame(painter);
  int height = 500.0 / controller->GetRowsMaze();
  int width = 500.0 / controller->GetColsMaze();
  for (int i = 0; i < controller->GetRowsMaze(); ++i) {
    for (int j = 0; j < controller->GetColsMaze(); ++j) {
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

void PaintWindow::DrawMazeFrame(QPainter &painter) {
  painter.drawLine(0, 0, this->width(), 0);
  painter.drawLine(0, this->height(), 0, 0);
  painter.drawLine(this->width(), 0, this->width(), this->height());
  painter.drawLine(0, this->height(), this->width(), this->height());
}

void PaintWindow::ClearPaintWindow() {
  image_.fill(Qt::white);
  update();
}

void PaintWindow::DrawCave(Controller *controller) {
  this->ClearPaintWindow();
  QPainter painter(&image_);
  int width_cell = 500.0 / controller->GetColsCave();
  int height_cell = 500.0 / controller->GetRowsCave();
  for (int i = 0; i < controller->GetRowsCave(); ++i) {
    for (int j = 0; j < controller->GetColsCave(); ++j) {
      int x0 = width_cell * j;
      int y0 = height_cell * i;

      if (controller->CheckCellCave(i, j)) {
        painter.fillRect(x0, y0, width_cell, height_cell, Qt::black);
      }
    }
  }
  update();
}
