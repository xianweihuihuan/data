#include"shared_ptr.hpp"

using namespace std;
int main(){
    shared_ptr<string> st(new string);
    (*st) += "1111111111111111111111111111";
    cout<<(*st)<<endl;
    st->clear();
    (*st) += "2123213213213213312321231321";
    shared_ptr<string> sp(st);
    cout<<(*sp)<<endl;
    shared_ptr<string> so(new string[10], [](string* ptr){delete[] ptr;});
    
}