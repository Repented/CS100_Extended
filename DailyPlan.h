#ifndef DAILYPLAN_H
#define DAILYPLAN_H
#include "Calendar.h"
#include <sstream>

class DailyPlan : public Calendar {
  public:
    DailyPlan(int m, int d, int y, int p, string n = "") : Calendar(m , d, y, p, n) { }
    std::string print() {
        stringstream ss;
        std::string strs;
      switch (month) {
        case 1: ss << "January ";
                break;
        case 2: ss << "February ";
                break;
        case 3: ss << "March ";
                break;
        case 4: ss << "April ";
                break;
        case 5: ss << "May ";
                break;
        case 6: ss << "June ";
                break;
        case 7: ss << "July ";
                break;
        case 8: ss << "August ";
                break;
        case 9: ss << "September ";
                break;
        case 10: ss << "October ";
                break;
        case 11: ss << "November ";
                break;
        case 12: ss << "December ";
                break;
                  //TEMP HOLDER - WILL UPDATE SOON
        default: throw std::invalid_argument("Month is not within range");
    break;
      }
      ss << day << ", " << year << "\n\n";
      ss << "Priority: " << priority << "\n\n";
      ss << "Note: " << note << "\n\n";
      strs = ss.str();
      return strs;
    }
        int getMonth() { return month; }
        int getDay() { return day; }
        int getYear() { return year; }
        string getNote() { return note; }
        int getPriority() { return priority; }
};

#endif
