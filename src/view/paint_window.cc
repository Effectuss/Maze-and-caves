#include "paint_window.h"

PaintWindow::PaintWindow(QWidget *parent) : QWidget(parent) {
  this->setAutoFillBackground(true);
  this->setStyleSheet("background-color:white;");
}
