// #include<iostream>
// #include <vector>
// #include <stack>
// using namespace std;

// vector<int> nextGreaterElement(vector<int>& arr, int n) {
//     vector<int> nge(n, -1); 
//     stack<int> st;
    
//     for(int i = 0; i < n; i++) {
//         while(!st.empty() && arr[st.top()] < arr[i]) {
//             nge[st.top()] = arr[i];
//             st.pop();
//         }
//         st.push(i);
//     }
    
//     return nge;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for( int i = 0; i < n ; i++) cin>>arr[i];
//     vector <int> result = nextGreaterElement(arr,n);
//     for(int i = 0 ; i < n ; i++) cout<<result[i]<< " ";
//     return 0;
// }


//Circular Array Implementation
#include<iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n) {
    vector<int> nge(n, -1); 
    stack<int> st;
    
    for(int i = 0; i < 2*n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i%n]) {
            nge[st.top()] = arr[i%n];
            st.pop();
        }
        if(i<n){
          st.push(i%n);
        }
    }
    
    return nge;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for( int i = 0; i < n ; i++) cin>>arr[i];
    vector <int> result = nextGreaterElement(arr,n);
    for(int i = 0 ; i < n ; i++) cout<<result[i]<< " ";
    return 0;
}