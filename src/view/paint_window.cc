#include "paint_window.h"

PaintWindow::PaintWindow(QWidget *parent)
    : QWidget(parent),
      image_(QImage(500, 500, QImage::Format_RGB32)),
      maze_path_(QImage(500, 500, QImage::Format_ARGB32)) {
  this->widht_area_ = image_.width();
  this->height_area_ = image_.height();
  this->ClearPaintWindow();
}

void PaintWindow::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QRect square(0, 0, this->width(), this->height());
  painter.drawImage(square, this->image_);
  painter.drawImage(square, this->maze_path_);
  if (path_exist_) maze_path_.fill(0);
}

QPoint PaintWindow::MakePoint(const point &position) {
  int i = position.second * height_one_cell_ + height_one_cell_ / 2;
  int j = position.first * widht_one_cell_ + widht_one_cell_ / 2;
  return QPoint(i, j);
}

void PaintWindow::DrawMaze(Controller const *controller) {
  this->ClearPaintWindow();
  QPainter painter(&image_);
  painter.setPen(QPen(Qt::black, 2));
  this->DrawMazeFrame(painter);
  height_one_cell_ = height_area_ / controller->GetRowsMaze();
  widht_one_cell_ = widht_area_ / controller->GetColsMaze();
  for (int i = 0; i < controller->GetRowsMaze(); ++i) {
    for (int j = 0; j < controller->GetColsMaze(); ++j) {
      int x_0 = widht_one_cell_ * j;
      int y_0 = height_one_cell_ * i;
      int x_1 = widht_one_cell_ * (j + 1);
      int y_1 = height_one_cell_ * (i + 1);
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
  maze_path_.fill(0);
  update();
}

void PaintWindow::DrawCave(Controller const *controller) {
  this->ClearPaintWindow();
  QPainter painter(&image_);
  this->height();
  widht_one_cell_ = ceil(widht_area_ / controller->GetColsCave());
  height_one_cell_ = ceil(height_area_ / controller->GetRowsCave());
  for (int i = 0; i < controller->GetRowsCave(); ++i) {
    for (int j = 0; j < controller->GetColsCave(); ++j) {
      int x0 = widht_one_cell_ * j;
      int y0 = height_one_cell_ * i;

      if (controller->CheckCellCave(i, j)) {
        painter.fillRect(x0, y0, widht_one_cell_, height_one_cell_, Qt::black);
      }
    }
  }
  update();
}

void PaintWindow::DrawPath(const Controller *controller) {
  QPainter painter(&maze_path_);
  painter.setPen(QPen(Qt::red, 2));
  widht_one_cell_ = widht_area_ / controller->GetRowsMaze();
  height_one_cell_ = height_area_ / controller->GetColsMaze();
  for (unsigned i = 0; i < controller->GetPath().size() - 1; i++) {
    painter.drawLine(MakePoint(controller->GetPath()[i]),
                     MakePoint(controller->GetPath()[i + 1]));
  }
  path_exist_ = true;
  update();
}
