#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<unordered_map>
#include<stack>

class Graph{
    private:
    std::unordered_map<int , std::vector<int>> adj;
    public:
    void addEdge(int u , int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start){
        std::set<int> visited;
        std::queue<int> q;
        visited.insert(start);
        q.push(start);
        std::cout<<"BFS Traversal: ";
        while(!q.empty()){
            int node = q.front();
            std::cout<<node<<" ";
            q.pop();
            for(int neighbour : adj[node]){
                if(!visited.count(neighbour)){
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
        std::cout<<std::endl;
    }

    void DFS(int start){
        std::set<int> visisted;
        std::stack<int> s;
        s.push(start);
        std::cout<<"DFS traversal: ";
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!visisted.count(node)){
                std::cout<<node<<" ";
                visisted.insert(node);
                for(auto it = adj[node].rbegin();it!=adj[node].rend();++it){
                    if(!visisted.count(*it)){
                        s.push(*it);
                    }
                }
            }
        }
        std::cout<<std::endl;
    }

};

int main() {
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

    g.BFS(1);
    g.DFS(1);

    return 0;
}

