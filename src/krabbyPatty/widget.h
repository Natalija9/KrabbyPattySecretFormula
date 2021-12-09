#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "settings.h"
#include "score.h"

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

    void on_startButton_clicked();

    void on_quitButton_clicked();

    void on_Level1_clicked();

    void on_settingsButton_clicked();

    void on_pushButton_clicked();

    void on_checkSound_stateChanged(int arg1);

    void on_rbEasy_clicked();

    void on_rbHard_clicked();




private:
    Ui::Widget *ui;
    Settings *settings;

};
#endif // WIDGET_H
