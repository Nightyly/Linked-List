#pragma once

#ifndef _linkedlist_hpp
#define _linkedlist_hpp
#include <stdexcept>
#include <iostream>
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
};

template<class T>
class linkedlist{
public:
    node<T> &operator[](unsigned long pos);
    node<T> *push_back(T data);
    node<T> *push_front(T data);
    node<T> *back();
    node<T> *front();
    node<T> *search(T data);
    node<T> *insert(T data, node<T> *index);
    node<T> *insert(T data, unsigned long index);
    void pop_back();
    void pop_front();
    void remove(node<T> *target);
    void remove(T target);
    unsigned long size();
    bool empty();
private:
    node<T> *frontptr = nullptr;
    node<T> *backptr = nullptr;
    unsigned long sizepr = 0;
};

template<class T>
void linkedlist<T>::pop_back(){
    sizepr--;
    node<T> *aux = backptr;
    if(backptr -> next != nullptr)
        backptr = backptr -> next;
    if(aux -> next == nullptr) //la lista tiene un solo elemento
        backptr = nullptr;
    else
        aux -> next -> previous = nullptr;
    free(aux);
}

template<class T>
node<T> *linkedlist<T>::push_back(T data){
    node<T> n(data);
    node<T> *ret = (node<T> *)malloc(sizeof(n));
    if(backptr != nullptr)
        ret -> next = backptr;
    else
        ret -> next = nullptr;
    ret -> previous = nullptr;
    ret -> data = data;
    if(sizepr != 0)
        backptr -> previous = ret;
    backptr = ret;
    if(sizepr == 0)
        frontptr = backptr = ret;
    sizepr++;
    return ret;
}

template<class T>
node<T> &linkedlist<T>::operator[](unsigned long pos){
    node<T> *n = backptr;
    while(pos--){
        if(n -> next == nullptr)
            throw std::invalid_argument("index bigger than list");
        n = n -> next;
    }
    return *n;
}

template<class T>
bool linkedlist<T>::empty(){
    if(sizepr == 0)
        return true;
    return false;
}

template<class T>
unsigned long linkedlist<T>::size(){
    return sizepr;
}

}


#endif //_linkedlist_hpp
