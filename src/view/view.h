#ifndef MAZE_AND_CAVES_VIEW_H_
#define MAZE_AND_CAVES_VIEW_H_

#include <QDebug>
#include <QFileDialog>
#include <QWidget>
#include <string>

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
  View(QWidget *parent = nullptr);

  ~View();

 private slots:
  void ClickedUploadFile();

 private:
  Ui::View *ui_;
  PaintWindow *paint_window_;
  Controller *controller_;
};

#endif  // MAZE_AND_CAVES_VIEW_H_
