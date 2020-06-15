#include "calendarviewwindow.h"
#include "ui_calendarviewwindow.h"
#include <QDebug>

CalendarViewWindow::CalendarViewWindow(Schedule* sch, QWidget *parent) : QMainWindow(parent), ui(new Ui::CalendarViewWindow), mySchedule(sch) {
    ui->setupUi(this);
    connect(ui->chooseDateButton, SIGNAL(clicked()), this, SLOT(findAllPlans()));
    connect(ui->selectButton, SIGNAL(clicked()), this, SLOT(updateEventWindow()));
    myMain = qobject_cast<MainCalendarWindow*>(parentWidget());
}

CalendarViewWindow::~CalendarViewWindow() {
    delete ui;
}

void CalendarViewWindow::updateEventWindow() {
    max = mySchedule->getIndices().size();
    string test = ui->listNumberText->text().toStdString();
    if (!mySchedule->invalidInput(test))
    {
        if (stoi(test) >= 0 && stoi(test) < max)
        {
            myUpdateEventWindow = new UpdateEventWindow(mySchedule, stoi(test), this);
            myUpdateEventWindow->show();
            ui->selectButton->setEnabled(false);
            child = myUpdateEventWindow;
        }
    }
}

void CalendarViewWindow::findAllPlans() {
    ui->planTextBrowser->setText(QString::fromStdString(mySchedule->updateEvent(ui->dateEdit->date().month(), ui->dateEdit->date().day(), ui->dateEdit->date().year())));
    if (child == nullptr)
    {
        ui->selectButton->setEnabled(true);
    }
}

void CalendarViewWindow::closeEvent(QCloseEvent* event) {
    if (child == nullptr)
    {
        myMain->toggleUpdateButton();
    }
    event->accept();
}

void CalendarViewWindow::setChild(QMainWindow * ch) {
    child = ch;
}
