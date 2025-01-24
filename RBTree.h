#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>

enum color
{
    Red,
    Black
};
template <class k, class v>
struct RBTreeNode
{
    std::pair<k, v> _kv;
    color _col;
    RBTreeNode<k, v> *_parent;
    RBTreeNode<k, v> *_left;
    RBTreeNode<k, v> *_right;

    RBTreeNode(const std::pair<k, v> &tmp)
        : _kv(tmp), _parent(nullptr), _left(nullptr), _right(nullptr)
    {
    }
};

template <class k, class v>
class RBTree
{
protected:
    typedef RBTreeNode<k, v> Node;

    void RotateR(Node *parent)
    {
        Node *subL = parent->_left;
        Node *subLR = subL->_right;
        Node *ppnode = parent->_parent;
        parent->_left = subLR;
        if (subLR)
        {
            subLR->_parent = parent;
        }
        subL->_right = parent;
        parent->_parent = subL;
        if (_root == parent)
        {
            _root = subL;
            subL->_parent = nullptr;
        }
        else
        {
            if (ppnode->_left == parent)
            {
                ppnode->_left = subL;
            }
            else
            {
                ppnode->_right = subL;
            }
            subL->_parent = ppnode;
        }
    }
    void RotateL(Node *parent)
    {
        Node *subR = parent->_right;
        Node *subRL = subR->_left;
        Node *ppndoe = parent->_parent;
        parent->_right = subRL;
        if (subRL)
        {
            subRL->_parent = parent;
        }
        subR->_left = parent;
        parent->_parent = subR;
        if (parent == _root)
        {
            _root = subR;
            subR->_parent = nullptr;
        }
        else
        {
            if (ppndoe->_left == parent)
            {
                ppndoe->_left = subR;
            }
            else
            {
                ppndoe->_right = subR;
            }
            subR->_parent = ppndoe;
        }
    }

    void _Print(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        _Print(node->_left);
        std::cout << node->_kv.first << ":" << node->_kv.second << std::endl;
        _Print(node->_right);
    }

    int _Size(Node *root)
    {
        if (root == nullptr)
            return 0;

        return _Size(root->_left) + _Size(root->_right) + 1;
    }

    int _Height(Node *root)
    {
        if (root == nullptr)
            return 0;
        int leftHeight = _Height(root->_left);
        int rightHeight = _Height(root->_right);

        return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
    }

public:
    void Print()
    {
        _Print(_root);
        std::cout << std::endl;
    }

    Node *Find(const k &key)
    {
        Node *cur = _root;
        while (cur)
        {
            if (cur->_kv.first < key)
            {
                cur = cur->_right;
            }
            else if (cur->_kv.first > key)
            {
                cur = cur->_left;
            }
            else
            {
                return cur;
            }
        }
        return nullptr;
    }

    int Height()
    {
        return _Height(_root);
    }

    int Size()
    {
        return _Size(_root);
    }

    bool insert(const std::pair<k, v> &tmp)
    {
        if (_root == nullptr)
        {
            _root = new Node(tmp);
            _root->_col = Black;
            return true;
        }
        Node *parent = nullptr;
        Node *cur = _root;
        while (cur)
        {
            if (tmp.first < cur->_kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (tmp.first > cur->_kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                return false;
            }
        }

        cur = new Node(tmp);
        cur->_col = Red;
        if (cur->_kv.first < parent->_kv.first)
        {
            parent->_left = cur;
        }
        else
        {
            parent->_right = cur;
        }
        cur->_parent = parent;

        while (parent && parent->_col == Red)
        {
            Node *grandfather = parent->_parent;
            if (grandfather->_left == parent)
            {
                Node *uncle = grandfather->_right;
                if (uncle && uncle->_col == Red)
                {
                    parent->_col = uncle->_col = Black;
                    grandfather->_col = Red;
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else
                {
                    if (cur == parent->_left)
                    {
                        RotateR(grandfather);
                        grandfather->_col = Red;
                        parent->_col = Black;
                    }
                    else
                    {
                        RotateL(parent);
                        RotateR(grandfather);
                        cur->_col = Black;
                        grandfather->_col = Red;
                    }
                    break;
                }
            }
            else
            {
                Node *uncle = grandfather->_left;
                if (uncle && uncle->_col == Red)
                {
                    parent->_col = uncle->_col = Black;
                    grandfather->_col = Red;
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else
                {
                    if (cur == parent->_right)
                    {
                        RotateL(grandfather);
                        parent->_col = Black;
                        grandfather->_col = Red;
                    }
                    else
                    {
                        RotateR(parent);
                        RotateL(grandfather);
                        cur->_col = Black;
                        grandfather->_col = Red;
                    }
                    break;
                }
            }
        }
        _root->_col = Black;
        return true;
    }

protected:
    Node *_root = nullptr;
};