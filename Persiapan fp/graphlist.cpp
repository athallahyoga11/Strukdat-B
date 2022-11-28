#include <iostream>
#include <list>
#include <iterator>
#include <queue>
using namespace std;

class Graph{
private:
    int V;
    vector<list<int>> adj;  
public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }
    
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    void showVertex()
{
    for (int i = 1; i <= V; i++)
    {
        cout << i << " --> ";
        list<int>::iterator it; // iterator for list
        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << *it << " "; // *it is the value of the node/ngeakses pointer nya
        }
        cout << endl;
    }
}

    void BFS(int s, int d){
        vector<bool> visited;
        visited.resize(V,false);

        list<int> queue;
     
        visited[s] = true;
        queue.push_back(s);
     
        while(!queue.empty()){
            s = queue.front();
            cout << "(V" << s << ")";
            if (s == d) return;
            queue.pop_front();
            for (auto adjecent: adj[s]){
                if (!visited[adjecent]){
                    visited[adjecent] = true;
                    queue.push_back(adjecent);
                }
            }
        }
    }
};

int main()
{
    Graph g(21);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(9, 10);
    g.addEdge(10, 11);
    g.addEdge(11, 12);
    g.addEdge(12, 13);
    g.addEdge(13, 14);
    g.addEdge(14, 15);
    g.addEdge(15, 16);
    g.addEdge(16, 17);
    g.addEdge(17, 18);
    g.addEdge(17, 19);
    g.addEdge(19, 20);

     g.BFS(1,20);
cout << endl;
g.showVertex();
 
    return 0;
}
