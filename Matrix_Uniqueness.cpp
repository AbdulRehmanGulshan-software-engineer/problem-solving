// 6. Write C/C++ code to check whether a matrix is unique (a matrix with all unique elements must be
// considered unique for this question).
#include <iostream>
void matrix_input(int rows, int cols, int *p)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int k;
            std::cout << "Enter Element " << i * cols + j + 1 << " : ";
            std::cin >> k;
            *(p + i * cols + j) = k;
        }
    }
}
void print_matrix(int rows, int cols, int *p)
{
    for (int i = 0; i < rows; i++)
    {
        std::cout << "[ ";
        for (int j = 0; j < cols; j++)
        {
            std::cout << *(p + i * cols + j) << " ";
        }
        std::cout << "]" << std::endl;
    }
}

bool is_unique_matrix(int rows, int cols, int *matrix)
{
    int total = rows * cols;
    int i, j;
    for (i = 0; i < total - 1; i++)
    {
        for (j = i + 1; j < total; j++)
        {
            if (*(matrix + i) == *(matrix + j))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int rows, cols, row_index, col_index;
    std::cout << "Enter Rows: ";
    std::cin >> rows;
    std::cout << "Enter Columns: ";
    std::cin >> cols;
    int *matrix = new int[rows * cols];
    matrix_input(rows, cols, matrix);
    print_matrix(rows, cols, matrix);
    if (is_unique_matrix(rows, cols, matrix))
    {
        std::cout << "Matrix Is Unique (Distinct Elements)." << std::endl;
    }
    else
        std::cout << "Matrix Is Not Unique (Duplicate Found)." << std::endl;
    delete[] matrix;
    return 0;
}