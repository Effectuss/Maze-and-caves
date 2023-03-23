#include "view.h"

#include "ui_view.h"

View::View(Controller *controller, QWidget *parent)
    : QWidget(parent),
      ui_(new Ui::View),
      paint_window_(new PaintWindow),
      controller_(controller) {
  ui_->setupUi(this);
  ui_->areaSettings->setCurrentWidget(ui_->settingsMaze);
  connect(ui_->actionUploadFile, SIGNAL(clicked()), this,
          SLOT(ClickedActionUploadFile()));
}

View::~View() {
  delete paint_window_;
  delete ui_;
}

void View::ClickedActionUploadFile() {
  QString file_path = QFileDialog::getOpenFileName(
      this, "Open a file", QDir::homePath(), "txt (*.txt)");
  auto file_name = file_path.split(u'/');
  try {
    if (ui_->areaSettings->currentIndex() == 0) {
      controller_->ParsingFileMaze(file_path.toStdString());
      paint_window_->DrawMaze();
    }
    ui_->lineFileName->setText(file_name.back());
  } catch (const std::exception &ex) {
    QMessageBox::critical(this, "Warning", ex.what());
  }
}

void View::ClickedActionClear() {}
