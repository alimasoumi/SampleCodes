//
//  priorityQueue.h
//  Practices
//
//  Created by Ali on 6/11/19.
//  Copyright © 2019 Ali. All rights reserved.
//

#ifndef priorityQueue_h
#define priorityQueue_h
#include <vector>
#include <stdexcept>
#include "random_generator.h"
//This is a max priority queue.
//operations: peek, is_empty, insert, remove, heapify.
template <typename T>
class PriorityQueue{
public:
    PriorityQueue(){};
    PriorityQueue(std::vector<T> vec);
    bool is_empty();
    void insert(T);
    T pull();
    T peek();
 
    inline int parent(int i){ return (i-1)/2;}
    inline int left_child(int i){return 2*i+1;}
    inline int right_child(int i){return 2*i+2;}
    void remove(T);
    void heapify(int i);// i must be smaller than the num of elements.
    void heapify(int i, int last_elem);// i must be smaller than the num of elements.
    void build_max_heap();
    void heap_sort();
    void add_elem(T elem);
    void print1();
    //private:
    std::vector<T> data;
    
    
};

//_________________________________________________________________
template<typename T>
PriorityQueue<T>::PriorityQueue(std::vector<T> vec):data(vec){
    data = vec;
    build_max_heap();
};

//_________________________________________________________________
template<typename T>
bool PriorityQueue<T>::is_empty(){
    return data.size()==0;
}


//_________________________________________________________________
template<typename T>
void PriorityQueue<T>::heapify(int i){
    int l = left_child(i);
    int r = right_child(i);
    int largest = i;
    if (l<data.size() && data[l]>data[i])
        largest = l;
    if (r<data.size() && data[r]>data[largest])
        largest = r;
    if(largest != i){
        std::swap(data[largest], data[i]);
        heapify(largest);
    }
}

//_________________________________________________________________
template<typename T>
void PriorityQueue<T>::heapify(int i, int last){
    int l = left_child(i);
    int r = right_child(i);
    int largest = i;
    if (l<last && data[l]>data[i])
        largest = l;
    if (r<last && data[r]>data[largest])
        largest = r;
    if(largest != i){
        std::swap(data[largest], data[i]);
        heapify(largest, last);
    }
}

//_________________________________________________________________
template<typename T>
void PriorityQueue<T>::print1(){
    for(auto x: data)
        std::cout<<x<<"\t";
    std::cout<<std::endl;
}

//_________________________________________________________________
template<typename T>
void PriorityQueue<T>::build_max_heap(){
    for (int i=static_cast<int>(data.size())/2-1;  i>=0; i--) {
        heapify(i);
    }
}
//_________________________________________________________________
template<typename T>
T PriorityQueue<T>::peek(){
    return data[0];
}

//_________________________________________________________________
template<typename T>
T PriorityQueue<T>::pull(){
    T output = data[0];
    if (data.size()==0){
        throw std::out_of_range("Pulling form an empty priority queue.");
    }
    if (data.size()>0) {
        data[0] = data.back();
        data.pop_back();
        heapify(0);
    }
    return output;
}


//_________________________________________________________________
template<typename T>
void PriorityQueue<T>::heap_sort(){
    for (int i = static_cast<int>(data.size())-1; i>0; i--) {
        std::swap(data[0], data[i]);
        heapify(0, i);
    }
}
//_________________________________________________________________
template<typename T>
void PriorityQueue<T>::add_elem(T elem){
    data.push_back(elem);
    int l = static_cast<int>(data.size())-1;
    while(l>0 && data[l]>data[parent(l)]){
        std::swap(data[l], data[parent(l)]);
        l = parent(l);
        
    }
}

//_________________________________________________________________
template<typename T>
void PriorityQueue<T>::remove(T elem){
    for(auto i=0; i<data.size()-1; i++)
        if (data[i]==elem) {
            std::swap(data[i], data.back());
            data.pop_back();
            heapify(i);
            return;
        }
    if (data.back() == elem)
        data.pop_back();
    
    
}


void test_priority_queue(){
    std::vector<int> vec = generate_uniform(8, -10, 10, 3);
    vec.back() = 21;
    PriorityQueue<int> pq(vec);
    
    std::cout<<"initial priority queue is\t";
    pq.print1();
    for (unsigned long i = vec.size(); i>0; i--) {
        std::cout<<" removing "<< pq.pull()<< "  remaining\t";
        pq.print1();
    }
    pq = PriorityQueue<int>(vec);
    std::cout<<"initial priority queue is:\t";
    pq.print1();
    pq.add_elem(200);
    std::cout<<"after adding 200  to the queue  \t";
    pq.print1();
    pq.add_elem(-30);
    std::cout<<"after adding -30  to the queue  \t";
    pq.print1();
    std::cout<<"After sorting ";
    pq.heap_sort();
    pq.print1();
    std::cout<<"building the heap again:\t";
    pq.build_max_heap();
    pq.print1();
    pq.remove(21);
    std::cout<<"After removing 21:\t ";
    pq.print1();
    
}























//_________________________________________________________________

#endif /* priorityQueue_h */
