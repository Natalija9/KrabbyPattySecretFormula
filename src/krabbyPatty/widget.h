#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "settings.h"
#include "score.h"
#include "ranglist.h"
#include "leveldata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void onEsc(QKeyEvent *event);
    //Score *score;
    ~Widget();

private slots:

    void updateScore();

    void on_startButton_clicked();

    void on_quitButton_clicked();

    void on_settingsButton_clicked();

    void on_pushButton_clicked();

    void on_checkSound_stateChanged(int arg1);

    void on_rbEasy_clicked();

    void on_rbHard_clicked();

    void createLevel();


    void on_rangListButton_clicked();

    void on_pushButtonMainMenu_clicked();

    void on_helpButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Widget *ui;
    Settings *settings;
    RangList *ranglist;
    LevelData *levelData;


};
#endif // WIDGET_H
