#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

typedef struct Line Line;

typedef struct Column Column;

typedef struct Matrix Matrix;

struct Line {
    int number;
    int value;
    Line *next;
};

struct Column {
    int number;
    Line *line;
    Column *next;
};

struct Matrix {
    int column_count;
    int line_count;
    Column *first;
};

namespace matrix {
    Matrix create_matrix(int column_count, int line_count);

    void delete_number(Matrix &matrix, int column_number, int line_number);

    void insert_number(Matrix &matrix, int column_number, int line_number, int value);

    void display_matrix(const Matrix &matrix);

    void clean_matrix(const Matrix &matrix);

    std::vector<int> create_vector(const Matrix &matrix);
}


#endif //MATRIX_H