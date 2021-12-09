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

private:
    std::vector<int> scores;
    int current_score;
    int lives;
    const int value = 5;
};

#endif // SCORE_H
