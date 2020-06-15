#ifndef UPDATEEVENTWINDOW_H
#define UPDATEEVENTWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "Schedule.h"
#include "maincalendarwindow.h"

namespace Ui {
    class UpdateEventWindow;
}

class MainCalendarWindow;

class UpdateEventWindow : public QMainWindow
{
    Q_OBJECT
public:
    UpdateEventWindow(Schedule* sch = nullptr, int index = -1, QWidget* parent = nullptr);
    ~UpdateEventWindow();
private:
    Ui::UpdateEventWindow *ui;

    Schedule* mySchedule;
    Calendar* myPlan;
    int index;
    MainCalendarWindow* myMain;
private slots:
    void updateDate();
    void updatePriority();
    void updateNote();
    void closeWindow();
    void closeEvent(QCloseEvent* event);
};

#endif // UPDATEEVENTWINDOW_H
