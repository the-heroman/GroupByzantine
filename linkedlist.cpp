/*********************
Name: William Castillo
**********************/

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    clearList();
}

bool LinkedList::addNode(int id, string *stringData,int voteWeight) {
    bool status = true;

    if (id > 0 && stringData->length() > 0){
        BlockChainNode *current = head;
        BlockChainNode *duplicate = head;

        if (current != NULL) {
            while(duplicate->data.id != id && duplicate->next){
                duplicate = duplicate->next;
            }
            if(id != duplicate->data.id){
                if (id > current->data.id){
                    while(id > current->data.id && current->next != NULL){
                        current = current->next;
                    }
                    replaceTail(id,stringData,current,voteWeight);
                }
            }else{
                status = false;
            }
        }else{
            addHead(id, stringData,voteWeight);
        }
    }else{
        status = false;
    }
    return status;
}

bool LinkedList::deleteNode(int id) {
    bool status = true;
    BlockChainNode *current = head;

    while (current->data.id != id && current->next) {
        current = current->next;
    }

    if(id == current->data.id && current)
    {
        if (current->prev && current->next) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;

        }else if( current->next == NULL && current->prev && current->prev->prev) {

            current->prev->prev->next = current->prev;
            current->prev->next = NULL;
            delete current;

        }else if (current->prev == NULL && current->next && current->next->next) {

            current->next->next->prev = current->next;
            current->next->prev = NULL;
            head = current->next;
            delete current;

        } else if( current->prev == NULL && current->next && current->next->next == NULL){
            current->next->prev = NULL;
            current->next->next = NULL;
            head = current->next;
            delete current;

        } else if(current->next == NULL && current->prev && current->prev->prev == NULL){
            current->prev->next = NULL;
            delete current;
        }
    } else {
        status = false;
    }

    return status;
}

bool LinkedList::getNode(int id, Data *data) {
    bool status = true;
    BlockChainNode *current = head;

    while(current->data.id != id && current->next!= NULL ){
        current = current->next;
    }

    if (id == current->data.id){
        data->id = current->data.id;
        data->data = current->data.data;
    }else{
        status = false;
    }

    return status;
}

void LinkedList::printList(bool backwards) {
    if(!backwards){
        printListForward();
    }else{
        printListBackward();
    }
}

int LinkedList::getCount(){

    BlockChainNode *current = head;

    int count = 0;
    while(current) {
        current = current->next;
        count++;
    }

    return count;
}

bool LinkedList::clearList() {
    bool status = true;
    BlockChainNode *current = head;

    if(current){
        while(current){
            BlockChainNode *trash = current;
            current = current->next;
            delete trash;
        }
        head = NULL;

    } else{
        status = false;
    }

    return status;
}

bool LinkedList::exists(int id) {

    bool status = false;
    BlockChainNode *current = head;

    while(current->data.id != id && current->next!= NULL ){
        current = current->next;
    }

    if (id == current->data.id) {
        status = true;
    }

    return status;

}

void LinkedList::printListForward() {
    BlockChainNode* current = head;
    while(current){
        if(current->next) {
            cout << current->data.data << " ---> ";
        }else
        {
            cout << current->data.data;
        }
        current = current->next;
    }
}

void LinkedList::printVoteWeight() {
    BlockChainNode* current = head;
    while(current){
        if(current->next) {
            cout << current->data.data << " : "<< current->data.voteWeight << " ---> ";
        }else
        {
            cout << current->data.data << " : "<< current->data.voteWeight << endl;
        }
        current = current->next;
    }
}

void LinkedList::printListBackward() {
    BlockChainNode *current = head;
    while(current->next) {
        current = current->next;
    }
    while(current){
        cout << current->data.id << ": " << current->data.data << endl;
        current = current->prev;
    }
}

void LinkedList::addHead( int &id, string *stringData,int voteWeight){
    BlockChainNode *addHead = newNode(id,stringData, addHead,voteWeight);
    addHead->next = NULL;
    addHead->prev = NULL;
    head = addHead;
}


void LinkedList::replaceTail(int &id, string *stringData, BlockChainNode *current, int voteWeight) {

    BlockChainNode *replaceTail = newNode(id,stringData, replaceTail, voteWeight);
    replaceTail->next = NULL;
    replaceTail->prev = current;
    current->next = replaceTail;
}



BlockChainNode* LinkedList::newNode(int &id, string *stringDada, BlockChainNode *newNode,int voteWeight) {
    newNode = new BlockChainNode;
    newNode->data.id = id;
    newNode->data.data = *stringDada;
    newNode->data.voteWeight = voteWeight;
    return newNode;
}

void LinkedList::printVoteWeightPublic() {
    printVoteWeight();
}

