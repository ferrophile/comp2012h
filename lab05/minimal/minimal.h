#ifndef MINIMAL_H
#define MINIMAL_H

#include <QtGui>
#include <QLabel>
#include <qtimer.h>

class Minimal : public QWidget {
	Q_OBJECT
	
	private:
		QLabel mainLabel;
		QVBoxLayout mainLayout;
		QTimer *timer;
		
		int timeLeft;
	
	public:
		Minimal(int time);
		
	public slots:
		void updateTimer();
};

#endif
