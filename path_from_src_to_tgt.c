#include <stdio.h>

int visited[5] = {0}; // Array to track visited nodes
int a[5][5] = {
    {0, 1, 0, 0, 0}, // From node 0: edge to 1
    {0, 0, 1, 1, 0}, // From node 1: edges to 2 and 3
    {0, 0, 0, 0, 1}, // From node 2: edge to 4
    {0, 0, 0, 0, 0}, // From node 3: no outgoing edges
    {0, 0, 0, 0, 0}  // From node 4: no outgoing edges
};

// DFS function to check for a path from source to target
int DFS(int source, int target) {
    // If we reached the target, return true
    if (source == target) {
        return 1;
    }

    visited[source] = 1; // Mark the current node as visited

    for (int j = 0; j < 5; j++) {
        // If there is a connection and the node is not visited
        if (a[source][j] == 1 && !visited[j]) {
            // Recursively call DFS
            if (DFS(j, target)) {
                return 1; // If path found in the recursive call
            }
        }
    }
    
    return 0; // No path found
}

int main() {
    int source = 1; // Starting node
    int target = 0; // Target node to reach
    
    // Reset visited array for each new search
    for (int i = 0; i < 5; i++) {
        visited[i] = 0;
    }
    
    // Check if there is a path from source to target
    if (DFS(source, target)) {
        printf("Path exists from %d to %d.\n", source, target);
    } else {
        printf("No path exists from %d to %d.\n", source, target);
    }

    return 0;
}


// 0 -----> 1
//           |
//           v
//           2
//           |
//           v
//           4
          
// 1 -----> 3

// Time Complexity of DFS with an Adjacency Matrix: O(V2)

