//
// Network of nodes
//

#ifndef GROUP_BYZANTINE_NETWORK_H
#define GROUP_BYZANTINE_NETWORK_H

# include "node.h"

class Network {
    Node *head;
    int peerCount = 0;


public:
    // default constructor
    Network() { head = nullptr;}

    // get the length of of the list
    int getLen();

    // get entry at position
    Node* getEntry(int position);

    // insert a node at the end
    void insertNode(values);

    // assign peers
    void assignPeer();

    // print nodes
    void printNetwork();

};

#endif //GROUP_BYZANTINE_NETWORK_H
