#include <iostream>
#include <vector>
#include <list>
#include <memory>

using namespace std;

template<class K, class V>
class Node{
public:
    K m_key;
    V m_value;

    Node(const K & k, const V &v): m_key(k), m_value(v) {}
    K & key() { return m_key; }
    V & value() { return m_value; }

};
template<class K>
struct KeyHash{
    unsigned long operator()(const K & key, unsigned long tableSize) const
    {
        return static_cast<unsigned long>(key) % tableSize;
    }
};

template<class K, class V, class F = KeyHash<K> >
class HashTable
{
public:
    static const int TABLE_SIZE = 100;
    vector<list<Node<K, V>>> m_table;
    int m_tableSize;
    F hashFunc;

    HashTable(int tableSize = TABLE_SIZE) : m_tableSize(tableSize)
    {
        m_table.resize(tableSize);
    }

    bool get(const K & key, V & value)
    {
        unsigned long hashValue = hashFunc(key, m_tableSize);

        if (m_table[hashValue].size() == 0)
            return false;

        for (auto & nPtr : m_table[hashValue])
        {
            if (nPtr.key() == key)
            {
                value = nPtr.value();
                return true;
            }
        }

        return false;
    }

    void put(const K & key, const V & value)
    {
        unsigned long hashValue = hashFunc(key, m_tableSize);

        if (m_table[hashValue].size() == 0)
        {
            m_table[hashValue].push_front(Node<K, V>(key, value));
        }
        else
        {
            for (auto & nPtr : m_table[hashValue])
            {
                if (nPtr.key() == key)
                {
                    nPtr.value() = value;
                    return;
                }
            }

            m_table[hashValue].push_front(Node<K, V>(key, value));
        }
    }

    void remove(const K & key)
    {
        unsigned long hashValue = hashFunc(key, m_tableSize);

        if (m_table[hashValue].size() == 0)
            return;

        for (auto it = m_table[hashValue].begin(); it != m_table[hashValue].end(); it++)
        {
            if (it->key() == key)
            {
                m_table[hashValue].erase(it);
                return;
            }
        }
    }


};

int main()
{
    cout << "Hello world!" << endl;
    HashTable<int, string> hashmap;
    hashmap.put(1, "val1");
    hashmap.put(2, "val2");
    hashmap.put(3, "val3");

    string value;
    hashmap.get(2, value);
    cout << value << endl;
    bool res = hashmap.get(3, value);
    if (res)
        cout << value << endl;
    hashmap.remove(3);
    res = hashmap.get(3, value);
    if (res)
        cout << value << endl;


    return 0;
}
