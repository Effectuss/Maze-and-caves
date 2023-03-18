#include "view.h"

#include "ui_view.h"

View::View(QWidget *parent)
    : QWidget(parent), ui_(new Ui::View), paint_window_(new PaintWindow) {
  ui_->setupUi(this);
}

View::~View() {
  delete ui_;
  delete paint_window_;
}
