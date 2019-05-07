/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QFrame *line;
    QGroupBox *groupBox;
    QLabel *label_4;
    QLabel *label_3;
    QProgressBar *escudoBar;
    QLabel *label;
    QProgressBar *atqBar;
    QProgressBar *saludBar;
    QLabel *label_2;
    QProgressBar *atqespBar;
    QLCDNumber *posXLCD;
    QLabel *label_9;
    QLCDNumber *posYLCD;
    QLCDNumber *paLCD;
    QLabel *label_5;
    QPushButton *habilidadButton;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QLabel *label_7;
    QProgressBar *escudoBar_enemigo;
    QLabel *label_8;
    QProgressBar *atqBar_enemigo;
    QProgressBar *saludBar_enemigo;
    QLabel *label_10;
    QProgressBar *atqespBar_enemigo;
    QLCDNumber *posXLCD_enemigo;
    QLabel *label_11;
    QLCDNumber *posYLCD_enemigo;
    QGroupBox *groupBox_3;
    QPushButton *leftButton;
    QPushButton *downButton;
    QPushButton *atacarButton;
    QPushButton *upButton;
    QPushButton *rightButton;
    QPushButton *atacarEspButton;
    QLCDNumber *turnoLCD;
    QLabel *label_13;
    QPushButton *terminarTurnoButton;
    QLabel *label_12;

    void setupUi(QWidget *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QStringLiteral("GameWindow"));
        GameWindow->resize(1026, 646);
        GameWindow->setMinimumSize(QSize(1026, 646));
        GameWindow->setMaximumSize(QSize(1026, 646));
        GameWindow->setStyleSheet(QLatin1String("QWidget#GameWindow{\n"
"background-color: rgb(36, 49, 63);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 2px;\n"
"   border-color: black;\n"
"	color: rgb(63, 85, 101);\n"
"	font: 9pt \"Small Fonts\";\n"
"}\n"
"QLCDNumber {\n"
"	\n"
"	color: rgb(6, 176, 37);\n"
"	border-color: rgb(37, 38, 91);\n"
"	background-color:rgb(85, 85, 127);\n"
"}\n"
"\n"
"QPushButton#upButton {\n"
"border-image: url(:/images/flecha_U.png);\n"
"}\n"
"\n"
"QPushButton#upButton:pressed {\n"
"border-image: url(:/images/flecha_pressed_U.png);\n"
"}\n"
"\n"
"QPushButton#downButton {\n"
"border-image: url(:/images/flecha_D.png);\n"
"}\n"
"\n"
"QPushButton#downButton:pressed {\n"
"border-image: url(:/images/flecha_pressed_D.png);\n"
"}\n"
"\n"
"QPushButton#leftButton {\n"
"border-image: url(:/images/flecha_L.png);\n"
"}\n"
"\n"
"QPushButton#leftButton:pressed {\n"
"border-image: url(:/images/flecha_pressed_L.png);\n"
"}\n"
"\n"
"QPushButton#rightButton {\n"
"border-image: url(:/images/flecha_R.png);\n"
"}\n"
"\n"
""
                        "QPushButton#rightButton:pressed {\n"
"border-image: url(:/images/flecha_pressed_R.png);\n"
"}\n"
"\n"
"QPushButton#atacarButton { \n"
"background-color: rgba(72, 73, 88, 255);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 2px;\n"
"   border-color: rgb(137, 139, 142);\n"
"    padding: 6px;\n"
"\n"
"	color: rgb(220, 220, 220);\n"
"	font: bold 11pt \"Small Fonts\";\n"
"}\n"
"\n"
"QPushButton#atacarEspButton { \n"
"background-color: rgba(72, 73, 88, 255);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 2px;\n"
"   border-color: rgb(137, 139, 142);\n"
"    padding: 6px;\n"
"\n"
"	color: rgb(220, 220, 220);\n"
"	font: bold 10pt \"Small Fonts\";\n"
"}\n"
"\n"
"QPushButton#habilidadButton { \n"
"background-color: rgba(72, 73, 88, 255);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 2px;\n"
"   border-color: rgb(137, 139, 142);\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"\n"
"	color: rgb(220, 220, 220);\n"
"	font: bold 11pt"
                        " \"Small Fonts\";\n"
"}\n"
"\n"
"QPushButton#terminarTurnoButton { \n"
"background-color: rgba(72, 73, 88, 255);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 2px;\n"
"   border-color: rgb(137, 139, 142);\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"\n"
"	color: rgb(220, 220, 220);\n"
"	font: bold 11pt \"Small Fonts\";\n"
"}\n"
"\n"
"QPushButton#atacarButton:pressed {\n"
"	border-style: inset;\n"
"	border-color: rgb(30, 39, 90);\n"
"}\n"
"\n"
"QPushButton#habilidadButton:pressed {\n"
"	border-style: inset;\n"
"	border-color: rgb(30, 39, 90);\n"
"}\n"
"\n"
"\n"
"QPushButton#terminarTurnoButton:pressed {\n"
"	border-style: inset;\n"
"	border-color: rgb(30, 39, 90);\n"
"}\n"
"\n"
"QGroupBox#groupBox {\n"
"background-color: rgba(72, 73, 88, 255);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 2px;\n"
"   border-color: rgb(137, 139, 142);\n"
"    padding: 6px;\n"
"color: rgb(220, 220, 220);\n"
"font:  8pt \"Small Fonts\";\n"
"}\n"
"\n"
"QGroupBox#gr"
                        "oupBox_2 {\n"
" \n"
"background-color: rgba(72, 73, 88, 255);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 2px;\n"
"   border-color: rgb(137, 139, 142);\n"
"    padding: 6px;\n"
"color: rgb(220, 220, 220);\n"
"font: 8pt \"Small Fonts\";\n"
"}\n"
"\n"
"QGroupBox#groupBox_3 {\n"
"border-style: outlet;\n"
"border-color: transparent;\n"
"background-color: transparent;\n"
"color: rgb(220, 220, 220);\n"
"font:  8pt \"Small Fonts\";\n"
"}\n"
"\n"
"QLabel{\n"
"color: rgb(220, 220, 220);\n"
"font:  10pt \"Small Fonts\";\n"
"\n"
"}\n"
"\n"
"QLine {\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QMessageBox{\n"
"background-color: rgb(36, 49, 63);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 2px;\n"
"   border-color: black;\n"
"	color: rgb(63, 85, 101);\n"
"	font: 12pt \"Small Fonts\";\n"
"}\n"
"\n"
"QPushButton{\n"
"background-color: rgba(72, 73, 88, 255);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 2px;\n"
"   border-colo"
                        "r: rgb(137, 139, 142);\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"\n"
"	color: rgb(220, 220, 220);\n"
"	font: bold 11pt \"Small Fonts\";\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed {\n"
"	border-style: inset;\n"
"	border-color: rgb(30, 39, 90);\n"
"}\n"
"\n"
"QProgressBar{\n"
"background-color: rgb(0, 0, 0);\n"
"border: 2px solid grey;\n"
"}\n"
"QProgressBar:chunk{\n"
"background-color: rgb(170, 0, 0);\n"
"}\n"
"\n"
""));
        line = new QFrame(GameWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(740, 25, 11, 596));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(GameWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(760, 230, 261, 211));
        QFont font;
        font.setFamily(QStringLiteral("Small Fonts"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        groupBox->setFont(font);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 110, 71, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Small Fonts"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_4->setFont(font1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 61, 21));
        label_3->setFont(font1);
        escudoBar = new QProgressBar(groupBox);
        escudoBar->setObjectName(QStringLiteral("escudoBar"));
        escudoBar->setGeometry(QRect(87, 50, 161, 23));
        escudoBar->setValue(24);
        escudoBar->setTextVisible(false);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 61, 21));
        label->setFont(font1);
        atqBar = new QProgressBar(groupBox);
        atqBar->setObjectName(QStringLiteral("atqBar"));
        atqBar->setGeometry(QRect(87, 80, 161, 23));
        atqBar->setValue(24);
        atqBar->setTextVisible(false);
        saludBar = new QProgressBar(groupBox);
        saludBar->setObjectName(QStringLiteral("saludBar"));
        saludBar->setGeometry(QRect(87, 20, 161, 23));
        saludBar->setValue(24);
        saludBar->setTextVisible(false);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 61, 21));
        label_2->setFont(font1);
        atqespBar = new QProgressBar(groupBox);
        atqespBar->setObjectName(QStringLiteral("atqespBar"));
        atqespBar->setGeometry(QRect(87, 110, 161, 23));
        atqespBar->setValue(24);
        atqespBar->setTextVisible(false);
        posXLCD = new QLCDNumber(groupBox);
        posXLCD->setObjectName(QStringLiteral("posXLCD"));
        posXLCD->setGeometry(QRect(90, 180, 51, 21));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 180, 71, 16));
        label_9->setFont(font1);
        posYLCD = new QLCDNumber(groupBox);
        posYLCD->setObjectName(QStringLiteral("posYLCD"));
        posYLCD->setGeometry(QRect(140, 180, 51, 21));
        paLCD = new QLCDNumber(groupBox);
        paLCD->setObjectName(QStringLiteral("paLCD"));
        paLCD->setGeometry(QRect(90, 140, 51, 23));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 140, 81, 20));
        label_5->setFont(font1);
        habilidadButton = new QPushButton(groupBox);
        habilidadButton->setObjectName(QStringLiteral("habilidadButton"));
        habilidadButton->setGeometry(QRect(149, 140, 101, 31));
        habilidadButton->setStyleSheet(QStringLiteral(""));
        habilidadButton->setCheckable(false);
        groupBox_2 = new QGroupBox(GameWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(760, 450, 261, 171));
        groupBox_2->setFont(font);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 110, 71, 21));
        label_6->setFont(font1);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 80, 61, 21));
        label_7->setFont(font1);
        escudoBar_enemigo = new QProgressBar(groupBox_2);
        escudoBar_enemigo->setObjectName(QStringLiteral("escudoBar_enemigo"));
        escudoBar_enemigo->setGeometry(QRect(87, 50, 161, 23));
        escudoBar_enemigo->setValue(24);
        escudoBar_enemigo->setTextVisible(false);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 20, 61, 21));
        label_8->setFont(font1);
        atqBar_enemigo = new QProgressBar(groupBox_2);
        atqBar_enemigo->setObjectName(QStringLiteral("atqBar_enemigo"));
        atqBar_enemigo->setGeometry(QRect(87, 80, 161, 23));
        atqBar_enemigo->setValue(24);
        atqBar_enemigo->setTextVisible(false);
        saludBar_enemigo = new QProgressBar(groupBox_2);
        saludBar_enemigo->setObjectName(QStringLiteral("saludBar_enemigo"));
        saludBar_enemigo->setGeometry(QRect(87, 20, 161, 23));
        saludBar_enemigo->setValue(24);
        saludBar_enemigo->setTextVisible(false);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 50, 61, 21));
        label_10->setFont(font1);
        atqespBar_enemigo = new QProgressBar(groupBox_2);
        atqespBar_enemigo->setObjectName(QStringLiteral("atqespBar_enemigo"));
        atqespBar_enemigo->setGeometry(QRect(87, 110, 161, 23));
        atqespBar_enemigo->setValue(24);
        atqespBar_enemigo->setTextVisible(false);
        posXLCD_enemigo = new QLCDNumber(groupBox_2);
        posXLCD_enemigo->setObjectName(QStringLiteral("posXLCD_enemigo"));
        posXLCD_enemigo->setGeometry(QRect(90, 140, 51, 21));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 140, 71, 16));
        label_11->setFont(font1);
        posYLCD_enemigo = new QLCDNumber(groupBox_2);
        posYLCD_enemigo->setObjectName(QStringLiteral("posYLCD_enemigo"));
        posYLCD_enemigo->setGeometry(QRect(140, 140, 51, 21));
        groupBox_3 = new QGroupBox(GameWindow);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(760, 60, 271, 171));
        groupBox_3->setFont(font);
        leftButton = new QPushButton(groupBox_3);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(0, 100, 80, 61));
        leftButton->setStyleSheet(QLatin1String("QPushBtton{\n"
"border-image: url(:/images/flecha_L.png);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"border-image: url(:/images/flecha_pressed_L.png);\n"
"}"));
        downButton = new QPushButton(groupBox_3);
        downButton->setObjectName(QStringLiteral("downButton"));
        downButton->setGeometry(QRect(90, 100, 80, 61));
        downButton->setStyleSheet(QStringLiteral(""));
        atacarButton = new QPushButton(groupBox_3);
        atacarButton->setObjectName(QStringLiteral("atacarButton"));
        atacarButton->setGeometry(QRect(0, 30, 80, 61));
        atacarButton->setMinimumSize(QSize(80, 61));
        atacarButton->setMaximumSize(QSize(80, 61));
        atacarButton->setStyleSheet(QStringLiteral(""));
        upButton = new QPushButton(groupBox_3);
        upButton->setObjectName(QStringLiteral("upButton"));
        upButton->setGeometry(QRect(90, 30, 80, 61));
        upButton->setStyleSheet(QStringLiteral(""));
        rightButton = new QPushButton(groupBox_3);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(180, 100, 80, 61));
        rightButton->setStyleSheet(QStringLiteral(""));
        atacarEspButton = new QPushButton(groupBox_3);
        atacarEspButton->setObjectName(QStringLiteral("atacarEspButton"));
        atacarEspButton->setGeometry(QRect(180, 30, 80, 61));
        atacarEspButton->setMinimumSize(QSize(80, 61));
        atacarEspButton->setMaximumSize(QSize(80, 61));
        atacarEspButton->setStyleSheet(QStringLiteral(""));
        turnoLCD = new QLCDNumber(GameWindow);
        turnoLCD->setObjectName(QStringLiteral("turnoLCD"));
        turnoLCD->setGeometry(QRect(893, 10, 121, 51));
        turnoLCD->setStyleSheet(QStringLiteral(""));
        label_13 = new QLabel(GameWindow);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(3, 3, 720, 640));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMinimumSize(QSize(720, 640));
        label_13->setMaximumSize(QSize(720, 640));
        label_13->setStyleSheet(QLatin1String("border-image: url(:/images/fondo.png);\n"
"border-color: rgb(0, 85, 127);\n"
"border-width: 2px;"));
        terminarTurnoButton = new QPushButton(GameWindow);
        terminarTurnoButton->setObjectName(QStringLiteral("terminarTurnoButton"));
        terminarTurnoButton->setGeometry(QRect(760, 10, 120, 51));
        terminarTurnoButton->setMinimumSize(QSize(120, 51));
        terminarTurnoButton->setMaximumSize(QSize(120, 51));
        terminarTurnoButton->setStyleSheet(QStringLiteral(""));
        label_12 = new QLabel(GameWindow);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(900, 10, 71, 51));
        label_12->setFont(font1);
        label_13->raise();
        line->raise();
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        turnoLCD->raise();
        terminarTurnoButton->raise();
        label_12->raise();

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QWidget *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "Juego de naves", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("GameWindow", "Jugador", Q_NULLPTR));
        label_4->setText(QApplication::translate("GameWindow", "Atq.Esp", Q_NULLPTR));
        label_3->setText(QApplication::translate("GameWindow", "Ataque", Q_NULLPTR));
        label->setText(QApplication::translate("GameWindow", "Salud", Q_NULLPTR));
        label_2->setText(QApplication::translate("GameWindow", "Escudo", Q_NULLPTR));
        label_9->setText(QApplication::translate("GameWindow", "Posicion", Q_NULLPTR));
        label_5->setText(QApplication::translate("GameWindow", "P.Accion", Q_NULLPTR));
        habilidadButton->setText(QApplication::translate("GameWindow", "POWER", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("GameWindow", "Enemigo", Q_NULLPTR));
        label_6->setText(QApplication::translate("GameWindow", "Atq.Esp", Q_NULLPTR));
        label_7->setText(QApplication::translate("GameWindow", "Ataque", Q_NULLPTR));
        label_8->setText(QApplication::translate("GameWindow", "Salud", Q_NULLPTR));
        label_10->setText(QApplication::translate("GameWindow", "Escudo", Q_NULLPTR));
        label_11->setText(QApplication::translate("GameWindow", "Posicion", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        leftButton->setText(QString());
        downButton->setText(QString());
        atacarButton->setText(QApplication::translate("GameWindow", "Atacar", Q_NULLPTR));
        upButton->setText(QString());
        rightButton->setText(QString());
        atacarEspButton->setText(QApplication::translate("GameWindow", "At. Esp", Q_NULLPTR));
        label_13->setText(QString());
        terminarTurnoButton->setText(QApplication::translate("GameWindow", "Fin turno", Q_NULLPTR));
        label_12->setText(QApplication::translate("GameWindow", "RONDA", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
