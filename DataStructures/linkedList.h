//  Created by Ali on 6/9/19.
//  Copyright © 2019 Ali. All rights reserved.
//

#ifndef linkedList_h
#define linkedList_h


#include <iostream>
#include <vector>
#include "Node.h"

//_________________________________________________________________
template<typename T>
class Linked_List{
public:
    Linked_List(): head(nullptr){};
    Linked_List(T value);
    template<class  InputIt >
    Linked_List(InputIt first, InputIt last);
    template <class U>
    friend std::ostream & operator<<(std::ostream &, const Linked_List<U>&);
    void push_back(T value);
    void push_front(T value);
    Node<T>* find(T value);
    void remove_one(T value);
    void remove_all(T value);
    void reverse();
private:
    Node<T>* head;
};

//_________________________________________________________________

template <typename T >
Linked_List<T>::Linked_List(T value) {
    Node<T>* new_node = new Node<T>(value);
    head = new_node;
}

//_________________________________________________________________
template <typename T>
template<typename InputIt>
Linked_List<T>::Linked_List(InputIt first, InputIt last) {
    head = nullptr;
    Node<T> * curr = head;
    for( InputIt it = first; it != last; it++){
        Node<T> * new_node = new Node<T>(*it);
        if(head == nullptr)
            curr = head = new_node;
        curr->next = new_node;
        curr = new_node;
    }
}
//_________________________________________________________________
template<typename T>
std::ostream & operator<<(std::ostream& os, const Linked_List<T> &ls){
    if (ls.head!=nullptr){
        Node<T> * curr = ls.head;
        while(curr){
            os << curr->value;
            if(curr->next != nullptr)
                os<<' ';
            curr = curr->next;
        }
    }
    return os;
}

//_________________________________________________________________

template <typename T >
void Linked_List<T>::push_back(T value) {
    Node<T>* new_node = new Node<T>(value);
    Node<T>* curr = head;
    if(head == nullptr){
        head = new_node;
        return;
    }
    while(curr->next != nullptr)
        curr = curr->next;
    curr->next = new_node;
}


//_________________________________________________________________

template <typename T >
void Linked_List<T>::push_front(T value) {
    Node<T>* new_node = new Node<T>(value);
    new_node->next = head;
    head = new_node;
}

//_________________________________________________________________

template <typename T >
Node<T>* Linked_List<T>::find(T value) {
    Node<T>* curr = head;
    while(curr!=nullptr){
        if(curr->value == value)
            return curr;
        curr = curr->next;
        
    }
    return curr ;
}


//_________________________________________________________________

template <typename T >
void Linked_List<T>::remove_one(T value) {
    if(head == nullptr)
        return;
    Node<T>* curr = head;
    if(head->value == value){
        head = head->next;
        delete curr;
        return;
    }
    Node<T>* prev = head;
    while(curr->next!=nullptr){
        prev = curr;
        curr = curr->next;
        if(curr->value ==  value){
            prev->next = curr->next;
            delete curr;
            return;}
    }
}
//_________________________________________________________________

template <typename T >
void Linked_List<T>::remove_all(T value) {
    if(head == nullptr)
        return;
    Node<T>* curr = head;

    while(head->value == value){
        curr = head;
        head = head->next;
        delete curr;
        if(head == nullptr)
            return;
    }
    curr = head->next;
    Node<T>* prev_non = head;
    while(curr != nullptr){
        if(curr->value != value){
            prev_non = curr;
            curr = curr->next;
        }
        else
            while(curr != nullptr && curr->value==value){
                prev_non->next = curr->next;
                delete curr;
                if(prev_non->next == nullptr)
                    return;
                curr = prev_non->next;
            }
    }
}
//_________________________________________________________________
template <typename T>
void Linked_List<T>::reverse(){
    if(head == nullptr || head->next == nullptr)
        return;
    Node<T>* curr = head;
    Node<T>* next = head;
    Node<T>* prev = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
//_________________________________________________________________
void test_linked_list(){
    std::vector<int> vec{1,3,5,2};
    Linked_List<int> ls(vec.begin(), vec.end());
    std::cout <<"initial linked list \t\t"<<  ls <<std::endl;
    ls.push_back(4);
    std::cout <<"add to the end \t\t\t"<<  ls << std::endl;
    ls.push_front(8);
    std::cout <<"add to the front \t\t"<< ls << std::endl;
    ls.reverse();
    std::cout << "reversed Linked_List \t"<< ls << std::endl;
    auto loc = ls.find(1);
    std::cout<< "finding one in the linked list " << loc->value << std::endl;
    vec = std::vector<int>{2,2,3, 3, 2, 2, 3, 3, 2};
    Linked_List<int> ls2(vec.begin(), vec.end());
    std::cout << "new linked list  \t\t"<< ls2 << std::endl;
    ls2.remove_one(2);
    std::cout<< "Removing a 2 (single) \t"<<ls2 << std::endl;
    ls2.remove_all(2);
    std::cout << "Removing all twos \t\t"<<ls2 << std::endl;
}
//_________________________________________________________________





#endif /* linkedList_h */
