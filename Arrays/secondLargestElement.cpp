#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int secondLargest(vector<int> &a,int n){
    int largest=a[0];
    int slargest=-1;
    for(int i=1;i<n;i++){
        if(a[i]>largest){
            //Update slargest to the current value of largest (the previous largest).
            slargest=largest;
           //Update largest to the new value of a[i].
            largest=a[i];
        }
        else if(a[i]>largest && a[i]<slargest){
            slargest=a[i];
        }
    }
    return slargest;
}

int secondSmallest(vector<int> &a,int n){
    int smallest=a[0];
    int ssmallest=INT_MAX;
    for(int i=1;i<n;i++){
        if(a[i]<smallest){
            ssmallest=smallest;
            smallest=a[i];
        }
        else if(a[i]!=smallest && a[i]<ssmallest){
            ssmallest=a[i];
        }
    }
    return ssmallest;
}
vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int slargest=secondLargest(a,n);
    int ssmallest=secondSmallest(a,n);
    return {slargest,ssmallest};
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)  cin>>arr[i];
    vector<int> result = getSecondOrderElements(n, arr);
    cout << "Second Largest Element: " << result[0] << endl;
    cout << "Second Smallest Element: " << result[1] << endl;
    return 0;
}