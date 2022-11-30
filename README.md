# GroupByzantine
Group 3 Members: 

Jena Lee Heroman

Will Castillo

Katia Melina Gutierrez

Nicodemus A. Robles

## Functionality

n = total number of nodes
f = number of faulty nodes
pBFT can tolerate f = (n-1)/3
pBFT consensus rounds are broken into 4 phases:

Vote messages for a proposal are sent to each peer in the specified order.
A delay exists between each propagation. The process repeats until a valid commit or reject message is received from the network. One iteration of this process is called a vote step. The process of propagation starts from the first peer after propagation to last peer in the order of validating peers.
 
Alice is a "validator who makes a proposal. The first peer in this round's permutation is Clara. Alice creates a vote and propagates the vote to Clara. Alice then switches to "waiting", until some time delay. The vote will be sent to Deana if no commit message is received after some time delay. Clara receives Alice's vote, so now Clara has two votes: Alice and Clara. Deena sends her vote to Clara. Now Clara has 3 votes, and makes a commit message

Node structure

```
Node()
{
	int nodeID
    int vote;   // need 3 to be validated
    bool state;  // is the node valid for voting, default false
    int consensus; // consensus of the system : (n-1)/3
    // request served successfully when m+1
    int peers[3]; // assigned peers to vote
}
```

## CRITERIA
YAC: BFT Consensus Algorithm for Blockchain
by Muratov, Lebedev, Iushkevich, Nasrulin, Takemiya

this program confirms the algorithm that in any system with n number of nodes, the number of faulty nodes allowed is (n-1)/3

## HOW TO RUN USING Online Compiler and Debugger for C/C++ (OnlineGDB)



Download the Program Repository files from...

https://github.com/the-heroman/GroupByzantine/archive/refs/heads/main.zip

Extract folder from Zip to local storage

On your web browser visit https://www.onlinegdb.com/online_c++_compiler

On the top of the webpage, left of "RUN", there will be a cloud icon with an upward arrow.
Click it and locate the previously extracted folder. Then, upload each of the following files.

You should upload 10 files in total.

node.h

network.h

network.cpp

linkedlist.h

linkedlist.cpp

insertValues.h

evaluate.h

evaluate.cpp

data.h

main.cpp 

// Please note by default main.cpp is provided by OnlineGDB but will automatically be replaced with the newly uploaded main.cpp

//Text file "CmakeLists.txt" and folders "cmake-build-debug", ".idea", and ".git"
DO NOT NEED TO BE UPLOADED

Once all 10 files are uploaded click run and program should compile. 


## CREDIT
Jena Lee Heroman,

Will Castillo,

Katia Melina Gutierrez,

Nicodemus A. Robles
