#include <iostream>

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
    List l = List();
    for (int i = 0; i < 10; i++)
    {
        l.beszur_hatul(i);
        l.beszur_elol(i * 2);
    }
    l.kiir();
}