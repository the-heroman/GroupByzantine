/*********************
Name: William Castillo
**********************/

#include "data.h"
#include "iostream"

using std::cout;
using std::endl;

class LinkedList{

public:

    LinkedList();
    ~LinkedList();
    bool addNode(int, string*,int);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);
    void printVoteWeightPublic();

private:
    BlockChainNode *head;
    void addHead(int&, string*,int);
    void replaceTail(int&, string*, BlockChainNode*,int);
    BlockChainNode* newNode(int&, string*, BlockChainNode*,int);
    void printListBackward();
    void printListForward();
    void printVoteWeight();
};
