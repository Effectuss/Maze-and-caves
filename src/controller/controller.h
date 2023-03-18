#ifndef MAZE_AND_CAVES_CONTROLLER_H_
#define MAZE_AND_CAVES_CONTROLLER_H_

#include <QDebug>

class Controller {
 public:
  Controller(Controller const&) = delete;
  Controller(Controller&&) = delete;
  Controller& operator=(Controller const&) = delete;
  Controller& operator=(Controller&&) = delete;

  static Controller* GetController();
  static void Restart();
  void qwe() { qDebug() << "ASD"; }

 private:
  Controller() = default;
  static Controller* controller_;
};

#endif  // MAZE_AND_CAVES_CONTROLLER_H_
