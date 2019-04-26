#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    nave.cargarImagen(":/images/destructor.png");
    nave.inicializarLayout(this);



    this->lim_izq = 3;
    this->lim_der = this->width() - 3;
    this->lim_sup = 3;
    this->lim_inf = this->height() - this->lim_sup;


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


    QPoint sup_izq(lim_izq, lim_sup);
    QPoint sup_der(lim_der, lim_sup);
    QPoint inf_izq(lim_izq, lim_inf);
    QPoint inf_der(lim_der, lim_inf);

    paint.drawLine(sup_izq, sup_der);
    paint.drawLine(sup_izq, inf_izq);
    paint.drawLine(inf_izq, inf_der);
    paint.drawLine(sup_der, inf_der);

    for (int i = 1; i < COLUMNAS ; i++) {
        QPoint sup(this->lim_izq + i*floor(this->lim_der/COLUMNAS), this->lim_sup);
        QPoint inf(this->lim_izq + i*floor(this->lim_der/COLUMNAS),
                   this->lim_inf);
        paint.drawLine(sup, inf);
    }
    for (int i = 1; i < FILAS ; i++) {
        QPoint izq(this->lim_izq, this->lim_sup + i*floor(this->lim_inf/FILAS));
        QPoint der(this->lim_der,
                   this->lim_sup + i*floor(this->lim_inf/FILAS));
        paint.drawLine(izq, der);
    }

}

void GameWindow::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        nave.mover('w');
    }else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        nave.mover('a');
    }else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        nave.mover('d');
    }else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        nave.mover('s');
    }


}
