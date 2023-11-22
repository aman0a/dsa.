#include<bits/stdc++.h>
using namespace std;

#define INF 1000000

void primMST(vector<pair<int, int>> adj[], int V) {
    priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;

    int src = 0; 

    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (inMST[v] == false && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<pair<int, int>> adj[V];

    cout << "Enter edges (u v w) where u and v are vertices and w is weight: " << endl;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // Remove this line for directed graph
    }

    cout << "Edges of minimum spanning tree are: " << endl;
    primMST(adj, V);

    return 0;
}

