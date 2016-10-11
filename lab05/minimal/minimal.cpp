#include "minimal.h"

#include <QApplication>

Minimal::Minimal(int time) : QWidget(0), timeLeft{time} {
	mainLayout.addWidget(&mainLabel);
	setLayout(&mainLayout);
	
	mainLabel.setText(QString::number(time));
	mainLabel.show();
	
	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
	timer->start(1000);
}

void Minimal::updateTimer() {
	if (!timeLeft) return;
	mainLabel.setText(QString::number(--timeLeft));
	mainLabel.show();
}
