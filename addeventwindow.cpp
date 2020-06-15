#include "addeventwindow.h"
#include "ui_addeventwindow.h"

AddEventWindow::AddEventWindow(Schedule* sch, QWidget* parent) : QMainWindow(parent), ui(new Ui::AddEventWindow), mySchedule(sch)
{
    ui->setupUi(this);
    connect(ui->priorityButton, SIGNAL(clicked()), this, SLOT(savePriority()));
    connect(ui->dateButton, SIGNAL(clicked()), this, SLOT(saveDate()));
    connect(ui->noteButton, SIGNAL(clicked()), this, SLOT(saveNote()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveEvent()));
}

AddEventWindow::~AddEventWindow() {
    delete ui;
}

void AddEventWindow::savePriority() {
    priority = ui->prioritySpinBox->value();
}

void AddEventWindow::saveDate() {
    month = ui->dateEdit->date().month();
    day = ui->dateEdit->date().day();
    year = ui->dateEdit->date().year();
}

void AddEventWindow::saveNote() {
    note = ui->noteTextEdit->toPlainText().toStdString();
}

void AddEventWindow::saveEvent() {
    if (month != -1 && day != -1 && year != -1 && priority != -1)
    {
        mySchedule->addEvent(new DailyPlan(month, day, year, priority, note));
        this->close();
    }
}
