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
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
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
    QSpacerItem *horizontalSpacer;
    QPushButton *quitButton;
    QSpacerItem *verticalSpacer;
    QPushButton *settingsButton;
    QPushButton *startButton;
    QPushButton *helpButton;
    QWidget *levelMenu;
    QPushButton *Level1;
    QPushButton *Level2;
    QPushButton *Level3;
    QPushButton *Level4;
    QPushButton *Level5;
    QPushButton *Level6;
    QLabel *Score1;
    QLabel *Score2;
    QLabel *Score3;
    QLabel *Score4;
    QLabel *Score5;
    QLabel *Score6;
    QPushButton *Give_up;
    QWidget *settings;
    QLabel *Sound;
    QCheckBox *checkSound;
    QLabel *Sound_2;
    QRadioButton *rbEasy;
    QRadioButton *rbHard;
    QPushButton *pushButton;
    QWidget *rangList;
    QLabel *label_top10;
    QLabel *label_player_score;
    QLabel *text_rang_list;
    QPushButton *pushButtonMainMenu;
    QWidget *help;
    QDialogButtonBox *buttonBox;
    QLabel *label_message;
    QLabel *label_arrows;
    QLabel *label_2;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit;

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
        font.setPointSize(19);
        font.setBold(true);
        font.setItalic(false);
        rangListButton->setFont(font);
        rangListButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));

        gridLayout->addWidget(rangListButton, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        quitButton = new QPushButton(widget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        sizePolicy.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy);
        quitButton->setMaximumSize(QSize(300, 75));
        QFont font1;
        font1.setPointSize(19);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setStyleStrategy(QFont::PreferDefault);
        quitButton->setFont(font1);
        quitButton->setAutoFillBackground(false);
        quitButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));

        gridLayout->addWidget(quitButton, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(150, 370, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

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
"color: #feff41;\n"
""));

        gridLayout->addWidget(startButton, 0, 0, 1, 1);

        helpButton = new QPushButton(widget);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(helpButton->sizePolicy().hasHeightForWidth());
        helpButton->setSizePolicy(sizePolicy2);
        helpButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/help.png);\n"
"width: 60;\n"
"height: 50;"));

        gridLayout->addWidget(helpButton, 0, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);

        stackedWidget->addWidget(mainMenu);
        levelMenu = new QWidget();
        levelMenu->setObjectName(QString::fromUtf8("levelMenu"));
        levelMenu->setStyleSheet(QString::fromUtf8("border-image: url(:/images/levelMenuBackground.png) 0 0 0 0 stretch stretch;"));
        Level1 = new QPushButton(levelMenu);
        Level1->setObjectName(QString::fromUtf8("Level1"));
        Level1->setGeometry(QRect(-20, 60, 211, 61));
        QFont font2;
        font2.setPointSize(19);
        font2.setBold(true);
        Level1->setFont(font2);
        Level1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Level2 = new QPushButton(levelMenu);
        Level2->setObjectName(QString::fromUtf8("Level2"));
        Level2->setGeometry(QRect(-20, 130, 211, 61));
        Level2->setFont(font2);
        Level2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;\n"
""));
        Level3 = new QPushButton(levelMenu);
        Level3->setObjectName(QString::fromUtf8("Level3"));
        Level3->setGeometry(QRect(-20, 200, 211, 61));
        Level3->setFont(font2);
        Level3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Level4 = new QPushButton(levelMenu);
        Level4->setObjectName(QString::fromUtf8("Level4"));
        Level4->setGeometry(QRect(-20, 280, 211, 61));
        Level4->setFont(font2);
        Level4->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Level5 = new QPushButton(levelMenu);
        Level5->setObjectName(QString::fromUtf8("Level5"));
        Level5->setGeometry(QRect(-20, 350, 211, 61));
        Level5->setFont(font2);
        Level5->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Level6 = new QPushButton(levelMenu);
        Level6->setObjectName(QString::fromUtf8("Level6"));
        Level6->setGeometry(QRect(-20, 420, 211, 61));
        Level6->setFont(font2);
        Level6->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Score1 = new QLabel(levelMenu);
        Score1->setObjectName(QString::fromUtf8("Score1"));
        Score1->setGeometry(QRect(150, 40, 51, 71));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        Score1->setFont(font3);
        Score1->setStyleSheet(QString::fromUtf8("border-image: url(:/images/unlocked.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Score2 = new QLabel(levelMenu);
        Score2->setObjectName(QString::fromUtf8("Score2"));
        Score2->setGeometry(QRect(150, 120, 48, 65));
        Score2->setFont(font3);
        Score2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/locked_grey.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Score3 = new QLabel(levelMenu);
        Score3->setObjectName(QString::fromUtf8("Score3"));
        Score3->setGeometry(QRect(150, 190, 48, 65));
        Score3->setFont(font3);
        Score3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/locked_grey.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Score4 = new QLabel(levelMenu);
        Score4->setObjectName(QString::fromUtf8("Score4"));
        Score4->setGeometry(QRect(150, 270, 48, 65));
        Score4->setFont(font3);
        Score4->setStyleSheet(QString::fromUtf8("border-image: url(:/images/locked_grey.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Score5 = new QLabel(levelMenu);
        Score5->setObjectName(QString::fromUtf8("Score5"));
        Score5->setGeometry(QRect(150, 340, 48, 65));
        Score5->setFont(font3);
        Score5->setStyleSheet(QString::fromUtf8("border-image: url(:/images/locked_grey.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Score6 = new QLabel(levelMenu);
        Score6->setObjectName(QString::fromUtf8("Score6"));
        Score6->setGeometry(QRect(150, 420, 48, 65));
        Score6->setFont(font3);
        Score6->setStyleSheet(QString::fromUtf8("border-image: url(:/images/locked_grey.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Give_up = new QPushButton(levelMenu);
        Give_up->setObjectName(QString::fromUtf8("Give_up"));
        Give_up->setGeometry(QRect(570, 440, 211, 61));
        QFont font4;
        font4.setPointSize(25);
        font4.setBold(true);
        Give_up->setFont(font4);
        Give_up->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        stackedWidget->addWidget(levelMenu);
        settings = new QWidget();
        settings->setObjectName(QString::fromUtf8("settings"));
        settings->setStyleSheet(QString::fromUtf8("border-image: url(:/images/settingsBackground.jpg) 0 0 0 0 stretch stretch;"));
        Sound = new QLabel(settings);
        Sound->setObjectName(QString::fromUtf8("Sound"));
        Sound->setGeometry(QRect(590, 200, 161, 71));
        QFont font5;
        font5.setPointSize(17);
        font5.setBold(true);
        Sound->setFont(font5);
        Sound->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        checkSound = new QCheckBox(settings);
        checkSound->setObjectName(QString::fromUtf8("checkSound"));
        checkSound->setGeometry(QRect(680, 230, 61, 16));
        QFont font6;
        font6.setPointSize(15);
        font6.setBold(true);
        font6.setUnderline(false);
        checkSound->setFont(font6);
        checkSound->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        Sound_2 = new QLabel(settings);
        Sound_2->setObjectName(QString::fromUtf8("Sound_2"));
        Sound_2->setGeometry(QRect(590, 290, 161, 71));
        Sound_2->setFont(font5);
        Sound_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        rbEasy = new QRadioButton(settings);
        rbEasy->setObjectName(QString::fromUtf8("rbEasy"));
        rbEasy->setGeometry(QRect(680, 300, 71, 20));
        QFont font7;
        font7.setPointSize(15);
        font7.setBold(true);
        rbEasy->setFont(font7);
        rbEasy->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        rbHard = new QRadioButton(settings);
        rbHard->setObjectName(QString::fromUtf8("rbHard"));
        rbHard->setGeometry(QRect(680, 330, 71, 23));
        rbHard->setFont(font7);
        rbHard->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        pushButton = new QPushButton(settings);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 30, 89, 25));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: black;"));
        stackedWidget->addWidget(settings);
        rangList = new QWidget();
        rangList->setObjectName(QString::fromUtf8("rangList"));
        rangList->setStyleSheet(QString::fromUtf8("border-image: url(:/images/ranglistBackground.jpg) 0 0 0 0 stretch stretch;"));
        label_top10 = new QLabel(rangList);
        label_top10->setObjectName(QString::fromUtf8("label_top10"));
        label_top10->setGeometry(QRect(90, 10, 191, 51));
        QFont font8;
        font8.setPointSize(26);
        font8.setBold(true);
        font8.setItalic(true);
        label_top10->setFont(font8);
        label_top10->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        label_player_score = new QLabel(rangList);
        label_player_score->setObjectName(QString::fromUtf8("label_player_score"));
        label_player_score->setGeometry(QRect(60, 60, 181, 41));
        QFont font9;
        font9.setPointSize(15);
        font9.setBold(true);
        font9.setItalic(true);
        label_player_score->setFont(font9);
        label_player_score->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        text_rang_list = new QLabel(rangList);
        text_rang_list->setObjectName(QString::fromUtf8("text_rang_list"));
        text_rang_list->setGeometry(QRect(30, 100, 241, 361));
        text_rang_list->setStyleSheet(QString::fromUtf8("border-image: url(:/images/papir.png) 0 0 0 0 stretch strech;\n"
"font-size: 20px; font-style: bolid italic;  color: rgb(0, 0, 0);\n"
"text-align: left;"));
        pushButtonMainMenu = new QPushButton(rangList);
        pushButtonMainMenu->setObjectName(QString::fromUtf8("pushButtonMainMenu"));
        pushButtonMainMenu->setGeometry(QRect(60, 480, 141, 51));
        QFont font10;
        font10.setPointSize(16);
        font10.setBold(true);
        font10.setItalic(true);
        pushButtonMainMenu->setFont(font10);
        pushButtonMainMenu->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;\n"
"color: #feff41;"));
        stackedWidget->addWidget(rangList);
        help = new QWidget();
        help->setObjectName(QString::fromUtf8("help"));
        help->setStyleSheet(QString::fromUtf8("border-image: url(:/images/how_to_play.jpg) 0 0 0 0 stretch stretch;"));
        buttonBox = new QDialogButtonBox(help);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(280, 240, 121, 51));
        buttonBox->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch;"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_message = new QLabel(help);
        label_message->setObjectName(QString::fromUtf8("label_message"));
        label_message->setGeometry(QRect(180, 0, 281, 261));
        label_message->setStyleSheet(QString::fromUtf8("border-image: url(:/images/bubble_for_help.png) 0 0 0 0 stretch stretch;"));
        label_arrows = new QLabel(help);
        label_arrows->setObjectName(QString::fromUtf8("label_arrows"));
        label_arrows->setGeometry(QRect(240, 20, 61, 41));
        label_arrows->setStyleSheet(QString::fromUtf8("border-image: url(:/images/button_arrow.png) 0 0 0 0 stretch stretch;"));
        label_2 = new QLabel(help);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 40, 31, 16));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch; font-size: 18px;"));
        label_3 = new QLabel(help);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(310, 40, 121, 21));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch; font-size: 18px;"));
        plainTextEdit = new QPlainTextEdit(help);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(200, 60, 241, 141));
        plainTextEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/images/transparent.png) 0 0 0 0 stretch stretch; font-size: 18px;"));
        stackedWidget->addWidget(help);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        rangListButton->setText(QCoreApplication::translate("Widget", "Rang list", nullptr));
        quitButton->setText(QCoreApplication::translate("Widget", "Quit game", nullptr));
        settingsButton->setText(QCoreApplication::translate("Widget", "Settings", nullptr));
        startButton->setText(QCoreApplication::translate("Widget", "Start game", nullptr));
        helpButton->setText(QString());
        Level1->setText(QCoreApplication::translate("Widget", "Level 1", nullptr));
        Level2->setText(QCoreApplication::translate("Widget", "Level 2", nullptr));
        Level3->setText(QCoreApplication::translate("Widget", "Level 3", nullptr));
        Level4->setText(QCoreApplication::translate("Widget", "Level 4", nullptr));
        Level5->setText(QCoreApplication::translate("Widget", "Level 5", nullptr));
        Level6->setText(QCoreApplication::translate("Widget", "Level 6", nullptr));
        Score1->setText(QString());
        Score2->setText(QString());
        Score3->setText(QString());
        Score4->setText(QString());
        Score5->setText(QString());
        Score6->setText(QString());
        Give_up->setText(QCoreApplication::translate("Widget", "Give up", nullptr));
        Sound->setText(QCoreApplication::translate("Widget", " Sound", nullptr));
        checkSound->setText(QCoreApplication::translate("Widget", "On", nullptr));
        Sound_2->setText(QCoreApplication::translate("Widget", " Mode", nullptr));
        rbEasy->setText(QCoreApplication::translate("Widget", "Easy", nullptr));
        rbHard->setText(QCoreApplication::translate("Widget", "Hard", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Back", nullptr));
        label_top10->setText(QCoreApplication::translate("Widget", "TOP 10 ", nullptr));
        label_player_score->setText(QCoreApplication::translate("Widget", "PLAYER         SCORE", nullptr));
        text_rang_list->setText(QString());
        pushButtonMainMenu->setText(QCoreApplication::translate("Widget", "MAIN MENU", nullptr));
        label_message->setText(QString());
        label_arrows->setText(QString());
        label_2->setText(QCoreApplication::translate("Widget", "Use", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "to move left,", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("Widget", "up and right. Try to be fast and to avoid every obstacle. If you manage to pass all the levels, you may be in the top 10! So, have a good luck!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
