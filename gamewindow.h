#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <nave.h>
#include <iostream>
#include <QLabel>

#define FILAS 10
#define COLUMNAS 10

using namespace std;

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
    Nave nave;
    QLabel lab;
    int lim_der;
    int lim_izq;
    int lim_sup;
    int lim_inf;

};

#endif // GAMEWINDOW_H
