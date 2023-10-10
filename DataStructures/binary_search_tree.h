//
//  binary_search_tree.h
//  Practices
//
//  Created by Ali on 11/26/19.
//  Copyright © 2019 Ali. All rights reserved.
//
// This class does not allow for duplication of elements
#ifndef binary_search_tree_h
#define binary_search_tree_h
#include <iostream>
#include<stack>

//_________________________________________________________________
template <typename T>
class BST_node{
public:
    BST_node():value(T()), left(nullptr), right(nullptr), parent(nullptr){};
    BST_node(T value): value(value), left(nullptr), right(nullptr), parent(nullptr){};
    BST_node(T value, BST_node* parent): value(value), left(nullptr), right(nullptr), parent(parent){};
    
    T value;
    BST_node<T> * parent;
    BST_node<T> *left ;
    BST_node<T> * right;
    void inorder_print();
    void postorder_print();
    void preorder_print();
};
//_________________________________________________________________

template<typename T>
class binary_search_tree{
public:
    binary_search_tree<T>():head(nullptr){};
    binary_search_tree<T>(T value): head(new BST_node<T>(value)){};
    
    BST_node<T> * find(T val);
    BST_node<T>* find_next();
    BST_node<T>* parent();
    
    void add_elem(T value);
    void delete_elem(T value);
    BST_node<T>* get_head(){return head;}
    
private:
    BST_node<T> * head;
};

//_________________________________________________________________

template<typename T>
void binary_search_tree<T>::add_elem(T value){
    if(head==nullptr)
        head = new BST_node<T>(value);
    else{
        BST_node<T>* temp = head;
        while(temp){
            if ( value > temp->value){
                if(temp->right)
                    temp = temp->right;
                else{
                    temp->right = new BST_node<T>(value, temp);
                    return;
                }
            }
            else if (value < temp->value){
                if(temp->left)
                    temp = temp->left;
                else{
                    temp->left = new BST_node<T>(value, temp);
                    return;
                }
            }
            else
                return;
        }
    }
}
//_________________________________________________________________
template <typename T>
BST_node<T>* binary_search_tree<T>::find(T value){
    BST_node<T>* curr = head;
    while(curr){
        if(curr->value == value)
            return curr;
        else if(curr->value < value)
            curr = curr->right;
        else curr = curr->left;
    }
    return curr;
};
//_________________________________________________________________
template <typename T>
void BST_node<T>::inorder_print(){
    if(left)
        left->inorder_print();
    std::cout << value<< ',';
    if(right)
        right->inorder_print();
};

//_________________________________________________________________
template <typename T>
void BST_node<T>::preorder_print(){
    std::cout << value<< ',';
    if(left)
        left->inorder_print();
    if(right)
        right->inorder_print();
};

//_________________________________________________________________
template <typename T>
void BST_node<T>::postorder_print(){
    if(left)
        left->inorder_print();
    if(right)
        right->inorder_print();
    std::cout << value<< ',';

};
//_________________________________________________________________
void test_bst(){
    binary_search_tree<int> bst(12);
    bst.add_elem(18);
    bst.add_elem(10);
    bst.add_elem(12);
    bst.add_elem(16);
    for(int ctr = 10; ctr <= 20; ctr+=2){
        BST_node<int>* result = bst.find(ctr);
        std::cout << "number "<<ctr << (result?" exists ": " does not exist") << "in the binary tree\n";
    }
    bst.get_head()->inorder_print();
    std::cout << '\n';
    bst.get_head()->preorder_print();
    std::cout<<'\n';
    bst.get_head()->postorder_print();
}













#endif /* binary_search_tree_h */
