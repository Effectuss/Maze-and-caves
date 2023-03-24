#ifndef _MAZE_AND_CAVES_PAINT_WINDOW_H_
#define _MAZE_AND_CAVES_PAINT_WINDOW_H_

#include <QDebug>
#include <QImage>
#include <QPainter>
#include <QWidget>

class PaintWindow : public QWidget {
 public:
  PaintWindow(QWidget *parent = nullptr);
  void DrawMaze();
  void paintEvent(QPaintEvent *event) override;

 private:
  QImage image_;
};

#endif  // _MAZE_AND_CAVES_PAINT_WINDOW_H_
