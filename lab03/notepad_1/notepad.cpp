#include <QtGui>
#include "notepad.h"

Notepad::Notepad()
 {
     textEdit = new QTextEdit;
     quitButton = new QPushButton(tr("Quit"));

     connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(textEdit);
     layout->addWidget(quitButton);

     setLayout(layout);

     setWindowTitle(tr("Notepad"));
 }

void Notepad::quit()
{
	QMessageBox messageBox;
	messageBox.setWindowTitle(tr("Notepad"));
	messageBox.setText(tr("Do you really want to quit?"));
	messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	messageBox.setDefaultButton(QMessageBox::No);
	if (messageBox.exec() == QMessageBox::Yes)
		qApp->quit();
}
