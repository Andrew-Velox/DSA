#include <bits/stdc++.h>
using namespace std;

const int mx = 100;
int graph[mx][mx];
bool visit[mx];

const int QUEUE_SIZE = mx;
int queueArr[QUEUE_SIZE];
int front = 0;
int rear = -1;
int itemCount = 0;

bool isQueueEmpty() {
    return itemCount == 0;
}

bool isQueueFull() {
    return itemCount == QUEUE_SIZE;
}

void enqueue(int data) {
    if (!isQueueFull()) {
        if (rear == QUEUE_SIZE - 1) {
            rear = -1;
        }
        queueArr[++rear] = data;
        itemCount++;
    }
}

int dequeue() {
    int data = queueArr[front++];
    if (front == QUEUE_SIZE) {
        front = 0;
    }
    itemCount--;
    return data;
}

void bfs(int st, int n) {
    enqueue(st);
    visit[st] = true;

    while (!isQueueEmpty()) {
        int surur_val = dequeue();

        cout << surur_val << " ";

        for (int x = 1; x <= n; x++) {
            if (graph[surur_val][x] && !visit[x]) {
                enqueue(x);
                visit[x] = true;
            }
        }
    }
}

int main() {
    int node, edge;
    cin >> node >> edge;


    while (edge--) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    for(int x=0; x<=node; x++) visit[x] = false;

    cout << "Connected Nodes" << endl;
    for(int x = 1; x <= node; x++){
        cout << "\t\t";
        for(int y = 1; y <= node; y++){
            cout << graph[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int start;
    cin >> start;

    cout << "BFS Traversal: ";
    bfs(start, node);
    cout << endl;

    return 0;
}

/*
input:
7 6
1 2
1 3
3 4
3 5
2 6
2 7
1

output:
Connected Nodes
		0 1 1 0 0 0 0 
		1 0 0 0 0 1 1 
		1 0 0 1 1 0 0 
		0 0 1 0 0 0 0 
		0 0 1 0 0 0 0 
		0 1 0 0 0 0 0 
		0 1 0 0 0 0 0 

BFS Traversal: 1 2 3 6 7 4 5
*/
