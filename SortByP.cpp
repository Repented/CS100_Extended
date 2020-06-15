#include "SortByP.h"

void SortByP::sort(Schedule* sch) {
    int max = -1;

    for(int i = 0; i < sch->size()-1; ++i){
        max = i;
        for(int j = i + 1; j < sch->size(); ++j){
            if(sch->at(j)->getPriority() > sch->at(max)->getPriority()){
                max = j;
                sch->swap(max, i);
        }
    }

    }
return;
}
