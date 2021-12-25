#ifndef MESSAGE_H
#define MESSAGE_H

#include <QMessageBox>

enum class MessageText
{
    LostLife,
    Esc,
    NoMoreLives,
    LevelCompleted,
    OutOfTime
};


class Message
{
public:
    Message();
    void setMessageText(MessageText text);

private:
    QMessageBox *msgBox;
};

#endif // MESSAGE_H
