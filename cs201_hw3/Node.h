//Kemal Sarper Sahin
#ifndef HW3_NODE_H
#define HW3_NODE_H
#include <string>
#include <cstddef>

template<class ItemType>
class Node{
public:
    ItemType item; // a data item
    Node<ItemType>* next; // pointer to the next node
    Node(){
        this->next = NULL;
    }
    Node(const ItemType& anItem){
        this->item = anItem;
        this->next = NULL;
    }
    Node(const ItemType& anItem, Node<ItemType>* nextPtr){
        this->item= anItem;
        this->next = nextPtr;
    }
    void setItem(const ItemType& anItem){
        this->item = anItem;
    }
    void setNext(Node<ItemType>* nextPtr){
        this->next = nextPtr;
    }
    ItemType getItem() const{
        return item;
    }
    Node<ItemType>* getNext() const{
        return next;
    }
};
#endif