/*                                  */
/* Group Project                    */
/* Will, Katia, Jena, Nicodemus     */
/* Due November 29, 2022            */

#include <iostream>

#include "node.h"
#include "network.h"
#include "insertValues.h"
#include "evaluate.h"
#include <string>
#include "data.h"
#include "linkedlist.h"

using std::cout;
using std::endl;

int main() {

    // n = total number of nodes
    // f = number of faulty nodes
    // pBFT can tolerate f = (n-1)/3
    // pBFT consensus rounds are broken into 4 phases:

    /* Vote messages for a proposal are sent to each peer in the specified order.
     * A delay exists between each propagation. The process repeats until a valid commit or
     * reject message is received from the network. One iteration of this process is called
     * a vote step. The process of propagation starts from the first peer after propagation to
     * last peer in the order of validating peers.
     */

    /* Alice is a "validator who makes a proposal. The first peer in this round's permutation
     * is Clara. Alice creates a vote and propagates the vote to Clara. Alice then switches
     * to "waiting", until some time delay.
     *
     * The vote will be sent to Deana if no commit message is received after some time delay.
     *
     * Clara receives Alice's vote, so now Clara has two votes: Alice and Clara
     *
     * Deena sends her vote to Clara. Now Clara has 3 votes, and makes a commit message
     *
     */



    int state = 0;
    // nodeID, vote, state, consensus
    Network network2;
    for (int i = 1; i <= 100; i++) {
        state = 1;
        if (i % 3 == 0) {
            state = 0;
        }
        values v = insertValues(i, 0, state, 0);
        network2.insertNode(v);
    }

    Network network;

    Evaluate ev;
    network2.assignPeer();
    ev.votePeers(network2);

    // with 5 nodes
    values v1 = insertValues(001, 0, 1, 0);
    network.insertNode(v1);
    values v2 = insertValues(002, 0, 1, 0);
    network.insertNode(v2);
    values v3 = insertValues(003, 0, 0, 0);
    network.insertNode(v3);
    values v4 = insertValues(004, 0, 1, 0);
    network.insertNode(v4);
    values v5 = insertValues(005, 0, 1, 0);
    network.insertNode(v5);

    network.assignPeer();
    ev.votePeers(network);

    Network network1;
    v1 = insertValues(001, 0, 0, 0);
    network1.insertNode(v1);
    v2 = insertValues(002, 0, 1, 0);
    network1.insertNode(v2);
    v3 = insertValues(003, 0, 0, 0);
    network1.insertNode(v3);
    v4 = insertValues(004, 0, 1, 0);
    network1.insertNode(v4);
    v5 = insertValues(005, 0, 1, 0);
    network1.insertNode(v5);

    network1.assignPeer();
    ev.votePeers(network1);


    // with 10 nodes
    values v6 = insertValues(6, 0, 1, 0);
    network.insertNode(v6);
    values v7 = insertValues(7, 0, 0, 0);
    network.insertNode(v7);
    values v8 = insertValues(8, 0, 0, 0);
    network.insertNode(v8);
    values v9 = insertValues(9, 0, 1, 0);
    network.insertNode(v9);
    values v10 = insertValues(10, 0, 1, 0);
    network.insertNode(v10);

    network.assignPeer();
    ev.votePeers(network);

    v6 = insertValues(6, 0, 0, 0);
    network1.insertNode(v6);
    v7 = insertValues(7, 0, 1, 0);
    network1.insertNode(v7);
    v8 = insertValues(8, 0, 0, 0);
    network1.insertNode(v8);
    v9 = insertValues(9, 0, 1, 0);
    network1.insertNode(v9);
    v10 = insertValues(10, 0, 1, 0);
    network1.insertNode(v10);

    network1.assignPeer();
    ev.votePeers(network1);

    // with 15 nodes
    values v11 = insertValues(11, 0, 1, 0);
    network.insertNode(v11);
    values v12 = insertValues(12, 0, 1, 0);
    network.insertNode(v12);
    values v13 = insertValues(13, 0, 0, 0);
    network.insertNode(v13);
    values v14 = insertValues(14, 0, 1, 0);
    network.insertNode(v14);
    values v15 = insertValues(15, 0, 0, 0);
    network.insertNode(v15);

    // with 20 nodes
    values v16 = insertValues(16, 0, 0, 0);
    network.insertNode(v16);
    values v17 = insertValues(17, 0, 0, 0);
    network.insertNode(v17);
    values v18 = insertValues(18, 0, 1, 0);
    network.insertNode(v18);
    values v19 = insertValues(19, 0, 1, 0);
    network.insertNode(v19);
    values v20 = insertValues(20, 0, 0, 0);
    network.insertNode(v20);

    network.assignPeer();
    ev.votePeers(network);


    // with 25
    values v21 = insertValues(21, 0, 1, 0);
    network.insertNode(v21);
    values v22 = insertValues(22, 0, 1, 0);
    network.insertNode(v22);
    values v23 = insertValues(23, 0, 1, 0);
    network.insertNode(v23);
    values v24 = insertValues(24, 0, 1, 0);
    network.insertNode(v24);
    values v25 = insertValues(25, 0, 1, 0);
    network.insertNode(v25);

    network.assignPeer();
    ev.votePeers(network);



    std::cout << "******************************************" << std::endl;

    //generate and display the test data
    int numTestID[] ={1,2,3,4,5,6,7,8,9,10};
    string peerList[] ={"Peer 1", "Peer 2","Peer 3","Peer 4","Peer 5","Peer 6","Peer 7","Peer 8","Peer 9","Peer 10"};
    bool faultList[] = {false,false,true,true,true,true,false,true,false,false};
    bool voteList[] = {true,true,true,true,true,true,true,true,true,true};

    //making temporary data holder for testing
    Data tmpData;

    //making linked list object
    cout << "creating blockchain...";
    LinkedList list;
    cout << "done" << endl << endl;

    cout << "checking blockchain...\n";
    cout << "\tThere are " << list.getCount() << " nodes." << endl;
    list.printList();
    cout << endl;

    int faultCount = 0;
    int voteCout = 0;

    //adding all the test data to the list
    for (int i = 0; i < 10; i++) {
        tmpData.id = numTestID[i];
        tmpData.data = peerList[i];
        tmpData.isFaulty = faultList[i];
        tmpData.vote = voteList[i];

        cout << "adding " << tmpData.id << ": " << tmpData.data ;

        if (list.addNode(tmpData.id, &(tmpData.data),0)) {
            cout << " success";
        } else {
            cout << "failed";
        }

        if(tmpData.isFaulty){
            cout << " Faulty" << endl;
            faultCount++;
        }
        else
        {
            cout << endl;
        }

        if(tmpData.vote)
        {
            voteCout++;
        }
    }
    cout << endl;



    cout << "checking blockchain...\n";
    cout << "\tThere are " << list.getCount() << " nodes." << endl;
    list.printList();
    cout << endl << endl;

    cout << "Block Chain Size: " << list.getCount() << endl;
    cout << "Fault Count = " << faultCount << endl << endl << endl;


    cout <<"Client Sending Transaction..." << endl << endl;

    cout <<"Phase 1 Begins..." << endl << endl;
    cout << "Vote Count = " << voteCout << endl;
    cout << "Fault Count = " << faultCount << endl << endl << endl;


    if (list.getCount()-1/faultCount < voteCout)
    {
        cout << "Proceed with voting..." << endl;
    }
    else
    {
        cout << "Faulty Nodes exceeds N-1/3 Votes" << endl;
        cout << "Transaction Declined" << endl;

        cout << endl << endl;
        cout << "clearing blockchain...";
        list.clearList();
        cout << "done" << endl << endl;

        cout << "checking blockchain...\n";
        cout << "\tThere are " << list.getCount() << " nodes." << endl;
        list.printList();
        cout << endl << endl;
        cout << endl;
    }
    faultCount = 0;
    voteCout = 0;


    cout << "**********************************************************************" << endl << endl;


    int numTestID2[] ={1,2,3,4,5,6,7,8,9,10};
    string peerList2[] ={"Peer 1", "Peer 2","Peer 3","Peer 4","Peer 5","Peer 6","Peer 7","Peer 8","Peer 9","Peer 10"};
    bool faultList2[] = {true,false,false,false,false,false,false,true,true,false};
    bool voteList2[] = {true,true,true,true,true,true,true,true,true,true};
    int voteWeight[] = {10,9,8,7,6,5,4,3,2,1};
    LinkedList list2;
    //making Block Chain object
    cout << "creating blockchain...";
    list2.clearList();
    cout << "done" << endl << endl;

    cout << "checking blockchain...\n";
    cout << "\tThere are " << list2.getCount() << " nodes." << endl;
    list2.printList();
    cout << endl;

    Data tmpData2;
    int faultyWeightTotal = 0;
    int nonFaultWeightTotal=0;
    //adding all the test data to the list
    for (int i = 0; i < 10; i++) {
        tmpData2.id = numTestID2[i];
        tmpData2.data = peerList2[i];
        tmpData2.isFaulty = faultList2[i];
        tmpData2.vote = voteList2[i];


        cout << "adding " << tmpData2.id << ": " << tmpData2.data ;

        if (list2.addNode(tmpData2.id, &(tmpData2.data),voteWeight[i] * 10)) {
            cout << " success";
        } else {
            cout << "failed";
        }

        if(tmpData2.isFaulty){
            cout << " Faulty" << endl;
            faultCount++;
            faultyWeightTotal += voteWeight[i] * 10;
        }
        else
        {
            cout << endl;
        }
        if(tmpData.vote)
        {
            voteCout++;
        }

        if(!tmpData2.isFaulty){
            nonFaultWeightTotal += voteWeight[i] * 10;
        }
    }
    cout << endl;



    cout << "checking blockchain...\n";
    cout << "\tThere are " << list2.getCount() << " nodes." << endl;
    list2.printList();
    cout << endl << endl;

    cout << "Block Chain Size: " << list2.getCount() << endl;
    cout << "Fault Count = " << faultCount << endl;
    cout << "Votes Needed = " << list2.getCount() - faultCount << endl << endl;

    cout <<"Client Sending Transaction..." << endl << endl;


    cout << "Display Vote Weight" << endl;
    list2.printVoteWeightPublic();

    cout << endl;
    cout << "Faulty Weight Total: 100+20+30 / 2 = " << faultyWeightTotal/2 << endl;
    cout << "Non Faulty Weight Total: 100+20+30 = " << nonFaultWeightTotal- 10 << endl;

    cout << "Dividing NonFaultWeight by Fault Weight..." << endl;
    cout << "Must be greater than or equal to 2..." << endl <<endl;

    if(nonFaultWeightTotal/faultyWeightTotal >= 2)
    {
        cout <<"Transaction Approved" << endl;
    }

    return 0;
}