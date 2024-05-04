#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {
        std::cout << "constructor called\n";
    };
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    void print()
    {
        for (const auto& elem : m_down)
               std::cout << elem << " ";
        std::cout <<"\n";
        for (const auto& elem : m_upper)
            std::cout << elem << " ";
        std::cout << "\n";
        for (const auto& elem : m_middle)
            std::cout << elem << " ";
    }

    //clone()
    std::unique_ptr<tridiagonal_matrix> clone()
    {
        std::unique_ptr<tridiagonal_matrix> matrix_clone = std::make_unique<tridiagonal_matrix>(m_down,m_upper, m_middle);
        return matrix_clone;
    }
    
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );
    std::cout << "matrix:" << std::endl;
    matrix->print();
    //for (const auto& elem : matrix)
     //   std::cout << elem << "\n";
    std::cout << std::endl;
    auto matrix_clone = matrix->clone();
    std::cout << "\nmatrix_clone:" << std::endl;
    matrix_clone->print();
    std::cout << std::endl;

    return 0;
}