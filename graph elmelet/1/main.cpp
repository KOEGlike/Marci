#include <iostream>
#include <cstdlib>

using namespace std;

class Lista
{
private:
    int adat;
    Lista *next;

    // Lista *getNode(int index)
    // {
    //     Lista *current = this;
    //     for (int i = 0; i <= index && current->next != nullptr; i++)
    //     {
    //         current = current->next;
    //     }
    //     return current;
    // }

public:
    Lista(int adat, Lista *next = nullptr) : adat(adat), next(next) {}
    ~Lista()
    {
        if (this->next != nullptr)
        {
            delete this->next;
        }
    }

    // void removeFrom(int inedx)
    // {
    //     Lista *node = getNode(inedx);

    //     node->removeFrom(0)

    //     delete node;
    // }

    void felfuz_hatul(int adat)
    {
        if (next == nullptr)
        {
            next = new Lista(adat);
        }
        else
        {
            next->felfuz_hatul(adat);
        }
    }

    Lista *felfuz_elol(int adat)
    {
        Lista *new_node = new Lista(adat);

        new_node->next = this;

        return new_node;
    }

    void print()
    {
        cout << adat << " ";
        if (next != nullptr)
        {
            next->print();
        }
    }

    // int get(int index)
    // {
    //     Lista *node = getNode(index);
    //     return node->adat;
    // }

    // void remove(int index)
    // {
    //     Lista *node = getNode(index - 1);
    //     Lista *next_node = node->next;
    //     Lista *next_next_node = next_node->next;

    //     delete next_node;
    //     if (next_next_node != nullptr)
    //     {
    //         node->next = next_next_node;
    //     }
    // }
};

int main()
{
    Lista *l = new Lista(5);

    for (int i = 0; i < 10; i++)
    {
        l = l->felfuz_elol(rand() % 101);
    }

    l->print();
    return 0;
}