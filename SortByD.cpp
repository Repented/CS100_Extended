#include "SortByD.h"

void SortByD::sort(Schedule* sch) {
    int max = -1;

    for(int i = 0; i < sch->size()-1; ++i){
        max = i;
        for(int j = i + 1; j < sch->size(); ++j){
            if(sch->at(j)->getYear() < sch->at(max)->getYear()){
                max = j;
                sch->swap(max, i);
            }
            else if((sch->at(j)->getYear() == sch->at(max)->getYear()) &&
                    (sch->at(j)->getMonth() < sch->at(max)->getMonth())){
                max = j;
                sch->swap(max, i);
            }
            else if((sch->at(j)->getYear() == sch->at(max)->getYear()) &&
                    (sch->at(j)->getMonth() == sch->at(max)->getMonth()) &&
                    (sch->at(j)->getDay() < sch->at(max)->getDay())){
                max = j;
                sch->swap(max, i);
            }
        }
    }
    return;
}
