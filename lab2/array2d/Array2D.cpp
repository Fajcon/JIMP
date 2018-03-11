//
// Created by ficojaku on 06.03.18.
//

#include "Array2D.h"

int **NewArray2D(int n_rows, int n_columns){

    if (n_rows <= 0 or n_columns <= 0)
        return nullptr;
    int value = 1;
    int** array = new int* [10];
    for (int i = 0; i < n_rows ; ++i) {
        array[i] = new int [n_columns];
        for (int j = 0; j < n_columns ; ++j) {
            array[i][j] = value;
            value++;
        }
    }
    return array;

}
void DeleteArray2D(int **array, int n_rows, int n_columns) {

    for (int i = 0; i < n_rows; ++i) {
        delete array[i];

    }
    delete array;
}