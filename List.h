#ifndef CPP_PROJECT_LIST_H
#define CPP_PROJECT_LIST_H

#include <cstddef>

template<typename T>
struct Item {
    T *data;
    Item<T> *next;
    Item<T> *prev;

    unsigned operator==(Item<T> &other);
    unsigned operator!=(Item<T> &other);
};

template<typename T>
unsigned Item<T>::operator==(Item<T> &other) {
    return *(this->data) == *(other.data);
}

template<typename T>
unsigned Item<T>::operator!=(Item<T> &other) {
    return !(*this == other);
}

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

    unsigned Contains(T *item);

    unsigned operator==(List<T> &other);

    unsigned operator!=(List<T> &other);
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

    if (head == NULL) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tmp->prev = tail;
        tail = tail->next;
    }

    size += 1;
}

template<typename T>
unsigned List<T>::Size() const {
    return size;
}

template<typename T>
unsigned List<T>::Contains(T *item) {
    if (head == NULL) {
        return 0;
    }

    Item<T> *tmp = head;
    while (tmp != NULL) {
        if (tmp->data == item) {
            return 1;
        }
        tmp = head->next;
    }

    return 0;
}

template<typename T>
unsigned List<T>::operator==(List<T> &other) {

    // Defend against null obj
    if (&other == NULL) {
        return 0;
    }

    Item<T> *thisTmp = head;
    Item<T> *otherTmp = other.head;

    while (thisTmp != NULL && otherTmp != NULL) {
        if (*(thisTmp->data) != *(otherTmp->data)) {
            return 0;
        }

        thisTmp = thisTmp->next;
        otherTmp = otherTmp->next;
    }

    // If the lists are at the same length, both pointers needs to be NULL at this point --> return TRUE.
    // Otherwise, FALSE is returned.
    return (thisTmp == NULL && otherTmp == NULL);
}

template<typename T>
unsigned List<T>::operator!=(List<T> &other) {
    return !(*this==other);
}


#endif