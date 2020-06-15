#include "listviewwindow.h"
#include "ui_listviewwindow.h"

ListViewWindow::ListViewWindow(Schedule* sch, QWidget* parent) : QMainWindow(parent), ui(new Ui::ListViewWindow), mySchedule(sch)
{
    ui->setupUi(this);
    ui->textBrowser->setText(QString::fromStdString(mySchedule->print()));
    connect(ui->dateSortButton, SIGNAL(clicked()), this, SLOT(dateSort()));
    connect(ui->prioritySortButton, SIGNAL(clicked()), this, SLOT(prioritySort()));
}

ListViewWindow::~ListViewWindow() {
    delete ui;
}

void ListViewWindow::dateSort() {
    mySchedule->set_sort(new SortByD());
    mySchedule->sort();
    ui->textBrowser->setText(QString::fromStdString(mySchedule->print()));
}

void ListViewWindow::prioritySort() {
    mySchedule->set_sort(new SortByP());
    mySchedule->sort();
    ui->textBrowser->setText(QString::fromStdString(mySchedule->print()));
}
