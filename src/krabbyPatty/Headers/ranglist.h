#ifndef RANGLIST_H
#define RANGLIST_H
#include <QFile>
#include <QTextStream>
#include <QWidget>

class RangList : public QWidget {
public:
  RangList();
  void addPlayer(QString& name, int score);
  void readFromFileAndInsertIntoList();
  void sortPlayersByScore();
  void insertPlayerIntoList(QString name, int score);
  void printPlayersIntoFile();
  QString printListToRangList();
  QList<std::pair<QString, int>> playerList;

  ~RangList();
};

#endif // RANGLIST_H
