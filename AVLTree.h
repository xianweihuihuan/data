#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <assert.h>

template <class k, class v>
struct AVLTree_node
{
    std::pair<k, v> _kv;
    AVLTree_node<k, v> *_parent;
    AVLTree_node<k, v> *_left;
    AVLTree_node<k, v> *_right;
    int _bf; // 平衡因子

    AVLTree_node(const std::pair<k, v> &tmp)
        : _kv(tmp), _parent(nullptr), _left(nullptr), _right(nullptr), _bf(0)
    {
    }
};
template <class k, class v>
class AVLTree
{
protected:
    typedef AVLTree_node<k, v> Node;
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
        parent->_bf = 0;
        subL->_bf = 0;
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
        parent->_bf = 0;
        subR->_bf = 0;
    }

    void RotateLR(Node *parent)
    {
        Node *subL = parent->_left;
        Node *subLR = subL->_right;
        int bf = subLR->_bf;
        RotateL(parent->_left);
        RotateR(parent);
        if (bf == -1)
        {
            subL->_bf = 0;
            subLR->_bf = 0;
            parent->_bf = 1;
        }
        else if (bf == 1)
        {
            subL->_bf = -1;
            subLR->_bf = 0;
            parent->_bf = 0;
        }
        else if (bf == 0)
        {
            subL->_bf = 0;
            subLR->_bf = 0;
            parent->_bf = 0;
        }
        else
        {
            assert(false);
        }
    }

    void RotateRL(Node *parent)
    {
        Node *subR = parent->_right;
        Node *subRL = subR->_left;
        int bf = subRL->_bf;
        RotateR(parent->_right);
        RotateL(parent);
        if (bf == 0)
        {
            subR->_bf = 0;
            subRL->_bf = 0;
            parent->_bf = 0;
        }
        else if (bf == 1)
        {
            subR->_bf = 0;
            subRL->_bf = 0;
            parent->_bf = -1;
        }
        else if (bf == -1)
        {
            subR->_bf = 1;
            subRL->_bf = 0;
            parent->_bf = 0;
        }
        else
        {
            assert(false);
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

    bool _ISAVLtree(Node *node)
    {
        if (node == nullptr)
        {
            return true;
        }
        int leftheight = _Height(node->_left);
        int rightheight = _Height(node->_right);
        int diff = rightheight - leftheight;
        if (abs(diff) >= 2)
        {
            std::cout << node->_kv.first << "高度差错误" << std::endl;
            return false;
        }
        if (node->_bf != diff)
        {
            std::cout << node->_kv.first << "平衡因子错误" << std::endl;
            return false;
        }
        return _ISAVLtree(node->_left) && _ISAVLtree(node->_right);
    }

public:
    bool insert(const std::pair<k, v> &kv)
    {
        if (_root == nullptr)
        {
            Node *newnode = new Node(kv);
            _root = newnode;
            return true;
        }
        Node *parent = nullptr;
        Node *cur = _root;
        while (cur)
        {
            if (kv.first > cur->_kv.first)
            {
                parent = cur;
                cur = cur->_right;
            }
            else if (kv.first < cur->_kv.first)
            {
                parent = cur;
                cur = cur->_left;
            }
            else
            {
                return false;
            }
        }
        cur = new Node(kv);
        if (kv.first > parent->_kv.first)
        {
            parent->_right = cur;
        }
        else
        {
            parent->_left = cur;
        }
        cur->_parent = parent;
        while (parent)
        {
            if (cur == parent->_right)
            {
                parent->_bf++;
            }
            else if (cur == parent->_left)
            {
                parent->_bf--;
            }
            if (parent->_bf == 0)
            {
                break;
            }
            else if (parent->_bf == 1 || parent->_bf == -1)
            {
                cur = parent;
                parent = parent->_parent;
            }
            else if (parent->_bf == 2 || parent->_bf == -2)
            {
                if (parent->_bf == -2 && cur->_bf == -1)
                {
                    RotateR(parent);
                }
                else if (parent->_bf == 2 && cur->_bf == 1)
                {
                    RotateL(parent);
                }
                else if (parent->_bf == -2 && cur->_bf == 1)
                {
                    RotateLR(parent);
                }
                else if (parent->_bf == 2 && cur->_bf == -1)
                {
                    RotateRL(parent);
                }
                else
                {
                    assert(false);
                }
                break;
            }
            else
            {
                perror("The AVLTree has already been breaked");
                assert(false);
            }
        }
        return false;
    }

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

    bool ISAVLTree()
    {
        return _ISAVLtree(_root);
    }

protected:
    Node *_root = nullptr;
};