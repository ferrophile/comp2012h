#include "keypress.h"

#include <QApplication>
#include <QKeyEvent>
 
KeyPress::KeyPress(QWidget *parent) :
    QWidget(parent)
{
    mainLayout.addWidget(&myLabel);
    mainLayout.addWidget(&countLabel);
    setLayout(&mainLayout);
    myImage.load("penguin.png");
    myLabel.setPixmap(QPixmap::fromImage(myImage));
    myLabel.show();
    countLabel.setText("0");
    countLabel.show();

    count = 0;
}
 
void KeyPress::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
    count++;
    myImage.load("penguin.png");
    QPainter qPainter(&myImage);
    qPainter.setBrush(Qt::NoBrush);
    qPainter.setPen(Qt::red);
    qPainter.drawRect(250-count,150,50,50);
    myLabel.setPixmap(QPixmap::fromImage(myImage));
    myLabel.show();
    countLabel.setText(QString::number(count));
    countLabel.show();
    }
}
 
void KeyPress::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
    mainLayout.addWidget(&myLabel);
    mainLayout.addWidget(&countLabel);
    setLayout(&mainLayout);
    myImage.load("penguin.png");
    myLabel.setPixmap(QPixmap::fromImage(myImage));
    myLabel.show();
    countLabel.setText(QString::number(count));
    countLabel.show();
    }
}
