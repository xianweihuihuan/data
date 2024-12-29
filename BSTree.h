#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

namespace me
{
    template <class K>
    struct BSTreenode
    {
        K _key;
        BSTreenode *_left;
        BSTreenode *_right;

        BSTreenode(const K &x)
            : _key(x), _left(nullptr), _right(nullptr)
        {
        }
    };
    template <class K>
    class BSTree
    {
    protected:
        typedef BSTreenode<K> Node;
        Node *_root = nullptr;
        void _Print(Node *root)
        {
            if (root == nullptr)
            {
                return;
            }
            _Print(root->_left);
            std::cout << root->_key << " ";
            _Print(root->_right);
        }

    public:
        bool insert(const K &x)
        {
            if (_root == nullptr)
            {
                _root = new Node(x);
                return true;
            }
            Node *parent = nullptr;
            Node *cur = _root;
            while (cur)
            {
                if (cur->_key > x)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if (cur->_key <= x)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else
                {
                    return false;
                }
            }
            cur = new Node(x);
            if (parent->_key > cur->_key)
            {
                parent->_left = cur;
            }
            else
            {
                parent->_right = cur;
            }
            return true;
        }
        bool find(const K &x)
        {
            Node *cur = _root;
            while (cur)
            {
                if (cur->_key > x)
                {
                    cur = cur->_left;
                }
                else if (cur->_key < x)
                {
                    cur = cur->_right;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
        void Print()
        {
            _Print(_root);
            std::cout << std::endl;
        }
        bool earse(const K &x)
        {
            Node *parent = nullptr;
            Node *cur = _root;
            while (cur)
            {
                if (cur->_key > x)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if (cur->_key < x)
                {
                    parent = cur;
                    cur = cur->_right;
                }
                else
                {
                    if (cur->_left == nullptr)
                    {
                        if (cur == _root)
                        {
                            _root = cur->_right;
                        }
                        else
                        {
                            if (parent->_left == cur)
                            {
                                parent->_left = cur->_right;
                            }
                            else
                            {
                                parent->_right = cur->_right;
                            }
                        }
                        delete cur;
                    }
                    else if (cur->_right == nullptr)
                    {
                        if (cur == _root)
                        {
                            _root = cur->_left;
                        }
                        else
                        {
                            if (parent->_right == cur)
                            {
                                parent->_right = cur->_left;
                            }
                            else
                            {
                                parent->_left = cur->_left;
                            }
                        }
                        delete cur;
                    }
                    else
                    {
                        Node *minRightparent = cur;
                        Node *minRight = cur->_right;
                        while (minRight->_left)
                        {
                            minRightparent = minRight;
                            minRight = minRight->_left;
                        }
                        cur->_key = minRight->_key;
                        if (minRightparent->_left == minRight)
                        {
                            minRightparent->_left = minRight->_right;
                        }
                        else
                        {
                            minRightparent->_right = minRight->_right;
                        }
                        delete minRight;
                    }
                    return true;
                }
            }
            return false;
        }
    };
}