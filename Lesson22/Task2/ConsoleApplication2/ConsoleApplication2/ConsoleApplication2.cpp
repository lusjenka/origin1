#include <iostream>

template<typename T>
class RowWithCheck
{
protected:
    T* data;
    int size;
public:
    RowWithCheck(T* d, int s)
    {
        data = d;
        size = s;
    }
    T& operator[](int index)
    {
        if ((index < 0) || (index >= size))
        {
            throw std::runtime_error("index is out of bouns.");
        }
        return data[index];
    }
    T operator[](int index) const
    {
        if ((index < 0) || (index >= size))
        {
            throw std::runtime_error("index is out of bouns.");
        }
        return data[index];
    }
};

template<typename T>
class Table
{
protected:
    T** data;
    int rows;
    int cols;
public:
    Table(int r, int c)
    {
        rows = r;
        cols = c;
        data = new T * [rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new T[cols];
        }

    }
    Table(const Table& t)
    {
        rows = t.rows;
        cols = t.cols;
        data = new T * [rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new T[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                data[i][j] = t.data[i][j];
            }

        }
    }

    Table& operator=(const Table& t)
    {
        if (&t == this)
        {
            return *this;
        }
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;

        rows = t.rows;
        cols = t.cols;

        data = new T * [rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new T[cols];
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                data[i][j] = t.data[i][j];
            }

        }
    }
    ~Table()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    RowWithCheck<T> operator[](int index)
    {
        if ((index < 0) || (index >= rows))
        {
            throw std::runtime_error("index is beyond the border.");
        }
        return RowWithCheck<T>(data[index], cols);
    }
    const RowWithCheck<T> operator[](int index) const
    {
        if ((index < 0) || (index >= rows))
        {
            throw std::runtime_error("index is beyond the border.");
        }
        return RowWithCheck<T>(data[index], cols);
    }
};


int main()
{
    try
    {
        auto test = Table<int>(2, 3);
        test[0][0] = 4;
        std::cout << test[0][0];

   }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

