#ifndef LISTVIEWWINDOW_H
#define LISTVIEWWINDOW_H

#include <QMainWindow>
#include "Schedule.h"

namespace Ui {
    class ListViewWindow;
}
class ListViewWindow : public QMainWindow
{
    Q_OBJECT
public:
    ListViewWindow(Schedule* sch = nullptr, QWidget* parent = nullptr);
    ~ListViewWindow();
private:
    Ui::ListViewWindow* ui;
    Schedule* mySchedule;
private slots:
    void dateSort();
    void prioritySort();
};

#endif // LISTVIEWWINDOW_H
