#pragma once

#ifndef _linkedlist_hpp
#define _linkedlist_hpp
#include <stdexcept>
#include <vector>

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
    node<T> *operator[](unsigned long pos);
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
    ~linkedlist();
private:
    node<T> *frontptr = nullptr;
    node<T> *backptr = nullptr;
    unsigned long sizepr = 0;
};

template<class T>
node<T> *linkedlist<T>::operator[](unsigned long pos){
    node<T> *n = backptr;
    unsigned long size = sizepr;
    size--;
    if(pos > size)
        throw std::invalid_argument("index bigger than list");
    size++;
    unsigned long mitad = size / 2;
    if(pos <= mitad){
        while(pos--){
            n = n -> next;
        }
    }
    else{
        pos = size - pos;
        pos--;
        n = frontptr;
        while (pos--){
            n = n -> previous;
        }
        
    }
    return n;
}

template<class T>
node<T> *linkedlist<T>::push_back(T data){
    node<T> *ret = (node<T> *)malloc(sizeof(node<T>));
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
node<T> *linkedlist<T>::push_front(T data){
    node<T> *ret = (node<T> *)malloc(sizeof(node<T>));
    if(frontptr != nullptr)
        ret -> previous = frontptr;
    else
        ret -> previous = nullptr;
    ret -> next = nullptr;
    ret -> data = data;
    if(sizepr != 0)
        frontptr -> next = ret;
    frontptr = ret;
    if(sizepr == 0)
        frontptr = backptr = ret;
    sizepr++;
    return ret;
}

template<class T>
node<T> *linkedlist<T>::back(){
    return backptr;
}

template<class T>
node<T> *linkedlist<T>::front(){
    return frontptr;
}

template<class T>
node<T> *linkedlist<T>::search(T data){
    node<T> *ret = backptr;
    for(int n = 0; n != size(); n++){
        if(ret -> data == data){
            return ret;
        }
        ret = ret -> next;
    }
    return nullptr;
}

template<class T>
node<T> *linkedlist<T>::insert(T data, node<T> *index){
    if(index == frontptr)
        return push_front(data);
    node<T> *ret = (node<T> *)malloc(sizeof(node<T>));
    ret -> next = index -> next;
    ret -> previous = index;
    index -> next -> previous = ret;
    index -> next = ret;
    sizepr++;
    return ret;
}

template<class T>
node<T> *linkedlist<T>::insert(T data, unsigned long index){
    node<T> *idx = operator[](index);
    if(idx == frontptr)
        return push_front(data);
    node<T> *ret = (node<T> *)malloc(sizeof(node<T>));
    ret -> next = idx -> next;
    ret -> previous = idx;
    idx -> next -> previous = ret;
    idx -> next = ret;
    sizepr++;
    return ret;
}

template<class T>
void linkedlist<T>::pop_back(){
    sizepr--;
    node<T> *aux = backptr;
    if(backptr -> next != nullptr)
        backptr = backptr -> next;
    if(aux -> next == nullptr) //la lista tiene un solo elemento
        frontptr = backptr = nullptr;
    else
        aux -> next -> previous = nullptr;
    free(aux);
}

template<class T>
void linkedlist<T>::pop_front(){
    sizepr--;
    node<T> *aux = frontptr;
    if(frontptr -> previous != nullptr)
        frontptr = frontptr -> previous;
    if(aux -> previous == nullptr) //la lista tiene un solo elem
        frontptr = backptr = nullptr;
    else
        aux -> previous -> next = nullptr;
    free(aux);
}

template<class T>
void linkedlist<T>::remove(node<T> *target){
    if(target == frontptr){
        pop_front();
        return;
    }
    if(target == backptr){
        pop_back();
        return;
    }
    target -> previous -> next = target -> next;
    target -> next -> previous = target -> previous;
    free(target);
    sizepr--;
}

template<class T>
void linkedlist<T>::remove(T target){
    std::vector<node<T> *> tar;
    node<T> *aux = backptr;
    for(unsigned long n = 0; n != size(); n++){
        if(aux -> data == target)
            tar.push_back(aux);
        aux = aux -> next;
    }
    while(!tar.empty()){
        remove(tar.back());
        tar.pop_back();
    }
}

template<class T>
unsigned long linkedlist<T>::size(){
    return sizepr;
}

template<class T>
bool linkedlist<T>::empty(){
    if(sizepr == 0)
        return true;
    return false;
}

template<class T>
linkedlist<T>::~linkedlist(){
    while(!empty())
        pop_back();
}

}


#endif //_linkedlist_hpp
