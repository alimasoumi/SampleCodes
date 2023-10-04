#pragma once
#include <vector>
#include <iostream>

template <typename T>
class fenwick
{
public:
    fenwick<T>(size_t sz): sz(sz){data = std::vector<T>(sz,static_cast<T>(0));}
    fenwick<T>(std::vector<T> &vec);
    T querySum(int lower, int higher)
    {
        return prefix(higher) - (lower ? prefix(lower - 1) : static_cast<T>(0));
    }
    void update(int pos, T diff);
    void print();
private:
    size_t sz;
    T prefix(int ind);
    std::vector<T> data;
};

template<typename T>
T fenwick<T>::prefix(int ind)
{
    T tot= static_cast<T>(0); 
    ind++;
    while (ind > 0)
    {
        tot+= data[ind];
        ind-= ind& (-ind);
    }
    return tot;
}

template<typename T>
void fenwick<T>::update(int pos, T val)
{
    //  fenwick trees are 1 indexed.
    pos++;

    while (pos<= data.size())
    {
        data[pos] += val;
        pos+= pos & (-pos);
    }
}


template<typename T>
fenwick<T>::fenwick(std::vector<T>& vec){
    sz = vec.size();
    data = std::vector<T>(sz, 0);
    for (size_t i = 0; i < sz; i++)
        update(i, vec[i]);
}

template<typename T>
void fenwick<T>::print(){
    for (size_t i = 0; i < sz; i++)
        std::cout<< data[i] <<' ';
        std::cout<<std::endl;
}
