#include <iostream>

using namespace std;


template <typename T>
class List
{
    struct Node
    {
        Node* prev;
        T value;
        Node* next;
        Node(Node* prev, T value, Node* next):prev(prev), value(value), next(next) {}
    };
private:
    Node* head;
    Node* tail;
    int size;
public:
    List()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void AddToHead(T value)
    {
        Node* new_node = new Node(nullptr, value, head);
        if(isEmpty())
        {
            head = tail = new_node;
        }
        else
        {
            head->prev = new_node;
            head = new_node;
        }
        size++;
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
        Node * new_node = new Node(tail, value, nullptr);

        if(isEmpty())
            head = tail = new_node;
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
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
        if(isEmpty()) return;

        if(head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        size--;
    }

    int getSize()
    {
        return size;
    }

    void DeleteFromHead()
    {
        if(isEmpty())
            return;

        if(head->prev == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        size--;

    }

    void DeleteByPos(int pos)
    {
        if(pos < 1 || pos > size)
            return;
        else if(pos == 1)
        {
            //DeleteFromHead();
            return;
        }
        else if(pos == size)
        {
            DeleteFromTail();
            return;
        }
        else
        {
            Node* current;
            if (pos <= size / 2)
            {
                current = head;
                for (int i = 1; i < pos; ++i)
                {
                    current = current->next;
                }
            }
            else
            {
                current = tail;
                for (int i = size; i > pos; i--)
                {
                    current = current->prev;
                }
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            size--;
        }

    }

    void AddByPos(T value, int pos)
    {

        if(isEmpty())
        {
            Node* new_node = new Node(nullptr, value, nullptr);
            head = tail = new_node;
            return;
        }
        else
        {
            Node* current;
            if (pos <= size / 2)
            {
                current = head;
                for (int i = 1; i < pos; ++i)
                {
                    current = current->next;
                }
            }
            else
            {
                current = tail;
                for (int i = size; i > pos; i--)
                {
                    current = current->prev;
                }
            }
            Node* new_node = new Node(current->prev, value, current);
            current->prev->next = new_node;
            current->prev = new_node;

        }
        size++;
    }
};



/*Додати метод DeleteFromHead для класу двозв*язного списку.
Завдання 2:
Використати клас List для колекції вагонів в класі Train
Додати методи додавання вагона в початок/кінець та видалення з
початку/кінця.
На 12 балів зробити видалення по позиції та додавання по позиції

class Train
{
private:
	string model;
	int countVagons;
	List<Vagon> vagons;
}*/

struct Vagon
{
    int wag_number;
    int seats_number;
    int passengers;
    Vagon()
    {
        wag_number = 0;
        seats_number = 0;
        passengers = 0;
    }
    Vagon(int wag_number, int seats_number, int passengers)
    {
        this->wag_number = wag_number;
        this->seats_number = seats_number;
        this->passengers = passengers;
    }
};

ostream &operator<<(ostream& out, const Vagon &vagon)
{
    out << vagon.wag_number << ". Seats number: ";
    out << vagon.seats_number << ", Passengers: ";
    out << vagon.passengers << endl;
    return out;
}

class Train
{
private:
    string model;
    int countVagons;
    List<Vagon> vagons;
public:
    Train()
    {
        countVagons = 0;
    }

    void AddVagonToHead(Vagon vagon)
    {
        vagons.AddToHead(vagon);
        countVagons++;
    }

    void AddVagonToTail(Vagon vagon)
    {
        vagons.AddToTail(vagon);
        countVagons++;
    }

    void DeleteVagonFromHead()
    {
        vagons.DeleteFromHead();
        countVagons--;
    }

    void DeleteVagonFromTail()
    {
        vagons.DeleteFromTail();
        countVagons--;
    }

    void DeleteVagonByPos(int pos)
    {
        vagons.DeleteByPos(pos);
        countVagons--;
    }

    void AddVagonByPos(Vagon vagon, int pos)
    {
        vagons.AddByPos(vagon, pos);
        countVagons++;
    }


    void PrintTrain()
    {
        vagons.PrintList();
    }


};


int main() {
//    List<int> list;
//    for (int i = 0; i < 10; ++i)
//    {
//        list.AddToHead(i);
//    }
//    cout << " Size : " << list.getSize() << endl;
//    list.PrintList();
//    list.AddToTail(10);
//    list.PrintList();
//    list.DeleteFromTail();
//    list.PrintList();
//    list.DeleteByPos(3);
//    list.PrintList();

//    -----------------------------------------

    Train ukrzaliz;
    ukrzaliz.AddVagonToTail(Vagon(1, 10,5));
    ukrzaliz.AddVagonToTail(Vagon(2, 10,5));
    ukrzaliz.AddVagonToTail(Vagon(3, 10,5));
    ukrzaliz.PrintTrain();
    //ukrzaliz.DeleteVagonFromTail();
    //ukrzaliz.PrintTrain();
    ukrzaliz.AddVagonByPos(Vagon(222, 10, 5),2);
    ukrzaliz.PrintTrain();
    return 0;
}
