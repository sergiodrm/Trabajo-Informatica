#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::GameWindow(GameWindow &g) {
    this->ui = g.ui;
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::paintEvent(QPaintEvent *event){
    QPainter paint;
    paint.begin(this);

    QPen p;
    p.setWidth(1);
    paint.setPen(p);

    int x = 3;
    int y = 3;
    int y_lim = y;

    QPoint sup_izq(x, y);
    QPoint sup_der(this->width()-x, y);
    QPoint inf_izq(x, this->height()-y_lim);
    QPoint inf_der(this->width()-x, this->height()-y_lim);

    paint.drawLine(sup_izq, sup_der);
    paint.drawLine(sup_izq, inf_izq);
    paint.drawLine(inf_izq, inf_der);
    paint.drawLine(sup_der, inf_der);

    for (int i = 1; i < COLUMNAS ; i++) {
        QPoint sup(x + i*floor((this->width() - x)/COLUMNAS), y);
        QPoint inf(x + i*floor((this->width() - x)/COLUMNAS),
                   this->height()-y_lim);
        paint.drawLine(sup, inf);
    }
    for (int i = 1; i < FILAS ; i++) {
        QPoint izq(x, y + i*floor((this->height() - y_lim)/FILAS));
        QPoint der(this->width() - x,
                   y + i*floor((this->height() - y_lim)/FILAS));
        paint.drawLine(izq, der);
    }
}

void GameWindow::keyPressEvent(QKeyEvent *event){

}
