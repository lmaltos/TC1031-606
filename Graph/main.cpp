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
    g.addAdyacency('A','B');
    g.addAdyacency('A','C');
    g.addAdyacency('A','E');
    g.addAdyacency('B','D');
    g.addAdyacency('C','D');
    g.addAdyacency('E','D');
    for (char i = 'A'; i <= 'E'; i++) {
        for (char j = 'A'; j <= 'E'; j++) {
            if (i != j) {
                cout << (g.isAdyacency(i,j) ? 1 : 0) << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}