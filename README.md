# GroupByzantine
Group 3 Members: Jena Heroman, Katia Gutierrez, Nicodemus Robles, William Castillo

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
