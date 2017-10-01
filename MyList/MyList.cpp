#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node * prev;
    Node * next;
    Node(const T & d):data(d), prev(NULL), next(NULL) {}
};

template <class T>
class MyList
{
public:
    typedef Node<T> * MyListIterator;
    MyList()
    {
        head = tail = NULL;
        size = 0;
    }

    void push_back(const T & data)
    {
        if (size == 0)
        {
            head = tail = new Node<T>(data);
        }
        else
        {
            tail->next = new Node<T>(data);
            tail->next->prev = tail;

            tail = tail->next;
        }

        size++;
    }

    void push_front(const T & data)
    {
        if (size == 0)
        {
            head = tail = new Node<T>(data);
        }
        else
        {
            head->prev = new Node<T>(data);
            head->prev->next = head;

            head = head->prev;
        }

        size++;
    }

    void pop_back()
    {
        if (size == 0)
            throw runtime_error("List is empty");

        if (size == 1)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node<T> * toDel = tail;

            tail = tail->prev;
            tail->next = NULL;
            delete toDel;
        }

        size--;
    }

    void pop_front()
    {
        if (size == 0)
            throw runtime_error("List is empty");

        if (size == 1)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node<T> * toDel = head;

            head = head->next;
            head->prev = NULL;
            delete toDel;
        }

        size--;
    }

    const T & front()
    {
        if (size == 0)
            throw runtime_error("List is empty");

        return head->data;
    }

    const T & back()
    {
        if (size == 0)
            throw runtime_error("List is empty");

        return tail->data;
    }

    MyListIterator find(const T & data)
    {
        MyListIterator it = head;

        while (it)
        {
            if (it->data == data)
                return it;

            it = it->next;
        }

        return NULL;
    }

    void erase(MyListIterator it)
    {
        if (!it)
            return;

        if (it == tail)
            pop_back();
        else if (it == head)
            pop_front();
        else
        {
            Node<T> * toDel = it;
            Node<T> * prev = it->prev;
            Node<T> * next = it->next;

            prev->next = next;
            next->prev = prev;
            delete toDel;
        }
    }


    void print()
    {
        cout << "[";
        MyListIterator it = head;
        while (it)
        {
            cout << it->data << ", ";
            it = it->next;
        }

        cout << "]" << endl;
    }

    bool isEmpty() { return size == 0; }
    int len() {return size;}



private:
    Node<T> * head;
    Node<T> * tail;
    size_t size;
};

int main()
{
    cout << "Hello world!" << endl;

    MyList<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_front(4);
    myList.push_front(5);

    myList.print();

    cout << myList.front() << endl;
    cout << myList.back() << endl;
    myList.erase(myList.find(2));


    myList.print();
    myList.pop_front();
    myList.print();
    myList.pop_back();
    myList.print();
    myList.pop_front();
    myList.print();




    return 0;
}
