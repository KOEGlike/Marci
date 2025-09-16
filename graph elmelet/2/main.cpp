#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct ListElement
{
    int adat;
    ListElement *next = nullptr;
    ListElement(int adat, ListElement *next = nullptr)
    {
        this->adat = adat;
        this->next = next;
    }
    ~ListElement()
    {
        if (next)
        {
            delete next;
        }
    }
};

class List
{
private:
    ListElement *head;
    ListElement *tail;

public:
    List()
    {
        head = tail = nullptr;
    }
    ~List()
    {
        delete head;
        head = tail = nullptr;
    }
    void beszur_hatul(int adat)
    {
        ListElement *new_element = new ListElement(adat);
        if (head == nullptr)
        {
            head = tail = new_element;
        }
        else
        {
            tail->next = new_element;
            tail = new_element;
        }
    }

    void beszur_elol(int adat)
    {
        ListElement *new_element = new ListElement(adat);
        if (head == nullptr)
        {
            head = tail = new_element;
        }
        else
        {
            new_element->next = head;
            head = new_element;
        }
    }

    void beszur_rendez(int adat)
    {
        if (head == nullptr)
        {
            head = tail = new ListElement(adat);
        }
        else
        {

            if (adat >= head->adat)
            {
                head = new ListElement(adat, head);
            }
            else
            {
                ListElement *p;
                for (p = head; p->next != nullptr && p->next->adat > adat; p = p->next)
                    ;

                p->next = new ListElement(adat, p->next);
            }
        }
    }

    void kiir()
    {
        ListElement *i = head;
        while (i)
        {
            cout << i->adat << " ";
            i = i->next;
        }
    }
};

main()
{
    srand(time(0));
    List l = List();
    for (int i = 100; i > 0; i--)
    {
        int x = rand() % 1000;
        cout << x << " ";
        l.beszur_rendez(x);
    }
    cout << endl;
    l.kiir();
}