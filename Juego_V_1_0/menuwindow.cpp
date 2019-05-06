#include "menuwindow.h"
#include "ui_menuwindow.h"


MenuWindow::MenuWindow( QWidget *parent ) :
    QWidget(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);

    connect(ui->jugarButton, SIGNAL(clicked()), this, SLOT(empezarJuego()));
    connect(ui->salirButton, SIGNAL(clicked()), this, SLOT(salir()));
    connect(ui->cazaButton, SIGNAL(clicked()), this, SLOT(elegirNave()));
    connect(ui->acorazadoButton, SIGNAL(clicked()), this, SLOT(elegirNave()));
    connect(ui->batallaButton, SIGNAL(clicked()), this, SLOT(elegirNave()));
    connect(ui->destructorButton, SIGNAL(clicked()), this, SLOT(elegirNave()));

    ui->saludBar->setValue(28);
    ui->escudoBar->setValue(28);
    ui->ataqueBar->setValue(100);
    ui->ataqueEspBar->setValue(57);
    this->tipo_nave = Tipo::tipo_caza;
    ui->imagenNave->setPixmap(QPixmap(":/images/caza_menu.png"));
    ui->cazaButton->click();
    this->jugar = false;
}

MenuWindow::MenuWindow(MenuWindow &m){
    this->ui = m.ui;
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

bool MenuWindow::getJugar() { return this->jugar; }

void MenuWindow::empezarJuego(){

    if ( this->tipo_nave == Tipo::tipo_caza || this->tipo_nave == Tipo::tipo_acorazado ||
         this->tipo_nave == Tipo::tipo_destructor || this->tipo_nave == Tipo::tipo_warship ){
        this->jugar = true;
        this->close();
    }
}

void MenuWindow::salir() {
    exit(0);
}


void MenuWindow::elegirNave() {
    QPixmap pix;

    if ( ui->cazaButton->isChecked() ){
        pix.load(":/images/caza_menu.png");
        ui->saludBar->setValue(28);
        ui->escudoBar->setValue(28);
        ui->ataqueBar->setValue(100);
        ui->ataqueEspBar->setValue(57);
        this->tipo_nave = Tipo::tipo_caza;
    }else if ( ui->acorazadoButton->isChecked() ){
        pix.load(":/images/acorazado_menu.png");
        ui->saludBar->setValue(100);
        ui->escudoBar->setValue(100);
        ui->ataqueBar->setValue(14);
        ui->ataqueEspBar->setValue(28);
        this->tipo_nave = Tipo::tipo_acorazado;
    }else if ( ui->batallaButton->isChecked() ){
        pix.load(":/images/warship_menu.png");
        ui->saludBar->setValue(57);
        ui->escudoBar->setValue(57);
        ui->ataqueBar->setValue(57);
        ui->ataqueEspBar->setValue(57);
        this->tipo_nave = Tipo::tipo_warship;
    }else if ( ui->destructorButton->isChecked() ){
        pix.load(":/images/destructor_menu.png");
        ui->saludBar->setValue(42);
        ui->escudoBar->setValue(42);
        ui->ataqueBar->setValue(28);
        ui->ataqueEspBar->setValue(100);
        this->tipo_nave = Tipo::tipo_destructor;
    }

    ui->imagenNave->setPixmap(pix.scaled(QSize(100,100)));
}

int MenuWindow::getTipo() { return this->tipo_nave; }
void MenuWindow::setTipo(int tipo) { this->tipo_nave = tipo; }
