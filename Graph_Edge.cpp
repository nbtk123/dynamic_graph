#include "Graph_Edge.h"

Graph_Node *Graph_Edge::Get_Src() const {
    return src;
}

Graph_Node *Graph_Edge::Get_Dst() const {
    return dst;
}

unsigned Graph_Edge::operator==(ListItem &other) {
    Graph_Edge *otherEdge = dynamic_cast<Graph_Edge*>(&other);
    return otherEdge != NULL && src->Get_key() == otherEdge->src->Get_key() && this->dst->Get_key() == otherEdge->dst->Get_key();
}

unsigned Graph_Edge::operator!=(ListItem &other) {
    Graph_Edge *otherEdge = dynamic_cast<Graph_Edge*>(&other);
    return !(*this==*otherEdge);
}
