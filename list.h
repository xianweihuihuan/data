#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<list>
#include<stdlib.h>
#include<assert.h>

namespace me{
    template<class T>
    struct List_node 
    {
        T _data;
        List_node<T>* _next;
        List_node<T>* _prev;
        List_node(const T& data = T())
        :_data(data)
        ,_next(nullptr)
        ,_prev(nullptr)
        {}
    };
    template<class T>
    struct List_iterator{
        typedef List_node<T> Node;
        typedef List_iterator Self;
        Node* _node;
        List_iterator(Node* node)
        :_node(node)
        {}
        T& operator*(){
            return _node->_data;
        }
        Self& operator++(){
            _node = _node ->_next;
            return *this;
        }
        Self& operator++(int){
            _node = _node ->_next;
            return *this;
        }
        Self& operator--(){
            _node = _node ->_prev;
            return *this;
        }
        Self& operator--(int){
            _node = _node ->_prev;
            return *this;
        }
        bool operator!=(const Self& com){
            return _node != com._node;
        }
        bool operator==(const Self& com){
            return _node == com._node;
        }
    };
    template<class T>
    class list{
    private:
        typedef List_node<T> Node;
        Node* _head;
    public:
        typedef List_iterator<T> iterator;
        iterator begin(){
            return iterator(_head->_next);
        }
        iterator end(){
            return iterator(_head);
        } 
        void emptyinit(){
            _head = new Node();
            _head->_prev = _head;
            _head->_next = _head;
        }
        list(){
            emptyinit();
        }
        list(const list<T>& x){
            emptyinit();
            for(auto e: x){
                push_back(e);
            }
        }
        list(size_t n,const T& x){
            emptyinit();
            for(int i = 0;i<n;i++){
                push_back(x);
            }
        }
        void push_back(const T& x){
            Node* ne = new Node(x);
            Node* tail = _head->_prev;
            ne->_prev = tail;
            _head ->_prev = ne;
            tail->_next = ne;
            ne->_next = _head;
        }
        iterator insert(iterator pos,const T& data){
            Node* prev = pos._node->_prev;
            Node* pcur = pos._node;
            Node* th = new Node(data);
            prev->_next = th;
            th->_next = pcur;
            pcur->_prev = th;
            th->_prev = prev;
            return iterator(th);
        }
        iterator erase(iterator pos){
            assert(pos!=end());
            Node* prev = pos._node->_prev;
            Node* ptail = pos._node->_next;
            Node* tmp = pos._node;
            prev->_next = ptail;
            ptail->_prev = prev;
            delete[] tmp;
            return iterator(ptail);
        }
        void push_front(const T& data){
            insert(begin(),data);
        }
        void pop_back(){
            erase(_head->_prev);
        }
        ~list(){
            iterator it = begin();
            while(it!=end()){
                it = erase(it);
            }
            delete[] _head;
        }
    };
}