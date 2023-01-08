//Kemal Sarper Sahin
#ifndef HW3_LINKEDLIST_H
#define HW3_LINKEDLIST_H
#include <iostream>
#include "Node.h"
template <class ItemType>
class LinkedList{
public:
    Node<ItemType>* headPtr;
    int itemCount;
   Node<ItemType>* getNodeAt(int pos) const{
       Node<ItemType>* curPtr = headPtr;
       for(int i = 0; i < pos; i++){
           curPtr = curPtr->getNext();
       }
       return curPtr;
   }
    LinkedList(){
        headPtr = NULL;
        itemCount = 0;
    }
    LinkedList(const LinkedList<ItemType>& aList){
        itemCount = aList.itemCount;
        Node<ItemType>* origPtr = aList.headPtr;
        if(origPtr == NULL)
            headPtr = NULL;
        else{
            headPtr = new Node<ItemType>();
            headPtr->setItem(origPtr->getItem());
            Node<ItemType>* newChainPtr = headPtr;
            origPtr = origPtr -> getNext();
            while(origPtr != NULL){
                ItemType nextItem = origPtr->getItem();
                Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
                newChainPtr->setNext(newNodePtr);
                newChainPtr = newChainPtr->getNext();
                origPtr = origPtr->getNext();
            }
            newChainPtr->setNext(NULL);
        }
    }

    ~LinkedList(){
       this->itemCount = 0;
       this->clear();
   }
    bool isEmpty() const{
        return itemCount == 0;
    }

    void insert(const ItemType& newNode){
        Node<ItemType>* newNodePtr = new Node<ItemType>(newNode);
        if(itemCount==0){

            headPtr = newNodePtr;
            itemCount++;
            return;
        }
        else {
            if(newNodePtr->item < this->getNodeAt(0)->item){
                newNodePtr->setNext(this->headPtr);
                itemCount++;
                this->headPtr = newNodePtr;
                return;
            }
            for (int i = 0; i < itemCount; ++i) {
                if(newNodePtr->item <  this->getNodeAt(i)->item ){

                    itemCount++;
                    Node<ItemType>* temp = this->getNodeAt(i);
                    this->getNodeAt(i-1)->setNext(newNodePtr);
                    newNodePtr->setNext(temp);
                    return;
                }
            }
            this->getNodeAt(itemCount-1)->setNext(newNodePtr);
            itemCount++;
            return;
        }

    }
    void remove(int pos){
        Node<ItemType>* curPtr = NULL;
        if(pos == 0){
            curPtr = headPtr;
            headPtr = headPtr->getNext();
        }
        else{
            Node<ItemType>* prevPtr = getNodeAt(pos-1);
            curPtr = prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
        }
        curPtr->setNext(NULL);
        delete curPtr;
        curPtr = NULL;
        itemCount--;
    }
    void clear(){
        while(!isEmpty()){
            remove(0);
        }
    }
    ItemType getEntry(int pos) const{
        Node<ItemType>* nodePtr = getNodeAt(pos);
        return nodePtr->getItem();
    }

};
#endif