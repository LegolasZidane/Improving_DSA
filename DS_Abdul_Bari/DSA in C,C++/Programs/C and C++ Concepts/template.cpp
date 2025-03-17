#include <iostream>
using namespace std;


template <class T>
class Arithmetic //Arithmetic is the template class.
{
    private:
        T num1; // pehle sabh int
        T num2;
    public:
        Arithmetic();
        Arithmetic(T num1, T num2);
        T add();
        T sub();
};

template <class T>
Arithmetic<T>::Arithmetic()
{
    num1 = num2 = 0;
}

template <class T>
Arithmetic<T>::Arithmetic(T num1, T num2)
{
    this->num1 = num1;
    this->num2 = num2;
}

template <class T>
T Arithmetic<T>::add()
{
    T c;
    c = num1 + num2;
    return c;
}

template <class T>
T Arithmetic<T>::sub()
{
    T c;
    c = num1 - num2;
    return c;
}

int main()
{
    Arithmetic<int> a(10,5);

    cout<<endl<<a.add()<<endl<<a.sub()<<endl;

    return 0;
}