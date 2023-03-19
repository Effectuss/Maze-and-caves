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
  ui_->lineFileName->setText(file_name.back());
  try {
    if (1) {
    }
    std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>>
        maze_data = controller_->ParsingFileMaze(file_path.toStdString());
  } catch (const std::exception &ex) {
    QMessageBox::critical(this, "Warning", ex.what());
  }
}

void View::ClickedActionClear() {}
