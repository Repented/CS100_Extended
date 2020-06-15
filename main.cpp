#include "maincalendarwindow.h"

#include <QApplication>
#include "Schedule.h"
#include "DailyPlan.h"
#include <fstream>
#include <QFile>
#include <QDebug>
//#include <QtQml/QQmlEngine>

void build(Schedule*);
void quit(Schedule*);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Schedule* sch = new Schedule();
    build(sch);
    if (sch->size() != 0)
    {
        qDebug() << "Adds correctly";
    }
    else
    {
        qDebug() << "Incorrect Add";
    }
//    QQmlEngine::setObjectOwnership(sch, QQmlEngine::CppOwnership);
    MainCalendarWindow w(sch);
    w.show();
//    quit(sch);
    return a.exec();
}

void quit(Schedule* sch) {
    QFile myfile("calendardata.txt");
    if (myfile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&myfile);
        for (int i = 0; i < sch->size(); i++)
        {
            out << sch->at(i)->getMonth() << "\n";
            out << sch->at(i)->getDay() << "\n";
            out << sch->at(i)->getYear() << "\n";
            out << sch->at(i)->getPriority() << "\n";
            out << QString::fromStdString(sch->at(i)->getNote()) << "\n";
            out << "---END NOTE---" << "\n";
        }
    }
    myfile.close();
}

void build(Schedule* sch) {
      //using textfile, build all DailyPlans
    int m = 0;
    int d = 0;
    int y = 0;
    int p = 0;
    string n = "";
    string temp = "";
    string comparator = "---END NOTE---";
    QFile myfile("calendardata.txt");
//    string line = "";
    if (myfile.size() == 0)
    {
        return;
    }
    if (myfile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&myfile);
        while (!in.atEnd()) {
            m = in.readLine().toInt();
            d = in.readLine().toInt();
            y = in.readLine().toInt();
            p = in.readLine().toInt();
            temp = in.readLine().toStdString();
            qDebug() << QString::fromStdString(temp);
            while (temp != comparator)
            {
                n += temp;
                temp = in.readLine().toStdString();
                if (temp != comparator)
                {
                    n += "\n";
                }
            }
            DailyPlan* newPlan = new DailyPlan(m, d, y, p, n);
            sch->addEvent(newPlan);
            n = "";
        }
    }
    else
    {
        qDebug() << "Did not open correctly";
    }
    myfile.close();
    sch->set_sort(new SortByD());
}
