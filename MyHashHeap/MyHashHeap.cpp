#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

template <class T>
class MyHashHeap
{
public:
    MyHashHeap() {}

    //O(lgN)
    void add(const T & node)
    {
        if (!exist(node))
        {
            hashset.insert(node);
            heap.insert(node);
        }
    }
    //O(lgN)
    void del(const T & node)
    {
        if (exist(node))
        {
            hashset.erase(node);
            heap.erase(node);
        }
    }
    //O(1)
    bool exist(const T & node)
    {
        return hashset.count(node);
    }
    //O(1)
    const T & getMin()
    {
        if (hashset.empty())
            throw runtime_error("Hashheap is empty");

        return *(heap.begin());
    }
    //O(1)
    const T & getMax()
    {
         if (hashset.empty())
            throw runtime_error("Hashheap is empty");

        return *(heap.rbegin());
    }
private:
    unordered_set<T> hashset;
    set<T> heap;
};

int main()
{
    cout << "Hello world!" << endl;
    MyHashHeap<int> myHashHeap;

    myHashHeap.add(2);
    myHashHeap.add(3);
    myHashHeap.add(4);
    myHashHeap.add(1);
    cout << myHashHeap.getMax() << endl;
    cout << myHashHeap.getMin() << endl;
    cout << myHashHeap.exist(2) << endl;
    cout << myHashHeap.exist(5) << endl;
    myHashHeap.del(1);
    cout << myHashHeap.getMax() << endl;
    cout << myHashHeap.getMin() << endl;
    myHashHeap.del(4);
    cout << myHashHeap.getMax() << endl;
    cout << myHashHeap.getMin() << endl;

    return 0;
}
