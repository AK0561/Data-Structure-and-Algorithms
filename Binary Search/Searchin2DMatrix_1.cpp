#include<iostream>
using namespace std;
bool searchMatrix(vector<vector<int> >& mat, int target) {
    int n=mat.size();
    int m=mat[0].size();
    int low=0,high=(n*m)-1;
    while(low<=high){
        int mid=(low+high);
        int row=mid/m,col=mid%m;
        if(mat[row][col]==target) return true;
        else if(mat[row][col]<target) low=mid+1;
        else high=mid-1;
    }
    return false;    
}
int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    int target;
    cin>>target;
    vector<vector<int> > matrix(n, vector<int>(m));
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout<<searchMatrix(matrix,target);
    return 0;
}
