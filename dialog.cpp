#include "dialog.h"
#include <iostream>
#include <vector>

using namespace std;
namespace dialog {
    void insert_number(Matrix &matrix) {
        int column_number = read_int("column number");
        int line_number = read_int("line number");
        int value = read_int("value");
        if (column_number > matrix.column_count || column_number < 1 ||
            line_number > matrix.line_count || line_number < 1) {
            cout << "Element not found" << endl;
            return;
        } else {
            matrix::insert_number(matrix, column_number, line_number, value);
        }
    }

    void display_matrix(Matrix &matrix) {
        matrix::display_matrix(matrix);
    }

    Matrix create_matrix() {
        int column_count = read_int("columns count");
        int line_count = read_int("lines count");
        while (1){
            if (column_count > 0 && line_count > 0){
                break;
            }
            cout<< "Enter correct values" << endl;
            column_count = read_int("column number");
            line_count = read_int("line number");
        }
        Matrix matrix = matrix::create_matrix(column_count, line_count);
        return matrix;
    }

    void delete_number(Matrix &matrix) {
        int column_number = read_int("column number");
        int line_number = read_int("line number");
        if (column_number > matrix.column_count || column_number < 1 ||
            line_number > matrix.line_count || line_number < 1) {
            cout << "Element not found" << endl;
            return;
        } else {
            matrix::delete_number(matrix, column_number, line_number);
        }
    }

    int vector_index;

    void create_vector(Matrix &matrix) {
        vector<int> vector = matrix::create_vector(matrix);
        vector_index = 0;
        for_each(vector.begin(), vector.end(), [](int elem) {
            cout << "[" << vector_index + 1 << "]: " << elem << endl;
            vector_index++;
        });
    }
}