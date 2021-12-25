#include "message.h"

Message::Message()
{
    this->msgBox = new QMessageBox();
    this->msgBox->setWindowTitle(" ");
    this->msgBox->setFont(QFont("Seoge Ui", 25));
    this->msgBox->setStyleSheet("border-image: url(:/images/messageBox.jpg) stretch;");

}

void Message::setMessageText(MessageText text) {
    QString msgText;
    switch (text)
    {
        case MessageText::Esc:
            msgText = "Level over!";
            break;
        case MessageText::LevelCompleted:
            msgText = "Congratulations! \nYou have successfully completed the level!";
            break;
        case MessageText::LostLife:
            msgText = "Oops, you lost a life!";
            break;
        case MessageText::NoMoreLives:
            msgText = "No spare lives left.\nBetter luck next time!";
            break;
        case MessageText::OutOfTime:
            msgText = "Oops, you ran out of time!";
            break;
        default:
            throw "Unknown message";
    }


    this->msgBox->setText(msgText);
    this->msgBox->exec();
}
