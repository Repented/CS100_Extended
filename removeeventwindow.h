#ifndef REMOVEEVENTWINDOW_H
#define REMOVEEVENTWINDOW_H

#include <QMainWindow>
#include "Schedule.h"
#include <QCloseEvent>
#include "maincalendarwindow.h"

namespace Ui {
    class RemoveEventWindow;
}

class MainCalendarWindow;

class RemoveEventWindow : public QMainWindow
{
    Q_OBJECT
public:
    RemoveEventWindow(Schedule* sch = nullptr, QWidget* parent = nullptr);
    ~RemoveEventWindow();
public:
    void toggleSelectButton();
private:
    Ui::RemoveEventWindow* ui;
    Schedule* mySchedule;
    MainCalendarWindow* myMain;
//    int index;
private slots:
    void removeEvent();
    void findAllPlans();
    void closeEvent(QCloseEvent* event);
};

#endif // REMOVEEVENTWINDOW_H
