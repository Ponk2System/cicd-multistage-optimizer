#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits> // Untuk INT_MAX (pengganti Integer.MAX_VALUE)

using namespace std;

struct Node {
    string name;
    int ds; 
    bool visited;
    Node* parent;

    Node(string name) {
        this->name = name;
        this->ds = INT_MAX;
        this->visited = false;
        this->parent = nullptr;
    }
};

struct Edge {
    Node* node1;
    Node* node2;
    int W;

    Edge(Node* n1, Node* n2, int W) {
        this->node1 = n1;
        this->node2 = n2;
        this->W = W;
    }
};

struct CompareNode {
    bool operator()(Node* const& n1, Node* const& n2) {
        return n1->ds > n2->ds; // > menghasilkan Min-Heap
    }
};

class Dijkstra {
public:
    vector<Edge*> graph;
    priority_queue<Node*, vector<Node*>, CompareNode> pq;

    Node* s = new Node("S");
    Node* a1 = new Node("A1");
    Node* a2 = new Node("A2");
    Node* b1 = new Node("B1");
    Node* b2 = new Node("B2");
    Node* c1 = new Node("C1");
    Node* c2 = new Node("C2");
    Node* e = new Node("E");

    Dijkstra() {
        graph.push_back(new Edge(s, a1, 15));
        graph.push_back(new Edge(s, a2, 25));
        graph.push_back(new Edge(a1, b1, 35));
        graph.push_back(new Edge(a1, b2, 45));
        graph.push_back(new Edge(a2, b1, 20));
        graph.push_back(new Edge(a2, b2, 30));
        graph.push_back(new Edge(b1, c1, 25));
        graph.push_back(new Edge(b1, c2, 55));
        graph.push_back(new Edge(b2, c1, 40));
        graph.push_back(new Edge(b2, c2, 30));
        graph.push_back(new Edge(c1, e, 20));
        graph.push_back(new Edge(c2, e, 15));
    }

    void runDijkstra() {
        Node* startNode = s;
        startNode->ds = 0;
        startNode->parent = nullptr;
        pq.push(startNode);

        while (!pq.empty()) {
            Node* current = pq.top();
            pq.pop();

            current->visited = true;
            cout << "\nCurrent node : " << current->name << endl;

            vector<Node*> tetanggaCurrent = getAdjacentNodes(current);
            if (!tetanggaCurrent.empty()) {
                for (Node* next : tetanggaCurrent) {
                    cout << "\nTetangga Node : " << next->name << endl;
                    int weight = getWeight(current, next);
                    
                    // Relaksasi Edge
                    if (next->ds > current->ds + weight) {
                        next->ds = current->ds + weight;
                        next->parent = current;
                        pq.push(next);
                    }
                }
            }
        }
        printCostGraph();
    }

private:
    int getWeight(Node* a, Node* b) {
        for (Edge* edge : graph) {
            if (edge->node1->name == a->name && edge->node2->name == b->name) {
                return edge->W;
            }
        }
        return 0;
    }

    vector<Node*> getAdjacentNodes(Node* current) {
        vector<Node*> adjacents;
        for (Edge* edge : graph) {
            if (edge->node1->name == current->name) {
                adjacents.push_back(edge->node2);
            }
        }
        return adjacents;
    }

    string printPath(Node* a, Node* b) {
        Node* current = b;
        string path = current->name;
        while (current->parent != nullptr) {
            current = current->parent;
            path = current->name + "->" + path;
        }
        return path;
    }

public:
    void printCostGraph() {
        cout << "\n--- HASIL PATH ---" << endl;
        cout << "\nS dist : " << s->ds << "\nPath : " << printPath(s, s) << "\n" << endl;
        cout << "A1 dist : " << a1->ds << "\nPath : " << printPath(s, a1) << "\n" << endl;
        cout << "A2 dist : " << a2->ds << "\nPath : " << printPath(s, a2) << "\n" << endl;
        cout << "B1 dist : " << b1->ds << "\nPath : " << printPath(s, b1) << "\n" << endl;
        cout << "B2 dist : " << b2->ds << "\nPath : " << printPath(s, b2) << "\n" << endl;
        cout << "C1 dist : " << c1->ds << "\nPath : " << printPath(s, c1) << "\n" << endl;
        cout << "C2 dist : " << c2->ds << "\nPath : " << printPath(s, c2) << "\n" << endl;
        cout << "E dist : " << e->ds << "\nPath : " << printPath(s, e) << "\n" << endl;
    }
};

int main() {
    Dijkstra dijkstra;
    dijkstra.runDijkstra();
    return 0;
}