#include "view.h"

#include "ui_view.h"

View::View(Controller *controller, QWidget *parent)
    : QWidget(parent), ui_(new Ui::View), controller_(controller) {
  ui_->setupUi(this);
  ui_->areaSettings->setCurrentWidget(ui_->settingsMaze);
  connect(ui_->actionUploadFile, SIGNAL(clicked()), this,
          SLOT(ClickedActionUploadFile()));
}

View::~View() { delete ui_; }

void View::ClickedActionUploadFile() {
  QString file_path = QFileDialog::getOpenFileName(
      this, "Open a file", QDir::homePath(), "txt (*.txt)");
  auto file_name = file_path.split(u'/');
  try {
    if (ui_->areaSettings->currentIndex() == kMazeTab) {
      controller_->ParsingMazeFile(file_path.toStdString());
      ui_->valueHeight->setValue(controller_->GetRowsMaze());
      ui_->valueWidth->setValue(controller_->GetColsMaze());
      ui_->paintWindow->DrawMaze();
    } else if (ui_->areaSettings->currentIndex() == kCaveTab) {
      controller_->ParsingCaveFile(file_path.toStdString());
    }
    ui_->lineFileName->setText(file_name.back());
  } catch (const std::exception &ex) {
    QMessageBox::critical(this, "Warning", ex.what());
  }
}

void View::ClickedActionClear() {}
