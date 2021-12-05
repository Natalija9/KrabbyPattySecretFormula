/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *mainMenu;
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *rangListButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QPushButton *settingsButton;
    QPushButton *startButton;
    QPushButton *quitButton;
    QWidget *levelMenu;
    QPushButton *Level1;
    QPushButton *Level2;
    QPushButton *Level3;
    QPushButton *Level4;
    QPushButton *Level5;
    QWidget *settings;
    QLabel *Sound;
    QCheckBox *checkBox;
    QLabel *Sound_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        Widget->setMinimumSize(QSize(800, 600));
        Widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(300, 75));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        mainMenu = new QWidget();
        mainMenu->setObjectName(QString::fromUtf8("mainMenu"));
        gridLayout_3 = new QGridLayout(mainMenu);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        widget = new QWidget(mainMenu);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/images/menuBackground.jpg) 0 0 0 0 stretch stretch;"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(50);
        gridLayout->setVerticalSpacing(30);
        rangListButton = new QPushButton(widget);
        rangListButton->setObjectName(QString::fromUtf8("rangListButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rangListButton->sizePolicy().hasHeightForWidth());
        rangListButton->setSizePolicy(sizePolicy1);
        rangListButton->setMaximumSize(QSize(300, 75));
        QFont font;
        font.setFamilies({QString::fromUtf8("Krabby Patty")});
        font.setPointSize(19);
        font.setBold(true);
        font.setItalic(true);
        rangListButton->setFont(font);
        rangListButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));

        gridLayout->addWidget(rangListButton, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(150, 370, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(575, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        settingsButton = new QPushButton(widget);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));
        sizePolicy1.setHeightForWidth(settingsButton->sizePolicy().hasHeightForWidth());
        settingsButton->setSizePolicy(sizePolicy1);
        settingsButton->setMaximumSize(QSize(300, 75));
        settingsButton->setFont(font);
        settingsButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));

        gridLayout->addWidget(settingsButton, 1, 0, 1, 1);

        startButton = new QPushButton(widget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        sizePolicy1.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy1);
        startButton->setMaximumSize(QSize(300, 75));
        startButton->setFont(font);
        startButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));

        gridLayout->addWidget(startButton, 0, 0, 1, 1);

        quitButton = new QPushButton(widget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        sizePolicy.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy);
        quitButton->setMaximumSize(QSize(300, 75));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Krabby Patty")});
        font1.setPointSize(19);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setStyleStrategy(QFont::PreferDefault);
        quitButton->setFont(font1);
        quitButton->setAutoFillBackground(false);
        quitButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));

        gridLayout->addWidget(quitButton, 3, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        stackedWidget->addWidget(mainMenu);
        levelMenu = new QWidget();
        levelMenu->setObjectName(QString::fromUtf8("levelMenu"));
        levelMenu->setStyleSheet(QString::fromUtf8("border-image: url(:/images/levelMenuBackground.png) 0 0 0 0 stretch stretch;"));
        Level1 = new QPushButton(levelMenu);
        Level1->setObjectName(QString::fromUtf8("Level1"));
        Level1->setGeometry(QRect(10, 100, 211, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Krabby Patty")});
        font2.setPointSize(19);
        font2.setBold(true);
        Level1->setFont(font2);
        Level1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Level2 = new QPushButton(levelMenu);
        Level2->setObjectName(QString::fromUtf8("Level2"));
        Level2->setGeometry(QRect(10, 180, 211, 61));
        Level2->setFont(font2);
        Level2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;\n"
""));
        Level3 = new QPushButton(levelMenu);
        Level3->setObjectName(QString::fromUtf8("Level3"));
        Level3->setGeometry(QRect(10, 260, 211, 61));
        Level3->setFont(font2);
        Level3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Level4 = new QPushButton(levelMenu);
        Level4->setObjectName(QString::fromUtf8("Level4"));
        Level4->setGeometry(QRect(10, 340, 211, 61));
        Level4->setFont(font2);
        Level4->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Level5 = new QPushButton(levelMenu);
        Level5->setObjectName(QString::fromUtf8("Level5"));
        Level5->setGeometry(QRect(10, 420, 211, 61));
        Level5->setFont(font2);
        Level5->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        stackedWidget->addWidget(levelMenu);
        settings = new QWidget();
        settings->setObjectName(QString::fromUtf8("settings"));
        settings->setStyleSheet(QString::fromUtf8("border-image: url(:/images/settingsBackground.jpg) 0 0 0 0 stretch stretch;"));
        Sound = new QLabel(settings);
        Sound->setObjectName(QString::fromUtf8("Sound"));
        Sound->setGeometry(QRect(590, 200, 161, 71));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Krabby Patty")});
        font3.setPointSize(17);
        font3.setBold(true);
        Sound->setFont(font3);
        Sound->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        checkBox = new QCheckBox(settings);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(680, 230, 61, 16));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Krabby Patty")});
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setUnderline(false);
        checkBox->setFont(font4);
        checkBox->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Sound_2 = new QLabel(settings);
        Sound_2->setObjectName(QString::fromUtf8("Sound_2"));
        Sound_2->setGeometry(QRect(590, 290, 161, 71));
        Sound_2->setFont(font3);
        Sound_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        radioButton = new QRadioButton(settings);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(680, 300, 71, 20));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Krabby Patty")});
        font5.setPointSize(15);
        font5.setBold(true);
        radioButton->setFont(font5);
        radioButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        radioButton_2 = new QRadioButton(settings);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(680, 330, 71, 23));
        radioButton_2->setFont(font5);
        radioButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        pushButton = new QPushButton(settings);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 89, 25));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: black;"));
        stackedWidget->addWidget(settings);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        rangListButton->setText(QCoreApplication::translate("Widget", "Rang list", nullptr));
        settingsButton->setText(QCoreApplication::translate("Widget", "Settings", nullptr));
        startButton->setText(QCoreApplication::translate("Widget", "Start game", nullptr));
        quitButton->setText(QCoreApplication::translate("Widget", "Quit game", nullptr));
        Level1->setText(QCoreApplication::translate("Widget", "Level 1", nullptr));
        Level2->setText(QCoreApplication::translate("Widget", "Level 2", nullptr));
        Level3->setText(QCoreApplication::translate("Widget", "Level 3", nullptr));
        Level4->setText(QCoreApplication::translate("Widget", "Level 4", nullptr));
        Level5->setText(QCoreApplication::translate("Widget", "Level 5", nullptr));
        Sound->setText(QCoreApplication::translate("Widget", " Sound", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "On", nullptr));
        Sound_2->setText(QCoreApplication::translate("Widget", " Mode", nullptr));
        radioButton->setText(QCoreApplication::translate("Widget", "Easy", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Widget", "Hard", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
