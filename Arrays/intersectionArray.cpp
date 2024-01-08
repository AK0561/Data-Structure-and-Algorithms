#include<iostream>
#include<vector>
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i=0;
	int j=0;
	vector <int> ans;
	while(i<n && j<m){
		if(arr1[i]<arr2[j]){
			i++;
		}
		else if(arr2[j]<arr1[i]){
			j++;
		}
		else {
			ans.push_back(arr1[i]);
			i++;
			j++;
		}
	}
	return ans;
}
int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int> a(n1);
    for(int i=0;i<n1;i++) cin>>a[i];
    vector<int> b(n2);
    for(int j=0;j<n2;j++) cin>>b[j];
    vector<int> IntersectResult = findArrayIntersection(a,n1,b,n2);
    for (int i = 0; i < IntersectResult.size(); i++) {
        cout << IntersectResult[i] << " ";
    }
    return 0;
}
