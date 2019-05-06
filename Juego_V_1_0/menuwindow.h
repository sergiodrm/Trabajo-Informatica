#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QPixmap>
#include <QDir>
#include <iostream>
#include <QMessageBox>
#include "nave.h"



using namespace std;

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0);
    MenuWindow(MenuWindow &m);
    ~MenuWindow();



    int getTipo();
    void setTipo(int tipo);
    bool getJugar();

public slots:

    void empezarJuego();
    void salir();
    void elegirNave();

private:
    Ui::MenuWindow *ui;

    int tipo_nave;
    bool jugar;
};

#endif // MENUWINDOW_H
