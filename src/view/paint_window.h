#ifndef _MAZE_AND_CAVES_PAINT_WINDOW_H_
#define _MAZE_AND_CAVES_PAINT_WINDOW_H_

#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QWidget>
#include <cmath>
#include <utility>

#include "controller.h"

class View;

class PaintWindow : public QWidget {
 public:
  using point = Controller::pair_type;

  explicit PaintWindow(QWidget *parent = nullptr);
  PaintWindow(const PaintWindow &) = delete;
  PaintWindow(PaintWindow &&) = delete;
  void operator=(const PaintWindow &) = delete;
  void operator=(PaintWindow &&) = delete;

  void DrawMaze(Controller const *controller);
  void DrawMazeFrame(QPainter &painer);
  void ClearPaintWindow();
  void DrawCave(Controller const *controller);
  void DrawPath(Controller const *controller);

 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  QImage image_;
  QImage maze_path_;
  double height_one_cell_, widht_one_cell_;
  double widht_area_, height_area_;
  bool path_exist_;

  QPoint MakePoint(const point &position);
};

#endif  // _MAZE_AND_CAVES_PAINT_WINDOW_H_
