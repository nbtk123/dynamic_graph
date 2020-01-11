#include "Graph_Node.h"

Graph_Node::~Graph_Node() {
    delete in;
    delete out;
}

unsigned Graph_Node::Get_out_Degree() const {
    return out->Size();
}

unsigned Graph_Node::Get_in_Degree() const {
    return in->Size();
}

unsigned Graph_Node::Get_key() const {
    return key;
}

//unsigned Graph_Node::Add_Outgoing_Edge_If_Not_Exists(Graph_Edge *edge) {
//    return Add_Edge_If_Not_Exists(out, edge);
//}
//
//unsigned Graph_Node::Add_Incoming_Edge_If_Not_Exists(Graph_Edge *edge) {
//    return Add_Edge_If_Not_Exists(in, edge);
//}

unsigned Graph_Node::operator==(Graph_Node &other) {
    return key == other.key && *in == *other.in && *out == *other.out;
}

unsigned Graph_Node::operator!=(Graph_Node &other) {
    return !(*this==other);
}

//unsigned Graph_Node::Is_Edge_Exist(List<Graph_Edge> *lst, Graph_Edge *edge) {
//    return lst->Contains(edge);
//}

//unsigned int Graph_Node::Add_Edge_If_Not_Exists(List<Graph_Edge> *lst, Graph_Edge *edge) {
//    if (Is_Edge_Exist(lst, edge)) {
//        return 0;
//    }
//
//    lst->Push_Back(edge);
//    return 1;
//}

void Graph_Node::Add_Outgoing_Edge(Graph_Edge *edge) {
    out->Push_Back(edge);
}

void Graph_Node::Add_Incoming_Edge(Graph_Edge *edge) {
    in->Push_Back(edge);
}

void Graph_Node::Remove_Outgoing_Edge(Graph_Edge *edge) {
    out->Remove(edge);
}

void Graph_Node::Remove_Incoming_Edge(Graph_Edge *edge) {
    in->Remove(edge);
}

unsigned Graph_Node::Has_Edges() {
    return in->Size() > 0 || out->Size() > 0;
}

/*
 * Testing Graph_Node
 * Comment out when running from main.cpp
*/

//unsigned test_Get_Key() {
//    Graph_Node *node = new Graph_Node(1);
//    return node->Get_key() == 1;
//}
//unsigned test_Get_in_Degree() {
//    Graph_Node *node = new Graph_Node(1);
//    node->Add_Incoming_Edge_If_Not_Exists(new Graph_Edge(NULL, node));
//    return node->Get_in_Degree() == 1;
//}
//unsigned test_Get_out_Degree() {
//    Graph_Node *node = new Graph_Node(1);
//    node->Add_Outgoing_Edge_If_Not_Exists(new Graph_Edge(node, NULL));
//    return node->Get_out_Degree() == 1;
//}
//unsigned test_equals() {
//    Graph_Node *node1 = new Graph_Node(1);
//    Graph_Node *node1Copy = new Graph_Node(1);
//
//    Graph_Node *node3 = new Graph_Node(2);
//
//    Graph_Edge *edge1 = new Graph_Edge(node1, node3);
//    Graph_Edge *edge1Copy = new Graph_Edge(node1Copy, node3);
//
//    node1->Add_Outgoing_Edge_If_Not_Exists(edge1);
//    node1Copy->Add_Outgoing_Edge_If_Not_Exists(edge1Copy);
//
//    node3->Add_Incoming_Edge_If_Not_Exists(edge1);
//    node3->Add_Incoming_Edge_If_Not_Exists(edge1Copy);
//
//    return *node1 == *node1Copy;
//}
//
//int main() {
//    return test_Get_Key() &&
//    test_Get_in_Degree() &&
//    test_Get_out_Degree() &&
//    test_equals();
//}