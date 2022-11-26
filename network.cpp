//
// network
//

#include <iostream>
#include "network.h"


// function to insert
void Network::insertNode(values valueToEnter) {
    // create new
    Node *newNode = new Node(valueToEnter);

    // if it's empty, it starts the list
    if(head == nullptr){
        head = newNode;
        return;
    }

    // otherwise, go to the end of the list
    Node *temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }

    // insert at the end
    temp->next = newNode;
}

// function to print
void Network::printNetwork() {
    Node *temp = head;

    // make sure it's not empty
    if (head == nullptr){
        std::cout << "empty" << std::endl;
        return;
    }

    // otherwise, print
    while (temp!= nullptr){
        std::cout << temp->nv.nodeID << " " << temp->nv.consensus;
        temp = temp->next;
        std::cout << std::endl;
    }
}