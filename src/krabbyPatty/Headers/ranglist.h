#ifndef RANGLIST_H
#define RANGLIST_H
#include <QWidget>
#include <QFile>
#include <QTextStream>

class RangList : public QWidget
{
public:
     RangList();
     QList<std::pair<QString, int>> playerList;
     void addPlayer(QString& name, int score);
     void readFromFileAndInsertIntoList();
     void sortPlayersByScore();
     void insertPlayerIntoList(QString name, int score);
     void printPlayersIntoFile();
     QString printListToRangList();
     ~RangList();
};

#endif // RANGLIST_H
