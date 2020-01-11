#ifndef CPP_PROJECT_GRAPH_EDGE_H
#define CPP_PROJECT_GRAPH_EDGE_H


#include "Graph_Node.h"
class Graph_Node;

class Graph_Edge : public ListItem {

private:
    Graph_Node *src;
    Graph_Node *dst;
public:
    Graph_Edge(Graph_Node *src, Graph_Node *dst) : ListItem{} {
        this->src = src;
        this->dst = dst;
    }
    Graph_Node* Get_Src() const;
    Graph_Node* Get_Dst() const;

    unsigned operator==(ListItem &other);
    unsigned operator!=(ListItem &other);
};


#endif
