#include <iostream>
using namespace std;


template <typename T>
class Queue
{
private:
    struct Element
    {
        T value;
        int priority;
    };
    Element* data;
    int size;
public:
    Queue():data(nullptr), size(0){}

    ~Queue()
    {
        if(data != nullptr)
            delete [] data;
    }

    void Enqueue(T value, int priority)
    {
        int index = 0;

        while (index < size && data[index].priority > priority)
            index++;
        size++;
        Element* temp = new Element[size];
        for (int i = 0; i < index; ++i)
        {
            temp[i] = data[i];
        }
        temp[index] = Element{value, priority};
        for (int i = index; i < size - 1; ++i)
        {
            temp[i + 1] = data[i];
        }

        if(data != nullptr)
            delete [] data;

        data = temp;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    Element Dequeue()
    {
        if(!isEmpty())
        {
            Element first = data[0];
            for (int i = 0; i < size; ++i)
            {
                data[i] = data[i + 1];
            }
            size--;
            return first;
        }
        return Element();
    }

    void Print()
    {
        cout << "--------- Queue -----------" << endl;
        for (int i = 0; i < size; ++i) {
            cout << data[i].value << " : " << data[i].priority << endl;
        }
    }

};

/*ТЕМА: DYNAMIC DATA STRUCTURES. PRIORITY QUEUE.
Завдання 1:
Розробити додаток, що імітує чергу друку принтера.
Програма надає меню з наступними можливостями:
•Додати документ в чергу.
Користувач повинен ввести ім’я файлу та
вибрати свою посаду. В залежності від посади,
документу надається певний пріорітет
(до прикладу: гість – 1, адміністратор – 2, менеджер – 3,
директор – 4 і тд.)
•Виконати друк. Відображається на екран документ,
який наразі друкується (з максимальним пріорітетом).
Для збереження колекції документів використати динамічну
структуру даних – Queue (черга з пріорітетним включенням).*/

/*Завдання N1
Реалізуйте клас стек для роботи з символами (символь-
ний стек). Стек повинен мати фіксований розмір. Також
реалізуйте набір операцій для роботи зі стеком: внесення
символу в стек, видалення символу зі стеку, підрахунок
кількості символів в стеці, перевірку, чи стек порожній,
перевірку, чи стек повний, очищення стеку, отримання
без видалення верхнього символу в стеці.*/

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

    void Push(T_arr element)
    {
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

int main()
{
//    Queue<char> q;
//
//    q.Enqueue('B', 2);
//    q.Enqueue('C', 3);
//    q.Enqueue('G', 5);
//    q.Enqueue('K', 8);
//    q.Enqueue('N', 12);
//    q.Print();
//    q.Enqueue('D', 4);
//    q.Print();
//    cout << "Value : " << q.Dequeue().value << endl;

    /*
    Queue<string> printer;

    bool exit = 0;

    while(!exit)
    {
        int choice = 0;
        string filename = " ";
        cout << "---------- Printer ----------" << endl;
        cout << "1. Add file\n2. Print files\n\n0. Exit\n\nEnter a choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter a file name: ";
                cin >> filename;
                cout << "Enter a priority (1 - Noob, 2 - Admin, 3 - Manager, 4 - BOSS): ";
                cin >> choice;
                printer.Enqueue(filename, choice);
                break;
            case 2:
                while(!printer.isEmpty())
                {
                    cout << "Is printing: " << printer.Dequeue().value << endl;
                }
                break;
            case 0:
                exit = true;
                break;
            default:
                cout << "Error choice!!!!!!!!!!" << endl;
                break;
        }



    }*/


    // ------------------------------------------------






    return 0;
}
