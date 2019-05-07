#include "game.h"

template <class N>
Game<N>::Game()
{
    game_over = false;
    this->turno = 1;

    /*
     * Inicialización aleatoria de los obstáculos en el escenario de juego
     */
    //Esta función debe ejecutarse antes de crear las naves enemigas
    int i = 0;
    int posx, posy;
    int aux;
    srand(time(NULL));
    while (i < this->n_bloqueos){
        aux = 0;

        posx = rand() % COLUMNAS;
        posy = rand() % FILAS;
        vector< pair<int, int> >::iterator item;
        for (item = this->bloqueos.begin(); item != this->bloqueos.end(); item++){
            if ( make_pair(posx, posy) == *item ){
                aux = 1;
            }
        }
        /* El obstáculo que se genere no puede bloquear la casilla de salida
         * ni formar círculos encerrando casillas
         */
        if (!((posx == 0 && posy == 0) || (posx == 1 && posy == 0) || (posx == 0 && posy == 1)) && aux == 0){
            this->bloqueos.push_back(  make_pair(posx, posy) );
            this->gamewindow.introducirBloqueo(make_pair(posx, posy));
            i++;
        }
    }


    // INTRODUCCION DE MISIONES DESPUES DE BLOQUEOS
    // -----------------------------------------------------
    int mision = 0;
    int posx_mision, posy_mision;
    int aux_mision;

    while (mision < this->n_misiones){
        aux_mision = 0;
        qDebug("Inicio: %d",mision);
        srand(time(NULL));
        posx_mision = rand() % 10;
        posy_mision = rand() % 10;
        bool result_mision = false;
        vector< pair<int, int> >::iterator item;
        pair< int, int> centro = make_pair(posx_mision, posy_mision);
        for (item = this->misiones.begin(); item != this->misiones.end(); item++){
            for (int colm = centro.first - 1; colm != centro.first + 1; colm++){
                for (int fil = centro.second - 1; fil != centro.second + 1; fil++){
                    qDebug("Centro: %d,%d",colm,fil);
                    if (make_pair(colm, fil) == *item){ result_mision = true;}
                }
            }

            if ( result_mision){
                qDebug("Coincide");
                aux_mision = 1;
            }
        }
        /* La misión que se genere no puede bloquear la casilla de salida
             * ni situarse sobre los objetos ya creados
             */
        for (item = this->bloqueos.begin(); item != this->bloqueos.end(); item++){
            if ( make_pair(posx_mision, posy_mision) == *item)
            {
                aux_mision = 1;
            }
        }
        qDebug("posx:%d posY:%d aux:%d",posx,posy,aux);
        if ((!((posx_mision == 0 && posy_mision == 0) || (posx_mision == 1 && posy_mision == 0) || (posx_mision == 0 && posy_mision == 1))) && aux_mision == 0 )
        {
            this->misiones.push_back(  make_pair(posx_mision, posy_mision) );
            // Crear misión pixelart y meterla
            this->gamewindow.introducirMision(make_pair(posx_mision, posy_mision),mision + 1);
            mision++;
        }
    }


    /*-----------------------------------------------------*/

    qDebug("Inicializacion del jugador\n");
    /* Inicialización del QLabel del jugador */

    QLabel lay;
    pair<int, int> pos_tab = this->gamewindow.calculoPosicion(this->jugador.getPos(),
                                                              make_pair(this->jugador.getImagen().width(),
                                                                        this->jugador.getImagen().height()));
    lay.setParent(&(this->gamewindow));
    lay.setGeometry(pos_tab.first, pos_tab.second, this->jugador.getImagen().width(), this->jugador.getImagen().height());
    lay.setPixmap(this->jugador.getImagen());

    this->gamewindow.setLabel_jugador(&lay);

    qDebug("Inicializacion de enemigos\n");
    /* ------------------------ Inicialización de enemigos --------------------------------- */
    vector<pair<int, int>> pos_enemigos;
    i = 0;
    while (i < this->n_enemigos)
    {
        posx = rand() % COLUMNAS;
        posy = rand() % FILAS;
        vector<pair<int, int>>::iterator item;

        bool pos_valida = true;

        if ( !(posx == this->jugador.getX() && posy == this->jugador.getY()) )
        {
            for (item = this->bloqueos.begin(); item != this->bloqueos.end(); item++){
                qDebug("Comparacion: " + QString::number(posx).toLatin1() + ", " + QString::number(posy).toLatin1() + " == " +
                       QString::number(item->first).toLatin1() +
                       ", " + QString::number(item->second).toLatin1() + "\n");
                if ( item->first == posx && item->second == posy)
                    pos_valida = false;
            }
            for (item = pos_enemigos.begin(); item != pos_enemigos.end() ; item++){
                qDebug("Comparacion: " + QString::number(posx).toLatin1() + ", " + QString::number(posy).toLatin1() + " == " +
                       QString::number(item->first).toLatin1() +
                       ", " + QString::number(item->second).toLatin1() + "\n");
                if ( item->first == posx && item->second == posy)
                    pos_valida = false;
            }
        }else pos_valida = false;

        if ( pos_valida )
        {
            pos_enemigos.push_back(make_pair(posx, posy));
            qDebug("Posicion enemiga: " + QString::number(posx).toLatin1() + ", " + QString::number(posy).toLatin1() + "\n");
            i++;
        }
    }
    qDebug("Posiciones de enemigos calculadas\n");

    this->enemy_acorazado.setPos(pos_enemigos.at(this->enemy_acorazado.getId()));
    this->enemy_caza.setPos(pos_enemigos.at(this->enemy_caza.getId()));
    this->enemy_destructor.setPos(pos_enemigos.at(this->enemy_destructor.getId()));
    this->enemy_warship.setPos(pos_enemigos.at(this->enemy_warship.getId()));

    qDebug("Inicializacion QLabel de enemigos\n");
    /* Añadir el label para el enemigo acorazado */

    lay.setPixmap(this->enemy_acorazado.getImagen());
    pair<int, int> pos = this->gamewindow.calculoPosicion(this->enemy_acorazado.getPos(),
                                                          make_pair(this->enemy_acorazado.getImagen().width(),
                                                                    this->enemy_acorazado.getImagen().height()));
    lay.setGeometry(pos.first, pos.second,
                    this->enemy_acorazado.getImagen().width(),
                    this->enemy_acorazado.getImagen().height() );
    this->gamewindow.addLabel_enemy(&lay);

    /* Añadir el label para el enemigo caza */
    lay.setPixmap(this->enemy_caza.getImagen());
    pos = this->gamewindow.calculoPosicion(this->enemy_caza.getPos(),
                                           make_pair(this->enemy_caza.getImagen().width(),
                                                     this->enemy_caza.getImagen().height()));
    lay.setGeometry(pos.first, pos.second,
                    this->enemy_caza.getImagen().width(),
                    this->enemy_caza.getImagen().height() );
    this->gamewindow.addLabel_enemy(&lay);

    /* Añadir el label para el enemigo destructor */
    lay.setPixmap(this->enemy_destructor.getImagen());
    pos = this->gamewindow.calculoPosicion(this->enemy_destructor.getPos(),
                                           make_pair(this->enemy_destructor.getImagen().width(),
                                                     this->enemy_destructor.getImagen().height()));
    lay.setGeometry(pos.first, pos.second,
                    this->enemy_destructor.getImagen().width(),
                    this->enemy_destructor.getImagen().height() );
    this->gamewindow.addLabel_enemy(&lay);

    /* Añadir el label para el enemigo warship */
    lay.setPixmap(this->enemy_warship.getImagen());
    pos = this->gamewindow.calculoPosicion(this->enemy_warship.getPos(),
                                           make_pair(this->enemy_warship.getImagen().width(),
                                                     this->enemy_warship.getImagen().height()));
    lay.setGeometry(pos.first, pos.second,
                    this->enemy_warship.getImagen().width(),
                    this->enemy_warship.getImagen().height() );
    this->gamewindow.addLabel_enemy(&lay);

    /* ------------------------------------------------------------------------------------------------------- */

    this->enemy_acorazado.getId();

    this->gamewindow.setSaludBar(this->jugador.getVida());
    this->gamewindow.setEscudoBar(this->jugador.getEscudo());
    this->gamewindow.setAtqBar(this->jugador.getAtaque());
    this->gamewindow.setAtqEspBar(this->jugador.getAtaque_especial());
    this->gamewindow.setTurnoLCD(this->turno);
    this->gamewindow.setPosXLCD(this->jugador.getX());
    this->gamewindow.setPosYLCD(this->jugador.getY());
    this->gamewindow.setPALCD(this->jugador.getPuntos_accion());
    this->hab_cerrojo1 = false;
    this->hab_cerrojo2 = false;
    this->mision_recogida = false;
    qDebug("Constructor finalizado\n");
}

template <class N>
GameWindow Game<N>::getGameWindow() { return this->gamewindow; }

template <class N>
bool Game<N>::getGameOver() { return this->game_over; }

template <class N>
void Game<N>::setGameOver(bool game_over) { this->game_over = game_over; }

template <class N>
N Game<N>::getJugador() { return this->jugador; }

template <class N>
void Game<N>::setJugador(N jugador) { this->jugador = jugador; }

template <class N>
void Game<N>::iniciarGame(QApplication *a){

    this->gamewindow.show();

    while ( !this->game_over && this->gamewindow.isVisible() ) {
        a->processEvents();
        this->actualizarGame();
        Sleep(50);
    }

}

template <class N>
bool Game<N>::comprobarPosicion(int mov)
{
    pair<int, int> avance = this->jugador.getPos();
    switch ( mov )
    {
    case Mov::Up:
        avance.second -= this->jugador.getVelocidad();
        break;
    case Mov::Down:
        avance.second += this->jugador.getVelocidad();
        break;
    case Mov::Left:
        avance.first -= this->jugador.getVelocidad();
        break;
    case Mov::Right:
        avance.first += this->jugador.getVelocidad();
        break;
    }
    if ( avance.first >= 0 && avance.first < COLUMNAS &&
         avance.second >= 0 && avance.second < FILAS )
    {
        vector<pair<int, int>>::iterator item = this->bloqueos.begin();
        while (item != this->bloqueos.end() && !(item->first == avance.first && item->second == avance.second) )
        {
            item++;
        }
        if ( item != this->bloqueos.end() )
            return false;

        if (( avance.first == this->enemy_acorazado.getX() && avance.second == this->enemy_acorazado.getY() ) ||
                ( avance.first == this->enemy_caza.getX() && avance.second == this->enemy_caza.getY() ) ||
                ( avance.first == this->enemy_destructor.getX() && avance.second == this->enemy_destructor.getY() ) ||
                ( avance.first == this->enemy_warship.getX() && avance.second == this->enemy_warship.getY() )   )
            return false;
    }else return false;

    return true;
}

template <class N>
void Game<N>::mostrarMensaje(QString mensaje)
{
    QMessageBox msg;
    msg.setText(mensaje);
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setDefaultButton(QMessageBox::Ok);
    msg.setWindowTitle("Informe de situación");
    msg.setFont(QFont("Small Fonts", 12, QFont::Bold));
    msg.setStyleSheet("QMessageBox{ background-color: rgb(36, 49, 63);"
                      " border-style: outset;"
                      "border-width: 2px;"
                      "border-radius: 2px;"
                      "border-color: black;"
                      "color: white}\n"
                      "QPushButton{ background-color: rgba(72, 73, 88, 255);"
                                     " border-style: outset;"
                                     "border-width: 2px;"
                                     " border-radius: 2px;"
                                     "border-color: rgb(137, 139, 142);"
                                     "font: bold 14px;"
                                     "padding: 6px;"
                                     "color: rgb(220, 220, 220);}");
    msg.exec();
}

template <class N>
void Game<N>::actualizarGame(){


    /* Actualizar información en la pantalla */
    this->gamewindow.setSaludBar(this->jugador.getVida());
    this->gamewindow.setEscudoBar(this->jugador.getEscudo());
    this->gamewindow.setAtqBar(this->jugador.getAtaque());
    this->gamewindow.setAtqEspBar(this->jugador.getAtaque_especial());
    this->gamewindow.setPosXLCD(this->jugador.getX());
    this->gamewindow.setPosYLCD(this->jugador.getY());
    this->gamewindow.setPALCD(this->jugador.getPuntos_accion());

    /* Si se ha pulsado la habilidad, se reducen los puntos de acción a cero */
    if ( this->jugador.getPuntos_accion() > 0)
    {
        if (this->gamewindow.getHabilidad() && !this->hab_cerrojo2){
            if (!this->hab_cerrojo1){
                this->jugador.setPuntos_accion(0);
                this->hab_cerrojo2 = true;
                qDebug("Espere un turno...");
            }

        } else if (this->hab_cerrojo1 && this->hab_cerrojo2){
            qDebug("Habilidad Activada. ");
            this->jugador.habilidad(true);
            this->hab_cerrojo2 = false;

        } else if (!this->hab_cerrojo2){
            this->hab_cerrojo1 = false;
        }
    }



    /* Mover la posicion del jugador */
    if ( this->jugador.getPuntos_accion() > 0)
    {
        while (!this->gamewindow.emptyMov()) {

            if ( this->comprobarPosicion(this->gamewindow.frontMov()) )
            {
                this->jugador.mover(this->gamewindow.frontMov());
                this->gamewindow.setPosXLCD(this->jugador.getX());
                this->gamewindow.setPosYLCD(this->jugador.getY());
                this->gamewindow.setPALCD(this->jugador.getPuntos_accion());
            }
            this->gamewindow.popMov();
            QLabel lay;
            pair<int, int> pos_tab = this->gamewindow.calculoPosicion(this->jugador.getPos(),
                                                                      make_pair(this->jugador.getImagen().width(),
                                                                                this->jugador.getImagen().height()));
            lay.setParent(&(this->gamewindow));
            lay.setGeometry(pos_tab.first, pos_tab.second, this->jugador.getImagen().width(), this->jugador.getImagen().height());
            lay.setPixmap(this->jugador.getImagen());

            this->gamewindow.setLabel_jugador(&lay);

        }
    }

    /*
     * Si el jugador a pulsado el botón de atacar,
     * primero se comprueban los puntos de acción y luego se ataca
     *
    */

    if ( this->jugador.getPuntos_accion() > 0 )
    {
        // Comprobacion de existencia de enemigo
        if (this->gamewindow.getEnemigoSeleccionado() == this->enemy_acorazado.getId())
        {
            // Confirmacion de ataque
            if (this->gamewindow.getAtacarActivado())
            {
                // Ataquerl a acorazado
                if(this->jugador.atacar(this->enemy_acorazado.getNave()))
                {
                    this->mostrarMensaje("Ataque realizado con éxito.\n¡Buen trabajo capitán!");

                } else
                    this->mostrarMensaje("Enemigo fuera del alcance");


            }else if (this->gamewindow.getAtacarEspActivado())
            {
                // Ataquerl especial a acorazado
                if (this->jugador.atacarEsp(this->enemy_acorazado.getNave()))
                {
                    this->mostrarMensaje("Ataque realizado con éxito.\n¡Buen trabajo capitán!");

                } else
                    this->mostrarMensaje("Enemigo fuera del alcance");
            }

            if (this->enemy_acorazado.getVida() <= 0 )
            {
                this->enemy_acorazado.setPos(make_pair(-1, -1));
                this->gamewindow.borrarEnemigo(this->enemy_acorazado.getId());
            }

        }else if (this->gamewindow.getEnemigoSeleccionado() == this->enemy_caza.getId())
        {
            if (this->gamewindow.getAtacarActivado())
            {
                // Ataquerl a caza
                if (this->jugador.atacar(this->enemy_caza.getNave()))
                {
                    this->mostrarMensaje("Ataque realizado con éxito.\n¡Buen trabajo capitán!");

                }
                else
                    this->mostrarMensaje("Enemigo fuera del alcance");

            }else if (this->gamewindow.getAtacarEspActivado())
            {
                // Ataquerl especial a caza
                if (this->jugador.atacarEsp(this->enemy_caza.getNave()))
                    this->mostrarMensaje("Ataque realizado con éxito.\n¡Buen trabajo capitán!");
                else
                    this->mostrarMensaje("Enemigo fuera del alcance");
            }
            if (this->enemy_caza.getVida() <= 0 )
            {
                this->enemy_caza.setPos(make_pair(-1, -1));
                this->gamewindow.borrarEnemigo(this->enemy_caza.getId());
            }

        }else if (this->gamewindow.getEnemigoSeleccionado() == this->enemy_destructor.getId())
        {
            if (this->gamewindow.getAtacarActivado())
            {
                // Ataquerl a destructor
                if (this->jugador.atacar(this->enemy_destructor.getNave()))
                    this->mostrarMensaje("Ataque realizado con éxito.\n¡Buen trabajo capitán!");
                else
                    this->mostrarMensaje("Enemigo fuera del alcance");

            }else if (this->gamewindow.getAtacarEspActivado())
            {
                // Ataquerl especial a destructor
                if (this->jugador.atacarEsp(this->enemy_destructor.getNave()))
                    this->mostrarMensaje("Ataque realizado con éxito.\n¡Buen trabajo capitán!");
                else
                    this->mostrarMensaje("Enemigo fuera del alcance");
            }
            if (this->enemy_destructor.getVida() <= 0 )
            {
                this->enemy_destructor.setPos(make_pair(-1, -1));
                this->gamewindow.borrarEnemigo(this->enemy_destructor.getId());
            }


        }else if (this->gamewindow.getEnemigoSeleccionado() == this->enemy_warship.getId())
        {
            if (this->gamewindow.getAtacarActivado())
            {
                // Ataquerl a nave de batalla
                if (this->jugador.atacar(this->enemy_warship.getNave()))
                    this->mostrarMensaje("Ataque realizado con éxito.\n¡Buen trabajo capitán!");
                else
                    this->mostrarMensaje("Enemigo fuera del alcance");

            }else if (this->gamewindow.getAtacarEspActivado())
            {
                // Ataquerl especial a nave de batalla
                if (this->jugador.atacarEsp(this->enemy_warship.getNave()))
                    this->mostrarMensaje("Ataque realizado con éxito.\n¡Buen trabajo capitán!");
                else
                    this->mostrarMensaje("Enemigo fuera del alcance");
            }
            if (this->enemy_warship.getVida() <= 0 )
            {
                this->enemy_warship.setPos(make_pair(-1, -1));
                this->gamewindow.borrarEnemigo(this->enemy_warship.getId());
            }

        }
        // Una vez se realiza el ataque, se desactiva (SOLO SE GASTA UN PUNTO DE ACCION)
        this->gamewindow.setAtacarActivado(false);
        this->gamewindow.setAtacarEspActivado(false);
    }



    /*
     * Hasta aquí mover la nave jugador del jugador (TURNO DEL JUGADOR)
     */


    /*
     * Cuando acabe el turno del jugador se moverán los enemigos
     * y habrá que cambiar los QLabel del GameWindow
     */
    if (this->enemy_acorazado.getVida() <= 0 && this->enemy_caza.getVida() <= 0
            && this->enemy_destructor.getVida() <= 0
            && this->enemy_warship.getVida() <= 0 && mision_recogida){
        //Mensaje de victoria
        this->mostrarMensaje("Has completado la misión.");
        this->setGameOver(true);
    }

    if ( this->gamewindow.getTurnoTerminado()) {

        /* Cuando se acaben de mover los enemigos, vuelve a ser el turno del jugador */
        this->jugador.setPuntos_accion(PA_MAX);
        this->gamewindow.setTurnoLCD(++this->turno);
        this->gamewindow.setPosXLCD(this->jugador.getX());
        this->gamewindow.setPosYLCD(this->jugador.getY());
        this->gamewindow.setPALCD(this->jugador.getPuntos_accion());


        /*
         *  Se comprueba si se ha alcanzado alguna misión
         */
        if ( this->jugador.getPos() == this->misiones.back()){
            mision_recogida = true;
            //Hay que quitar el label final de mision en gamewindow
            //Mensaje de recogida completada
        }

        // Se muestra la misión activada

        // Se comprueba si se ha completado la misión

        vector<pair<int, int>> pos_en;
        pair<int, int> pos_tab;
        QLabel lay(&(this->gamewindow));

        /* Turno del acorazado enemigo*/
        pos_en.push_back(this->enemy_acorazado.getPos());
        pos_en.push_back(this->enemy_caza.getPos());
        pos_en.push_back(this->enemy_destructor.getPos());
        pos_en.push_back(this->enemy_warship.getPos());

        if ( this->enemy_acorazado.getVida() > 0 )
        {
            for ( int k = 0; k < this->enemy_acorazado.getPuntos_accion(); k++){


                this->enemy_acorazado.mover(this->jugador.getNave(), this->bloqueos, pos_en);

                pos_tab = this->gamewindow.calculoPosicion(this->enemy_acorazado.getPos(),
                                                           make_pair(this->enemy_acorazado.getImagen().width(),
                                                                     this->enemy_acorazado.getImagen().height()));
                lay.setPixmap(this->enemy_acorazado.getImagen());
                lay.setGeometry(pos_tab.first, pos_tab.second,
                                this->enemy_acorazado.getImagen().width(),
                                this->enemy_acorazado.getImagen().height());
                this->gamewindow.setLabel_enemy(this->enemy_acorazado.getId(), &lay);

                this->gamewindow.repaint();
                pos_en.at(this->enemy_acorazado.getId()) = this->enemy_acorazado.getPos();
                Sleep(500);
            }
        } else {
            this->enemy_acorazado.setPos(make_pair(-1, -1));
            this->gamewindow.borrarEnemigo(this->enemy_acorazado.getId());
        }

        if (this->jugador.getVida() == 0)
        {
            this->mostrarMensaje("Tu nave ha sido destruida.");
            this->setGameOver(true);
        }

        /* Turno del caza enemigo */

        if ( this->enemy_caza.getVida() > 0 )
        {
            for (int k = 0; k < this->enemy_caza.getPuntos_accion(); k++){
                this->enemy_caza.mover(this->jugador.getNave(), this->bloqueos, pos_en);
                pos_tab = this->gamewindow.calculoPosicion(this->enemy_caza.getPos(),
                                                           make_pair(this->enemy_caza.getImagen().width(),
                                                                     this->enemy_caza.getImagen().height()));
                lay.setPixmap(this->enemy_caza.getImagen());
                lay.setGeometry(pos_tab.first, pos_tab.second,
                                this->enemy_caza.getImagen().width(),
                                this->enemy_caza.getImagen().height());
                this->gamewindow.setLabel_enemy(this->enemy_caza.getId(), &lay);

                this->gamewindow.repaint();
                pos_en.at(this->enemy_caza.getId()) = this->enemy_caza.getPos();
                Sleep(500);
            }
        } else {
            this->enemy_caza.setPos(make_pair(-1, -1));
            this->gamewindow.borrarEnemigo(this->enemy_caza.getId());
        }

        if (this->jugador.getVida() == 0)
        {
            this->mostrarMensaje("Tu nave ha sido destruida.");
            this->setGameOver(true);
        }

        /* Turno del destructor enemigo */

        if ( this->enemy_destructor.getVida() > 0 )
        {
            for (int k = 0; k < this->enemy_destructor.getPuntos_accion(); k++){
                this->enemy_destructor.mover(this->jugador.getNave(), this->bloqueos, pos_en);
                pos_tab = this->gamewindow.calculoPosicion(this->enemy_destructor.getPos(),
                                                           make_pair(this->enemy_destructor.getImagen().width(),
                                                                     this->enemy_destructor.getImagen().height()));
                lay.setPixmap(this->enemy_destructor.getImagen());
                lay.setGeometry(pos_tab.first, pos_tab.second,
                                this->enemy_destructor.getImagen().width(),
                                this->enemy_destructor.getImagen().height());
                this->gamewindow.setLabel_enemy(this->enemy_destructor.getId(), &lay);
                this->gamewindow.repaint();
                pos_en.at(this->enemy_destructor.getId()) = this->enemy_destructor.getPos();
                Sleep(500);
            }
        } else {
            this->enemy_destructor.setPos(make_pair(-1, -1));
            this->gamewindow.borrarEnemigo(this->enemy_destructor.getId());
        }

        if (this->jugador.getVida() == 0)
        {
            this->mostrarMensaje("Tu nave ha sido destruida.");
            this->setGameOver(true);
        }

        /* Turno del warship enemigo */

        if (this->enemy_warship.getVida() > 0)
        {
            for (int k = 0; k < this->enemy_warship.getPuntos_accion(); k++){
                this->enemy_warship.mover(this->jugador.getNave(), this->bloqueos, pos_en);
                pos_tab = this->gamewindow.calculoPosicion(this->enemy_warship.getPos(),
                                                           make_pair(this->enemy_warship.getImagen().width(),
                                                                     this->enemy_warship.getImagen().height()));
                lay.setPixmap(this->enemy_warship.getImagen());
                lay.setGeometry(pos_tab.first, pos_tab.second,
                                this->enemy_warship.getImagen().width(),
                                this->enemy_warship.getImagen().height());
                this->gamewindow.setLabel_enemy(this->enemy_warship.getId(), &lay);
                this->gamewindow.repaint();
                pos_en.at(this->enemy_warship.getId()) = this->enemy_warship.getPos();
                Sleep(500);
            }
        } else {
            this->enemy_warship.setPos(make_pair(-1, -1));
            this->gamewindow.borrarEnemigo(this->enemy_warship.getId());
        }

        if (this->jugador.getVida() == 0)
        {
            this->mostrarMensaje("Tu nave ha sido destruida.");
            this->setGameOver(true);
        }

        while ( !this->gamewindow.emptyMov() )
            this->gamewindow.popMov();

        this->gamewindow.setTurnoTerminado(false);
        this->jugador.setPuntos_accion(PA_MAX);
        this->gamewindow.setAtacarActivado(false);

        if (this->hab_cerrojo2){
            qDebug("Turno completado:");
            this->hab_cerrojo1 = true;

        } else if (this->hab_cerrojo1 && !this->hab_cerrojo2){
            qDebug("Habilidad Desactivada");
            this->jugador.habilidad(false);
        }


    }


    /* ---------------------------- */

    /* Cambiar la información del enemigo en la interfaz */
    int salud = 0;
    int escudo = 0;
    int atq = 0;
    int atq_esp = 0;
    int px = 0, py = 0;
    if ( this->enemy_acorazado.getId() == this->gamewindow.getEnemigoSeleccionado() )
    {
        salud = this->enemy_acorazado.getVida();
        escudo = this->enemy_acorazado.getEscudo();
        atq = this->enemy_acorazado.getAtaque();
        atq_esp = this->enemy_acorazado.getAtaque_especial();
        px = this->enemy_acorazado.getX();
        py = this->enemy_acorazado.getY();
    }else if ( this->enemy_caza.getId() == this->gamewindow.getEnemigoSeleccionado() )
    {
        salud = this->enemy_caza.getVida();
        escudo = this->enemy_caza.getEscudo();
        atq = this->enemy_caza.getAtaque();
        atq_esp = this->enemy_caza.getAtaque_especial();
        px = this->enemy_caza.getX();
        py = this->enemy_caza.getY();
    }else if ( this->enemy_destructor.getId() == this->gamewindow.getEnemigoSeleccionado() )
    {
        salud = this->enemy_destructor.getVida();
        escudo = this->enemy_destructor.getEscudo();
        atq = this->enemy_destructor.getAtaque();
        atq_esp = this->enemy_destructor.getAtaque_especial();
        px = this->enemy_destructor.getX();
        py = this->enemy_destructor.getY();
    }else if ( this->enemy_warship.getId() == this->gamewindow.getEnemigoSeleccionado() )
    {
        salud = this->enemy_warship.getVida();
        escudo = this->enemy_warship.getEscudo();
        atq = this->enemy_warship.getAtaque();
        atq_esp = this->enemy_warship.getAtaque_especial();
        px = this->enemy_warship.getX();
        py = this->enemy_warship.getY();
    }
    this->gamewindow.setSaludBar_enemy(salud);
    this->gamewindow.setEscudoBar_enemy(escudo);
    this->gamewindow.setAtqBar_enemy(atq);
    this->gamewindow.setAtqEspBar_enemy(atq_esp);
    this->gamewindow.setPosXLCD_enemy(px);
    this->gamewindow.setPosYLCD_enemy(py);


    /*
     * El repaint lo último
     */
    this->gamewindow.repaint();
}

template class Game<Acorazado>;
template class Game<Caza>;
template class Game<Destructor>;
template class Game<Warship>;

