#ifndef _MAZE_AND_CAVES_PAINT_WINDOW_H_
#define _MAZE_AND_CAVES_PAINT_WINDOW_H_

#include <QPainter>
#include <QWidget>

class PaintWindow : public QWidget {
 public:
  PaintWindow(QWidget *parent = nullptr);
  void DrawMaze() noexcept;

 protected:
  void paintEvent(QPaintEvent *event) override;
};

#endif  // _MAZE_AND_CAVES_PAINT_WINDOW_H_
