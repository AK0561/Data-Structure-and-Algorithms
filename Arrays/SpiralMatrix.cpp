#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralMatrix(vector<vector<int> >&MATRIX) {
    int n=MATRIX.size();
    int m=MATRIX[0].size();
    int left=0,top=0;
    int bottom=n-1,right=m-1;
    vector<int>ans;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(MATRIX[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(MATRIX[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(MATRIX[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(MATRIX[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    vector<vector<int> > matrix(n, vector<int>(m));
    cout << "Enter the matrix elements:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<int> result = spiralMatrix(matrix);
    cout << "Spiral Order: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}