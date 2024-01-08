#include<iostream>
using namespace std;
int count=0;
void print()
{
    if(::count == 3) return;  // :: use this operator to specify count as a global variable
    cout<<::count<<endl;;
    ::count++;
    print();
}
int main(){
    print();
    return 0;
}