#include <iostream>

using namespace std;


template <typename T>
class List
{
    struct Node
    {
        T value;
        Node* next;
        Node(T value, Node* next):value(value), next(next) {}
    };
private:
    Node* head;
public:
    List()
    {
        head = nullptr;
    }

    void AddToHead(T value)
    {
        Node* new_node = new Node(value, head);
//        new_node->value = value;
//        new_node->next = head;

        head = new_node;
    }

    void PrintList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
    }

    void AddToTail(T value)
    {
        Node * new_node = new Node(value, nullptr);

        if(head == nullptr)
            head = new_node;
        else
        {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = new_node;
        }


    }

    T GetElementByPos(int pos)
    {
        Node* current = head;
        int i = 1;
        while (current != nullptr)
        {
            if (pos == i)
                return current->value;
            current = current->next;
            i++;
        }
    }

    void DeleteFromTail()
    {
        if(head == nullptr) return;

        if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }

            delete current->next;
            current->next = nullptr;
        }
    }
};


/*Реалізувати клас Vector, який містить колекцію точок на площині.
Точки зберігаються у вигляді списка (змінна типу List).
Для класу потрібно реалізувати необхідний набір конструкторів,
методи для видалення, додавання нової точки на початок та в кінець
та метод Print() для виводу точок на екран.*/

struct Point
{
    int x;
    int y;
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

};

ostream &operator<<(ostream& out, const Point &point)
{
    out << point.x << " ";
    out << point.y << endl;
    return out;
}

class Vector
{
    int size;
    List<Point> points;
public:
    Vector()
    {
        size = 0;
    }

    Vector(int size)
    {
        this->size = size;
        for (int i = 0; i < size; ++i)
        {
            Point temp;
            temp = Point(i+100, i+1000);
            points.AddToHead(temp);
        }
    }

    void AddPointToHead(Point p)
    {
        points.AddToHead(p);
        size++;
    }

    void AddPointToTail(Point p)
    {
        points.AddToTail(p);
        size++;
    }

    void DeletePointFromTail()
    {
        points.DeleteFromTail();
        size--;
    }

    void PrintPoints()
    {
        points.PrintList();
    }
};


int main() {
//    List<int> list;
//    for (int i = 0; i < 10; i++)
//    {
//        list.AddToHead(i);
//    }
//
//    list.PrintList();
//    list.AddToTail(100);
//    list.AddToTail(200);
//    list.AddToTail(300);
//    list.AddToTail(400);
//    list.PrintList();
//    cout << "Element[3] : " << list.GetElementByPos(3) << endl;
//    list.DeleteFromTail();
//    list.DeleteFromTail();
//    list.DeleteFromTail();
//    list.PrintList();

    // --------------------------

    Vector vector(5);
    vector.PrintPoints();

    return 0;
}
