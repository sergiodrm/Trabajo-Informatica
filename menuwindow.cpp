#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
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

}

MenuWindow::MenuWindow(MenuWindow &m){
    this->ui = m.ui;
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::empezarJuego(){

}

void MenuWindow::salir() {
    exit(0);
}

void MenuWindow::elegirNave() {
    QPixmap pix;

    QDir dir(":/");
    cout << dir.absolutePath().toStdString() << endl;




    if ( ui->cazaButton->isChecked() ){
        pix.load(":/images/caza.png");
        ui->saludBar->setValue(28);
        ui->escudoBar->setValue(28);
        ui->ataqueBar->setValue(100);
        ui->ataqueEspBar->setValue(57);
    }else if ( ui->acorazadoButton->isChecked() ){
        pix.load(":/images/acorazado.png");
        ui->saludBar->setValue(100);
        ui->escudoBar->setValue(100);
        ui->ataqueBar->setValue(14);
        ui->ataqueEspBar->setValue(28);
    }else if ( ui->batallaButton->isChecked() ){
        pix.load(":/images/batalla.png");
        ui->saludBar->setValue(57);
        ui->escudoBar->setValue(57);
        ui->ataqueBar->setValue(57);
        ui->ataqueEspBar->setValue(57);
    }else if ( ui->destructorButton->isChecked() ){
        pix.load(":/images/destructor.png");
        ui->saludBar->setValue(42);
        ui->escudoBar->setValue(42);
        ui->ataqueBar->setValue(28);
        ui->ataqueEspBar->setValue(100);
    }

    ui->imagenNave->setPixmap(pix);


}
