#include <bits/stdc++.h>
using namespace std;

class GraphWithAdjMatrix {
    public:
        vector<vector<int>> adj_matrix;
        int vertices;
        int edges;
        bool is_directed;

        // Constructor
        GraphWithAdjMatrix(int n, int m, bool is_directed)
            : vertices(n), edges(m), is_directed(is_directed) {
            adj_matrix.resize(n + 1, vector<int>(n + 1, 0));  // Initialize the matrix with 0s
        }

        // Function to add an edge
        void add_edge(int u, int v) {
            adj_matrix[u][v] = 1;  // Add edge u -> v

            if (!is_directed) {
                adj_matrix[v][u] = 1;  // If undirected, also add edge v -> u
            }
        }

        // Function to print the adjacency matrix (for verification)
        void print_adj_matrix() {
            for (int i = 1; i <= vertices; ++i) {
                for (int j = 1; j <= vertices; ++j) {
                    cout << adj_matrix[i][j] << " ";
                }
                cout << endl;
            }
        }

};
class GraphWithAdjList {
    public:
        vector<vector<int>> adj_list;  // Adjacency list
        int vertices;
        int edges;
        bool is_directed;

        // Constructor
        GraphWithAdjList(int n, int m, bool is_directed)
            : vertices(n), edges(m), is_directed(is_directed) {
            adj_list.resize(n + 1);  // Initialize the list with n+1 empty vectors
        }

        // Function to add an edge
        void add_edge(int u, int v) {
            adj_list[u].push_back(v);  // Add edge u -> v

            if (!is_directed) {
                adj_list[v].push_back(u);  // If undirected, also add edge v -> u
            }
        }

        // Function to print the adjacency list (for verification)
        void print_adj_list() {
            for (int i = 1; i <= vertices; ++i) {
                cout << i << ": ";
                for (int j : adj_list[i]) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }

};

int main() {
    int n, m;
    bool is_directed = false;
    bool is_mat;
    cout << "Enter the no. of vertices and no. of edges in the graph:  "<<endl;
    cin >> n>>m;

    cout <<"enter 0 for non directed graph and 1 for directed graph"<<endl;
    cin >> is_directed;

    cout<< "Enter 1 for AdjMatrix or Enter 0 for AdjList "<<endl;
    cin >> is_mat;

    if (is_mat) {
        GraphWithAdjMatrix graph(n, m, is_directed);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph.add_edge(u, v);
        }

        // Print adjacency matrix
        graph.print_adj_matrix();
    } else {
        GraphWithAdjList graph(n, m, is_directed);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            graph.add_edge(u, v);
        }

        // Print adjacency list
        graph.print_adj_list();
    }

    return 0;
}
