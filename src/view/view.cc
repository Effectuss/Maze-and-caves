#include "view.h"

#include "ui_view.h"

View::View(QWidget *parent)
    : QWidget(parent),
      ui_(new Ui::View),
      paint_window_(new PaintWindow),
      controller_(Controller::GetController()) {
  ui_->setupUi(this);
  ui_->areaSettings->setCurrentWidget(ui_->settingsMaze);
  connect(ui_->actionUploadFile, SIGNAL(clicked()), this,
          SLOT(ClickedActionUploadFile()));
}

View::~View() {
  Controller::Restart();
  delete paint_window_;
  delete ui_;
}

void View::ClickedActionUploadFile() {
  QString file_path = QFileDialog::getOpenFileName(
      this, "Open a file", QDir::homePath(), "txt (*.txt)");
  auto file_name = file_path.split(u'/');
  ui_->lineFileName->setText(file_name.back());
}

void View::ClickedActionClear()
{

}
