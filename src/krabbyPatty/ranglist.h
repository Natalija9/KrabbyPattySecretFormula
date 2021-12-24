#ifndef RANGLIST_H
#define RANGLIST_H
#include <QWidget>
#include <QFile>
#include <QTextStream>

class RangList : public QWidget
{
public:
     RangList();
     void addPlayer(QString& name, int score);
     void readFromFileAndInsertIntoList();
     void sortPlayersByScore();
     void insertPlayerIntoList(QString name, int score);
     void printPlayersIntoFile();
     QString printListToRangList();

private:
    QList<std::pair<QString, int>> playerList;

};

#endif // RANGLIST_H
