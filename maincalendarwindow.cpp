#include "maincalendarwindow.h"
#include "ui_maincalendarwindow.h"
//#include <time.h>
#include <QFile>

MainCalendarWindow::MainCalendarWindow(Schedule* sch, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainCalendarWindow), mySchedule(sch)
{
    ui->setupUi(this);
    //maybe use connect() functions to do the buttons instead
    connect(ui->openCalendarButton, SIGNAL(clicked()), this, SLOT(openOptionsWindow()));
    connect(ui->addEventButton, SIGNAL(clicked()), this, SLOT(addEventWindow()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveEvents()));
    connect(ui->printButton, SIGNAL(clicked()), this, SLOT(printEventsWindow()));
    connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(removeEventsWindow()));
}

MainCalendarWindow::~MainCalendarWindow()
{
    delete ui;
}

void MainCalendarWindow::openOptionsWindow() {
    myCalendarViewWindow = new CalendarViewWindow(mySchedule, this);
    myCalendarViewWindow->show();
    ui->openCalendarButton->setEnabled(false);
    ui->removeButton->setEnabled(false);
}

void MainCalendarWindow::addEventWindow() {
    myAddEventWindow = new AddEventWindow(mySchedule);
    myAddEventWindow->show();
}

void MainCalendarWindow::on_updateReminderButton_clicked()
{
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    int dayToday = aTime->tm_mday;
    int monthToday = aTime->tm_mon + 1;
    int yearToday = aTime->tm_year + 1900;
    ui->ReminderTextBrowser->setText(QString::fromStdString(mySchedule->printToday(monthToday, dayToday, yearToday)));
}

void MainCalendarWindow::saveEvents() {
    QFile myfile("calendardata.txt");
    if (myfile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&myfile);
        for (int i = 0; i < mySchedule->size(); i++)
        {
            out << mySchedule->at(i)->getMonth() << "\n";
            out << mySchedule->at(i)->getDay() << "\n";
            out << mySchedule->at(i)->getYear() << "\n";
            out << mySchedule->at(i)->getPriority() << "\n";
            out << QString::fromStdString(mySchedule->at(i)->getNote()) << "\n";
            out << "---END NOTE---" << "\n";
        }
    }
    myfile.resize(myfile.pos());
    myfile.close();
    this->close();
}

void MainCalendarWindow::removeEventsWindow() {
    myRemoveEventWindow = new RemoveEventWindow(mySchedule, this);
    myRemoveEventWindow->show();
    ui->removeButton->setEnabled(false);
    ui->openCalendarButton->setEnabled(false);
}

void MainCalendarWindow::printEventsWindow() {
    myListViewWindow = new ListViewWindow(mySchedule, this);
    myListViewWindow->show();
}

void MainCalendarWindow::toggleUpdateButton() {
    if (ui->openCalendarButton->isEnabled())
    {
        ui->openCalendarButton->setEnabled(false);
    }
    else
    {
        ui->openCalendarButton->setEnabled(true);
    }
    if (ui->removeButton->isEnabled())
    {
        ui->removeButton->setEnabled(false);
    }
    else
    {
        ui->removeButton->setEnabled(true);
    }
}
