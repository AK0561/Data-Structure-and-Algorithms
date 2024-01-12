#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int MaxiElem(vector<int> &arr){
    int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
        }
    return maxi;
    }
int SumElem(vector<int> &arr){
    int n=arr.size();
    int sum1=0;
    for(int i=0;i<n;i++){
        sum1+=arr[i];
        }
    return sum1;
    }
int countNoStudents(vector<int> & arr,int pages){
    int n=arr.size();
    int stud=1,pagesStud=0;
    for(int i=0;i<n;i++){
        if(pagesStud+arr[i]<=pages){
            pagesStud+=arr[i];
        }
        else{
            stud++;
            pagesStud=arr[i];
        }
    }
    return stud;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int low = MaxiElem(arr);
    int high = SumElem(arr);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countNoStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
int main(){
    int n,students;
    cin>>n>>students;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<findPages(arr,n,students);
    return 0;
}