#include "List.h"
//#include "Graph_Node.h"

ListItem *List::Head() const {
    return head;
}


ListItem *List::Tail() const {
    return tail;
}

List::List() {
    head = NULL;
    tail = NULL;
    size = 0;
}

void List::Push_Back(ListItem *item) {
    item->next = NULL;

    if (head == NULL) {
        head = item;
        tail = item;
    } else {
        tail->next = item;
        item->prev = tail;
        tail = tail->next;
    }

    size += 1;
}

void List::Remove(ListItem *item) {
    if (size == 1) {
        // Only one item
        head = NULL;
        tail = NULL;
    } else if (*item == *head) {
        // Removing first item, and there's a next
        head = item->next;
        item->next->prev = NULL;
    } else if (*item == *tail){
        // Removing last item, and there's a previous
        tail = item->prev;
        item->prev->next = NULL;
    } else {
        // Item is neither first nor last
        item->prev->next = item->next;
        item->next->prev = item->prev;
    }

    item->next = NULL;
    item->prev = NULL;
    delete item;
}

unsigned List::Size() const {
    return size;
}

unsigned List::Contains(ListItem *item) {
    if (head == NULL) {
        return 0;
    }

    ListItem *tmp = head;
    while (tmp != NULL) {
        if (*tmp == *item) {
            return 1;
        }
        tmp = head->next;
    }

    return 0;
}

unsigned List::operator==(List &other) {

    // Defend against null obj
    if (&other == NULL) {
        return 0;
    }

    ListItem *thisTmp = head;
    ListItem *otherTmp = other.head;

    while (thisTmp != NULL && otherTmp != NULL) {
        if (*(thisTmp) != *(otherTmp)) {
            return 0;
        }

        thisTmp = thisTmp->next;
        otherTmp = otherTmp->next;
    }

    // If the lists are at the same length, both pointers needs to be NULL at this point --> return TRUE.
    // Otherwise, FALSE is returned.
    return (thisTmp == NULL && otherTmp == NULL);
}

unsigned List::operator!=(List &other) {
    return !(*this==other);
}

//unsigned test_Push_Back() {
//    int a = 123;
//    List<int> *list = new List<int>;
//    list->Push_Back(&a);
//    int b = 123;
//    return list->Head() == list->Tail() && *list->Head()->data == b;
//}
//
//int main() {
//    return test_Push_Back();
//}
