#ifndef SCORE_H
#define SCORE_H

#include <vector>
#include <QLabel>


class Score
{
public:
    Score();

    void increase();
    void decrease();
    void addLife();
    void takeLife();
    std::vector<int> getScores();
    void saveCurrentScore(int levelId);
    void saveCurrentTime(int levelId, int time);
    int getLevelTime(int levelId);
    int getLives();
    bool isSuccessful();
    void reset();
    void updateScoreLabel(int levelId);
    bool isUnlocked(int levelId);
    void setScoreLabels(QVector<QLabel*> labels);

private:
    std::vector<int> scores;
    std::vector<bool> unlocked;
    int current_score;
    int lives;
    const int value = 5;
    std::vector<int> level_time;
    QVector<QLabel*> scoreLabels;
};

#endif // SCORE_H
