#include "updateeventwindow.h"
#include "ui_updateeventwindow.h"
#include <QDebug>

UpdateEventWindow::UpdateEventWindow(Schedule* sch, int ind, QWidget* parent) : QMainWindow(parent), ui(new Ui::UpdateEventWindow), mySchedule(sch), index(ind)
{
    ui->setupUi(this);
    connect(ui->dateButton, SIGNAL(clicked()), this, SLOT(updateDate()));
    connect(ui->noteButton, SIGNAL(clicked()), this, SLOT(updateNote()));
    connect(ui->priorityButton, SIGNAL(clicked()), this, SLOT(updatePriority()));
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(closeWindow()));
    myPlan = mySchedule->at(mySchedule->getIndices().at(index));
    QDate date;
    date.setDate(myPlan->getYear(), myPlan->getMonth(), myPlan->getDay());
    ui->dateEdit->setDate(date);
    ui->noteTextEdit->setText(QString::fromStdString(myPlan->getNote()));
    ui->prioritySpinBox->setValue(myPlan->getPriority());
    myMain = qobject_cast<MainCalendarWindow*>(parentWidget()->parentWidget());

}

UpdateEventWindow::~UpdateEventWindow() {
    delete ui;
}

void UpdateEventWindow::updateDate() {
    mySchedule->at(mySchedule->getIndices().at(index))->setMonth(ui->dateEdit->date().month());
    mySchedule->at(mySchedule->getIndices().at(index))->setDay(ui->dateEdit->date().day());
    mySchedule->at(mySchedule->getIndices().at(index))->setYear(ui->dateEdit->date().year());
}

void UpdateEventWindow::updateNote() {
    mySchedule->at(mySchedule->getIndices().at(index))->setNote(ui->noteTextEdit->toPlainText().toStdString());
//    qDebug() << ui->noteTextEdit->toPlainText();
}

void UpdateEventWindow::updatePriority() {
    mySchedule->at(mySchedule->getIndices().at(index))->setPriority(ui->prioritySpinBox->value());
}

void UpdateEventWindow::closeWindow() {
    myMain->toggleUpdateButton();
    qobject_cast<CalendarViewWindow*>(parentWidget())->setChild(nullptr);
    this->close();
}

void UpdateEventWindow::closeEvent(QCloseEvent* event) {
    myMain->toggleUpdateButton();
    qobject_cast<CalendarViewWindow*>(parentWidget())->setChild(nullptr);
    event->accept();
}
