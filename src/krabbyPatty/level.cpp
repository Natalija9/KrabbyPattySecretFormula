#include<QGraphicsScene>
#include<QGraphicsView>
#include <QApplication>
#include <QMessageBox>
#include <QTimer>
#include <QFile>

#include "level.h"
#include "player.h"
#include "life.h"
#include "ingredient.h"
#include "score.h"
#include "tile.h"
#include "flag.h"
#include "deadlybarrier.h"
#include "slowingbarrier.h"

#include <iostream>




extern Score *score;

Level::Level(int levelId, LevelData *levelData)
{

    this->levelId = levelId;
    this->levelData = levelData;

}

void Level::startLevel(){

    QScreen *screen = QApplication::screens().at(0);
    screenHeight = screen->size().height();
    screenWidth = screen->size().width();

    scene =new QGraphicsScene(0,0,5 * screenWidth ,screenHeight);
    mainTimer = new QTimer(this);
    Player *player = new Player();
    player-> setFlag(QGraphicsItem::ItemIsFocusable);

    player ->setFocus();
    QObject::connect(mainTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    mainTimer->start(20);

    levelTimer = new QTimer(this);
    levelTimer->start(120000);
    QObject::connect(levelTimer, SIGNAL(timeout()), this, SLOT(outOfTime()));

    playerWidth = player->_width;
    playerHeight = player->_height;

    scene->addItem(player);
    parseLevelMap();

    this->view = new QGraphicsView(scene);

    QString path = levelData->getBackground(levelId);
    view->setBackgroundBrush(QPixmap(path).scaledToHeight(screenHeight));

    view->resize(screenWidth,screenHeight);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->ensureVisible(player);
    view->centerOn(player);


//Information bar during game
    ingredientLabelPic = new QLabel(view);
    ingredientLabelText = new QLabel(view);
    setInformationBar();


//Connections
    QObject::connect(player, SIGNAL(deadlyBarrier()), this, SLOT(death()));
    QObject::connect(player, SIGNAL(countChanged()), this, SLOT(setInformationBar()));


    view->setWindowTitle(QString::fromStdString("Level " + std::to_string(levelId)));
    view->setFocus();
    QApplication::setOverrideCursor(Qt::BlankCursor);

    view->showFullScreen();

}

void Level::setInformationBar(){

    //Lives
   if(score->getLives() != lifeBar.size()){

        lifeBar.clear();
        QPixmap pix = QPixmap(":/images/star.png").scaled(40,40);
        for(int i = 0; i < score -> getLives(); i++){
            lifeBar.append(new QLabel(view));
            lifeBar[i]->setGeometry(10+(i*45),10,40,40);
            lifeBar[i]->setPixmap(pix);
            lifeBar[i]->show();
        }
    }

    //Ingredient picture
           QPixmap pix1 = QPixmap(levelData->getIngredient(levelId)).scaled(40,40);
           ingredientLabelPic->setGeometry(10,60,40,40);
           ingredientLabelPic->setPixmap(pix1);
           ingredientLabelPic->show();

    //Ingredient count
           ingredientLabelText->setGeometry(55,60,40,40);
           ingredientLabelText->setText("");
           ingredientLabelText->setText(QString::number(score->current_score));
           ingredientLabelText->show();

}
void Level::finishLevel(){
    QApplication::setOverrideCursor(Qt::ArrowCursor);

    score->saveCurrentScore(levelId, levelTimer->remainingTime());
    levelTimer->stop();
    this->view->close();

    emit endLevel();
}


void Level::death() {
    score->takeLife();
    QApplication::setOverrideCursor(Qt::ArrowCursor);

    QMessageBox msgBox;
    msgBox.setText("Ooops, you lost a life!");
    msgBox.setWindowTitle(" ");
    msgBox.setStyleSheet("font-size: 20px; font-style: bolid italic;  color: rgb(0, 0, 0);");
    msgBox.exec();

    this->finishLevel();

}

void Level::outOfTime() {
    score->takeLife();
    QApplication::setOverrideCursor(Qt::ArrowCursor);

    QMessageBox msgBox;
    msgBox.setText("Ooops, you ran out of time!");
    msgBox.setWindowTitle("No more time");
    msgBox.setStyleSheet("font-size: 20px; font-style: bolid italic;  color: rgb(0, 0, 0);");
    msgBox.exec();

    this->finishLevel();

}

void Level::parseLevelMap(){
    QFile file(levelData->getLevelMap(levelId));
    if(!file.exists()){
        qDebug() << "File does not exist";
        return ;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "Opening failed";
        return ;
    }

    QTextStream in(&file);
    QStringList line = in.readLine().split(" ");
    int sizeX = line[0].toInt();
    int sizeY = line[1].toInt();

    for(int y = 0; y < sizeY; y++){
        QString sceneObjects = in.readLine();
        for( int x = 0; x < sizeX - 1; x++){
            addObject(sceneObjects[x].toLatin1(), x*screenWidth*5/200,y);
        }
    }

    file.close();
}


void Level::addObject(char type, int x,int y){
    switch(type){
        case '-' :
            break;
    case '*' :{
            Life *life = new Life(playerWidth);
            life->setPos(x, (0.225 + y * 0.25 )*screenHeight);
            scene->addItem(life);
            break;
    }
    case '_' :{
            Tile *tile = new Tile(playerWidth,levelData->getTiles(levelId));
            tile->setPos(x, (0.1 + y * 0.25)*screenHeight);
            scene->addItem(tile);
            break;
    }
    case '$' :{
            Ingredient *ingredient = new Ingredient(playerWidth, levelData->getIngredient(levelId));
            ingredient->setPos(x, (0.225 + y * 0.25 )*screenHeight);
            scene->addItem(ingredient);
            break;
    }
    case 'X' :{

            if(levelData->getRandomDecision()){
                DeadlyBarrier *barrier = levelData->getDeadlyBarrier(playerWidth);
                barrier->setPos(x, (0.225 + y * 0.25 )*screenHeight);
                scene->addItem(barrier);
            }
            break;

    }
    case 'S' :{

            if(levelData->getRandomDecision()){
                SlowingBarrier *waterTiles = new SlowingBarrier(playerWidth, levelData->getSlowingBarrier(levelId));
                waterTiles->setPos(x, (0.1 + y * 0.25)*screenHeight);
                scene->addItem(waterTiles);
            }
            else{
                Tile *tile = new Tile(playerWidth,levelData->getTiles(levelId));
                tile->setPos(x, (0.1 + y * 0.25)*screenHeight);
                scene->addItem(tile);
                }
            break;

    }
    case 'B' :{
                SlowingBarrier *waterTiles = new SlowingBarrier(playerWidth, levelData->getSlowingBarrier(levelId));
                waterTiles->setPos(x, (0.1 + y * 0.25)*screenHeight);
                scene->addItem(waterTiles);
            break;
    }
    case '+' :{
            Flag *flag = new Flag(playerHeight*1.41);
            flag->setPos(x, (0.225 + y * 0.25 )*screenHeight);
            scene->addItem(flag);
            break;
    }
        default :
            break;
    }
}

Level::~Level(){}




