#include <iostream>
#include "dialog.h"
#include "matrix.h"

using namespace std;
using namespace dialog;

void menu() {
    cout << "1. Insert value" << endl;
    cout << "2. Delete value" << endl;
    cout << "3. Display matrix" << endl;
    cout << "4. Create vector" << endl;
    cout << "0. Exit" << endl;
}


int main() {
    Matrix matrix;
    try {
        matrix = create_matrix();
    }
    catch (const bad_alloc &exeption) {
        cout << "Alloc error" << endl;
        matrix::clean_matrix(matrix);
        return 0;
    }
    void (*foo[])(Matrix &) = {nullptr, insert_number, delete_number,
                               display_matrix, create_vector};
    while (1) {
        menu();
        int number = read_menu_int(">");
        if (number == 0) {
            break;
        }
        foo[number](matrix);
    }
    matrix::clean_matrix(matrix);
    return 0;
}