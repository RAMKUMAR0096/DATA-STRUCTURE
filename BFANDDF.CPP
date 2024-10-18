#include <iostream.h>
#include <conio.h>
#include <dos.h>

#define MAX_VERTICES 100

class Graph {
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES];
    int visited[MAX_VERTICES];

public:
    Graph(int v) : V(v) {
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0; 
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1; 
        adj[v][u] = 1; 
    }

    void BFS(int start) {
        int queue[MAX_VERTICES], front = 0, rear = -1;
        visited[start] = 1;
        queue[++rear] = start;

        while (front <= rear) {
            int node = queue[front++];
            cout << node << " ";

            for (int i = 0; i < V; i++) {
                if (adj[node][i] == 1 && !visited[i]) {
                    visited[i] = 1;
                    queue[++rear] = i;
                }
            }
        }
    }

    void DFSUtil(int node) {
        visited[node] = 1;
        cout << node << " ";

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                DFSUtil(i);
            }
        }
    }

    void DFS(int start) {
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
        }
        DFSUtil(start);
    }
};

void main() {
    clrscr();
    Graph g(5); 
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    int choice, start;
    cout << "Choose the traversal method:\n1. BFS\n2. DFS\nEnter your choice: ";
    cin >> choice;
    cout << "Enter starting vertex (0-4): ";
    cin >> start;

    switch (choice) {
        case 1:
            cout << "BFS starting from vertex " << start << ":\n";
            g.BFS(start);
            break;
        case 2:
            cout << "DFS starting from vertex " << start << ":\n";
            g.DFS(start);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    getch();
}
