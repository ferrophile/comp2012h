#include <unistd.h>
#include <QtGui>
#include <QLabel>

class MyMainWindow : public QWidget
{
private:
  QImage myImage;
  QLabel myLabel;
  QVBoxLayout mainLayout;

public:
  MyMainWindow(QWidget *parent = 0) : QWidget(parent)
  {
    mainLayout.addWidget(&myLabel);
    setLayout(&mainLayout);
    myImage.load("penguin.png");
    QPainter qPainter(&myImage);
    qPainter.setBrush(Qt::NoBrush);
    qPainter.setPen(Qt::red);
    qPainter.drawRect(250,150,50,50);
    myLabel.setPixmap(QPixmap::fromImage(myImage));
    myLabel.show();
    
  }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 
    MyMainWindow *window = new MyMainWindow();
    window->show();
    return a.exec();
}
