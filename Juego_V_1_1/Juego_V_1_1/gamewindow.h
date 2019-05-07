#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <iostream>
#include <QLabel>
#include <QCloseEvent>
#include <QMessageBox>
#include <queue>

#include "acorazado.h"
#include "caza.h"
#include "destructor.h"
#include "warship.h"

#define FILAS 10
#define COLUMNAS 10

using namespace std;

template <class N> class Game;

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
    void mousePressEvent(QMouseEvent *event);


    pair <int,int> getPosMouse();
    void setPosMouse(pair <int,int> pos);
    int getLim_der();
    int getLim_izq();
    int getLim_sup();
    int getLim_inf();
    int getEnemigoSeleccionado();

    bool getHabilidad();

    pair<int, int> calculoPosicion(pair<int, int> pos);
    pair<int, int> calculoPosicion(pair<int, int> pos, pair<int, int> dim);

    void introducirBloqueo(pair<int, int> pos);

    void setLabel_jugador(QLabel *label_jugador);
    void setLabel_jugadorGeometry(int qx, int qy, int w, int h);
    void addLabel_enemy(QLabel* lay);
    void setLabel_enemy(int index, QLabel *lay);
    void setSaludBar(int v);
    void setEscudoBar(int v);
    void setAtqBar(int v);
    void setAtqEspBar(int v);
    void setPosXLCD(int v);
    void setPosYLCD(int v);
    void setPALCD(int v);
    void setTurnoLCD(int v);

    bool getTurnoTerminado();
    void setTurnoTerminado(bool t);

    bool getAtacarActivado();
    void setAtacarActivado(bool a);
    bool getAtacarEspActivado();
    void setAtacarEspActivado(bool a);

    void setSaludBar_enemy(int v);
    void setEscudoBar_enemy(int v);
    void setAtqBar_enemy(int v);
    void setAtqEspBar_enemy(int v);
    void setPosXLCD_enemy(int v);
    void setPosYLCD_enemy(int v);

    void setHabilidad(bool value);

    int frontMov();
    bool emptyMov();
    void popMov();

    void closeEvent(QCloseEvent *event);



public slots:

    void moverUp();
    void moverDown();
    void moverLeft();
    void moverRight();
    void terminarTurno();
    void atacar();
    void atacarEsp();

    void on_habilidadButton_pressed();

private:
    Ui::GameWindow *ui;

    queue<int> cola_mov;

    const int lim_izq = 3;
    const int lim_der = 723;
    const int lim_sup = 3;
    const int lim_inf = 643;
    const int ancho_casilla = 72;
    const int alto_casilla = 64;
    int row_marcador;
    int col_marcador;
    pair<int,int> pos_mouse;

    QLabel label_jugador;
    QLabel marcador;
    int enemigo_seleccionado;
    vector<QLabel*> label_bloqueo;
    vector<QLabel*> label_enemy;

    bool habilidad;
    bool turno_terminado;
    bool atacar_activado;
    bool atacar_esp_activado;
    bool activar_ataque;

};

#endif // GAMEWINDOW_H
