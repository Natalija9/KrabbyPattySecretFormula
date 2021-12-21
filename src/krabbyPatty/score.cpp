#include "score.h"
#include<iostream>

/*
 * score * remainingTime * koeficijent
 * koef. 0.1 za easy i 0.15 za hard
 * easy 352 hard 520
 *       344     516
 */

Score::Score()
{
    scores.resize(6, 0);
    unlocked.resize(6, false);
    unlocked[0] = true;
    level_time.resize(6, 0);
    current_score = 0;
    lives = 3;
}

void Score::increase()
{
    current_score += value;
//    std::cout << current_score << std::endl;
}

void Score::decrease()
{
    current_score -= 1;
}

void Score::addLife()
{
    this->lives++;
//    std::cout << this->lives << std::endl;
}

void Score::takeLife()
{
    this->lives--;
    current_score = 0;

//    if(lives == 0)
//        std::cout << "nema vise zivota, kraj igrice" << std::endl;
}

std::vector<int> Score::getScores(){
    return this->scores;
}

int Score::getLives(){
    return this->lives;
}

void Score::saveCurrentScore(int levelId){
    if(current_score > scores[levelId - 1]){
        this->scores[levelId - 1] = this->current_score;
        if(levelId < 6){
            unlocked[levelId] = true;
            buttons[levelId]->setEnabled(true);
        }
    }
    current_score = 0;

    updateScoreLabel(levelId);
}

void Score::saveCurrentTime(int levelId, int time){
    this->level_time[levelId - 1] = time;
}

int Score::getLevelTime(int levelId) {
    return this->level_time[levelId - 1];
}

bool Score::isUnlocked(int levelId){
    return unlocked[levelId - 1];
}

bool Score::isSuccessful(){

    for(int i = 0; i < 6; i++){
        if(scores[i] == 0)
            return false;
    }

    return true;
}

void Score::reset(){

    for(int i = 0; i < 6; i++){
        scores[i] = 0;
        unlocked[i] = false;
        level_time[i] = 0;
        updateScoreLabel(i+1);
        buttons[i]->setDisabled(true);
    }

    unlocked[0] = true;
    buttons[0]->setEnabled(true);
    current_score = 0;
    lives = 3;
}


void Score::setScoreLabels(QVector<QLabel *> labels){

    this->scoreLabels = labels;
}

void Score::updateScoreLabel(int levelId){
    QLabel* label = scoreLabels[levelId - 1];
    QString str = "";

    if(isUnlocked(levelId)){
        str = QString::number(scores[levelId - 1]);
    }

    label->setText(str);
}

void Score::setLevelButtons(QVector<QPushButton *> buttons){
    this->buttons = buttons;
    for(int i = 0; i < 6; i++){
        buttons[i]->setDisabled(true);
    }
    buttons[0]->setEnabled(true);
}
