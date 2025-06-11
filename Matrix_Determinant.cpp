#include <iostream>
void print_array_using_pointers(int rows, int cols, int *ptr)
{
    for (int i = 0; i < rows; i++)
    {
        std::cout << "[";
        for (int j = 0; j < cols; j++)
        {
            std::cout << " " << *ptr;
            ptr = ptr + 1;
        }
        std::cout << " ]" << std::endl;
    }
    return;
}
void initialize_array(int rows, int cols, int *ptr)
{
    int k;
    std::cout << std::endl
              << "Enter Number's till you're done." << std::endl;
    std::cout << "Press enter after each number entry." << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> k;
            *(ptr + i * cols + j) = k;
        }
    }
}
double determinant(int m, int *p)
{
    double ans = 0;
    if (m == 1 || m == 2) // our stopping criteria
    {
        // for 1_by_1 matrix
        if (m == 1)
        {
            ans = *p;
        }
        else
        {
            // for 2_by_2 matrix
            int a, b, c, d;
            if (m == 2)
                a = *p;
            b = *(p + 1);
            c = *(p + 2);
            d = *(p + 3);
            ans = (a * d) - (b * c);
        }
    }
    // for 3_by_3 and further matrix
    else
    {
        int sign, i, basic, element, inner_sol, inner_determinant;
        sign = +1;
        int *q;
        q = new int[(m - 1) * (m - 1)];
        for (int i = 0; i < m; i++)
        {
            basic = *(p + i);
            int l = 0;
            int n = 0;
            for (int j = 0; j < m; j++) // this is how we initialize q
            {
                for (int k = 0; k < m; k++)
                {
                    element = *(p + l);
                    std::cout << element << " ";
                    if ((j == 0) || (i == k))
                        ;
                    else
                    {
                        *(q + n) = element;
                        n = n + 1;
                    }
                    l = l + 1;
                }
            }
            std::cout << std::endl
                      << basic << " x " << std::endl;
            print_array_using_pointers((m - 1), (m - 1), q);
            inner_determinant = determinant(m - 1, q);
            inner_sol = sign * basic * inner_determinant;
            std::cout << "Sign: " << sign << " x Basic: " << basic << " x Determinant: " << inner_determinant << " = " << inner_sol << std::endl;
            ans = ans + inner_sol;
            sign = sign * -1;
        }
        delete[] q;
    }
    return ans;
}
int main()
{
    int size;
    std::cout << "Enter Size n*n : ";
    std::cin >> size;
    int *p = new int[size * size]; // matrix dynamically using single pointer
    initialize_array(size, size, p);
    print_array_using_pointers(size, size, p);
    double ans = determinant(size, p);
    std::cout << "Determinant: " << ans << std::endl;
    delete[] p;
    return 0;
}