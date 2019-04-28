#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QPixmap>
#include <QDir>
#include <nave.h>
#include <iostream>

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

public slots:

    void empezarJuego();
    void salir();
    void elegirNave();

private slots:
    void on_jugarButton_clicked();

private:
    Ui::MenuWindow *ui;
};

#endif // MENUWINDOW_H
