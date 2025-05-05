#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeDFS {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* insert(Node* curr, int val) {
        if (!curr) {
            Node* newNode = new Node;
            newNode->data = val;
            newNode->left = newNode->right = nullptr;
            return newNode;
        }
        if (val < curr->data)
            curr->left = insert(curr->left, val);
        else
            curr->right = insert(curr->right, val);
        return curr;
    }

    void dfs_helper(Node* n) {
        if (!n) return;
        cout << n->data << " ";
        dfs_helper(n->left);
        dfs_helper(n->right);
    }

public:
    TreeDFS() { root = nullptr; }

    void insert(int val) {
        root = insert(root, val);
    }

    void dfs() {
        cout << "DFS Tree (Preorder): ";
        dfs_helper(root);
        cout << endl;
    }
};

class GraphDFS {
private:
    int vertices;
    vector<vector<int>> adjList;
    vector<bool> seen;

    void explore(int vertex) {
        seen[vertex] = true;
        cout << vertex << " ";
        for (int neighbor : adjList[vertex]) {
            if (!seen[neighbor]) {
                explore(neighbor);
            }
        }
    }

public:
    GraphDFS(int v) : vertices(v) {
        adjList.resize(v);
        seen.resize(v);
    }

    void addEdge(int from, int to) {
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    void dfs(int startVertex) {
        fill(seen.begin(), seen.end(), false);
        cout << "DFS Graph: ";
        explore(startVertex);
        cout << endl;
    }
};

class TreeBFS {
private:
    struct Node {
        int data;
        Node *left, *right;
    };

    Node* root;

    Node* insert(Node* node, int val) {
        if (!node) {
            auto newNode = new Node{val, nullptr, nullptr};
            return newNode;
        }
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

public:
    TreeBFS() { root = nullptr; }

    void insert(int val) { root = insert(root, val); }

    void bfs() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        cout << "BFS Tree (Level Order): ";
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }
};

class GraphBFS {
private:
    int size;
    vector<vector<int>> edges;

public:
    GraphBFS(int n) : size(n) {
        edges.resize(n);
    }

    void addEdge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    void bfs(int start) {
        vector<bool> visited(size, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS Graph: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            for (int next : edges[current]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    TreeDFS myTreeDFS;
    myTreeDFS.insert(30);
    myTreeDFS.insert(20);
    myTreeDFS.insert(40);
    myTreeDFS.insert(10);
    myTreeDFS.dfs();

    GraphDFS myGraphDFS(5);
    myGraphDFS.addEdge(0, 1);
    myGraphDFS.addEdge(0, 2);
    myGraphDFS.addEdge(1, 3);
    myGraphDFS.addEdge(1, 4);
    myGraphDFS.dfs(0);

    TreeBFS myTreeBFS;
    myTreeBFS.insert(30);
    myTreeBFS.insert(20);
    myTreeBFS.insert(40);
    myTreeBFS.insert(10);
    myTreeBFS.bfs();

    GraphBFS myGraphBFS(5);
    myGraphBFS.addEdge(0, 1);
    myGraphBFS.addEdge(0, 2);
    myGraphBFS.addEdge(1, 3);
    myGraphBFS.addEdge(1, 4);
    myGraphBFS.bfs(0);

    return 0;
}
