#include "Graph_Edge.h"

Graph_Node *Graph_Edge::Get_Src() const {
    return src;
}

Graph_Node *Graph_Edge::Get_Dst() const {
    return dst;
}

unsigned Graph_Edge::operator==(Graph_Edge &other) {
    return src->Get_key() == other.src->Get_key() && this->dst->Get_key() == other.dst->Get_key();
}

unsigned Graph_Edge::operator!=(Graph_Edge &other) {
    return !(*this==other);
}


