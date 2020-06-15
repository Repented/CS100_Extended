#ifndef CALENDAROPTIONSWINDOW_H
#define CALENDAROPTIONSWINDOW_H

#include <QMainWindow>
#include "Schedule.h"
#include <QCloseEvent>

#include "updateeventwindow.h"
#include "maincalendarwindow.h"

namespace Ui {
    class CalendarViewWindow;
}

class MainCalendarWindow;

class UpdateEventWindow;

class CalendarViewWindow : public QMainWindow {
    Q_OBJECT

    public:
        CalendarViewWindow(Schedule* sch = nullptr, QWidget *parent = nullptr);
        ~CalendarViewWindow();
        void setChild(QMainWindow*);
    private:
        Ui::CalendarViewWindow* ui;
        Schedule* mySchedule;
        int max = -1;

        UpdateEventWindow* myUpdateEventWindow;
        MainCalendarWindow* myMain;

        QMainWindow* child = nullptr;

    private slots:
        void findAllPlans();
        void updateEventWindow();
        void closeEvent(QCloseEvent* event);
};

#endif // CALENDAROPTIONSWINDOW_H
