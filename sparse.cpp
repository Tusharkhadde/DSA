#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter number of non-zero elements in Matrix A: ";
    cin >> n1;

    int A[100][3];  // Each row: row, col, value
    cout << "Enter row col value for Matrix A:\n";
    for (int i = 0; i < n1; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter number of non-zero elements in Matrix B: ";
    cin >> n2;

    int B[100][3];
    cout << "Enter row col value for Matrix B:\n";
    for (int i = 0; i < n2; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    int C[200][3];  // To store result
    int i = 0, j = 0, k = 0;
    while(i<n1 && j<n2){
        if(A[i][0] == B[j][0] && A[i][1] == B[j][1]){
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
            k++;
        }
        else if(A[i][0]<B[j][0] || (A[i][0] == B[j][0] && A[i][1]<B[j][1])){
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] ;
            i++;
            k++;           
        }
        else {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2] ;
            k++;
            j++;
        }
    }
    while(i<n1){
         C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] ;
            i++;
            k++;
    }
  while(i<n2){
         C[k][0] = B[i][0];
            C[k][1] = B[i][1];
            C[k][2] = B[i][2] ;
            j++;
            k++;
    }
     cout << "\nResultant Sparse Matrix (A + B):\n";
    cout << "Row\tCol\tVal\n";
    for (int x = 0; x < k; x++)
        cout << C[x][0] << "\t" << C[x][1] << "\t" << C[x][2] << endl;

    return 0;


}