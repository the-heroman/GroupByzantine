//
//
//

#ifndef GROUP_BYZANTINE_EVALUATE_H
#define GROUP_BYZANTINE_EVALUATE_H

#include "network.h"

// best guess as to how this should look?

class Evaluate: public Network {
public:


    // leader starts the message attempt

    // attempt vote with peers; state is determining factor
    // update vote count
    void votePeers(Network& net);

    // update the system; consensus: (n-1)/3

    // print if consensus was reached or if it failed

};

#endif //GROUP_BYZANTINE_EVALUATE_H
