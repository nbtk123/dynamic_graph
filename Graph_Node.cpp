#include "Graph_Node.h"

unsigned Graph_Node::Get_out_Degree() const {
    return out->Size();
}

unsigned Graph_Node::Get_in_Degree() const {
    return in->Size();
}

unsigned Graph_Node::Get_key() const {
    return key;
}

unsigned Graph_Node::Add_Outgoing_Edge_If_Not_Exists(Graph_Edge *edge) {
    return Add_Edge_If_Not_Exists(out, edge);
}

unsigned Graph_Node::Add_Incoming_Edge_If_Not_Exists(Graph_Edge *edge) {
    return Add_Edge_If_Not_Exists(in, edge);
}

unsigned Graph_Node::operator==(Graph_Node *other) {
    return this->key == other->key && this->in == other->in && this->out == other->out;
}

unsigned Graph_Node::Is_Edge_Exist(List<Graph_Edge> *lst, Graph_Edge *edge) {
//    for (std::list<Graph_Edge *>::iterator it = lst->begin(); it != lst->end(); ++it) {
//        if ((*it) == edge) return 1;
//    }

    return 0;
}

unsigned int Graph_Node::Add_Edge_If_Not_Exists(List<Graph_Edge> *lst, Graph_Edge *edge) {
    if (Is_Edge_Exist(lst, edge)) {
        return 0;
    }

    lst->Push_Back(edge);
    return 1;
}
