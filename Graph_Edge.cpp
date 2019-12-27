#include "Graph_Edge.h"

Graph_Node *Graph_Edge::getSrc() const {
    return src;
}

Graph_Node *Graph_Edge::getDst() const {
    return dst;
}

unsigned Graph_Edge::operator==(Graph_Edge *other) {
    return this->src == other->src && this->dst == other->dst;
}
