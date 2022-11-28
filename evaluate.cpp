//
//
//

#include <iostream>
#include <cmath>
#include "evaluate.h"


void Evaluate::votePeers(Network& net) {
    // get the first node
    Node *temp = net.getEntry(1);
    int numberInSystem = net.getLen();

    int f = faultyAllowed(net);
    bool val = false;
    bool canVote = false;
    int cUP = 0;

    // for each node in the system
    for (int i = 0; i < numberInSystem; i++){
        temp->nv.consensus = cUP; // consensus update
        // count the votes for the Node's 3 peers
        for (int j = 0; j < 3; j++){
            // if the state of the current node is false, it cannot vote
            if (temp->nv.state){
                Node *A = net.getEntry(temp->nv.peers[j]);

                // if the state of the peer is faulty, vote can't be validated
                if (A->nv.state){
                    temp->nv.vote++;
                    //std::cout << "cUP " << cUP << std::endl;
                }
                canVote = true;
            }
        }
        // if the node can vote, see if the system has reached the amount needed for validation
        // increase the consensus of the system as well
        if (canVote){
            cUP++;
            val = validateSystem(numberInSystem, cUP, f);
        }
        // update the status of the system next
        temp->nv.consensus = cUP;
        temp = temp->next;


        canVote = false;
    }
    net.printNetwork();
    std::cout << std::boolalpha << "Validated: " << val << std::endl;
}

// n = total number of nodes
// f = number of faulty nodes
// pBFT can tolerate f = (n-1)/3
bool Evaluate::validateSystem(int n, int c, int f){
    // number of nodes needed for validation: (#totalNodes -1) / 3
    int tol = floor((n-1)/3);
    int needed = n-tol;

    // if the current consensus is greater or equal to the number needed for validation
    if (c >= needed){
        return true;
    }

}

// find the number of faulty nodes
// cheating: just count the status if it's 0
int Evaluate::faultyAllowed(Network net) {
    // get the first node
    Node *temp = net.getEntry(1);
    // number of faulty nodes in the system
    // needed for Status update
    int f = 0;
    while (temp != nullptr){
        if (!temp->nv.state)
            f++;
        temp = temp->next;
    }
    return f;
}


