#include <iostream>
using namespace std;

int main(){
    int rows1, columns1, rows2, columns2;
    cout << "No.of rows of 1st matrix : ";
    cin >> rows1;
    cout << "No.of columns of 1st matrix : ";
    cin >> columns1;
    cout << "No.of rows of 2nd matrix : ";
    cin >> rows2;
    cout << "No.of columns of 2nd matrix : ";
    cin >> columns2;
    
    if (columns1 != rows2) {
        cout << "Matrix multiplication is not possible.";
        return 0;
    }

    int matrix1[rows1][columns1];
    int matrix2[rows2][columns2];

    cout << "\n";
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            cin >> matrix1[i][j];
        }
    }
    
    cout << "\n";
    
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            cin >> matrix2[i][j];
        }
    }
    
    int resultant[rows1][columns2];
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            resultant[i][j] = 0;
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            for (int k = 0; k < columns1; k++) {
                resultant[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    
    cout << "\n";
    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            cout << resultant[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}