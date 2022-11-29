#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id;
    string data;
    bool isFaulty;
    bool proposal;
    bool validation;
    bool agreement;
    bool vote;
    int voteWeight;
};

struct BlockChainNode {
    Data data;
    BlockChainNode *next;
    BlockChainNode *prev;
};

#endif /* DATA_H */

