#ifndef SCORE_H
#define SCORE_H

#include <vector>
#include <QLabel>
#include <QPushButton>
#include "leveldata.h"


class Score
{
public:
    Score(LevelData *level_data);

    void increase();
    void decrease();
    void addLife();
    void takeLife();
    std::vector<int> getScores();
    void saveCurrentScore(int levelId, int time);
   // void saveCurrentTime(int levelId, int time);
    int getLevelTime(int levelId);
    int getLives();
    bool isSuccessful();
    void reset();
    void updateScoreLabel(int levelId);
    void updateLevelButton(int levelId, bool enabled);
    bool isUnlocked(int levelId);
    void setScoreLabels(QVector<QLabel*> labels);
    void setLevelButtons(QVector<QPushButton*> buttons);
    void updateLabels(int levelId);
    int getTotalScore();
    int current_score;

private:
    std::vector<int> scores;
    std::vector<bool> unlocked;

    int lives;
    const int value = 5;
    std::vector<int> level_time;
    QVector<QLabel*> scoreLabels;
    QVector<QPushButton*> buttons;
    LevelData *level_data;
};

#endif // SCORE_H
