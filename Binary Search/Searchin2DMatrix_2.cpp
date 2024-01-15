#include<iostream>
using namespace std;
bool searchElement(vector<vector<int> > &MATRIX, int target) {
    int n=MATRIX.size();
    int m=MATRIX[0].size();
    int row=0,col=m-1;
    while(row<n && col>=0){
      if (MATRIX[row][col] == target) {
        return true;
      } else if (MATRIX[row][col] < target)
        row++;
      else
        col--;
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
    cout<<searchElement(matrix,target);
    return 0;
}
