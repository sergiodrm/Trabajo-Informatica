#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "game.h"


GameWindow::GameWindow( QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    connect(ui->upButton, SIGNAL(clicked()), this, SLOT(moverUp()));
    connect(ui->downButton, SIGNAL(clicked()), this, SLOT(moverDown()));
    connect(ui->leftButton, SIGNAL(clicked()), this, SLOT(moverLeft()));
    connect(ui->rightButton, SIGNAL(clicked()), this, SLOT(moverRight()));
    connect(ui->terminarTurnoButton, SIGNAL(clicked()), this, SLOT(terminarTurno()));
    connect(ui->atacarButton, SIGNAL(clicked()), this, SLOT(atacar()));
    connect(ui->atacarEspButton, SIGNAL(clicked()), this, SLOT(atacarEsp()));

    this->label_jugador.setParent(this);
    this->enemigo_seleccionado = -1;
    this->turno_terminado = false;
    this->setHabilidad(false);
    this->atacar_activado = false;
    this->atacar_esp_activado = false;
}


GameWindow::GameWindow(GameWindow& g) {
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
        QPoint sup(this->lim_izq + i*floor(this->lim_der/COLUMNAS),
                   this->lim_sup);
        QPoint inf(this->lim_izq + i*floor(this->lim_der/COLUMNAS),
                   this->lim_inf);
        paint.drawLine(sup, inf);
    }
    for (int i = 1; i < FILAS ; i++) {
        QPoint izq(this->lim_izq,
                   this->lim_sup + i*floor(this->lim_inf/FILAS));
        QPoint der(this->lim_der,
                   this->lim_sup + i*floor(this->lim_inf/FILAS));
        paint.drawLine(izq, der);
    }




}

void GameWindow::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        this->cola_mov.push(Mov::Up);
    }else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        this->cola_mov.push(Mov::Left);
    }else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        this->cola_mov.push(Mov::Right);
    }else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        this->cola_mov.push(Mov::Down);
    }
}

void GameWindow::mousePressEvent(QMouseEvent *event){
    QPixmap pix;
    pix.load(":/images/marcador.png");
    marcador.setParent(this);

    if (event->y() > this->lim_sup && event->y() < this->lim_inf &&
            event->x() > this->lim_izq && event->x() < this->lim_der){

        this->setPosMouse(make_pair(event->x()-lim_izq,event->y()-lim_sup));
        // Cambio del origen de coordenadas [0,0] al borde de la cuadricula

        this->col_marcador = (this->getPosMouse().first/this->ancho_casilla);
        this->row_marcador = (this->getPosMouse().second/this->alto_casilla);
        qDebug("Fila: " + QString::number(this->row_marcador).toLatin1() + ", Columna: " + QString::number(this->col_marcador).toLatin1());

        marcador.setPixmap(pix.scaled(this->ancho_casilla,this->alto_casilla));
        marcador.setGeometry(QRect((this->col_marcador*this->ancho_casilla)+this->lim_izq,(this->row_marcador*this->alto_casilla)+this->lim_sup,
                                   this->ancho_casilla,this->alto_casilla));
        marcador.show();
        //qDebug(QString::number(marcador.pos().rx()).toLatin1() + ',' +QString::number(marcador.pos().ry()).toLatin1());
    }

    vector<QLabel*>::iterator item;
    int contador = 0;
    this->enemigo_seleccionado = -1;
    for (item = this->label_enemy.begin(); item != this->label_enemy.end(); item++)
    {
        if (event->x() > (*item)->x() && event->x() < (*item)->x() + this->ancho_casilla &&
                event->y() > (*item)->y() && event->y() < (*item)->y() + this->alto_casilla)
        {
            this->enemigo_seleccionado = contador;
        }
        contador++;
    }

    if (this->enemigo_seleccionado != -1)
        ui->groupBox_2->show();
    else
        ui->groupBox_2->hide();
}

pair <int,int> GameWindow::getPosMouse(){
    return this->pos_mouse;
}

void GameWindow::setPosMouse(pair <int,int> pos){
    this->pos_mouse.first = pos.first;
    this->pos_mouse.second = pos.second;
}

int GameWindow::getLim_der() { return this->lim_der; }

int GameWindow::getLim_inf() { return this->lim_inf; }

int GameWindow::getLim_izq() { return this->lim_izq; }

int GameWindow::getLim_sup() { return this->lim_sup; }

int GameWindow::getEnemigoSeleccionado() { return this->enemigo_seleccionado; }

bool GameWindow::getHabilidad(){ return this->habilidad; }


pair<int, int> GameWindow::calculoPosicion(pair<int, int> pos)
{
    int px = this->lim_izq + pos.first*floor((this->lim_der - this->lim_izq)/COLUMNAS);
    int py = this->lim_sup + pos.second*floor((this->lim_inf - this->lim_sup)/FILAS);

    return make_pair(px, py);
}

pair<int, int> GameWindow::calculoPosicion(pair<int, int> pos, pair<int, int> dim)
{
    int px = this->lim_izq + pos.first*floor((this->lim_der - this->lim_izq)/COLUMNAS);
    int py = this->lim_sup + pos.second*floor((this->lim_inf - this->lim_sup)/FILAS);
    int qx = floor(floor((this->lim_der - this->lim_izq)/COLUMNAS - dim.first)/2) + px;
    int qy = floor(floor((this->lim_inf - this->lim_sup)/FILAS - dim.second)/2) + py;
    return make_pair(qx, qy);
}

void GameWindow::introducirBloqueo(pair<int, int> pos)
{

    if (pos.first >= 0 && pos.first < COLUMNAS &&
            pos.second >= 0 && pos.second < FILAS)
    {

        qDebug("Introducido bloqueo en: " + QString::number(pos.first).toLatin1()
               + ", " + QString::number(pos.second).toLatin1() + ";\n");

        QLabel *lay = new QLabel(this);

        QPixmap pix(":/images/obstaculo.png");
        pair<int, int> p_tab = this->calculoPosicion(pos, make_pair(pix.width(), pix.height()));

        lay->setPixmap(pix);
        lay->setGeometry(p_tab.first, p_tab.second, pix.width(), pix.height());


        this->label_bloqueo.push_back(lay);



    }else qDebug(">> Problemas al inicializar labels de obstáculos <<\n");
}

void GameWindow::introducirMision(pair<int, int> pos, int num)
{
    if (pos.first >= 0 && pos.first < COLUMNAS &&
                pos.second >= 0 && pos.second < FILAS)
        {

            qDebug("Introducida mision en: " + QString::number(pos.first).toLatin1()
                   + ", " + QString::number(pos.second).toLatin1() + ";\n");

            QLabel *lay = new QLabel(this);
            QPixmap pix;
            if (num == 0){
                pix.load(":/images/portal.png");
            }else {
                pix.load(":/images/mission_data.png");
            }
            pix = pix.scaled(QSize(41,41));
            pair<int, int> p_tab = this->calculoPosicion(pos, make_pair(pix.width(), pix.height()));
            qDebug("p_tab en objetivo: %d,%d; pix scale: %d,%d",
                   p_tab.first,p_tab.second,pix.width(),pix.height());
            lay->setPixmap(pix);
            lay->setGeometry(p_tab.first, p_tab.second, pix.width(), pix.height());
            //lay->setText(QString("HOLA!"));

            this->label_mision.push_back(lay);


        }else qDebug(">> Problemas al inicializar labels de misión <<\n");
}

void GameWindow::setPosXLCD(int v)
{
    if (v >= 0 && v <= COLUMNAS )
        ui->posXLCD->display(v);
}

void GameWindow::setPosYLCD(int v)
{
    if (v >= 0 && v <= COLUMNAS )
        ui->posYLCD->display(v);
}

void GameWindow::setPALCD(int v)
{
    if (v >= 0)
        ui->paLCD->display(v);
}

void GameWindow::setTurnoLCD(int v)
{
    if (v >= 0)
        ui->turnoLCD->display(v);
}

void GameWindow::setSaludBar_enemy(int v)
{
    if (v >= 0 && v <= 100)
        ui->saludBar_enemigo->setValue(v);
}

void GameWindow::setEscudoBar_enemy(int v)
{
    if (v >= 0 && v <= 100)
        ui->escudoBar_enemigo->setValue(v);
}

void GameWindow::setAtqBar_enemy(int v)
{
    if (v >= 0 && v <= 100)
        ui->atqBar_enemigo->setValue(v);
}

void GameWindow::setAtqEspBar_enemy(int v)
{
    if (v >= 0 && v <= 100)
        ui->atqespBar_enemigo->setValue(v);
}

void GameWindow::setPosXLCD_enemy(int v)
{
    if (v >= 0 && v <= 100)
        ui->posXLCD_enemigo->display(v);
}

void GameWindow::setPosYLCD_enemy(int v)
{
    if (v >= 0 && v <= 100)
        ui->posYLCD_enemigo->display(v);
}

void GameWindow::setLabel_jugador(QLabel *label_jugador) {
    this->label_jugador.setParent(label_jugador->parentWidget());
    this->label_jugador.setPixmap(*(label_jugador->pixmap()));
    this->label_jugador.setGeometry(label_jugador->geometry());
}

void GameWindow::setLabel_jugadorGeometry(int qx, int qy, int w, int h) {
    this->label_jugador.setGeometry(qx, qy, w, h);
}

void GameWindow::addLabel_enemy(QLabel *lay)
{
    QLabel *l = new QLabel(this);
    l->setGeometry(lay->geometry());
    l->setPixmap(*lay->pixmap());
    this->label_enemy.push_back(l);
}

void GameWindow::setLabel_enemy(int index, QLabel *lay)
{

    this->label_enemy.at(index)->setParent(lay->parentWidget());
    this->label_enemy.at(index)->setPixmap(*lay->pixmap());
    this->label_enemy.at(index)->setGeometry(lay->geometry());
}

void GameWindow::borrarEnemigo(int id)
{
    this->label_enemy.at(id)->setParent(NULL);
    this->label_enemy.at(id)->setVisible(false);
    this->label_enemy.at(id)->setGeometry(-1,-1, 0, 0);
    this->ui->groupBox_2->hide();

}

void GameWindow::setSaludBar(int v)
{
    if (v >= 0 && v <= 100)
        ui->saludBar->setValue(v);
}

void GameWindow::setEscudoBar(int v)
{
    if (v >= 0 && v <= 100)
        ui->escudoBar->setValue(v);
}

void GameWindow::setAtqBar(int v)
{
    if (v >= 0 && v <= 100)
        ui->atqBar->setValue(v);
}

void GameWindow::setAtqEspBar(int v)
{
    if (v >= 0 && v <= 100)
        ui->atqespBar->setValue(v);
}

void GameWindow::setHabilidad(bool value){
    habilidad = value;
}

bool GameWindow::getTurnoTerminado() { return this->turno_terminado; }

void GameWindow::setTurnoTerminado(bool t) { this->turno_terminado = t; }

int GameWindow::frontMov() {
    return this->cola_mov.front();
}

bool GameWindow::emptyMov() {
    return this->cola_mov.empty();
}

void GameWindow::popMov() {
    this->cola_mov.pop();
}


void GameWindow::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton rest = QMessageBox::question ( this, tr("Aviso"),
                                                               tr("Perderás la partida.\n¿Estás seguro?\n"),
                                                               QMessageBox::No | QMessageBox::Yes,
                                                               QMessageBox::No);

    if (rest != QMessageBox::Yes) {
        event->ignore();
    }else event->accept();
}

bool GameWindow::getAtacarActivado()
{
    return this->atacar_activado;
}

void GameWindow::setAtacarActivado(bool a)
{
    this->atacar_activado = a;
}

bool GameWindow::getAtacarEspActivado()
{
    return this->atacar_esp_activado;
}

void GameWindow::setAtacarEspActivado(bool a)
{
    this->atacar_esp_activado = a;
}

/*
 * ~~~~~~~~~~~~~~~~~** SLOTs **~~~~~~~~~~~~~~~~~
 */

void GameWindow::moverUp()
{
    this->cola_mov.push(Mov::Up);
}

void GameWindow::moverDown()
{
    this->cola_mov.push(Mov::Down);
}

void GameWindow::moverLeft()
{
    this->cola_mov.push(Mov::Left);
}

void GameWindow::moverRight()
{
    this->cola_mov.push(Mov::Right);
}

void GameWindow::on_habilidadButton_pressed()
{

    if (!this->habilidad){
        this->habilidad = true;
    } else{
        this->habilidad = false;
    }

}

void GameWindow::terminarTurno()
{
    this->turno_terminado = true;
}

void GameWindow::atacar()
{
    if (!this->turno_terminado)
        this->atacar_activado = true;

}
void GameWindow::atacarEsp()
{
    if (!this->turno_terminado)
        this->atacar_esp_activado = true;
}
