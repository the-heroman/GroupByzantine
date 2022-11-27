//
// network
//

#include <iostream>
#include "network.h"

int Network::getLen(){
    return peerCount;
}

// function to insert
void Network::insertNode(values valueToEnter) {
    // create new
    Node *newNode = new Node(valueToEnter);

    // if it's empty, it starts the list
    if(head == nullptr){
        head = newNode;
        peerCount++;
        return;
    }

    // otherwise, go to the end of the list
    Node *temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }

    // insert at the end
    temp->next = newNode;
    peerCount++;
}

// not sure if it will be needed, but why not
Node* Network::getEntry(int position){
    bool ableToGet = (position >=1) && (position <= peerCount);
    if (ableToGet) {
        Node *curPtr = head;
        for (int skip = 1; skip < position; skip++)
            curPtr = curPtr->next;
        return curPtr;
    }

}

// everyone gets a voting peer
void Network::assignPeer(){
    Node *temp = head;

    while (temp != nullptr){
        int y = 0;
        int count = 1;
        int x = temp->nv.nodeID;

        // 3 peers for everyone
        for (int i = 0; i < 3; i++){

            // if the ID is greater then the number of nodes, it's peer starts over from the beginning
            if ((x + count) > peerCount) {
                temp->nv.peers[i] = y + 1;
                y++;

            // peer is the next 3 nodes
            } else {
                temp->nv.peers[i] = x + count;
            }
            count++;
        }
        temp = temp->next;

    }
}


// function to print
// for testing
void Network::printNetwork() {
    Node *temp = head;

    // make sure it's not empty
    if (head == nullptr){
        std::cout << "empty" << std::endl;
        return;
    }

    // otherwise, print
    while (temp!= nullptr){
        std::cout << "ID " << temp->nv.nodeID << "; consensus " << temp->nv.consensus << std::endl;
        std::cout << "Peers: ";
        for (int i = 0; i < 3; i++){
            std::cout << temp->nv.peers[i] << "; ";
        }
        temp = temp->next;
        std::cout << std::endl;
    }
}