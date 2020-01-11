#include "Dynamic_Graph.h"

Dynamic_Graph::Dynamic_Graph() {

}

Dynamic_Graph::~Dynamic_Graph() {

}

Graph_Node *Dynamic_Graph::Insert_Node(unsigned node_key) {
    Graph_Node *node = new Graph_Node(node_key);
    return node;
}

void Dynamic_Graph::Delete_Node(Graph_Node *node) {
    if (!node->Has_Edges()) {
        delete node;
    }
}

Graph_Edge *Dynamic_Graph::Insert_Edge(Graph_Node *from, Graph_Node *to) {
    Graph_Edge *edge = new Graph_Edge(from, to);
    from->Add_Outgoing_Edge(edge);
    to->Add_Incoming_Edge(edge);
    return edge;
}

void Dynamic_Graph::Delete_Edge(Graph_Edge *edge) {
    edge->Get_Dst()->Remove_Outgoing_Edge(edge);
    edge->Get_Src()->Remove_Incoming_Edge(edge);
    delete edge;
}

Rooted_Tree *Dynamic_Graph::SCC() const {
    return nullptr;
}

Rooted_Tree *Dynamic_Graph::BFS(Graph_Node *source) const {
    return nullptr;
}
