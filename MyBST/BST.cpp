#include <iostream>

using namespace std;

//UNBALANCED Binary Search Tree
//It is unreasonable to expect candidate to come up with
//the implementation of a balanced binary tree during an 45 min interview.
//See MyAVLTree, MyRedBlackTree


struct TreeNode
{
    int cnt;
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v): cnt(1), val(v) {}
};

class BST
{
public:
    TreeNode * root;
    BST(): root(NULL) {}

    TreeNode * addHelper(TreeNode * root, int node)
    {
        if (!root)
            return new TreeNode(node);

        if (root->val == node)
            root->cnt++;
        else if (root->val > node)
            root->left = addHelper(root->left, node);
        else
            root->right = addHelper(root->right, node);

        return root;
    }

    void addNode(int node)
    {
        root = addHelper(root, node);
    }

    TreeNode * deleteHelper(TreeNode * root, int node)
    {
        if (!root)
            return NULL;;

        if (root->val == node)
        {
            if (root->cnt > 1)
                root->cnt--;
            else
            {
                //real delete
                if (!root->left && !root->right)
                    return NULL;
                else if (!root->right)
                    return root->left;
                else if (!root->left)
                    return root->right;
                else
                {
                    TreeNode * n = root->right;
                    while (n->left)
                        n = n->left;
                    n->left = root->left;

                    return root->right;
                }
            }
        }
        else if (root->val > node)
            root->left = deleteHelper(root->left, node);
        else
            root->right = deleteHelper(root->right, node);

        return root;
    }

    void deleteNode(int node)
    {
        root = deleteHelper(root, node);
    }

    bool findHelper(TreeNode * root, int node)
    {
        if (!root)
            return false;

        if (root->val == node)
            return true;
        else if (root->val > node)
            return findHelper(root->left, node);
        else
            return findHelper(root->right, node);
    }

    bool find(int node)
    {
        return findHelper(root, node);
    }

    void preOrderPrintHelper(TreeNode * root)
    {
        if (!root)
        {
            cout << "#" << ",";
            return;
        }

        cout << root->val;
        if (root->cnt > 1)
            cout << "(" << root->cnt << ")";

        cout << ",";

        preOrderPrintHelper(root->left);
        preOrderPrintHelper(root->right);
    }

    void inOrderPrintHelper(TreeNode * root)
    {
        if (!root)
            return;

        inOrderPrintHelper(root->left);

        cout << root->val;
        if (root->cnt > 1)
            cout << "(" << root->cnt << ")";

        cout << ",";

        inOrderPrintHelper(root->right);

    }
    void inOrderPrint()
    {
        inOrderPrintHelper(root);
    }
    void preOrderPrint()
    {
        preOrderPrintHelper(root);
    }
};

int main()
{
    cout << "Hello world!" << endl;

    BST bst;
    bst.addNode(3);

    bst.addNode(5);
    bst.addNode(5);
    bst.addNode(1);
    bst.addNode(9);
    bst.addNode(8);

    bst.inOrderPrint();
    cout << endl;
    bst.preOrderPrint();
    cout << endl;


    bst.deleteNode(5);
    bst.inOrderPrint();
    cout << endl;
    bst.preOrderPrint();
    cout << endl;
    bst.deleteNode(5);
    bst.inOrderPrint();
    cout << endl;
    bst.preOrderPrint();
    cout << endl;
    bst.deleteNode(3);
    bst.inOrderPrint();
    cout << endl;
    bst.preOrderPrint();
    cout << endl;
    return 0;
}
