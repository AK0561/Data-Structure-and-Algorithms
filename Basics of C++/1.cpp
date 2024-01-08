// #include<iostream>
// using namespace std;
// int main()
// {
//     // cout<<"Hello World !";
//     string str;
//     getline(cin,str); //This built-in function helps us to print the strings in which there is a space in between 
//     cout<<str;
//     return 0;
// }

//pass by value
// #include<iostream>
// using namespace std;
// void doSomething(int num){
//     cout<<num<<endl;
//     num+=5;
//     cout<<num<<endl;
//     num+=5;
//     cout<<num<<endl;
// }
// int main()
// {
//     int num=10;
//     doSomething(num);//At this point it sends a copy value of the original value to the above function and thus referred to as pass by value 
//     cout<<num<<endl;//and at this point it prints the original value of the num i.e. 10.
//     return 0;
// }


//pass by reference
//arrays always pass the value by reference 
#include<iostream>
using namespace std;
void doSomething(int &num){ // & helps us to take the original value of this integer instead of a copied value as it specifies the address of the value where it's stored.
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
    num+=5;
    cout<<num<<endl;
}
int main()
{
    int num=10;
    doSomething(num);
    cout<<num<<endl;
    return 0;
}
