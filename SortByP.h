#ifndef __SORTBYP_H__
#define __SORTBYP_H__
#include "Schedule.h"
#include "Sort.h"

class SortByP : public Sort {
    public:
        /* Constructors */
        SortByP() { };

        /* Pure Virtual Functions */
        virtual void sort(Schedule* sch);
};

#endif //__SORTBYP_H__
