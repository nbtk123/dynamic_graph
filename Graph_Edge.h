#ifndef CPP_PROJECT_GRAPH_EDGE_H
#define CPP_PROJECT_GRAPH_EDGE_H


#include "Graph_Node.h"

class Graph_Edge {
private:
    Graph_Node* src;
    Graph_Node* dst;
public:
    Graph_Edge(Graph_Node* src, Graph_Node* dst) {
        this->src = src;
        this->dst = dst;
    }
    Graph_Node* getSrc() const;
    Graph_Node* getDst() const;

    unsigned operator ==(Graph_Edge* other);
};


#endif
