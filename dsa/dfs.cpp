/*
this file contains the code for recursive and iterative algorithms for dfs on a graph.
problem statement: Depth First Search (DFS):
Application: Web crawlers use DFS to explore web pages systematically, following
 links and indexing content for search engines. Write a simple program to index
 web pages using Depth First Search (DFS). The program should simulate a web graph
 where pages are represented as nodes and hyperlinks as edges.
 I am going to refer a sample algorithm and output for this task, because of it's complication.

 Basic idea/ algorithm for reference:
 Depth First Search:
Application: Web Page Indexing using DFS:
Pages = nodes
Hyperlinks = edges
DFS explores as deep as possible before backtracking, indexing pages in that order.
DFS Algorithm (Recursive):
Mark the starting page as visited.
Print or process the current page (indexing).
Recursively visit all unvisited linked pages.

Sample output:
Enter number of web pages (max 10): 6
Enter number of hyperlinks: 5
Enter links (from to):
0 1
0 2
1 3
2 4
4 5
Enter seed (start) page number: 0
Starting DFS web crawling from page: 0
 Indexed page: 0
 Indexed page: 1
 Indexed page: 3
 Indexed page: 2
 Indexed page: 4
 Indexed page: 5
*/
#include <iostream>
using namespace std;

void dfs(int vertex, int adj_mat[][10], bool visited[], int nodes)
{
    cout << vertex << endl;
    visited[vertex] = true;
    for (int i = 0; i < nodes; i++)
    {
        if (adj_mat[vertex][i] == 1 && visited[i] == false)
        {
            dfs(i, adj_mat, visited, nodes);
        }
    }
}

int main()
{
    int nodes, edges;
    cout << "Enter number of web pages(max 10): ";
    cin >> nodes;
    cout << "Enter the number of hyperlinks: ";
    cin >> edges;

    int adj_matr[10][10];
    // initialize adjacency matrix to zero.
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            adj_matr[i][j] = 0;
        }
    }
    int from, to;
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter links (from to)";
        cin >> from >> to;
        adj_matr[from][to] = 1;
    }
    int start;
    cout << "Enter seed (start) page number: ";
    cin >> start;

    bool visited[nodes];
    for (int i = 0; i < nodes; i++)
    {
        visited[i] = false;
    }
    int result[nodes];
    cout << "Displaying the web pages after dfs traversal" << endl;
    dfs(start, adj_matr, visited, nodes);

    return 0;
}