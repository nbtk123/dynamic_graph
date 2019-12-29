#ifndef CPP_PROJECT_LIST_H
#define CPP_PROJECT_LIST_H

#include <cstddef>

template<typename T>
struct Item {
    T *data;
    Item<T> *next;
    Item<T> *prev;
};

template<typename T>
class List {
private:
    Item<T> *head;
    Item<T> *tail;
    unsigned size;
public:
    List();

    Item<T> *Head() const;

    Item<T> *Tail() const;

    void Push_Back(T *item);

    unsigned Size() const;
};

template<typename T>
Item<T> *List<T>::Head() const {
    return head;
}

template<typename T>
Item<T> *List<T>::Tail() const {
    return tail;
}

template<typename T>
List<T>::List() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<typename T>
void List<T>::Push_Back(T *item) {
    Item<T> *tmp = new Item<T>;
    tmp->data = item;
    tmp->next = NULL;

    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tmp->prev = tail;
        tail = tail->next;
    }

    size+=1;
}

template<typename T>
unsigned List<T>::Size() const {
    return size;
}


#endif