#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

#define FILAS 10
#define COLUMNAS 10

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    GameWindow(GameWindow& g);
    ~GameWindow();

    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);


private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_H
