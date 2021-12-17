#ifndef SCORE_H
#define SCORE_H

#include <vector>

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

private:
    std::vector<int> scores;
    int current_score;
    int lives;
    const int value = 5;
    std::vector<int> level_time;
};

#endif // SCORE_H
