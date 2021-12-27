#ifndef INFORMATIONBAR_H
#define INFORMATIONBAR_H

#include <QLabel>
#include <QGraphicsView>


class InformationBar : public QObject
{
public:
    InformationBar(QGraphicsView *view, QString ingredientPath);
    void updateInformation();

    ~InformationBar();

private:
    QGraphicsView *view;
    QLabel *ingredientLabelPic;
    QLabel *ingredientLabelText;
    QVector<QLabel*> lifeLabels;
    QPixmap lifePixmap;

};

#endif // INFORMATIONBAR_H
