#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QMessageBox>
#include <QTimer>
#include <QFile>

#include "level.h"
#include "player.h"
#include "life.h"
#include "ingredient.h"
#include "score.h"
#include "regulartile.h"
#include "flag.h"
#include "deadlybarrier.h"
#include "slowingtile.h"

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

    scene = new QGraphicsScene(0, 0, 5 * screenWidth, screenHeight);

    this->setView();

    Player *player = new Player();
    player-> setFlag(QGraphicsItem::ItemIsFocusable);
    player ->setFocus();

    scene->addItem(player);
    view->ensureVisible(player);
    view->centerOn(player);

    playerWidth = player->parameters->_width;
    playerHeight = player->parameters->_height;

    this->parseLevelMap();

    mainTimer = new QTimer(this);
    mainTimer->start(20);

    levelTimer = new QTimer(this);
    levelTimer->start(120000);

    informationBar = new InformationBar(view, levelData->getIngredient(levelId));
    timerLabel = new QLabel(view);
    music = new Sound(levelData->getSound());

    QObject::connect(mainTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    QObject::connect(levelTimer, SIGNAL(timeout()), this, SLOT(outOfTime()));
    QObject::connect(player, SIGNAL(countChanged()), this, SLOT(setInformationBar()));
    QObject::connect(player, SIGNAL(activeTimer()), this, SLOT(updateTimerLabel()));

    QApplication::setOverrideCursor(Qt::BlankCursor);

    view->showFullScreen();
}

void Level::setView(){
    this->view = new QGraphicsView(scene);

    QString path = levelData->getBackground(levelId);
    view->setBackgroundBrush(QPixmap(path).scaledToHeight(screenHeight));
    view->resize(screenWidth, screenHeight);

    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setWindowTitle(QString::fromStdString("Level " + std::to_string(levelId)));
    view->setFocus();
}


void Level::setInformationBar(){
    informationBar->updateInformation();
}

void Level::updateTimerLabel(){
    timerLabel->setText("time: " + QString::number(levelTimer->remainingTime()/1000) + " s");
    timerLabel->setStyleSheet("font-size: 23px; font: bold;");
    timerLabel->setGeometry(screenWidth-140, 10, 120, 20);
    timerLabel->show();
}

void Level::finishLevel(MessageText msgText){
    music->stopMusic();
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    if(msgText != MessageText::LevelCompleted)
        score->takeLife();

    score->saveCurrentScore(levelId, levelTimer->remainingTime());
    levelTimer->stop();
    score->msg->setMessageText(msgText);

    this->view->close();

    emit endLevel();
}


void Level::outOfTime() {
    this->finishLevel(MessageText::OutOfTime);
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
            if(score->getLives() < 4){
                Life *life = new Life(playerWidth);
                life->setPos(x, (0.225 + y * 0.25 )*screenHeight);
                scene->addItem(life);
            }
            break;
    }
    case '_' :{
            RegularTile *tile = new RegularTile(playerWidth,levelData->getTiles(levelId));
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
                SlowingTile *waterTiles = new SlowingTile(playerWidth, levelData->getSlowingBarrier(levelId));
                waterTiles->setPos(x, (0.1 + y * 0.25)*screenHeight);
                scene->addItem(waterTiles);
            }
            else{
                RegularTile *tile = new RegularTile(playerWidth,levelData->getTiles(levelId));
                tile->setPos(x, (0.1 + y * 0.25)*screenHeight);
                scene->addItem(tile);
                }
            break;

    }
    case 'B' :{
                SlowingTile *waterTiles = new SlowingTile(playerWidth, levelData->getSlowingBarrier(levelId));
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

Level::~Level(){
    delete this->music;
    delete this->mainTimer;
    delete this->levelTimer;
    delete this->informationBar;
    delete this->timerLabel;

}




