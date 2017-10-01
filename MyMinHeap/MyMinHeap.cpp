#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <class T>
class MyMinHeap
{
public:
    MyMinHeap() {}
    MyMinHeap(const vector<T> & vec): m_vec(vec)
    {
        heapify();
    }

    int len()
    {
        return m_vec.size();
    }

    void push(const T & node)
    {
        m_vec.push_back(node);

        siftDown(node.size() - 1);
    }

    const T & peak()
    {
        if (len() == 0)
            throw runtime_error("MyHeap is empty");

        return m_vec[0];
    }

    void pop()
    {
        if (len() == 0)
            throw runtime_error ("MyHeap is empty");

        swap(m_vec[0], m_vec.back());
        m_vec.pop_back();

        siftDown(0);
    }

private:

    vector<T> m_vec;
    void heapify()
    {
        int size = len();
        //start with the first non-leaf node
        for (int i = (size - 1)/2; i >= 0; i--)
        {
            siftDown(i);
        }
    }

    void siftDown(int idx)
    {
        int lChild = idx * 2 + 1;
        int rChild = idx * 2 + 2;

        int minIdx = idx;
        if (lChild < len() && m_vec[minIdx] > m_vec[lChild])
            minIdx = lChild;
        if (rChild < len() && m_vec[minIdx] > m_vec[rChild])
            minIdx = rChild;

        if (idx != minIdx)
        {
            swap(m_vec[minIdx], m_vec[idx]);
            siftDown(minIdx);
        }
    }

    void siftUp(int idx)
    {
        int parentIdx = (idx - 1)/2;

        if (parentIdx >= 0)
        {
            if (m_vec[parentIdx] > m_vec[idx])
            {
                swap(m_vec[parentIdx], m_vec[idx]);
                siftUp(parentIdx);
            }
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;

    vector<int> vec({9,4,6,4,3,2,4,5,6});
    MyMinHeap<int> myMinHeap(vec);

    int size = vec.size();
    for (int i = 0; i < size; i++)
    {
        cout << myMinHeap.peak() << ",";
        myMinHeap.pop();
    }



    return 0;
}
