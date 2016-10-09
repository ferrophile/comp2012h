#ifndef KEYPRESS_H
#define KEYPRESS_H
 
#include <QWidget>
#include <QtGui>

class KeyPress : public QWidget
{
    Q_OBJECT
public:
    KeyPress(QWidget *parent = 0);
 
protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
 
private:
  QImage myImage;
  QLabel myLabel, countLabel;
  QVBoxLayout mainLayout;

  int count;
};
 
#endif // KEYPRESS_H
