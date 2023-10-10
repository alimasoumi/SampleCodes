//
//  sorter.h
//  Practices
//
//  Created by Ali on 6/14/19.
//  Copyright © 2019 Ali. All rights reserved.
//

#ifndef sorter_h
#define sorter_h
#include<vector>
#include<iostream>
#include<queue>

// In all the following functions low and high are inclusive.
//_________________________________________________________________

template<typename T>
void print(T arr[], int low, int high, std::ostream &os = std::cout, bool print_new_line=true){
    if (high<low)
        return;
    
    for (int i=low; i!=high-1; i++)
        os<<arr[i]<<",";
    os<<arr[high];
    if(print_new_line)
        os<<"\n";
}

//_________________________________________________________________

template<typename T>
void initialize_array(T arr[], std::vector<T> vec){
    for (int i=0; i<vec.size(); i++)
        arr[i] = vec[i];
}
//_________________________________________________________________
template<typename T>
void test_sorted(T arr[], int sz, std::string sorter_name){
    for (int i=0; i<sz-1; i++)
        if(arr[i] > arr[i+1]){
            std::cout<< arr[i] << arr[i+1] << std::endl;
            std::cout<<"algorithm " << sorter_name << " did not finish correctly"<<std::endl;
            return;
        }
    std::cout<<"algorithm " << sorter_name << " finished correctly"<<std::endl;
}
//_________________________________________________________________



//_________________________________________________________________
template<typename T>
int partition(T arr[], int low, int high){
    int last_smaller = low-1;
    int current_loc = low;
    while(current_loc<high){
        if(arr[current_loc]<arr[high]){
            last_smaller ++;
            std::swap(arr[current_loc], arr[last_smaller]);
        }
        current_loc++;
    }
    
    std::swap(arr[++last_smaller], arr[high]);
    return last_smaller;
}
//_________________________________________________________________
template<typename T>
void quick_sort(T arr[], int low, int high){
    if(high>low){
        int pos = partition(arr, low, high);
        quick_sort(arr, low, pos-1);
        quick_sort(arr, pos+1,  high);
        
    }
    
}
//_________________________________________________________________
template<typename T>
void heap_sort(T arr[], int low, int high){
    std::priority_queue<T> pq(arr+low, arr+high+1 );
    for(int i=0; i<= high-low; i++){
        arr[high-i] = pq.top();
        pq.pop();
    }

    
    
    
}
//_________________________________________________________________
template<typename T>
void merge(T arr[], int low, int mid, int high){

    int lsz = mid-low+1;
    int rsz = high - mid;
    int li = 0;
    int ri = 0;
    int ctr = low;
    T* L = new T[lsz];
    T* R = new T[rsz];
    for(int i=0; i<lsz; i++)
        L[i] = arr[low+i];
    for(int i=0; i<rsz; i++)
        R[i] = arr[mid+1+i];
    while(li<lsz && ri<rsz){
        if(L[li]<R[ri]){
            arr[ctr] = L[li];
            li++;
        }
        else{
            arr[ctr] = R[ri];
            ri++;
        }
        ctr++;
    }
    while(li<lsz){
        arr[ctr]=L[li];
        li++;
        ctr++;
    }
    while(ri<rsz){
        arr[ctr]=R[ri];
        ri++;
        ctr++;
    }

    
    
}


//_________________________________________________________________
template<typename T>
void merge_sort(T arr[], int low, int high){
    if (low<high){
        int mid =  low + (high - low)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
 }
//_________________________________________________________________
template<typename T>
void insertion_sort(T arr[], int low, int high){
    for (int i=low; i<high; i++) {
        if (arr[i]>arr[i+1]) {
            int j = i+1;
            while(j>low){
                if (arr[j]<arr[j-1])
                    std::swap(arr[j], arr[j-1]);
                else
                    break;
                j--;}
        }
    }
}

//_________________________________________________________________
template<typename T>
void bubble_sort(T arr[], int low, int high){
    for (int i=low; i<high; i++) {
        for (int j=low; j<high+low-i; j++) {
            if(arr[j]>arr[j+1])
                std::swap(arr[j], arr[j+1]);
        }
    }
    
}

//_________________________________________________________________
template<typename T>
void radix_sort(T arr[], int low, int high){
    
    
}
//_________________________________________________________________
template<typename T>
void bucket_sort(T arr[], int low, int high){
    
    
}



void test_sorting(){
    const int num_of_elem = 100;
    int* arr = new int[num_of_elem];
    std::vector<int> vec = generate_uniform(num_of_elem, -1000, 1000, 203);
    
    if(num_of_elem < 1000){
        initialize_array(arr, vec);
        insertion_sort(arr, 0, num_of_elem);
        test_sorted(arr, num_of_elem, "insertion sort");
        
        initialize_array(arr, vec);
        bubble_sort(arr, 0, num_of_elem);
        test_sorted(arr, num_of_elem, "bubble sort");
    }
    initialize_array(arr, vec);
    merge_sort(arr, 0, num_of_elem-1);
    test_sorted(arr, num_of_elem, "merge sort");
    
    initialize_array(arr, vec);
    quick_sort(arr, 0, num_of_elem-1);
    test_sorted(arr, num_of_elem, "quick sort");
    
    initialize_array(arr, vec);
    heap_sort(arr, 0, num_of_elem-1);
    test_sorted(arr, num_of_elem, " heap sort ");

    
}



#endif /* sorter_h */
