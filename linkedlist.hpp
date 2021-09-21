#pragma once

#ifndef _linkedlist_hpp
#define _linkedlist_hpp
namespace linked{

template<class T>
struct node{
    node *next;
    node *previous;
    T data;
    node(T d, node *n = nullptr, node *p = nullptr){
        data = d;
        next = n;
        previous = p;
    }
    ~node(){
        if(next == nullptr){ //es el final de la lista
            previous -> next = nullptr;
        }
        else if(previous == nullptr){ //es el principio
            next -> previous = nullptr;
        }
        else{
            previous -> next = next;
            next -> previous = previous;
        }
    }
};

template<class T>
class linkedlist{
    node<T> &operator[](unsigned long pos){
        node<T> n;
        while(pos--){
            if(n.next == nullptr)
                return nullptr;
            n = &n.next;
        }
        return n;
    }
public:
    node<T> *push_back(T data);
    node<T> *push_front(T data);
    node<T> *back();
    node<T> *front();
    node<T> *search(T data);
    void remove(node<T> *target);
    void remove(T target);
    unsigned long size();
    bool empty();
private:

};

}


#endif