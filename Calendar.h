#ifndef CALENDAR_H
#define CALENDAR_H
#include <time.h>
#include <iostream>
#include <cstring>

using namespace std;

class Sort;

class Calendar {
  protected:
    int month;
    int day;
    int year;
    string note;
  int priority;
  public:
    Calendar() { month = 0; day = 0; year = 0; note = ""; priority = 1; }
    Calendar(int m, int d, int y , int p = 1, string n = "") {
      month = m;
      day = d;
      year = y;
      note = n;
    priority = p;
    }
    int getMonth() const {
      return month;
    }

    int getDay() const {
      return day;
    }

    int getYear() const {
      return year;
    }

    void setMonth(int m) {
      month = m;
    }

    void setDay(int d) {
      day = d;
    }

    void setYear(int y) {
      year = y;
    }

    string getNote() const {
      return note;
    }

    void setNote(string n) {
      note = n;
    }

  int getPriority() const {
    return priority;
   }

   void setPriority(int p) {
    priority = p;
   }

    friend bool operator==(const Calendar& lhs, const Calendar& rhs) {
        return (lhs.priority == rhs.priority && lhs.note == rhs.note && lhs.month == rhs.month && lhs.day == rhs.day && lhs.year == rhs.year);
    }
    virtual string print() = 0;
};

#endif
