#ifndef MAINCALENDARWINDOW_H
#define MAINCALENDARWINDOW_H

#include <QMainWindow>
#include "Schedule.h"

#include "calendarviewwindow.h"
#include "addeventwindow.h"
#include "listviewwindow.h"
#include "removeeventwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainCalendarWindow; }
QT_END_NAMESPACE

class CalendarViewWindow;

class RemoveEventWindow;

class UpdateEventWindow;

class MainCalendarWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainCalendarWindow(Schedule* sch = nullptr, QWidget *parent = nullptr);
    ~MainCalendarWindow();
public:
    void toggleUpdateButton();

private slots:

    void on_updateReminderButton_clicked();

private:
    //UI for main window (starting window)
    Ui::MainCalendarWindow *ui;

    //New Window for advancing from View Calendar Button
    CalendarViewWindow* myCalendarViewWindow;

     AddEventWindow* myAddEventWindow;

     ListViewWindow* myListViewWindow;

     RemoveEventWindow* myRemoveEventWindow;

    //Schedule composite container for DailyPlans
    Schedule* mySchedule;
public slots:
    //public functions
    void openOptionsWindow();
    void addEventWindow();
    void saveEvents();
    void printEventsWindow();
    void removeEventsWindow();
};
#endif // MAINCALENDARWINDOW_H
