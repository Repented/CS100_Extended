#ifndef __SORT_H__
#define __SORT_H__
#include "Schedule.h"
class Schedule;

class Sort {
    public:
        /* Pure Virtual Functions */
        Sort() { };
        virtual void sort(Schedule* sch) = 0;
};

#endif //__SORT_H__
