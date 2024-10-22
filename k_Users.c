#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int* arr;
};

int isEmpty(struct queue* Q) {
    return (Q->front == Q->rear);
}

int isFull(struct queue* Q) {
    return (Q->rear == Q->size - 1);
}

void enqueue(struct queue * Q, int value) {
    if (isFull(Q)) {
        printf("Queue is Full.\n");
    } else {
        Q->rear++;
        Q->arr[Q->rear] = value;
    }
}

int dequeue(struct queue* Q) {
    int a = -1;
    if (isEmpty(Q)) {
        printf("Queue is Empty.\n");
    } else {
        Q->front++;
        a = Q->arr[Q->front];
    }
    return a;
}

// Function to perform BFS and find users within distance k
void BFS(int a[5][5], int numUsers, int startUser, int k) {
    if (startUser >= numUsers) {
        printf("Error: User %d does not exist in the graph.\n", startUser);
        return;
    }

    struct queue q;
    q.size = 100;
    q.front = q.rear = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    int visited[5] = {0};
    int distance[5] = {0}; // To track distances from the start user

    printf("Users within distance %d from user %d: ", k, startUser);
    
    // Start BFS from the given user
    visited[startUser] = 1;
    enqueue(&q, startUser);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        
        // If current distance is less than k, check neighbors
        if (distance[node] < k) {
            for (int j = 0; j < numUsers; j++) {
                if (a[node][j] == 1 && visited[j] == 0) {
                    printf("%d ", j);
                    visited[j] = 1;
                    distance[j] = distance[node] + 1; // Set distance
                    enqueue(&q, j);
                }
            }
        }
    }

    printf("\n");
    free(q.arr); // Free allocated memory for the queue
}

int main() {
    int numUsers = 5; // Number of users
    int a[5][5] = {
        {0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0}
    };

    int startUser = 0; // Example starting user
    int k = 1; // Example distance
    BFS(a, numUsers, startUser, k);

    return 0;
}

// Time Complexity of BFS with an Adjacency Matrix: O(V2)