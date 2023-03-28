#include "view.h"

#include "ui_view.h"

View::View(Controller *controller, QWidget *parent)
    : QWidget(parent), ui_(new Ui::View), controller_(controller) {
  ui_->setupUi(this);
  ui_->areaSettings->setCurrentWidget(ui_->settingsMaze);
  ui_->valueHeight->clear();
  ui_->valueWidth->clear();
  connect(ui_->actionUploadFile, SIGNAL(clicked()), this,
          SLOT(ClickedActionUploadFile()));
  connect(ui_->actionClear, SIGNAL(clicked()), this,
          SLOT(ClickedActionClear()));
  connect(ui_->actionGenerate, SIGNAL(clicked()), this,
          SLOT(ClickedActionGenerate()));
}

View::~View() { delete ui_; }

void View::ClickedActionUploadFile() {
  QString file_path = QFileDialog::getOpenFileName(
      this, "Open a file", QDir::homePath(), "txt (*.txt)");
  auto file_name = file_path.split(u'/');
  try {
    if (ui_->areaSettings->currentIndex() == kMazeTab) {
      controller_->ParsingMazeFile(file_path.toStdString());
      ui_->paintWindow->DrawMaze(this->controller_);
      ui_->valueHeight->setValue(controller_->GetRowsMaze());
      ui_->valueWidth->setValue(controller_->GetColsMaze());
    } else if (ui_->areaSettings->currentIndex() == kCaveTab) {
      controller_->ParsingCaveFile(file_path.toStdString());
      ui_->paintWindow->DrawCave(this->controller_);
    }
    ui_->lineFileName->setText(file_name.back());
  } catch (const std::exception &ex) {
    QMessageBox::critical(this, "Warning", ex.what());
  }
}

void View::ClickedActionClear() {
  ui_->paintWindow->ClearPaintWindow();
  ui_->lineFileName->clear();
  ui_->valueHeight->clear();
  ui_->valueWidth->clear();
}

void View::ClickedActionGenerate() {
  controller_->GenerationMaze(ui_->valueHeight->value(),
                              ui_->valueWidth->value());
}
