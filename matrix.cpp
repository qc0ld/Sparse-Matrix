#include "matrix.h"

using namespace std;


Matrix matrix::create_matrix(int column_count, int line_count) {
    Matrix matrix;
    matrix.column_count = column_count;
    matrix.line_count = line_count;
    matrix.first = nullptr;
    return matrix;
}

Column *find_column(const Matrix &matrix, int column) {
    Column *temp_column = matrix.first;
    while (1) {
        if (!temp_column) {
            break;
        }
        if (temp_column->number == column) {
            return temp_column;
        }
        temp_column = temp_column->next;
    }
    return nullptr;
}


Line *find_line(Column *column, int line) {
    Line *temp_line = column->line;
    while (1) {
        if (!temp_line) {
            break;
        }
        if (temp_line->number == line) {
            return temp_line;
        }
        temp_line = temp_line->next;
    }
    return nullptr;
}

Line *create_line(int number, int value) {
    Line *new_line = new Line;
    new_line->number = number;
    new_line->value = value;
    new_line->next = nullptr;
    return new_line;
}

Column *create_column(int number) {
    Column *new_column = new Column;
    new_column->number = number;
    new_column->line = nullptr;
    new_column->next = nullptr;
    return new_column;
}

void matrix::delete_number(Matrix &matrix, int column_number, int line_number) {
    Column *column = find_column(matrix, column_number);
    if (column) {
        Line *line = find_line(column, line_number);
        if (line) {
            Line *temp = column->line;
            if (column->line->number == line->number) {
                column->line = line->next;
            } else {
                while (1) {
                    if (temp->next->number == line->number) {
                        break;
                    }
                    temp = temp->next;
                }
                temp->next = line->next;
            }
            delete (line);
            if (!column->line) {
                Column *temp_column = matrix.first;
                if (matrix.first->number == column->number) {
                    matrix.first = column->next;
                } else {
                    while (1) {
                        if (temp_column->next->number == column->number) {
                            break;
                        }
                        temp_column = temp_column->next;
                    }
                    temp_column->next = column->next;
                }
                delete (column);
            }
        }
    }
    return;
}

void matrix::insert_number(Matrix &matrix, int column_number, int line_number, int value) {
    Column *column = find_column(matrix, column_number);
    if (value == 0) {
        matrix::delete_number(matrix, column_number, line_number);
        return;
    }
    if (!matrix.first) {
        matrix.first = create_column(column_number);
        matrix.first->line = create_line(line_number, value);
        return;
    }
    Line *line = nullptr;
    if (!column) {
        column = create_column(column_number);
        line = create_line(line_number, value);
        column->line = line;
        Column *temp_column = nullptr;
        if (column->number < matrix.first->number) {
            temp_column = matrix.first;
            matrix.first = column;
            column->next = temp_column;
        } else {
            Column *temp_column2 = matrix.first;
            while (column->number > temp_column2->number) {
                if (!temp_column2->next) {
                    break;
                }
                if (column->number < temp_column2->next->number) {
                    break;
                }
                temp_column2 = temp_column2->next;
            }
            temp_column = temp_column2->next;
            temp_column2->next = column;
            column->next = temp_column;
        }
    } else {
        line = find_line(column, line_number);
        if (!line) {
            line = create_line(line_number, value);
            Line *temp_line = nullptr;
            if (line->number < column->line->number) {
                temp_line = column->line;
                column->line = line;
                line->next = temp_line;
            } else {
                Line *temp_line2 = column->line;
                while (line->number > temp_line2->number) {
                    if (!temp_line2->next) {
                        break;
                    }
                    if (line->number < temp_line2->next->number) {
                        break;
                    }
                    temp_line2 = temp_line2->next;
                }
                temp_line = temp_line2->next;
                temp_line2->next = line;
                line->next = temp_line;
            }
        } else {
            line->value = value;
        }
    }
    return;
}

void matrix::display_matrix(const Matrix &matrix) {
    if (!matrix.first) {
        cout << "Matrix is empty" << endl;
        return;
    }
    Column *temp_column = matrix.first;
    Line *temp_line = nullptr;
    temp_column = matrix.first;
    while (temp_column) {
        temp_line = temp_column->line;
        printf("%d: ", temp_column->number);
        while (temp_line->next) {
            printf("[%d]%d->", temp_line->number, temp_line->value);
            temp_line = temp_line->next;
        }
        printf("[%d]%d", temp_line->number, temp_line->value);
        printf("\n");
        temp_column = temp_column->next;
    }
}

void matrix::clean_matrix(const Matrix &matrix) {
    Column *temp_column = matrix.first;
    Line *trash_line = nullptr;
    Column *trash_column = nullptr;
    while (1) {
        if (!temp_column) {
            break;
        }
        while (1) {
            if (!temp_column->line) {
                break;
            }
            trash_line = temp_column->line;
            temp_column->line = temp_column->line->next;
            delete (trash_line);
        }
        trash_column = temp_column;
        temp_column = temp_column->next;
        delete (trash_column);
    }
    return;
}

int sum_of_digits(int number) {
    int sum = 0;
    while (number != 0) {
        sum = sum + number % 10;
        number = number / 10;
    }
    return sum;
}

vector<int> matrix::create_vector(const Matrix &matrix) {
    vector<int> vector(matrix.column_count);
    Column *temp_column = matrix.first;
    Line *temp_line = nullptr;
    int sum;
    while (temp_column) {
        sum = 0;
        temp_line = temp_column->line->next;
        while (temp_line) {
            if (sum_of_digits(temp_column->line->value) == sum_of_digits(temp_line->value)) {
                sum = sum + temp_line->value;
            }
            temp_line = temp_line->next;
        }
        vector[temp_column->number - 1] = sum;
        temp_column = temp_column->next;
    }
    return vector;
}