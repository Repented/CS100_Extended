#ifndef __SORTBYD_H__
#define __SORTBYD_H__
#include "Schedule.h"
#include "Sort.h"

class SortByD : public Sort {
    public:
        /* Constructors */
        SortByD() { };

        /* Pure Virtual Functions */
        virtual void sort(Schedule* sch);
};

#endif //__SORTBYD_H__
