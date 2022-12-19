#include<bits/stdc++.h>
using namespace std;

class Graph {
    private:
        int v;
        string nama[100];
        vector<vector<int>> adj;
        vector<int> dfsResult;
        vector<int> dijkstraRes;
        int dfsWeight;

    public:
        Graph(int v) {
            this->v = v;
            vector<int> l (v+1, -1);
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }
        void namatempat(int i, string nama){
	    this->nama[i]=nama;
	    vector<int>arr;
	    arr.push_back(i);
	    sort(arr.begin(), arr.end());
	}

        void addVertex(int u, int v, int w){
            adj[u][v] = w;
        }

        void printList(){
            for (int i = 1; i <= v; i++)
            {
                for ( int j = 1; j <= v; j++)
                {
                	
                    if(adj[i][j] == -1)cout << ".  ";
                    else if (adj[i][j] < 10) cout << adj[i][j] << "  ";
                    else cout << adj[i][j] << " ";
                    
                }
                cout << endl;
            }
            cout << endl;
        }
        
        void BFS(int start, int end){
            cout << endl;
            cout << "=== BFS ===" << endl;
            vector<int> visit (v+1, 0);
            vector<int> dist (v+1, INT_MAX);
            vector<int> domain (v+1, 0);
            queue<int> q;

            dist[start] = 0;
            q.push(start);
            visit[start] = true;

            while (!q.empty())
            {
                int curr = q.front();
                for (int it = 1; it <= v; it++)
                {
                        if(adj[curr][it] != -1 && adj[curr][it] + dist[curr] < dist[it]){
                            dist[it] = adj[curr][it] + dist[curr];
                            domain[it] = curr;
                            q.push(it);
                        }
                }
                q.pop();
            }
            vector<int> result;
            int i = end;
            while(true){
                result.push_back(i);
                if(i == start) break;
                i = domain[i];
            }

            for (int i = result.size()-1; i >= 0; i--)
            {
                cout << nama[result[i]] <<"(V" <<  result[i] << ")"<< ", ";
            }
            
            cout << endl << "Weight = " << dist[end] << endl;
            
        }
        
        void DFS(int start, int end){
            cout << endl;
            cout << "=== DFS === "<< endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 );
            
            for (int i = 0; i < dfsResult.size(); i++)
            {
                cout << nama[dfsResult[i]] <<"(V" <<  dfsResult[i] << ")"<< ", ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
            }
            visited[start] = true;
            path.push_back(start);
            bool flag = false;
            for ( int it = 1; it <= v; it++)
            {
                if(!visited[it] && adj[start][it] != -1){
                    int wtemp = currWeight;
                    wtemp += adj[start][it];
                    flag = true;
                    solveDFS(it, end, path, visited, wtemp);
                }
            }
        }

        int minDist(vector<int> dist, vector<bool> vis){
            int min = INT_MAX;
            int min_index = INT_MAX;
            for (int i = 1; i <= v; i++)
            {
                if(!vis[i] && dist[i] < min) {
                    min = dist[i];
                    min_index = i;
                }
            }
            return min_index;
        }

        void dijkstra(int start, int end){
            cout << endl << "===  Dijkstra ===" << endl;
            vector<int> dist (v+1, INT_MAX);
            vector<bool> vis (v+1, false);
            vector<int> res (v+1, 0);
            dist[start] = 0;
            for (int itv = 1; itv <= v ; itv++)
            {
                int min = minDist(dist, vis);
                vis[min] = true;
                for(int it = 1; it <= v; it++){
                    if (
                        adj[min][it] != -1 &&
                        !vis[it] && 
                        dist[min] + adj[min][it] < dist[it]
                    )
                    {
                        dist[it] = dist[min] + adj[min][it] ; 
                        res[it] = min;
                    }
                }
            }
            int i = res[end];
            vector<int> r;
            r.push_back(end);
            while (true)
            {
                r.push_back(i);
                if(i == start) break;
                i = res[i];
            }
            reverse(r.begin(), r.end());
            for (int i = 0; i <  r.size(); i++)
            {
                cout << nama[r[i]] <<"(V" <<  r[i] << ")"<< ", ";
            }
            cout << endl << "Weight = " << dist[end] << endl;
        }
};

int main(){
    Graph g(21);
        g.namatempat(1, "Rumah"); 				g.namatempat(11, "shawarma");
        g.namatempat(2, "griya pakan");      g.namatempat(12, "jersey");
        g.namatempat(3, "purnama");  			g.namatempat(13, "laundry lagi");
        g.namatempat(4, "kumara"); 			g.namatempat(14, "rukun jaya");
        g.namatempat(5, "beres"); 			g.namatempat(15, "babat");
        g.namatempat(6, "tukang kunci"); 		g.namatempat(16, "bolamania");
        g.namatempat(7, "geprek bensu"); 			g.namatempat(17, "bca");
        g.namatempat(8, "boltz laundry"); 			g.namatempat(18, "ayam bakar");
        g.namatempat(9, "camat"); 				g.namatempat(19, "rs petro");
        g.namatempat(10, "warung"); 			g.namatempat(20, "perumahan");
        g.namatempat(21, "vivo");
    

        g.addVertex(1,20,4);		g.addVertex(20,1,4);
        g.addVertex(20,21,5);		g.addVertex(21,20,5);
        g.addVertex(20,17,1);		g.addVertex(17,20,1);
        g.addVertex(18,17,1);		g.addVertex(17,18,1);
        g.addVertex(18,19,8); 		g.addVertex(19,18,8);
        g.addVertex(17,16,5);		g.addVertex(16,17,5);
        g.addVertex(16,15,2);		g.addVertex(15,16,2);
        g.addVertex(15,14,2);		g.addVertex(14,15,2);
        g.addVertex(14,13,2); 		g.addVertex(13,14,2);
        g.addVertex(13,12,2); 		g.addVertex(12,13,2);
        g.addVertex(12,11,3);		g.addVertex(11,12,3);
        g.addVertex(11,10,1);		g.addVertex(10,11,1);
        g.addVertex(10,9,1);		g.addVertex(9,10,1);
        g.addVertex(9,8,1);		g.addVertex(8,9,1);
        g.addVertex(8,7,4);		g.addVertex(7,8,4);
        g.addVertex(7,6,2);		g.addVertex(6,7,2);
        g.addVertex(6,5,2);	g.addVertex(5,6,2);
        g.addVertex(5,4,2);	g.addVertex(4,5,2);
        g.addVertex(4,3,3);		g.addVertex(3,4,4);
        g.addVertex(3,2,3);		g.addVertex(2,3,3);

    
  
    g.printList();
    int start, end;
    cout << "start : ";
    cin >> start;
    cout << "end : ";
    cin >> end;
    g.BFS(start, end);
    g.DFS(start, end);
    g.dijkstra(start, end);
    return 0;    
}