#ifndef MAZE_AND_CAVES_VIEW_H_
#define MAZE_AND_CAVES_VIEW_H_

#include <QWidget>

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

 private:
  Ui::View *ui_;
  PaintWindow *paint_window_;
};

#endif  // MAZE_AND_CAVES_VIEW_H_
