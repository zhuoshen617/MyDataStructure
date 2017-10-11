#include <iostream>
#include <vector>
using namespace std;

struct TrieNode
{
    int cnt;
    bool isEnd;
    vector<TrieNode *> children;
    TrieNode(): cnt(0), isEnd(false) {children.resize(26);};
};


class Trie
{
public:
    TrieNode * root;
    Trie()
    {
        root = new TrieNode();
    }

    void add(const string & str)
    {
        TrieNode * node = root;
        for (char c: str)
        {
            if (!node->children[c - 'a'])
                node->children[c-'a'] = new TrieNode();

            node = node->children[c-'a'];
            node->cnt++;
        }

        node->isEnd = true;
    }

    bool search(const string & str)
    {
        TrieNode * node = root;
        for (char c: str)
        {
            if (!node->children[c-'a'])
                return false;

            node = node->children[c-'a'];
        }

        return node->isEnd;
    }

    bool prefixSearch(const string & str)
    {
        TrieNode * node = root;
        for (char c: str)
        {
            if (!node->children[c-'a'])
                return false;

            node = node->children[c-'a'];
        }

        return true;
    }

    void deleteByPrefix()
    {
        //printByPrefix
        //deleteWord
    }

    bool deleteHelper(const string& str, int start, TrieNode * node)
    {
        if (!node)
            return false;

        if (start == str.size())
        {
            if (node->isEnd)
            {
                node->isEnd = false;
                node->cnt--;
                return true;
            }

            return false;
        }

        if (deleteHelper(str, start+1, node->children[str[start] - 'a']))
        {
            if (node->children[str[start] - 'a']->cnt == 0)
            {
                delete node->children[str[start] - 'a'];
                node->children[str[start] - 'a'] = NULL;
            }

            return true;
        }

        return false;

    }

    bool deleteWord(const string& str)
    {
        return deleteHelper(str, 0, root);
    }

    void printByPrefix(const string & prefix)
    {
        TrieNode * node = root;
        for (char c : prefix)
        {
            if (!node->children[c-'a'])
                return;

            node = node->children[c-'a'];
        }

        print(prefix, node);
    }

    void print(string str, TrieNode * node)
    {
        if (!node)
            return;

        if (node->isEnd)
            cout << str << endl;

        for (int i = 0; i < root->children.size(); i++)
        {
            print(str + string(1, 'a' +i), node->children[i]);
        }
    }

    void printAll()
    {
        print("", root);
    }

};
int main()
{
    cout << "Hello world!" << endl;
    Trie trie;
    trie.add("abc");
    trie.add("ab");
    trie.add("abd");
    trie.add("acd");
    trie.add("aced");
    trie.add("acea");

    trie.deleteWord("a");
    cout << endl;
    trie.printByPrefix("");

    return 0;
}
