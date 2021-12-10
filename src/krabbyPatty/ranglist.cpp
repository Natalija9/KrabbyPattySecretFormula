#include "ranglist.h"
#include <iostream>
using namespace std;
RangList::RangList()
{
}

struct QPairScoreComparer {
    template <typename T1, typename T2>
    bool operator()(const std::tuple<T1, T2>& a,
        const std::tuple<T1, T2>& b)
    {
        return std::get<1>(a) > std::get<1>(b);
    }
};


// adding name-score to memory
void RangList::addPlayer(QString &name, int score)
{
    playerList.clear();
    readFromFileAndInsertIntoList();
    sortPlayersByScore();
    insertPlayerIntoList(name, score);
    printPlayersIntoFile();
}


// reading players from file and inserting into list
void RangList::readFromFileAndInsertIntoList()
{
    QFile players(":/files/players.txt");

    if(players.exists()){
        cout << "fajl postoji na toj putanji" << endl;
    }

    if (players.open(QIODevice::ReadOnly)){
        cout << "otvorio fajl" << endl;
    }else
        cout << " nije otvorio fajl " << endl;

    QTextStream stream(&players);

    while (!stream.atEnd()) {
        QString line = stream.readLine();

        QStringList lineList = line.split(" ");
        QString name = lineList.at(0);
        int score = lineList.at(1).toInt();

        playerList.append(std::make_tuple(name, score));
    }

    players.close();
}

// sorting list of players
void RangList::sortPlayersByScore()
{
    std::sort(playerList.begin(), playerList.end(), QPairScoreComparer());
}

// inserting new player to list
void RangList::insertPlayerIntoList(QString name, int score)
{
    int position = -1;
    for (int i = 0; i < playerList.size(); i++) {
        std::tuple<QString, int> player = playerList.at(i);
        int score1 = std::get<1>(player);

        if (score > score1) {
            position = i;
            break;
        }
    }

    if (position != -1) {
        for (int i = playerList.size() - 1; i >= 0; i--) {
            if (i > position) {
                playerList[i] = playerList.at(i - 1);
            } else if (i == position) {
                std::tuple<QString, int> currentPlayer = std::make_tuple(name, score);
                playerList[i] = currentPlayer;
            }
        }
    }
}

// printing players from list to file
void RangList::printPlayersIntoFile()
{
    QFile players(":/files/players.txt");
    players.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);

    QTextStream stream(&players);

    for (int i = 0; i < playerList.size(); i++) {
        std::tuple<QString, int> player = playerList.at(i);
        stream << std::get<0>(player) << " " << std::get<1>(player) << '\n';
    }

    players.close();
}

// printing list of players into Rang List
QString RangList::printListToRangList()
{
    playerList.clear();
    readFromFileAndInsertIntoList();
    sortPlayersByScore();

    //QString names;
    //QString scores;
    //QString positions;

    QString rez = "\n";
    for (int i = 0; i < playerList.size(); i++) {
        std::tuple<QString, int> player = playerList.at(i);
        QString position = QString::number(i + 1) + ". ";
        QString name = std::get<0>(player);
        QString score = QString::number(std::get<1>(player));

        //positions += QString("%1").arg(position, 5, QChar(' ')) + "\n";
        //names += QString("%1").arg(name, 15, QChar(' ')) + "\n";
        //scores += QString("%1").arg(score, 10, QChar(' ')) + "\n";

        if (i == playerList.size()-1){
            rez += "     " + position + " " + name + " " + score + "\n";
        }else{
            rez += "     " + position + "   " + name + " " + score + "\n";
        }
       // printf("%s \n", name.toStdString().c_str());
       // printf("%s \n", score.toStdString().c_str());

    }

    return rez;
    //ui->text_rang_list->setText(positions);
}




