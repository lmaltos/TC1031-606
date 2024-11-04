#include <iostream>
#include "Graph.h"

using namespace std;
int main() {
    Graph<char> g(false);
    Graph<char> *pg = &g;
    g.addNode('A');
    g.addNode('B');
    g.addNode('C');
    g.addNode('D');
    g.addNode('E');
    g.addNode('F');
    g.addNode('G');
    g.addNode('H');
    g.addNode('I');
    g.addNode('J');
    g.addAdyacency('A','B');
    g.addAdyacency('A','H');
    g.addAdyacency('A','E');
    g.addAdyacency('B','C');
    g.addAdyacency('B','E');
    g.addAdyacency('C','D');
    g.addAdyacency('C','E');
    g.addAdyacency('C','F');
    g.addAdyacency('E','G');
    g.addAdyacency('E','H');
    g.addAdyacency('F','J');
    g.addAdyacency('G','J');
    g.addAdyacency('H','J');
    g.addAdyacency('H','I');
    for (char i = 'A'; i <= 'J'; i++) {
        for (char j = 'A'; j <= 'J'; j++) {
            if (i != j) {
                cout << (g.isAdyacency(i,j) ? 1 : 0) << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    g.breadthFirst();
    g.depthFirst();
    return 0;
}