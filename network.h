//
// Network of nodes
//

#ifndef GROUP_BYZANTINE_NETWORK_H
#define GROUP_BYZANTINE_NETWORK_H

# include "node.h"

class Network {
    Node *head;

public:
    // default constructor
    Network() { head = nullptr;}

    // insert a node at the end
    void insertNode(values);

    // print nodes
    void printNetwork();

};

#endif //GROUP_BYZANTINE_NETWORK_H
