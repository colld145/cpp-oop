#include <iostream>

using namespace std;

/*
class Stack
        {
    enum{EMPTY = -1, FULL = 9};
    int arr[FULL + 1]; // size = 10
    int top_index;
public:
    Stack()
    {
        top_index = EMPTY;
    }
    // default methods
    ~Stack() = default;
    explicit Stack(const Stack & other) = default;

    bool IsFull() const
    {
        return top_index == FULL;
    }

    bool Push(int element)
    {
        if(!IsFull())
        {
            arr[++top_index] = element;
            return true;
        }
        return false;
    }

    bool IsEmpty() const
    {
        return top_index == EMPTY;
    }

    int Pop()
    {
        if(!IsEmpty())
        {
            return arr[top_index--];
        }
        return 0;
    }

    int GetCount() const
    {
        return top_index + 1;
    }

    void Clear()
    {
        top_index = EMPTY;
    }

    int Peek()
    {
        if(!IsEmpty())
        {
            return arr[top_index];
        }
        return 0;
    }

    void Print()
    {
        for (int i = 0; i <= top_index; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};
*/

/*
class Stack
        {
private:
    enum{EMPTY = -1};
    int* arr;
    int size;
    int top_index;
public:
    Stack(int size):size(size)
    {
        arr = new int[size];
    }

    bool IsFull() const
    {
        return top_index == size - 1;
    }

    bool IsEmpty() const
    {
        return top_index == EMPTY;
    }

    bool Push(int element)
    {
        if(!IsFull())
        {
            arr[++top_index] = element;
            return true;
        }
        return false;
    }

    int Pop()
    {
        if(!IsEmpty())
        {
            return arr[top_index--];
        }
        return 0;
    }

    int Peek()
    {
        if(!IsEmpty())
        {
            return arr[top_index];
        }
        return 0;
    }

    int GetCount() const
    {
        return top_index + 1;
    }

    void Clear()
    {
        top_index = EMPTY;
    }

    void Print()
    {
        for (int i = 0; i <= top_index; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};
*/


/*Завдання 1:
Створити клас, який описує структуру даних «Stack». Клас містить наступні поля:
колекція елементів (динамічний масив)
вершина (індекс останнього елемента)
Реалізувати набір стандартних методів:
Push – додає новий елемент в стек
Pop – витягує останній елемент з стеку
Peek – повертає останній елемент без видалення зі стеку
GetCount – повертає кількість елементів
IsEmpty – перевіряє чи стек порожній
IsFull – перевіряє чи стек повністю заповнений
Клас обов’язково повинен мати конструктор за замовчуванням  та конструктор,
 який приймає максимальний розмір стека.
Клас повинен бути шаблонним, тобто мати можливість зберігати будь-який тип даних.
Описати набір необхідних компонентів для коректної роботи класу.*/

template <typename T_arr>
class Stack
{
private:
    enum{EMPTY = -1};
    T_arr* arr;
    int size;
    int top_index;
public:
    Stack()
    {
        arr = new T_arr[size];
        size = 10;
        top_index = EMPTY;
    }

    Stack(int size):size(size)
    {
        arr = new T_arr[size];
        top_index = EMPTY;
    }

    bool IsFull() const
    {
        return top_index == size - 1;
    }

    bool IsEmpty() const
    {
        return top_index == EMPTY;
    }

    bool Push(T_arr element)
    {
        if(!IsFull())
        {
            arr[++top_index] = element;
            return true;
        }
        return false;
    }

    int Pop()
    {
        if(!IsEmpty())
        {
            return arr[top_index--];
        }
        return 0;
    }

    int Peek()
    {
        if(!IsEmpty())
        {
            return arr[top_index];
        }
        return 0;
    }

    int GetCount() const
    {
        return top_index + 1;
    }

    void Clear()
    {
        top_index = EMPTY;
    }

    void Print()
    {
        for (int i = 0; i <= top_index; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack()
    {
        delete[] arr;
    }

};

bool isValid(Stack<char> &st1, Stack<char> &st2, Stack<char> &st3)
{
    if(st1.IsEmpty() && st2.IsEmpty() && st3.IsEmpty())
        return true;
}


int main()
{

//    Stack st(10);
//    st.Push(5);
//    st.Push(7);
//    st.Push(9);
//    st.Push(4);
//    st.Push(11);
//    cout << "Count: " << st.GetCount() << endl;
//    st.Print();
//    while (!st.IsEmpty())
//    {
//        cout << "Delete element: " << st.Pop() << endl;
//        st.Print();
//    }

    Stack<char> st1(20); // (
    Stack<char> st2(20); // [
    Stack<char> st3(20); // {
    string text =  "({x-y-z} * [x + 2y] - (z + 4x))";

    for (char symbol : text){
        if(symbol == '(')
            st1.Push(symbol);
        else if(symbol == '[')
            st2.Push(symbol);
        else if(symbol == '{')
            st3.Push(symbol);
        else if(symbol == ')' && !st1.IsEmpty())
            st1.Pop();
        else if(symbol == ']' && !st2.IsEmpty())
            st2.Pop();
        else if(symbol == '}' && !st3.IsEmpty())
            st3.Pop();
        else if(symbol == ')' && st1.IsEmpty())
            st1.Push(' ');
        else if(symbol == ']' && st2.IsEmpty())
            st2.Push(' ');
        else if(symbol == '}' && st3.IsEmpty())
            st3.Push(' ');
    }

    if(isValid(st1, st2, st3))
        cout << "Valid code." << endl;
    else
        cout << "Invalid code." << endl;






    return 0;
}
