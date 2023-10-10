//  stack.h
//  Practices
//
//  Created by Ali on 6/10/19.
//  Copyright © 2019 Ali. All rights reserved.
//

#ifndef stack_h
#define stack_h
#include<vector>
#include<stdexcept>
#include<iostream>
#include"Node.h"

template<typename T>
class Stack{
public:
    Stack(): head(nullptr), sz(0){};
    Stack(T value);
template<typename InputIt>
    Stack(InputIt first, InputIt last);
    T pop();
    T peek();
    void push(T value);
    int size();
    bool is_empty();
private:
    Node<T>* head;
    int sz;
};

//_________________________________________________________________
template<typename T>
Stack<T>::Stack(T value){
    head = new Node<T>(value);
    sz = 1;
}
//_________________________________________________________________
template <typename T>
template <typename InputIt>
Stack<T>::Stack(InputIt first, InputIt last){
    head = nullptr;
    for(auto it = first; it!=last; it++){
        sz++;
        Node<T>* new_node = new Node<T>(*it);
        if(head == nullptr)
            head = new_node;
        else{
            new_node->next = head;
            head = new_node;
        }
    }
}
//_________________________________________________________________
template<class T>
bool Stack<T>::is_empty(){
    return head == nullptr;
}


//_________________________________________________________________
template<class T>
T Stack<T>::peek(){
    if(head != nullptr)
        return head->value;
    else
        throw std::out_of_range("Peeking an empty stack");
}

//_________________________________________________________________
template<class T>
T Stack<T>::pop(){
    if(head != nullptr){
        T val = head->value;
        Node<T> * temp = head;
        head = temp->next;
        sz--;
        delete temp;
        return val;
    }
    else{
        throw std::out_of_range("Popping an empty stack.\n");
    }
}

//_________________________________________________________________

template<class T>
void Stack<T>::push(T value){
    Node<T>* new_node = new Node<T>(value);
    new_node->next = head;
    head = new_node;
    sz++;
}
//_________________________________________________________________

template<class T>
int Stack<T>::size(){
    return sz;
}

void test_stack(){
    std::vector<double> vec{1.2,3.2,-1.4};
    Stack<double> st1(vec.begin(), vec.end());
    std::cout<<"the top of the stack is "<< st1.peek()<<std::endl;
    try{
        for(int i=0; i<4; i++)
            std::cout<< st1.pop()<<std::endl;
    }
    catch(std::out_of_range& oor){
        std::cout <<oor.what() ;
    }
    Stack<int> st2;
    try {
        std::cout<< "top of stack is "<<st2.peek()<< std::endl;
        } catch (std::out_of_range& oor) {
            std::cout<<oor.what()<<std::endl;
        }
        try {
            std::cout<< "top of stack is "<<st2.pop()<< std::endl;
        } catch (std::out_of_range& oor) {
            std::cout<<oor.what()<<std::endl;
        };

}

#endif /* stack_h */
