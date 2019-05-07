/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QGroupBox *groupBox;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *imagenNave;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QProgressBar *ataqueEspBar;
    QProgressBar *ataqueBar;
    QProgressBar *escudoBar;
    QProgressBar *saludBar;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QToolBox *toolBox;
    QWidget *toolPrincipal;
    QPushButton *jugarButton;
    QPushButton *salirButton;
    QWidget *toolSeleccion;
    QRadioButton *cazaButton;
    QRadioButton *acorazadoButton;
    QRadioButton *batallaButton;
    QRadioButton *destructorButton;

    void setupUi(QWidget *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QStringLiteral("MenuWindow"));
        MenuWindow->resize(532, 300);
        MenuWindow->setMinimumSize(QSize(532, 300));
        MenuWindow->setMaximumSize(QSize(532, 300));
        MenuWindow->setCursor(QCursor(Qt::CrossCursor));
        MenuWindow->setMouseTracking(false);
        MenuWindow->setStyleSheet(QLatin1String("QWidget#MenuWindow{\n"
"background-color: rgb(36, 49, 63);\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 2px;\n"
"   border-color: black;\n"
"	color: rgb(63, 85, 101);\n"
"	font: 9pt \"Small Fonts\";\n"
"}\n"
"\n"
"QFrame#frame{\n"
"    border-style: outset;\n"
"	background-color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QFrame#frame_3{\n"
"    border-style: outset;\n"
"}\n"
"\n"
"QPushButton#jugarButton { \n"
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
"\n"
"QPushButton#jugarButton:pressed {\n"
"	border-style: inset;\n"
"	border-color: rgb(30, 39, 90);\n"
"}\n"
"\n"
"QPushButton#salirButton { \n"
"background-color: rgba(72, 73, 88, 255);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 2px;\n"
"border-color: rgb(137, 13"
                        "9, 142);\n"
"font: bold 14px;\n"
"padding: 6px;\n"
"\n"
"color: rgb(220, 220, 220);\n"
"font: bold 11pt \"Small Fonts\";\n"
"}\n"
"\n"
"QPushButton#salirButton:pressed {\n"
"	border-style: inset;\n"
"	border-color: rgb(30, 39, 90);\n"
"}\n"
"\n"
"QGroupBox#groupBox{\n"
"background-color: rgba(72, 73, 88, 255);\n"
"border-style: outset;\n"
"border-width: 2px;\n"
"border-radius: 2px;\n"
"border-color: rgb(137, 139, 142);\n"
"padding: 6px;\n"
"\n"
"color: rgb(220, 220, 220);\n"
"font: bold 8pt \"Small Fonts\";\n"
"}\n"
"\n"
"\n"
"QToolBox{\n"
"     icon-size: 40px;\n"
"	 background: #1E2736;\n"
"}\n"
"\n"
"QToolBox QScrollArea>QWidget>QWidget\n"
"{\n"
"    background-color: rgb(36,49,63);\n"
"}\n"
"\n"
"QToolBox::tab {\n"
"\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(36, 49, 63, 255), stop:1    rgba(72, 73, 88, 255));\n"
"    border-radius: 2px;\n"
"	color: rgb(220, 220, 220);\n"
"	font: 12pt \"Small Fonts\";\n"
"}\n"
"\n"
"QRadioButton{\n"
"	color: rgb(220, 220, 220)"
                        ";\n"
"	font: 11pt \"Small Fonts\";\n"
"}\n"
"QRadioButton::indicator{\n"
"color: rgb(137, 139, 142);\n"
"width: 10px;\n"
"height: 10px;\n"
"background: white;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-radius: 7px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"color: black;\n"
"background: black;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-radius: 7px;\n"
"border-color: white;\n"
"}\n"
"\n"
"QLabel{\n"
"color:rgb(220, 220, 220);\n"
"	font: 10pt \"Small Fonts\";\n"
"}\n"
"\n"
"QProgressBar\n"
"{\n"
"    background: #010327;\n"
"    color: #0a9dff;\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-color: rgb(64, 88, 127);\n"
"    border-radius: 2px;\n"
"    text-align: left;\n"
"\n"
"}\n"
"QProgressBar::chunk\n"
"{\n"
"    background-color: rgb(0, 170, 255);\n"
"}\n"
"\n"
""));
        groupBox = new QGroupBox(MenuWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(290, 10, 231, 281));
        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(12, 9, 211, 131));
        frame->setMinimumSize(QSize(211, 131));
        frame->setMaximumSize(QSize(211, 131));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        imagenNave = new QLabel(frame);
        imagenNave->setObjectName(QStringLiteral("imagenNave"));
        imagenNave->setMinimumSize(QSize(0, 0));
        imagenNave->setMaximumSize(QSize(300, 300));
        imagenNave->setScaledContents(false);
        imagenNave->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(imagenNave);

        frame_3 = new QFrame(groupBox);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(10, 140, 211, 131));
        frame_3->setMinimumSize(QSize(211, 131));
        frame_3->setMaximumSize(QSize(211, 131));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ataqueEspBar = new QProgressBar(frame_3);
        ataqueEspBar->setObjectName(QStringLiteral("ataqueEspBar"));
        ataqueEspBar->setValue(0);
        ataqueEspBar->setAlignment(Qt::AlignCenter);
        ataqueEspBar->setTextVisible(false);

        gridLayout->addWidget(ataqueEspBar, 3, 1, 1, 1);

        ataqueBar = new QProgressBar(frame_3);
        ataqueBar->setObjectName(QStringLiteral("ataqueBar"));
        ataqueBar->setValue(0);
        ataqueBar->setTextVisible(false);

        gridLayout->addWidget(ataqueBar, 2, 1, 1, 1);

        escudoBar = new QProgressBar(frame_3);
        escudoBar->setObjectName(QStringLiteral("escudoBar"));
        escudoBar->setValue(0);
        escudoBar->setTextVisible(false);

        gridLayout->addWidget(escudoBar, 1, 1, 1, 1);

        saludBar = new QProgressBar(frame_3);
        saludBar->setObjectName(QStringLiteral("saludBar"));
        saludBar->setValue(0);
        saludBar->setTextVisible(false);

        gridLayout->addWidget(saludBar, 0, 1, 1, 1);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        frame_2 = new QFrame(MenuWindow);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(19, 9, 261, 281));
        frame_2->setStyleSheet(QStringLiteral(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        toolBox = new QToolBox(frame_2);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setCursor(QCursor(Qt::CrossCursor));
        toolBox->setStyleSheet(QStringLiteral(""));
        toolPrincipal = new QWidget();
        toolPrincipal->setObjectName(QStringLiteral("toolPrincipal"));
        toolPrincipal->setGeometry(QRect(0, 0, 237, 168));
        jugarButton = new QPushButton(toolPrincipal);
        jugarButton->setObjectName(QStringLiteral("jugarButton"));
        jugarButton->setGeometry(QRect(20, 30, 201, 41));
        jugarButton->setMinimumSize(QSize(201, 41));
        jugarButton->setMaximumSize(QSize(201, 41));
        salirButton = new QPushButton(toolPrincipal);
        salirButton->setObjectName(QStringLiteral("salirButton"));
        salirButton->setGeometry(QRect(20, 90, 201, 41));
        salirButton->setMinimumSize(QSize(201, 41));
        salirButton->setMaximumSize(QSize(201, 41));
        toolBox->addItem(toolPrincipal, QStringLiteral("Principal"));
        toolSeleccion = new QWidget();
        toolSeleccion->setObjectName(QStringLiteral("toolSeleccion"));
        toolSeleccion->setGeometry(QRect(0, 0, 237, 168));
        cazaButton = new QRadioButton(toolSeleccion);
        cazaButton->setObjectName(QStringLiteral("cazaButton"));
        cazaButton->setGeometry(QRect(50, 30, 141, 19));
        acorazadoButton = new QRadioButton(toolSeleccion);
        acorazadoButton->setObjectName(QStringLiteral("acorazadoButton"));
        acorazadoButton->setGeometry(QRect(50, 60, 151, 19));
        batallaButton = new QRadioButton(toolSeleccion);
        batallaButton->setObjectName(QStringLiteral("batallaButton"));
        batallaButton->setGeometry(QRect(50, 90, 151, 19));
        destructorButton = new QRadioButton(toolSeleccion);
        destructorButton->setObjectName(QStringLiteral("destructorButton"));
        destructorButton->setGeometry(QRect(50, 120, 141, 19));
        destructorButton->setLayoutDirection(Qt::LeftToRight);
        toolBox->addItem(toolSeleccion, QString::fromUtf8("Selecci\303\263n de nave"));

        verticalLayout->addWidget(toolBox);


        retranslateUi(MenuWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QWidget *MenuWindow)
    {
        MenuWindow->setWindowTitle(QApplication::translate("MenuWindow", "Men\303\272 principal", Q_NULLPTR));
        groupBox->setTitle(QString());
        imagenNave->setText(QString());
        ataqueEspBar->setFormat(QApplication::translate("MenuWindow", "%p%", Q_NULLPTR));
        label_2->setText(QApplication::translate("MenuWindow", "Salud", Q_NULLPTR));
        label_3->setText(QApplication::translate("MenuWindow", "Escudo", Q_NULLPTR));
        label_4->setText(QApplication::translate("MenuWindow", "Ataque", Q_NULLPTR));
        label_5->setText(QApplication::translate("MenuWindow", "At. Esp", Q_NULLPTR));
        label->setText(QApplication::translate("MenuWindow", "Titulo del juego", Q_NULLPTR));
        jugarButton->setText(QApplication::translate("MenuWindow", "Jugar", Q_NULLPTR));
        salirButton->setText(QApplication::translate("MenuWindow", "Salir", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(toolPrincipal), QApplication::translate("MenuWindow", "Principal", Q_NULLPTR));
        cazaButton->setText(QApplication::translate("MenuWindow", "Caza", Q_NULLPTR));
        acorazadoButton->setText(QApplication::translate("MenuWindow", "Acorazado", Q_NULLPTR));
        batallaButton->setText(QApplication::translate("MenuWindow", "Nave de batalla", Q_NULLPTR));
        destructorButton->setText(QApplication::translate("MenuWindow", "Destructor", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(toolSeleccion), QApplication::translate("MenuWindow", "Selecci\303\263n de nave", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
