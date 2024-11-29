#include<iostream>
#include<assert.h>
#include<string>
#include<string.h>
#include<stdbool.h>


namespace xw{
    class string{
    public:
        typedef char* iterator;
        typedef const char* const_iterator;
        iterator begin(){
            return _str;
        }
        iterator end(){
            return _str+_sz;
        }
        const iterator begin()const{
            return _str;
        }
        const iterator end()const{
            return _str+_sz;
        }
        string(const char* str = "");
        string(size_t n, const char ch);
        string(const string& str);
        void clear();
        void reserve(size_t n);
        void push_back(const char ch);
        void append(const char* str);
        const char* c_str(){
            return _str;
        }
        string& operator +=(const char* str);
        string& operator +=(const char ch);
        void insert(size_t pos,size_t n,const char ch);
        void insert(size_t pos,const char* str);
        void erase(size_t pos = 0,size_t len = npos);
        size_t find(const char ch,size_t pos = 0)const;
        size_t find(const char* str,size_t pos = 0)const;
        size_t size()const{
            return _sz;
        }
        size_t capacity()const{
            return _alloc;
        }
        char& operator [](size_t pos){
            assert(pos<_sz);
            return _str[pos];
        }
        const char& operator [](size_t pos)const{
            assert(pos<_sz);
            return _str[pos];
        }
        string substr(size_t pos,size_t = npos);
        bool operator ==(const string& str)const{
            return (strcmp(_str,str._str)==0);
        }
        bool operator >(const string& str)const{
            return (strcmp(_str,str._str)>0);
        }
        bool operator >=(const string& str)const{
            return (*this==str)||(*this>str);
        }
        bool operator <(const string& str)const{
            return !(*this>=str);
        }
        bool operator <=(const string& str)const{
            return !(*this>str);
        }
        bool operator !=(const string& str)const{
            return !(*this==str);
        }
        string& operator=(const string& str);
        std::istream& getline(std::istream& in,const char ch ='\n');
        ~string();
    protected:
        char* _str;
        size_t _sz;
        size_t _alloc;
        const static size_t npos;
    };
    std::ostream& operator<<(std::ostream&out,const string& s);
    std::istream& operator>>(std::istream&in,string& s);

}