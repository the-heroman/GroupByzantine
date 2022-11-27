//
// Node class
//

#ifndef GROUP_BYZANTINE_NODE_H
#define GROUP_BYZANTINE_NODE_H



struct values {
    int nodeID;
    int vote;   // need 3 to be validated
    bool state;  // is the node valid for voting
    int consensus; // consensus of the system : (n-1)/3
    // request served successfully when m+1
    int peers[3]; // assigned peers to vote
};
// ^ does it also need waiting?


class Node {
public:
    Node *next;
    values nv;

    // default constructor
    Node()
    {
        nv.nodeID = 000;

        nv.vote = 0;

        nv.state = false;

        nv.consensus = 0;

        nv.peers[3] = {0};

        next = nullptr;
    };
    // constructor
    Node(values nv)
    {
        this->nv = nv;
        this->next = nullptr;
    };
};

#endif //GROUP_BYZANTINE_NODE_H
