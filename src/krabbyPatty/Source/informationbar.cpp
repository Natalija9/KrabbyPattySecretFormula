#include "Headers/informationbar.h"
#include "Headers/score.h"

extern Score *score;

InformationBar::InformationBar(QGraphicsView *view, QString ingredientPath){

    this->view = view;

    ingredientLabelPic = new QLabel(view);
    ingredientLabelPic->setGeometry(10, 60, 40, 40);
    ingredientLabelPic->setPixmap(QPixmap(ingredientPath).scaled(40, 40));
    ingredientLabelPic->show();

    ingredientLabelText = new QLabel(view);
    ingredientLabelText->setGeometry(55, 60, 40, 40);
    ingredientLabelText->setStyleSheet("font-size: 15px; font: bold;");
    ingredientLabelText->setText("");
    ingredientLabelText->show();

    lifePixmap = QPixmap(":/images/star.png").scaled(40, 40);
    for(int i = 0; i < score -> getLives(); i++){
        lifeLabels.append(new QLabel(view));
        lifeLabels[i]->setGeometry(10 + (i * 45), 10, 40, 40);
        lifeLabels[i]->setPixmap(lifePixmap);
        lifeLabels[i]->show();
    }
}

void InformationBar::updateInformation(){
   if(score->getLives() != lifeLabels.size()){
        lifeLabels.clear();
        for(int i = 0; i < score -> getLives(); i++){
            lifeLabels.append(new QLabel(view));
            lifeLabels[i]->setGeometry(10 + (i * 45), 10, 40, 40);
            lifeLabels[i]->setPixmap(lifePixmap);
            lifeLabels[i]->show();
        }
    }
    else{
       ingredientLabelText->setText(QString::number(score->current_score));
       ingredientLabelText->show();
   }
}

InformationBar::~InformationBar(){
    delete this->ingredientLabelPic;
    delete this->ingredientLabelText;
}
