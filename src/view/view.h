#ifndef MAZE_AND_CAVES_VIEW_H_
#define MAZE_AND_CAVES_VIEW_H_

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QWidget>
#include <string>
#include <vector>

#include "controller.h"
#include "paint_window.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QWidget {
  Q_OBJECT

 public:
  enum CurrentTab { kMazeTab, kCaveTab };
  explicit View(Controller *controller, QWidget *parent = nullptr);
  View(const View &) = delete;
  View(View &&) = delete;
  void operator=(const View &) = delete;
  void operator=(View &&) = delete;
  ~View();

 private slots:
  void ClickedOnActionUploadFile();
  void ClickedOnActionClear();
  void ClickedOnActionGenerate();
  void ClickedOnActionSave();
  void ClickedOnActionGenerateCave();
  void ClickedOnActionNextFrame();
  void ClickedOnActionAutomate();

  void ClickedOnActionSolveMaze();

 private:
  Ui::View *ui_;
  Controller *controller_;
  QTimer *timer_;
};

#endif  // MAZE_AND_CAVES_VIEW_H_
