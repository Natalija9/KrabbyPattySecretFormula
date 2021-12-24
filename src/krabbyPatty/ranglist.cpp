#include "ranglist.h"
#include <QDir>
#include<iostream>
RangList::RangList()
{
}

struct QPairScoreComparer {
    template <typename T1, typename T2>
    bool operator()(const std::pair<T1, T2>& a,
        const std::pair<T1, T2>& b)
    {
        return a.second > b.second;
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
    QFile players("../krabbyPatty/files/players.txt");

//    if(players.exists()){
//        std::cout << "fajl postoji na toj putanji" <<std:: endl;
//    }
//    if (players.open(QIODevice::ReadOnly)){
//        std::cout << "otvoren" << std::endl;
//    }else
//        std::cout << " nije otvoren " <<std::  endl;


    players.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&players);

    while (!stream.atEnd()) {
        QString line = stream.readLine();

        QStringList lineList = line.split(" ");
        QString name = lineList.at(0);
        int score = lineList.at(1).toInt();

        playerList.append(std::make_pair(name, score));
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
        std::pair<QString, int> player = playerList.at(i);
        int score1 = player.second;

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
                std::pair<QString, int> currentPlayer = std::pair(name, score);
                playerList[i] = currentPlayer;
            }
        }
    }
}

// printing players from list to file
void RangList::printPlayersIntoFile()
{
    QFile players("../krabbyPatty/files/players.txt");
    players.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);

    QTextStream stream(&players);

    for (int i = 0; i < playerList.size(); i++) {
        std::pair<QString, int> player = playerList.at(i);
        stream << player.first << " " << player.second << '\n';
    }

    players.close();
}

// printing list of players into Rang List
QString RangList::printListToRangList()
{
    playerList.clear();
    readFromFileAndInsertIntoList();
    sortPlayersByScore();

    QString rez = "";
    for (int i = 0; i < playerList.size(); i++) {
        std::pair<QString, int> player = playerList.at(i);
        QString position = QString::number(i + 1) + ". ";
        QString name = player.first;
        QString score = QString::number(player.second);

        if (i == playerList.size()-1){
            rez += "      " + position + " " + name + " " + score + "\n";
        }else{
            rez += "      " + position + "   " + name + " " + score + "\n";
        }
    }

    return rez;
}




