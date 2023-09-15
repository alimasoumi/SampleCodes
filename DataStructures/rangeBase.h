#include <vector>
#include <functional>

/*
    Simple implementation of segment tree. 
        1- op is a binary operator (bivalent function) which determines the type of query (min, max, sum, ...)
        2- default_val is the identity of op operation(op(default_val, x) = x for all x).
        3- To update the value of a given number in the index add the increment. For min max just replace,
            for sum use the delta.
*/
template <class T>
class rangeQuery
{
public:
    rangeQuery(std::vector<T> &, std::function<T(const T &, const T &)>, const T);
    T query(int qlow, int qhigh);
    void update(int pos, T val);
private:
    void build_tree(std::vector<T> & input, int low, int high, int pos) ;
    int find_leaf(int low, int high, int orig_pos, int heap_pos);
    std::vector<T> heap;
    std::vector<T> input;
    std::function<T(const T&, const T&)> op;
    T default_value;
    size_t orig_sz;
    T query_helper(int qlow, int qhigh, int low, int high, int pos);
};

template<class T> 
void rangeQuery<T>::build_tree(std::vector<T>&input, int low, int high, int pos){
    if(low == high){
        heap[pos] = input[low];
        return;
    }
    int mid = low + (high-low)/2;
    build_tree(input, low, mid, 2*pos+1);
    build_tree(input, mid+1, high, 2*pos+2);
    heap[pos] = this->op(heap[2*pos+1], heap[2*pos+2]);
}

template <class T>
rangeQuery<T>::rangeQuery(std::vector<T> &input, std::function<T(const T &, const T &)> op1, const T default_value):
     op(op1), orig_sz(input.size()), default_value(default_value)
{
    size_t sz = input.size();
    size_t heap_sz = 1;
    while (sz > 1)
    {
        sz /= 2;
        heap_sz *= 2;
    };
    heap_sz *= 2;
    heap_sz--;
    heap = std::vector<T>(heap_sz, default_value);
    build_tree(input, 0, orig_sz-1, 0  );
};

template<class T>
T rangeQuery<T>::query_helper(int qlow, int qhigh, int low, int high, int pos){
    if(qlow<= low && qhigh>= high) return heap[pos];
    if(qlow>high || qhigh <low) return default_value;
    int mid = low + (high-low)/2;
    T val1 = query_helper(qlow, qhigh, low, mid, 2*pos+1);
    T val2 = query_helper(qlow, qhigh, mid+1, high, 2*pos+2);
    return op(val1, val2);
}

template<class T>
T rangeQuery<T>::query(int qlow, int qhigh){
    return query_helper(qlow, qhigh, 0, orig_sz-1,  0);
}

template<class T>
int rangeQuery<T>::find_leaf(int low, int high, int orig_pos, int heap_pos){
    if(low == high) return heap_pos;
    int mid = low + (high-low)/2;
    if(orig_pos<=mid) 
        return find_leaf(low, mid, orig_pos, 2*heap_pos+1);
    else   
        return find_leaf(mid+1, high, orig_pos, 2*heap_pos+2);
}

template<class T>
void rangeQuery<T>::update(int ind, T val){
    int pos = find_leaf(0, orig_sz-1, ind, 0);
    heap[pos] = val;
    while(pos ){
        pos /= 2;
        heap[pos] = op(heap[2*pos+1], heap[2*pos+2]);
    }
    for(int x: heap) std::cout << x << "\t";
    std::cout << std::endl;
}
