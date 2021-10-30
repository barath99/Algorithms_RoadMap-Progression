#include<iostream>
#include<vector>
#include<queue>

using namespace std;


/**
 * BFS will be used in bi-partite graph
 * 
 * @return bool
 */
bool isBipartite(vector<vector<int>>& g) {
    int n = g.size();
    
    vector<int> color(n, -1);

    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; ++i) {
        if(color[i] == -1) {
            q.push({i, 0});
            color[i] = 0;

            while(!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();

                int v = p.first;
                int c = p.second;

                for(int j : g[v]) {
                    if(color[j] == c) return false;
                    if(color[j] == -1) {
                        color[j] = 1 - c;
                        q.push({j, color[j]});
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    /**
     * @brief add Graph vertexes and edges and call isBipartite() with the adj list
     * 
     */
    return 0;
}
