/*

DFS using an explicit stack.

*/

#include "Graph.h"
#include <map>
#include <stack>
#include <cstdio>
using namespace std;

void DFS(Graph G, const int startVertex, const int endVertex) {

    struct s {
        int v, k;
    };
    map<int, int> visited, parents;
    stack<s> suspended;
    adj_list AL;
    int v, k;

    AL = G.get_adjList();
    for (int v : G.V) {
        visited.insert({v, 0});
        parents.insert({v, -1});
    }

    suspended.push({startVertex, 0});
    visited[startVertex] = 1;

    while (!suspended.empty()) {
        v = suspended.top().v;
        k = suspended.top().k;
        suspended.pop();
        while (k < AL[v].size()) {
            auto n = AL[v].cbegin();
            for (int i = 0; i < k; ++i, n++)
                ;
            if (!visited[*n]) {
                visited[*n] = 1;
                parents[*n] = v;
                suspended.push({v, k + 1});
                v = *n;
                k = 0;
            } else
                k++;
        }
    }

    printf("\nReachable : ");
    visited[endVertex]? printf("YES\n") : printf("NO\n");
    printf("\nvertex\tparent\tvisited\n");
    for (int v : G.V)
        printf("%2d\t%2d\t%2d\n", v, parents[v], visited[v]);
    printf("\n");

}

int main() {

    Graph G;

    // add edges
    G.add(1, 2);
    G.add(1, 3);
    G.add(1, 4);
    G.add(2, 3);
    G.add(4, 5);
    G.add(4, 8);
    G.add(5, 6);
    G.add(5, 7);
    G.add(6, 7);
    G.add(6, 8);
    G.add(6, 9);
    G.add(8, 9);
    G.add(9, 10);
    G.add(11);

    int startVertex, endVertex;
    printf("\nstartVertex  :  ");
    scanf("%d", &startVertex);
    printf("endVertex    :  ");
    scanf("%d", &endVertex);

    DFS(G, startVertex, endVertex);

    return EXIT_SUCCESS;
}