#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>

namespace me{
    template<class T,class al = std::vector<T>>
    class priority_queue{
    private:
        al _data;
    public:
        void adjustdown(size_t parent){
            size_t child = 2 *parent + 1;
            while(child<_data.size()){
                if(child+1 < _data.size()&&_data[child+1]>_data[child]){
                    child++;
                }
                if(_data[child]>_data[parent]){
                    std::swap(_data[child],_data[parent]);
                    parent = child;
                    child = 2* parent + 1;
                }else{
                    break;
                }
            }
        }
        void adjustup(size_t child){
            size_t parent = (child-1)/2;
            while(child>0){
                if(_data[child]>_data[parent]){
                    std::swap(_data[child],_data[parent]);
                    child = parent;
                    parent = (child -1)/2;
                }else{
                    break;
                }
            }
        }
        void push(const T& x){
            _data.push_back(x);
            adjustup(_data.size()-1);
        }
        T top(){
            return _data[0];
        }
        void pop(){
            std::swap(_data[0],_data[_data.size()-1]);
            _data.pop_back();
            adjustdown(0);
        }
        bool empty(){
            return _data.empty();
        }
        size_t size(){
            return _data.size();
        }
    };
}