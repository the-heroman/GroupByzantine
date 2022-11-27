//
//
//

#include <iostream>
#include "evaluate.h"


void Evaluate::votePeers(Network& net) {
    // get the first node
    Node *temp = net.getEntry(1);
    int numberInSystem = net.getLen();

    // for each node in the system
    for (int i = 0; i < numberInSystem; i++){

        // count the votes for the Node's 3 peers
        for (int j = 0; j < 3; j++){
            // if the state of the current node is false, it cannot vote
            if (temp->nv.state){
                Node *A = net.getEntry(temp->nv.peers[j]);

                // if the state of the peer is faulty, vote can't be validated
                if (A->nv.state){
                    temp->nv.vote++;

                    // update the status of the system next
                }
            }
        }
        temp = temp->next;

    }

}



