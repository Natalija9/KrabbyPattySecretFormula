#ifndef MESSAGE_H
#define MESSAGE_H

#include <QMessageBox>

enum class MessageText
{
    LostLife = 0,
    Esc = 1,
    NoMoreLives = 2,
    LevelCompleted = 3,
    OutOfTime = 4
};


class Message
{
public:
    Message();
    void setMessageText(MessageText messageValue);
    QString getMessage(MessageText messageValue);

    ~Message();

private:
    QMessageBox *msgBox;
    QVector<QString> messageTexts;
};

#endif // MESSAGE_H
