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




    // nodeID, vote, state, consensus
    Network network;
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
    //values v6 = insertValues(006, 0, 0, 0);
    //network.insertNode(v6);


    std::cout << std::endl;
    std::cout << "testing " << std::endl;

    network.assignPeer();
    Evaluate ev;
    ev.votePeers(network);
    //network.printNetwork();




    return 0;
}