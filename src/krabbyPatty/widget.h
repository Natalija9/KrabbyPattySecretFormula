#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void onEsc(QKeyEvent *event);
    ~Widget();

private slots:

    void on_startButton_clicked();

    void on_quitButton_clicked();

    void on_Level1_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
