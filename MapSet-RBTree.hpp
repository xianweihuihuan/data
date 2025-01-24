#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>

enum color
{
    Red,
    Black
};
template <class data>
struct RBTreeNode
{
    data _data;
    color _col;
    RBTreeNode<data> *_parent;
    RBTreeNode<data> *_left;
    RBTreeNode<data> *_right;

    RBTreeNode(const data &tmp)
        : _data(tmp), _parent(nullptr), _left(nullptr), _right(nullptr)
    {
    }
};
template <class data, class Ref, class Ptr>
struct RBTreeIterator
{
    typedef RBTreeNode<data> Node;
    typedef RBTreeIterator<data, Ref, Ptr> Self;
    Node *_node;
    Node *_root;

    RBTreeIterator( Node *node,  Node *root)
        : _node(node), _root(root)
    {
    }

    Ref &operator*()
    {
        return _node->_data;
    }

    Ptr operator->()
    {
        return &_node->_data;
    }

    Self &operator++()
    {
        if (_node->_right)
        {
            Node *minleft = _node->_right;
            while (minleft->_left)
            {
                minleft = minleft->_left;
            }
            _node = minleft;
        }
        else
        {
            Node *cur = _node;
            Node *parent = cur->_parent;
            while (parent && parent->_right == cur)
            {
                cur = parent;
                parent = parent->_parent;
            }
            _node = parent;
        }
        return *this;
    }

    Self &operator--()
    {
        if (_node == nullptr)
        {
            Node *maxright = _root;
            while (maxright && maxright->_right)
            {
                maxright = maxright->_right;
            }
            _node = maxright;
        }
        else if (_node->_left)
        {
            Node *maxright = _node->_left;
            while (maxright->_right)
            {
                maxright = maxright->_right;
            }
            _node = maxright;
        }
        else
        {
            Node *cur = _node;
            Node *parent = cur->_parent;
            while (parent && parent->_left == cur)
            {
                cur = parent;
                parent = parent->_parent;
            }
            _node = parent;
        }
        return *this;
    }

    bool operator!=(const Self &s)
    {
        return _node != s._node;
    }

    bool operator==(const Self &s)
    {
        return _node == s._node;
    }
};

template <class k, class data, class Keyofdata>
class RBTree
{
protected:
    typedef RBTreeNode<data> Node;

public:
    typedef RBTreeIterator<data, data &, data *> Iterator;
    typedef RBTreeIterator<data, const data &, const data *> Const_Iterator;

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

public:
    Iterator Begin()
    {
        Node *cur = _root;
        while (cur && cur->_left)
        {
            cur = cur->_left;
        }
        Iterator ret(cur, _root);
        return ret;
    }

    Iterator End()
    {
        Iterator ret(nullptr, _root);
        return ret;
    }

    Const_Iterator Begin() const
    {
        Node *cur = _root;
        while (cur && cur->_left)
        {
            cur = cur->_left;
        }
        Const_Iterator ret(cur, _root);
        return ret;
    }

    Const_Iterator End() const
    {
        Const_Iterator ret(nullptr, _root);
        return ret;
    }

    Iterator Find(const k &key)
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
                Iterator ret(cur,_root);
                return ret;
            }
        }
        return End();
    }

    std::pair<Iterator, bool> insert(const data &tmp)
    {
        if (_root == nullptr)
        {
            _root = new Node(tmp);
            _root->_col = Black;
            Iterator rr(_root, _root);
            std::pair<Iterator, bool> ret(rr, true);
            return ret;
        }
        Node *parent = nullptr;
        Keyofdata kot;
        Node *cur = _root;
        while (cur)
        {
            if (kot(tmp) < kot(cur->_data))
            {
                parent = cur;
                cur = cur->_left;
            }
            else if (kot(tmp) > kot(cur->_data))
            {
                parent = cur;
                cur = cur->_right;
            }
            else
            {
                Iterator rr(cur, _root);
                std::pair<Iterator, bool> ret(rr, false);
                return ret;
            }
        }
        Node *newcur = cur;
        cur = new Node(tmp);
        cur->_col = Red;
        if (kot(cur->_data) < kot(parent->_data))
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

        Iterator rr(newcur, _root);
        std::pair<Iterator, bool> ret(rr, true);
        return ret;
    }

protected:
    Node *_root = nullptr;
};