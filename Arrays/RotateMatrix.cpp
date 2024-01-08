#include<iostream>
#include<vector>
using namespace std;
void rotateMatrix(vector<vector<int> > &mat){
	int n=mat.size();
	for(int i=0;i<n-1;i++){
      for(int j=i+1;j<n;j++){
		  swap(mat[i][j],mat[j][i]);
	  }
	}
	for(int i=0;i<n;i++){
		reverse(mat[i].begin(),mat[i].end());
	}
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

    rotateMatrix(matrix);

    cout << "Matrix after rotating 90 deg:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
