#ifndef CPP_PROJECT_DYNAMIC_GRAPH_H
#define CPP_PROJECT_DYNAMIC_GRAPH_H


#include "Graph_Node.h"
#include "Graph_Edge.h"
#include "Rooted_Tree.h"

class Dynamic_Graph {

public:
    Dynamic_Graph();

    Graph_Node* Insert_Node(unsigned node_key);

    ~Dynamic_Graph();

    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);

    void Delete_Node(Graph_Node* node);

    void Delete_Edge(Graph_Edge* edge);

    Rooted_Tree* SCC() const;

    Rooted_Tree* BFS(Graph_Node* source) const;
};


#endif
