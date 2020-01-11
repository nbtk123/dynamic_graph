#ifndef CPP_PROJECT_LIST_H
#define CPP_PROJECT_LIST_H

#include <cstddef>

struct ListItem {
    ListItem *next = NULL;
    ListItem *prev = NULL;

    virtual unsigned operator==(ListItem &other) = 0;
    virtual unsigned operator!=(ListItem &other) = 0;
};

//unsigned ListItem::operator==(ListItem &other) {
//    return *this == other;
//}
//
//unsigned ListItem::operator!=(ListItem &other) {
//    return !(*this == other);
//}

class List {
private:
    ListItem *head;
    ListItem *tail;
    unsigned size;
public:
    List();

    ListItem *Head() const;

    ListItem *Tail() const;

    void Push_Back(ListItem *item);

    void Remove(ListItem *item);

    unsigned Size() const;

    unsigned Contains(ListItem *item);

    unsigned operator==(List &other);

    unsigned operator!=(List &other);
};

#endif