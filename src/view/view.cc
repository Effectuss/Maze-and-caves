#include "view.h"

#include "ui_view.h"

View::View(Controller *controller, QWidget *parent)
    : QWidget(parent),
      ui_(new Ui::View),
      controller_(controller),
      timer_(new QTimer(this)) {
  ui_->setupUi(this);
  ui_->areaSettings->setCurrentWidget(ui_->settingsMaze);
  controller_->GenerateCave(ui_->valueCaveHeight->value(),
                            ui_->valueCaveWidth->value());
  connect(ui_->actionUploadFile, SIGNAL(clicked()), this,
          SLOT(ClickedOnActionUploadFile()));
  connect(ui_->actionClear, SIGNAL(clicked()), this,
          SLOT(ClickedOnActionClear()));
  connect(ui_->actionGenerateMaze, SIGNAL(clicked()), this,
          SLOT(ClickedOnActionGenerate()));
  connect(ui_->actionSave, SIGNAL(clicked()), this,
          SLOT(ClickedOnActionSave()));
  connect(ui_->actionGenerateCave, SIGNAL(clicked()), this,
          SLOT(ClickedOnActionGenerateCave()));
  connect(ui_->actionNextFrame, SIGNAL(clicked()), this,
          SLOT(ClickedOnActionNextFrame()));
  connect(ui_->actionAutomate, SIGNAL(clicked()), this,
          SLOT(ClickedOnActionAutomate()));
  connect(ui_->actionSolveMaze, SIGNAL(clicked()), this,
          SLOT(ClickedOnActionSolveMaze()));
  connect(timer_, SIGNAL(timeout()), this, SLOT(ClickedOnActionNextFrame()));
}

View::~View() {
  delete ui_;
  delete timer_;
}

void View::ClickedOnActionUploadFile() {
  QString file_path = QFileDialog::getOpenFileName(
      this, "Open a file", QDir::homePath(), "txt (*.txt)");
  auto file_name = file_path.split(u'/');
  try {
    if (ui_->areaSettings->currentIndex() == kMazeTab) {
      controller_->ParsingMazeFile(file_path.toStdString());
      ui_->paintWindow->DrawMaze(this->controller_);
      ui_->valueHeightMaze->setValue(controller_->GetRowsMaze());
      ui_->valueWidthMaze->setValue(controller_->GetColsMaze());
    } else if (ui_->areaSettings->currentIndex() == kCaveTab) {
      if (timer_->isActive()) timer_->stop();
      controller_->ParsingCaveFile(file_path.toStdString());
      ui_->paintWindow->DrawCave(this->controller_);
    }
    ui_->lineFileName->setText(file_name.back());
  } catch (const std::exception &ex) {
    QMessageBox::critical(this, "Warning", ex.what());
  }
}

void View::ClickedOnActionClear() {
  ui_->paintWindow->ClearPaintWindow();
  ui_->lineFileName->clear();
  if (timer_->isActive()) timer_->stop();
  controller_->ClearMaze();
  controller_->ClearCave();
}

void View::ClickedOnActionGenerate() {
  controller_->GenerationMaze(ui_->valueHeightMaze->value(),
                              ui_->valueWidthMaze->value());
  ui_->lineFileName->clear();
  ui_->paintWindow->DrawMaze(this->controller_);
}

void View::ClickedOnActionGenerateCave() {
  if (timer_->isActive()) timer_->stop();
  controller_->GenerateCave(ui_->valueCaveHeight->value(),
                            ui_->valueCaveWidth->value());
  ui_->lineFileName->clear();
  ui_->paintWindow->DrawCave(this->controller_);
}

void View::ClickedOnActionNextFrame() {
  controller_->UpdateCave(ui_->valueBirth->value(), ui_->valueDeath->value());
  ui_->paintWindow->DrawCave(this->controller_);
}

void View::ClickedOnActionAutomate() {
  timer_->start(ui_->valueCaveSpeed->value());
}

void View::ClickedOnActionSave() {
  QString file_path = QFileDialog::getSaveFileName(
      this, "Save file", QDir::homePath(), "txt (*.txt)");
  try {
    if (ui_->areaSettings->currentIndex() == kMazeTab) {
      controller_->SaveMazeInFile(file_path.toStdString());
    } else if (ui_->areaSettings->currentIndex() == kCaveTab) {
      if (timer_->isActive()) timer_->stop();
      controller_->SaveCaveInFile(file_path.toStdString());
    }
    ui_->lineFileName->setText(file_path.split(u'/').back());
  } catch (const std::exception &ex) {
    QMessageBox::critical(this, "Warning", ex.what());
  }
}

void View::ClickedOnActionSolveMaze() {
  try {
    this->controller_->SolveMaze(
        std::make_pair(ui_->valueX0->value(), ui_->valueY0->value()),
        std::make_pair(ui_->valueX1->value(), ui_->valueY1->value()));
    ui_->paintWindow->DrawPath(this->controller_);
  } catch (std::exception &ex) {
    QMessageBox::critical(this, "Warning", ex.what());
  }
}
