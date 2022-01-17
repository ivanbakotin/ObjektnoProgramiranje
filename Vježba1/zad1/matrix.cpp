#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>

using namespace std;

struct Matrix {
    int rows, cols;
    float **data;

    void inputMatrix() {
        cout << "Rows: " << endl;
        cin >> rows;
        cout << "Columns: " << endl;
        cin >> cols;
    };

    void newMatrix() {

        data = new float*[rows];

        for(int i = 0; i < rows; i++) {
            data[i] = new float[cols];
        };
    };  

    void generateMatrixNumbers() {

        float L1, L2;

        cout << "First number: " << endl;
        cin >> L1;
        cout << "Last number: " << endl;
        cin >> L2;

        srand ( time(NULL) );

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                data[i][j] = L1 + (rand()) /((RAND_MAX/(L2-L1)));
            };
        };
    };

    void printMatrix() {
        cout << "Matrix:" << endl;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << right << setw(20) << fixed << setprecision(4) << data[i][j];
            };
            cout << endl;
        };
    };

    void deleteMatrix() {
        for(int i = 0; i < rows; i++) {
            delete data[i];
        };
        delete data;
    };

    void addOrSubMatrix(float **MatrixB, int rowsB, int colsB, bool plus) {

        if (cols == colsB && rows == rowsB) {

            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    if (plus) data[i][j] += MatrixB[i][j];
                    else data[i][j] -= MatrixB[i][j];
                };
            };   
        } else {
            cout << "Non-matching matrix size!" << endl;
        };
    };

    void multiplyMatrix(float **MatrixB, int rowsB, int colsB) {

        if (cols == rowsB) {

            struct Matrix matrixC;

            matrixC.rows = rows;
            matrixC.cols = colsB;

            matrixC.newMatrix();

            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < colsB; j++) {
                    matrixC.data[i][j] = 0;
                };
            };

            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < colsB; ++j) {
                    for (int k = 0; k < cols; ++k) {
                        matrixC.data[i][j] += data[i][k] * MatrixB[k][j];
                    };
                };  
            }; 

            deleteMatrix();

            cols = colsB;

            newMatrix();

            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    data[i][j] = matrixC.data[i][j];
                };
            };
        } else {
            cout << "Non-matching matrix size!" << endl;
        };
    };

    void transpositionMatrix() {

        struct Matrix matrixC;

        matrixC.rows = cols;
        matrixC.cols = rows;

        matrixC.newMatrix();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                matrixC.data[j][i] = data[i][j];
            };
        };

        deleteMatrix();

        int x = cols;
        cols = rows;
        rows = x;

        newMatrix();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                data[i][j] = matrixC.data[i][j];
            };
        };
    };
};

int main() {

    struct Matrix matrix_1;
    struct Matrix matrix_2;

    matrix_1.inputMatrix();
    matrix_1.newMatrix();
    matrix_1.generateMatrixNumbers();
    matrix_1.printMatrix();
    matrix_1.transpositionMatrix();
    matrix_1.printMatrix();

    matrix_2.inputMatrix();
    matrix_2.newMatrix();
    matrix_2.generateMatrixNumbers();
    matrix_2.printMatrix();

    matrix_1.addOrSubMatrix(matrix_2.data, matrix_2.rows, matrix_2.cols, true);
    matrix_1.addOrSubMatrix(matrix_2.data, matrix_2.rows, matrix_2.cols, false);
    matrix_1.multiplyMatrix(matrix_2.data, matrix_2.rows, matrix_2.cols);
    matrix_1.printMatrix();
};
