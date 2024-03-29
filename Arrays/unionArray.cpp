#include<iostream>
#include<vector>
using namespace std;
vector < int > sortedArray(vector < int > a, vector < int > b) {
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    vector <int> unionArr;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(unionArr.size()==0 || unionArr.back()!=a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else {
            if(unionArr.size()==0 || unionArr.back()!=b[j]){
                 unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
       if(unionArr.size()==0 || unionArr.back()!=a[i]){
            unionArr.push_back(a[i]);
            }
            i++; 
    }
    while(j<n2){
        if(unionArr.size()==0 || unionArr.back()!=b[j]){
            unionArr.push_back(b[j]);
            }
            j++;
    }
    return unionArr;
}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int> a(n1);
    for(int i=0;i<n1;i++) cin>>a[i];
    vector<int> b(n2);
    for(int j=0;j<n2;j++) cin>>b[j];
    vector<int> unionResult = sortedArray(a, b);
    for (int i = 0; i < unionResult.size(); i++) {
        cout << unionResult[i] << " ";
    }
    return 0;
}
