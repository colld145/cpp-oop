#include <iostream>

using namespace std;


class Queue{
    enum{EMPTY = 0};
    int* arr;
    int max_size;
    int top;
public:
    Queue(int max_size):max_size(max_size)
    {
        arr = new int[max_size];
        top = EMPTY;
    }

    ~Queue()
    {
        delete [] arr;
    }

    bool IsFull() const
    {
        return top == max_size;
    }

    bool IsEmpty() const
    {
        return top == EMPTY;
    }

    void Enqueue(int element)
    {
        if(!IsFull())
        {
            arr[top++] = element;
        }
    }

    int Dequeue()
    {
        if(!IsEmpty())
        {
            int first = arr[0];
            for (int i = 0; i < top - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            top--;
            return first;
        }
    }

    int GetCount() const
    {
        return top;
    }

    void Clear()
    {
        top = EMPTY;
    }

    void Show() const
    {
        for (int i = 0; i < top; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main()
{
    srand((unsigned)time(NULL));
    Queue q(15);

    for (int i = 0; i < 10; ++i) {
        q.Enqueue(rand() % 30);
    }
    q.Show();

    while(!q.IsEmpty())
    {
        cout << "Element: " << q.Dequeue() << endl;
    }

    cout << "Count: " << q.GetCount() << endl;

    return 0;
}
