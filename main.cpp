#include <iostream>
#include <cstddef>


template< class T >
T* merge2(const T* a, size_t sa,
          const T* b, size_t sb, T* c)
{
    size_t total = sa + sb;   
    size_t indA = 0;          
    size_t indB = 0;         
    size_t k= 0;              
    while (indA < sa && indB < sb)
    {
        if (a[indA] < b[indB])   
        {
            c[k] = a[indA];      
            ++indA;
        }
        else
        {
            c[k] = b[indB];      
            ++indB;
        }
        ++k;
    }

    
    while (indA < sa)
    {
        c[k] = a[indA];          
        ++indA;
        ++k;
    }

    
    while (indB < sb)
    {
        c[k] = b[indB];          
        ++indB;
        ++k;
    }
    return c;
}

int main()
{
    int a[] = {13, 67, 229, 333};
    int b[] = {52, 300, 911, 1234, 1235};

    size_t sa = sizeof(a) / sizeof(a[0]);   
    size_t sb = sizeof(b) / sizeof(b[0]);   
    int c[9];

    merge2(a, sa, b, sb, c);

    for (size_t i = 0; i < sa + sb; ++i)
    {
        std::cout << c[i] << " ";
    }
    std::cout << '\n';
    return 0;
}