#include "removeeventwindow.h"
#include "ui_removeeventwindow.h"

RemoveEventWindow::RemoveEventWindow(Schedule* sch, QWidget* parent) : QMainWindow(parent), ui(new Ui::RemoveEventWindow), mySchedule(sch)
{
    ui->setupUi(this);
    connect(ui->chooseDateButton, SIGNAL(clicked()), this, SLOT(findAllPlans()));
    connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(removeEvent()));
    myMain = qobject_cast<MainCalendarWindow*>(parentWidget());
}

RemoveEventWindow::~RemoveEventWindow() {
    delete ui;
}

void RemoveEventWindow::removeEvent() {
    int max = mySchedule->getIndices().size();
    string test = ui->listNumberText->text().toStdString();
    if (!mySchedule->invalidInput(test))
    {
        if (stoi(test) >= 0 && stoi(test) < max)
        {
                ui->removeLabel->setText(QString::fromStdString(mySchedule->removeEvent(mySchedule->at(mySchedule->getIndices().at(stoi(test))))));
        }
        else
        {
            ui->removeLabel->setText("No events to be removed.");
        }
    }
    findAllPlans();
}

void RemoveEventWindow::findAllPlans() {
    ui->planTextBrowser->setText(QString::fromStdString(mySchedule->removeEvent(ui->dateEdit_2->date().month(), ui->dateEdit_2->date().day(), ui->dateEdit_2->date().year())));
}

void RemoveEventWindow::closeEvent(QCloseEvent* event) {
    myMain->toggleUpdateButton();
    event->accept();
}

void RemoveEventWindow::toggleSelectButton() {
    if (ui->removeButton->isEnabled())
    {
        ui->removeButton->setEnabled(false);
    }
    else
    {
        ui->removeButton->setEnabled(true);
    }
}
