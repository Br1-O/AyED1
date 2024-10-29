#include <iostream>
#include <vector>

using namespace std;

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(3)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(a)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int N);

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(b)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

vector<vector<int>> subtractMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int N);

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(c)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int N);

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(d)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

vector<vector<int>> transposeMatrix(const vector<vector<int>>& A, int N);

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(e)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

void saddlePoints(const vector<vector<int>>& matrix, int N);

//functions to read and display matrices
void readMatrix(vector<vector<int>>& matrix, int N);
void displayMatrix(const vector<vector<int>>& matrix, int N);

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■(MAIN)■■■■■■■■■■■■■■■■■■■■■■■■■■■■//

int main() {
    int N, option;
    
    cout << "Ingresa la dimensión de las matrices (NxN): ";
    cin >> N;

    vector<vector<int>> matrixA(N, vector<int>(N));
    vector<vector<int>> matrixB(N, vector<int>(N));
    
    cout << "Ingresa los elementos de la primera matriz: \n";
    readMatrix(matrixA, N);

    cout << "\nSelecciona la operación que vas a realizar con las matrices:\n";
    cout << "1. Sumar \n";
    cout << "2. Restar \n";
    cout << "3. Multiplar \n";
    cout << "4. Trasponer \n";
    cout << "5. Mostrar puntos silla \n";
    cin >> option;

    if (option == 1 || option == 2 || option == 3) {
        cout << "Ingresa los elementos de la segunda matriz: \n";
        readMatrix(matrixB, N);
    }

    vector<vector<int>> result(N, vector<int>(N));

    switch(option) {
        case 1:
            result = addMatrices(matrixA, matrixB, N);
            cout << "\nResultado: \n";
            displayMatrix(result, N);
            break;
        case 2:
            result = subtractMatrices(matrixA, matrixB, N);
            cout << "\nResultado: \n";
            displayMatrix(result, N);
            break;
        case 3:
            result = multiplyMatrices(matrixA, matrixB, N);
            cout << "\nResultado: \n";
            displayMatrix(result, N);
            break;
        case 4:
            result = transposeMatrix(matrixA, N);
            cout << "\nResultado: \n";
            displayMatrix(result, N);
            break;
        case 5:
            cout << "\nResultado: \n";
            saddlePoints(matrixA, N);
            break;
        default:
            cout << "Opcion invalida.\n";
            break;
    }

    return 0;
}

//read a matrix from input
void readMatrix(vector<vector<int>>& matrix, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
}

//display a matrix on the console
void displayMatrix(const vector<vector<int>>& matrix, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//add two matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int N) {
    vector<vector<int>> result(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

//subtract two matrices
vector<vector<int>> subtractMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int N) {
    vector<vector<int>> result(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

//multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, int N) {
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

//transpose a matrix
vector<vector<int>> transposeMatrix(const vector<vector<int>>& A, int N) {
    vector<vector<int>> result(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[j][i] = A[i][j];
        }
    }
    return result;
}

//find the saddle points in a matrix
void saddlePoints(const vector<vector<int>>& matrix, int N) {
    for (int i = 0; i < N; ++i) {
        int minRow = matrix[i][0];
        int colMin = 0;

        //find minimum in row
        for (int j = 1; j < N; ++j) {
            if (matrix[i][j] < minRow) {
                minRow = matrix[i][j];
                colMin = j;
            }
        }

        //check if it is the maximum in column
        bool isSaddlePoint = true;
        for (int k = 0; k < N; ++k) {
            if (matrix[k][colMin] > minRow) {
                isSaddlePoint = false;
                break;
            }
        }

        if (isSaddlePoint) {
            cout << "Punto silla encontrado en [" << i << ", " << colMin << "] = " << minRow << endl;
        }
    }
}
