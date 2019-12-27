#ifndef CPP_PROJECT_ROOTED_TREE_H
#define CPP_PROJECT_ROOTED_TREE_H

#include <ostream>

class Rooted_Tree {
    Rooted_Tree();

public:
    void Print_By_Layer(std::ostream& stream) const;

    void Preorder_Print(std::ostream& stream) const;

    ~Rooted_Tree();
};


#endif
