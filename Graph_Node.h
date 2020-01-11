#ifndef CPP_PROJECT_GRAPH_NODE_H
#define CPP_PROJECT_GRAPH_NODE_H


#include "List.h"
#include "Graph_Edge.h"
class Graph_Edge;

class Graph_Node {
private:
    unsigned key;
    List *in = new List;
    List *out = new List;

    /**
     * Check whether an edge exists in some edge-list (used for incoming & outgoing edges).
     * @param lst - the edge list
     * @param edge - the edge to find
     * @return 1 if true, 0 otherwise
     */
//    static unsigned int Is_Edge_Exist(List<Graph_Edge> *lst, Graph_Edge *edge);
public:
    Graph_Node(unsigned key) {
        this->key = key;
    }

    ~Graph_Node();

    unsigned Get_key() const;

    unsigned Get_out_Degree() const;

    unsigned Get_in_Degree() const;

    void Add_Outgoing_Edge(Graph_Edge *edge);

    void Add_Incoming_Edge(Graph_Edge *edge);

    void Remove_Outgoing_Edge(Graph_Edge *edge);

    void Remove_Incoming_Edge(Graph_Edge *edge);

    unsigned Has_Edges();

//    unsigned Add_Outgoing_Edge_If_Not_Exists(Graph_Edge *edge);
//
//    unsigned Add_Incoming_Edge_If_Not_Exists(Graph_Edge *edge);

    unsigned operator==(Graph_Node &other);

    unsigned operator!=(Graph_Node &other);

    /**
     * Adds an edge to some edge-list if not exists (used to prevent double incoming && outgoing edges from this node)
     * @param lst - nodes (usually incmoing / outgoing)
     * @param edge - the edge to add if not exists.
     * @return 1 if edge was added. 0 Otherwise.
     */
//    static unsigned int Add_Edge_If_Not_Exists(List<Graph_Edge> *lst, Graph_Edge *edge);
};


#endif
