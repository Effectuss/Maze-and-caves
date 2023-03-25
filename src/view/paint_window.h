#ifndef _MAZE_AND_CAVES_PAINT_WINDOW_H_
#define _MAZE_AND_CAVES_PAINT_WINDOW_H_

#include <QImage>
#include <QPainter>
#include <QWidget>

#include "controller.h"

class PaintWindow : public QWidget {
 public:
  explicit PaintWindow(QWidget *parent = nullptr);
  PaintWindow(const PaintWindow &) = delete;
  PaintWindow(PaintWindow &&) = delete;
  void operator=(const PaintWindow &) = delete;
  void operator=(PaintWindow &&) = delete;

  void DrawMaze(Controller *controller);
  void DrawFrame(QPainter &painer);
  void ClearPaintWindow();
  void DrawCave(Controller *controller);

 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  QImage image_;
};

#endif  // _MAZE_AND_CAVES_PAINT_WINDOW_H_
