/*                                  */
/* Group Project                    */
/* Will, Katia, Jena, Nicodemus     */
/* Due November 29, 2022            */

#include <iostream>

#include "node.h"
#include "network.h"
#include "insertValues.h"
#include "evaluate.h"

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


    return 0;
}