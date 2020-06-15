#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Calendar.h"
#include "Sort.h"
#include "SortByD.h"
#include "SortByP.h"
#include <vector>
//#include <iostream>
#include <sstream>
#include <QDebug>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Schedule : public Calendar {
  private:
    std::vector<Calendar*> schedule;
    std::vector<int> myIndicesVector;
  protected:
    Sort* sort_function = nullptr;
  public:
    Schedule() : Calendar() { }
    string print() {
        stringstream ss;
        string strs;
      for (auto s : schedule) {
        ss << s->print();
      }
      strs = ss.str();
      return strs;
    }

    vector<int> getIndices() const {
        return myIndicesVector;
    }

    void set_sort (Sort* s) { sort_function = s; }
    void sort() {
        if (sort_function == nullptr) {
            qDebug() << "Error: sort function is null";
            return;
        } else {
            sort_function->sort(this);
        }
    }

    void addEvent(Calendar* newEvent) {
      schedule.push_back(newEvent);
      //TODO: REMOVE DEBUG LINE
      qDebug() << QString::number(schedule.size());
    }

    string removeEvent(Calendar* newEvent) {
        string remove = "";
      for (unsigned int i = 0; i < schedule.size(); i++)
      {
        if (*(schedule.at(i)) == *newEvent)
        {
          schedule.erase(schedule.begin() + i);
          remove = "Removed event successfully";
          break;
        }
      }
      return remove;
    }

    bool checkIfValidDate(int m , int d, int y) {
        bool result = false;
        for (unsigned int i = 0; i < schedule.size(); ++i) {
            if (schedule.at(i)->getMonth() == m && schedule.at(i)->getDay() == d && schedule.at(i)->getYear() == y) {
                result = true;
            }
        }
        return result;
    }

    string printToday(int m, int d, int y) {
        string strs;
        stringstream ss;
        int r = schedule.size();
        qDebug() << QString::number(r);
        ss << "Today is " << m << "/" << d << "/" << y << "\n";
        bool remindersToday = checkIfValidDate(m, d, y);
        if (remindersToday == false) {
            ss << "There are no reminders for today.\n";
            strs = ss.str();
            return strs;
        }
        ss << "\n";
        ss << "Your reminders for today are: \n\n";
        for (unsigned int i = 0; i < schedule.size(); ++i) {
            if (schedule.at(i)->getMonth() == m && schedule.at(i)->getDay() == d && schedule.at(i)->getYear() == y) {
                ss << schedule.at(i)->print();
            }
        }
        strs = ss.str();
        return strs;
    }

    string removeEvent(int m, int d, int y) {
        stringstream ss;
        string strs;
        bool exists = checkIfValidDate(m, d, y);
        if (!exists) {
            ss << "There is no event with the corresponding date.";
            myIndicesVector.clear();
            return ss.str();
        }
        ss << "Please enter an integer that corresponds to the event you would like to remove" << "\n";
        ss << "\n" << "-----------------------------" << "\n\n";
        vector<int> indices;
        for (unsigned int i = 0; i < schedule.size(); ++i) {
            if (schedule.at(i)->getMonth() == m && schedule.at(i)->getDay() == d && schedule.at(i)->getYear() == y) {
                ss << indices.size() << ". ";
                ss << schedule.at(i)->print();
                indices.push_back(i);
            }
        }
        myIndicesVector = indices;
        strs = ss.str();
        return strs;
    }
    string removeEventNow(vector<int> indices, string indexStr) {
        //after printing out
        stringstream ss;
        string strs;
        if (invalidInput(indexStr))
        {
            cout << "Invalid Input!" << endl;
            ss.clear();
            strs = ss.str();
            return strs;
        }
        int index = -1;
        index = stoi(indexStr);
        if (index >= (int)schedule.size() || index < 0) {
            cout << "Invalid index! Please try again" << endl;
            ss.clear();
            return ss.str();
        }
        removeEvent(schedule.at(indices.at(index)));
        ss << "Removed event at " << index << " successfully!" << "\n";
        return ss.str();
    }

    string updateEvent(int m, int d, int y) {
        stringstream ss;
        string strs;
        ss << "Please enter an integer that corresponds to the event you would like to update\n";
        ss << "\n-----------------------------\n\n";
        vector<int> indices;
        for (unsigned int i = 0; i < schedule.size(); ++i) {
            if (schedule.at(i)->getMonth() == m && schedule.at(i)->getDay() == d && schedule.at(i)->getYear() == y) {
//                qDebug() << "Passes first if statement";
                ss << indices.size() << ". ";
                ss << schedule.at(i)->print();
                indices.push_back(i);
            }
        }
        if (indices.size() <= 0)
        {
            qDebug() << "Passes";
            ss << "No matching plans found\n\n";
            strs = ss.str();
            myIndicesVector.clear();
            return strs;
        }
        myIndicesVector = indices;
        strs = ss.str();
        return strs;
}

    //OLD CML FUNCTION
//string updateEventNow(vector<int> indices, string indexStr) {
//        //after printing out
//        stringstream ss;
//        string strs;
//        if (invalidInput(indexStr))
//        {
//            cout << "Invalid Input!" << endl;
//            ss.clear();
//            strs = ss.str();
//            return strs;
//        }
//        int index = -1;
//        index = stoi(indexStr);
//        if (index >= (int)schedule.size() || index < 0) {
//            cout << "Invalid index! Please try again" << endl;
//            ss.clear();
//            strs = ss.str();
//            return strs;
//        }
//        cout << endl;
//        cout << "What about this event would you like to change?" << endl;
//        cout << endl << "-----------------------------" << endl << endl;
//        //MENU FOR UPDATES
//        printUpdateMenu();
//        string choiceStr;
//        cin >> choiceStr;
//        if (invalidInput(choiceStr))
//        {
//            cout << "Invalid Input!" << endl;
//            return strs;
//        }
//        int choice = stoi(choiceStr);
//        if (choice < 0 || choice > 3)
//        {
//            cout << "Invalid Input!" << endl;
//            return strs;
//        }
//        return strs;
//        switch(choice) {
//            case 1: {
//                        cout << endl << "What part?" << endl;
//                        cout << endl << "-----------------------------" << endl << endl;
//                        cout << "1. Month" << endl << "2. Day" << endl << "3. Year" << endl;
//                        string dateStr;
//                        cin >> dateStr;
//                        if (invalidInput(dateStr))
//                        {
//                            cout << "Invalid Input!" << endl;
//                            return strs;
//                        }
//                        switch(stoi(dateStr)) {
//                            case 1: {
//                                        cout << endl << "Enter an appropriate month" << endl;
//                                        string monthStr;
//                                        cin >> monthStr;
//                                        cout << stoi(monthStr) << endl;
//                                        if (invalidInput(monthStr))
//                                        {
//                                            cout << "Invalid Input!" << endl;
//                                            return strs;
//                                        }
//                                        int monthCheck = stoi(monthStr);
//                                        if (monthCheck <= 0 || monthCheck > 12)
//                                        {
//                                            cout << "Invalid Input!" << endl;
//                                            return strs;
//                                        }
//                                        schedule.at(indices.at(index))->setMonth(monthCheck);
//                                        break;
//                            }

//                            case 2: {
//                                        cout << endl << "Enter an appropriate day" << endl;
//                                        string dayStr;
//                                        cin >> dayStr;
//                                        if (invalidInput(dayStr))
//                                        {
//                                            cout << "Invalid Input!" << endl;
//                                            return strs;
//                                        }
//                                        //TODO: Check day limits based on month
//                                        int dayCheck = stoi(dayStr);
//                                        if (dayCheck <= 0)
//                                        {
//                                            cout << "Invalid Input!" << endl;
//                                            return strs;
//                                        }
//                                        schedule.at(indices.at(index))->setDay(stoi(dayStr));
//                                        break;
//                            }

//                            case 3: {
//                                        cout << endl << "Enter an appropriate year" << endl;
//                                        string yearStr;
//                                        cin >> yearStr;
//                                        if (invalidInput(yearStr))
//                                        {
//                                            cout << "Invalid Input!" << endl;
//                                            return strs;
//                                        }
//                                        schedule.at(indices.at(index))->setYear(stoi(yearStr));
//                                        break;
//                            }

//                            default: cout << "Invalid Input! Please Enter A Number 1-3" << endl;
//                                     break;
//                        }
//                break;
//            }
//            case 2: {
//                cout << endl << "Enter a new priority for the event." << endl;
//                string prStr;
//                cin >> prStr;
//                if (invalidInput(prStr))
//                {
//                    cout << "Invalid Input!" << endl;
//                    return strs;
//                }
//                else if (stoi(prStr) > 5 || stoi(prStr) < 1) {
//                    cout << "Please enter a number from 1-5." << endl;
//                    return strs;
//                }
//                schedule.at(indices.at(index))->setPriority(stoi(prStr));
//                break;
//            }

//            case 3: {
//                cout << endl << "Enter what you would like to replace the note by." << endl;
//                cin.ignore();
//                string noteStr;
//                getline(cin, noteStr);
//                schedule.at(indices.at(index))->setNote(noteStr);
//                break;
//            }
//            default: cout << "Invalid Input! Please Enter A Number 1-3" << endl;
//            break;
//        }
//    }

    void printUpdateMenu() {
        cout << "1. " << "Change the Date" << endl;
        cout << "2. " << "Change the Priority" << endl;
        cout << "3. " << "Change the Note" << endl;
    }
    void swap(int i, int j){
        vector<Calendar*>::iterator it = schedule.begin();
        vector<Calendar*>::iterator it1 = schedule.begin();
        advance(it, i);
        advance(it1, j);
        std::swap(*it, *it1);
    }

    Calendar* at(int i)
    {
      return schedule.at(i);
    }

    int size() const {
      return schedule.size();
    }

    bool invalidInput(string input) {
    string::const_iterator it = input.begin();
    while (it != input.end() && isdigit(*it)) {
        ++it;
    }
    if (it == input.end() && !input.empty()) {
        return false;
    }
    return true;
    }
};

#endif // SCHEDULE_H
