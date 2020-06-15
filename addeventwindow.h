#ifndef ADDEVENTWINDOW_H
#define ADDEVENTWINDOW_H

#include <QMainWindow>
#include "Schedule.h"
#include "DailyPlan.h"

namespace Ui {
    class AddEventWindow;
}

class AddEventWindow : public QMainWindow {
    Q_OBJECT

public:
    AddEventWindow(Schedule* sch = nullptr, QWidget* parent = nullptr);
    ~AddEventWindow();
private:
    Ui::AddEventWindow* ui;
    Schedule* mySchedule;
private:
    int month = -1, day = -1, year = -1;
    int priority = -1;
    std::string note = "";

private slots:
    void savePriority();
    void saveDate();
    void saveNote();
    void saveEvent();
};

#endif // ADDEVENTWINDOW_H
