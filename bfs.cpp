#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 1e5 + 5;
vector<int> adj[MAX_N];
bool visited[MAX_N];
int dist[MAX_N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> t;

    bfs(s);

    if (visited[t]) {
        cout << dist[t] << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
