#include"string.h"

namespace xw{
    const size_t string::npos = -1;

    string::string(const char* str)
        :_str(new char[strlen(str)+1])
        ,_sz(strlen(str))
        ,_alloc(_sz)
    {
        strcpy(_str,str);
    }
    string::string(size_t n,const char ch)
        :_str(new char[n+1])
        ,_sz(n)
        ,_alloc(n)
    {
        for(size_t i = 0;i < n;i++){
            _str[i] = ch;
        }
        _str[_sz] = '\0';
    }
    string::string(const string& str){
        _str = new char[str._alloc+1];
        strcpy(_str,str._str);
        _alloc = str._alloc;
        _sz = str._sz;
    }
    void string::clear(){
        _sz = 0;
        _str[0] = '\0';
    }
    void string::reserve(size_t n){
        if(n<_sz){
            n = _sz;
        }
        char*tmp = new char[n+1];
        strcpy(tmp,_str);
        delete[] _str;
        _str = tmp;
        _alloc = n;
    }
    void string::push_back(const char ch){
        if(_sz ==_alloc){
            int newn = (_alloc==0)?4:_alloc*2;
            reserve(newn);
        }
        _str[_sz] = ch;
        _sz++;
        _str[_sz] = '\0';
    }
    void string::append(const char* str){
        size_t len = strlen(str);
        if(_sz+len>_alloc){
            size_t newn = 2*_alloc;
            if(newn<_sz+len){
                newn = _sz+len;
            }
            reserve(newn);
        }
        strcpy(_str+_sz,str);
        _sz += len;
    }
    string&  string::operator +=(const char* str){
        append(str);
        return *this;
    }
    string& string::operator+=(const char ch){
        push_back(ch);
        return *this;
    }
    void string::insert(size_t pos,size_t n,const char ch){
        assert(pos<=_sz);
        assert(n>0);
        if(_sz+n>_alloc){
            size_t newn = 2*_alloc;
            if(newn<_sz+n){
                newn = _sz+n;
            }
            reserve(newn);
        }
        size_t end = _sz + n;
        for(;end>=pos+n;end--){
            _str[end] = _str[end-n];
        }
        for(int i = 0;i<n;i++){
            _str[pos+i] = ch;
        }
        _sz+=n;
    }
    void string::insert(size_t pos,const char*str){
        size_t len = strlen(str);
        insert(pos,len,'x');
        for(int i = 0;i<len;i++){
            _str[pos+i] = str[i];
        }
    }
    void string::erase(size_t pos,size_t n){
        if(n>_sz-pos){
            _sz = pos;
            _str[pos] = '\0';
            return;
        }
        size_t head = pos;
        for(;head<=_sz-n;head++){
            _str[head] = _str[head+n];
        }
        _sz-=n;
    }
    size_t string::find(const char ch,size_t pos)const{
        for(size_t i = pos;i<_sz;i++){
            if(_str[i]==ch){
                return i ;
            }
        }
        return npos;
    }
    size_t string::find(const char* str,size_t pos)const{
        char* tmp = strstr(_str+pos,str);
        if(tmp==NULL){
            return npos;
        }
        else{
            return tmp-_str;
        }
    }
    string string::substr(size_t pos,size_t len){
        size_t leftlen = _sz - pos;
        if(len>leftlen){
            len = leftlen;
        }
        string tmp;
        tmp.reserve(len);
        for(size_t i = 0;i<len;i++){
            tmp += _str[pos+i];
        }
        return tmp;
    }
    string& string::operator = (const string&str){
        delete[] _str;
        char*tmp = new char[str._alloc];
        strcpy(tmp,str._str);
        _sz = str._sz;
        _alloc = str._alloc;
    }
    string::~string(){
        delete[] _str;
        _sz = 0;
        _alloc = 0;
    }
    std::ostream& operator<<(std::ostream&out,const string s){
        for(auto tmp:s){
            out<<tmp;
        }
        return out;
    }
    std::istream& operator>>(std::istream& in,string s){
        s.clear();
        const size_t N = 1024;
        char buff[N];
        int i = 0;
        char ch = in.get();
        while(ch != ' '&&ch != '\n'){
            buff[i++] = ch;
            if(i==N-1){
                buff[N-1] = '\0';
                s+=buff;
                i = 0;
            }
            ch = in.get();
        }
        if(i>0){
            buff[i] = '\0';
            s += buff;
        }
        return in;
    }
    std::istream& string::getline(std::istream&in,const char ch){
        clear();
        const size_t N = 1024;
        char buff[N];
        int i = 0;
        char tmp = in.get();
        while(tmp!=ch){
            buff[i++] = tmp;
            if(i==N-1){
                buff[N-1] = '\0';
                *this+=buff;
                i= 0;
            }
            tmp = in.get();
        }
        if(i>0){
            buff[i] = '\0';
            *this += buff;
        }
        return in;
    }
}