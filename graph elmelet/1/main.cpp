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

            last = last->next;
        }
        else
        {
            first = new_node;
            last = new_node;
        }
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
        return 0;
    }

    bool isEmpty()
    {
        return first == nullptr;
    }
};

int main()
{
    // ListaNode *l = new ListaNode(5);

    // for (int i = 0; i < 10; i++)
    // {
    //     l->felfuz(rand() % 101);
    // }

    // l->print();

    Queue q;
    for (int i = 0; i < 10; i++)
    {
        q.push(rand() % 101);
    }
    while (!q.isEmpty())
    {
        cout << q.pop() << " ";
    }
    return 0;
}