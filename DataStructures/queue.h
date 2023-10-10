//
//  queue.h
//  Practices
//
//  Created by Ali on 6/10/19.
//  Copyright © 2019 Ali. All rights reserved.
//

#ifndef queue_h
#define queue_h
#include<vector>
#include<stdexcept>
#include<iostream>
#include"Node.h"

template<typename T>
class Queue{
public:
    Queue(): head(nullptr), tail(nullptr), sz(0){};
    Queue(T value);
template<typename InputIt>
    Queue(InputIt first, InputIt last);
    T pop();
    T peek_head();
    T peek_tail();

    void push(T value);
    int size();
    bool is_empty();
private:
    Node<T>* head;
    Node<T>* tail;
    int sz;
};

//_________________________________________________________________
template<typename T>
Queue<T>::Queue(T value){
    head = new Node<T>(value);
    tail = head;
    sz = 1;
}
//_________________________________________________________________
template <typename T>
template <typename InputIt>
Queue<T>::Queue(InputIt first, InputIt last){
    head = nullptr;
    tail = nullptr;
    sz = 0;
    for(auto it = first; it!=last; it++){
        sz++;
        Node<T>* new_node = new Node<T>(*it);
        if(head == nullptr){
            head = tail = new_node;
        }
        else{
            tail->next = new_node;
            tail = new_node;
        }
    }
}
//_________________________________________________________________
template<class T>
bool Queue<T>::is_empty(){
    return head == nullptr;
}

//_________________________________________________________________
template<class T>
T Queue<T>::peek_head(){
    if(head != nullptr)
        return head->value;
    else
        throw std::out_of_range("Peeking an empty queue");
}

//_________________________________________________________________
template<class T>
T Queue<T>::peek_tail(){
    if(head != nullptr)
        return tail->value;
    else
        throw std::out_of_range("Peeking an empty queue");
}

//_________________________________________________________________
template<class T>
T Queue<T>::pop(){
    if(head != nullptr){
        T val = head->value;
        Node<T> * temp = head;
        head = head->next;
        if(head == nullptr)
            tail = nullptr;
        sz--;
//        std::cout<<"deleteing\n";
        delete temp;
        return val;
    }
    else{
        throw std::out_of_range("Popping an empty queue.\n");
    }
}

//_________________________________________________________________

template<class T>
void Queue<T>::push(T value){
    Node<T>* new_node = new Node<T>(value);
    if ( head==nullptr)
        head=tail = new_node;
    tail->next = new_node;
    tail = new_node;
    sz++;
}
//_________________________________________________________________

template<class T>
int Queue<T>::size(){
    return sz;
}

void test_queue(){
    std::vector<double> vec{1.2,3.2,-1.4};
    Queue<double> q1(vec.begin(), vec.end());
    std::cout<<" head= " << q1.peek_head() << " tail= " << q1.peek_tail() <<std::endl;
    try{
        for(int i=0; i<4; i++){
            std::cout<< "element to be popped = "<< q1.pop()<<std::endl;
            std::cout<<" head= " << q1.peek_head() << " tail= " << q1.peek_tail() <<std::endl;
            
        }
    }
    catch(std::out_of_range& oor){
        std::cout <<oor.what() ;
    }
    Queue<int> q2;
    try {
        std::cout<< "front of the queue is "<<q2.peek_head()<< std::endl;
    } catch (std::out_of_range& oor) {
        std::cout<<oor.what()<<std::endl;
    }
    try {
        std::cout<< "top of queue is "<<q2.pop()<< std::endl;
    } catch (std::out_of_range& oor) {
        std::cout<<oor.what()<<std::endl;
    };

}

#endif /* queue_h */
