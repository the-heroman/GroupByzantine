//
//

#ifndef GROUP_BYZANTINE_INSERTVALUES_H
#define GROUP_BYZANTINE_INSERTVALUES_H

#include "network.h"

// function that makes inserting values a little easier
values insertValues(int a, int b, bool c, int d){
    values v1;
    v1.nodeID = a;
    v1.vote = b;
    v1.state = c;
    v1.consensus = d;

    return v1;
}

#endif //GROUP_BYZANTINE_INSERTVALUES_H
