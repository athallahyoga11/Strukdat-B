#include <iostream>
#include <list>

using namespace std;

class Graph
{
  int numVertices;
  list<int> *adjMatrix;
  bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
    void showMatrix();
};

Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjMatrix = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest)
{
  adjMatrix[src].push_back(dest);
  adjMatrix[src].sort();
}

// BFS algorithm
void Graph::BFS(int startVertex)
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty())
  {
    int currVertex = queue.front();
    // Fungsi memberhentikan BFS
    // if (currVertex == endVertex)
    // {
    //   break;
    // }
    //
    cout << "(V" << currVertex << ")";
    queue.pop_front();

    for (i = adjMatrix[currVertex].begin(); i != adjMatrix[currVertex].end(); ++i)
    {
      int adjVertex = *i;
      if (!visited[adjVertex])
      {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

void Graph::showMatrix()
{
  for (int i = 0; i < numVertices; i++)
  {
    list<int>::iterator it;

    int track = 0;
    int through = 0;
    for (it = adjMatrix[i].begin(); it != adjMatrix[i].end(); ++it)
    {
      // int track = 0;
      int temp = *it;
      if (through == 0)
      {
        while (track < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      else
      {
        while ((track + 1) < temp)
        {
          cout << "0 ";
          ++track;
          through++;
        }
      }
      cout << "1 ";
      through++;
    }
    while ((numVertices - through) > 0)
    {
      through++;
      cout << "0 ";
    }
    cout << endl;
  }
}

int main()
{
  Graph coba(20);

  coba.addEdge(0, 18);
  coba.addEdge(1, 18);
  coba.addEdge(2, 18);
  coba.addEdge(3, 18);
  coba.addEdge(4, 18);
  coba.addEdge(5, 18);
  coba.addEdge(6, 18);
  coba.addEdge(7, 18);
  coba.addEdge(8, 18);
  coba.addEdge(9, 18);
  coba.addEdge(10, 18);
  coba.addEdge(11, 18);
  coba.addEdge(12, 17);
  coba.addEdge(12, 16);
  coba.addEdge(12, 14);
  coba.addEdge(12, 12);
  coba.addEdge(11, 16);

  coba.BFS(1);
  cout << endl;
  coba.showMatrix();

  return 0;
}