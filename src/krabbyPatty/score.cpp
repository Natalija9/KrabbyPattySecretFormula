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
    std::cout << current_score << std::endl;
}

void Score::decrease()
{
    //current_score -= 1;
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

void Score::saveCurrentScore(int levelId, int time){
    std::cout<< "time: "<<time/1000 <<std::endl;
    std::cout<< "score: "<<current_score <<std::endl;

    current_score = current_score > 0 ? current_score * time  / 10000 : 0;
    if(current_score > scores[levelId - 1]){
        this->scores[levelId - 1] = this->current_score;
        this->level_time[levelId - 1] = time;
        if(levelId < 6){
            unlocked[levelId] = true;
            updateLevelButton(levelId+1, true);
        }
    }

    current_score = 0;
    updateScoreLabel(levelId);
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
        updateLevelButton(i+1, false);

    }

    unlocked[0] = true;
    updateLevelButton(1, true);
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
       updateLevelButton(i+1, false);
    }
      updateLevelButton(1, true);
}

void Score::updateLevelButton(int levelId, bool enabled){

    buttons[levelId - 1]->setEnabled(enabled);
    if(enabled){
        buttons[levelId-1]->setStyleSheet("border-image: url(:/images/transparent.png); color: #feff41;");
    }else{
        buttons[levelId-1]->setStyleSheet("border-image: url(:/images/transparent.png); color: rgb(128, 128, 128); ");
    }

}

int Score::getTotalScore(){
    int zbir = 0;
    for(int score : this->scores)
        zbir += score;

    return zbir;
}
