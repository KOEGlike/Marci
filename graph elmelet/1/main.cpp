#include <iostream>
#include <cstdlib>

using namespace std;

struct ListaNode
{
    int adat;
    ListaNode *next;

    ListaNode(int adat)
    {
        this->adat = adat;
        this->next = nullptr; // Explicitly initialize next to nullptr
    }
    ~ListaNode()
    {
        if (this->next != nullptr)
        {
            delete this->next;
        }
    }

    void felfuz(int adat)
    {
        if (next == nullptr)
        {
            next = new ListaNode(adat);
        }
        else
        {
            next->felfuz(adat);
        }
    }

    void print()
    {
        cout << adat << " ";
        if (next != nullptr)
        {
            next->print();
        }
    }
};

class Queue
{
    ListaNode *first;
    ListaNode *last;

public:
    Queue()
    {
        first = nullptr;
        last = nullptr;
    }

    ~Queue()
    {
        if (first)
        {
            delete first;
        }
        first = last = nullptr;
    }

    void push(int adat)
    {
        ListaNode *new_node = new ListaNode(adat);
        if (first)
        {
            last->next = new_node;
            last = new_node;
        }
        else
        {
            first = new_node;
            last = new_node;
        }
        cout << "new node added: " << new_node->adat << endl;
    }

    int elso()
    {
        return first ? first->adat : 0;
    }

    int utolso()
    {
        return last ? last->adat : 0;
    }

    int pop()
    {
        if (first != nullptr)
        {
            int adat = first->adat;
            ListaNode *temp = first;
            first = first->next;
            temp->next = nullptr;
            delete temp;
            return adat;
        }
        else
        {
            cout << "Attempted to pop from an empty queue!" << endl;
            return 0; // Return a sentinel value or handle this better as needed.
        }
    }

    bool isEmpty()
    {
        return first == nullptr;
    }
};

int main()
{
    Queue q;
    for (int i = 0; i < 10; i++)
    {
        q.push(rand() % 101);
    }

    // Display the queue elements
    cout << "Queue contents: ";
    while (!q.isEmpty())
    {
        cout << q.pop() << " ";
    }
    cout << endl;

    return 0;
}
