#ifndef DIALOG_H
#define DIALOG_H

#include "handle.h"
#include "matrix.h"

namespace dialog {
    void insert_number(Matrix &matrix);

    void display_matrix(Matrix &matrix);

    Matrix create_matrix();

    void delete_number(Matrix &matrix);

    void create_vector(Matrix &matrix);
}


#endif //DIALOG_H