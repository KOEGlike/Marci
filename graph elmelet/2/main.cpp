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
        cout << endl
             << endl;
    }

    friend List fesul_maskepp(List &l1, List &l2);
    friend List fesul(List &l1, List &l2);
};

void feltolt(List &l, int n)
{
    for (int i = 0; i < n; i++)
    {
        l.beszur_rendez(rand());
    }
}

List fesul(List &l1, List &l2)
{
    List l3;

    ListElement *p1 = l1.head;
    ListElement *p2 = l2.head;

    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->adat > p2->adat)
        {
            l3.beszur_elol(p1->adat);
            p2 = p2->next;
        }
        else
        {
            p1 = p1->next;
        }
    }
    return l3;
}

List fesul_maskepp(List &l1, List &l2)
{
    List l3;

    ListElement *p1head = l1.head;
    ListElement *p2head = l2.head;
    ListElement *p3tail = l3.tail;
    ListElement *p3head = l3.head;

    while (p1head != nullptr && p2head != nullptr)
    {

        if (p1head->adat > p2head->adat)
        {
            ListElement *tmp = new ListElement(p1head->adat);
            if (p3head == nullptr)
            {
                p3tail = p3head = tmp;
            }
            else
            {
                p3tail->next = tmp;
                p3tail = tmp;
            }
            p1head = p1head->next;
        }
        else
        {
            ListElement *tmp = new ListElement(p2head->adat);
            if (p3head == nullptr)
            {
                p3tail = p3head = tmp;
            }
            else
            {
                tmp->next = p3head;
                p3head = tmp;
            }
            p2head = p2head->next;
        }
    }

    l3.head = p3head;
    l3.tail = p3tail;
    return l3;
}

int main()
{
    srand(time(0));
    int n = 5;
    List l1 = List(), l2 = List();
    feltolt(l1, n);
    feltolt(l2, n);
    l1.kiir();
    l2.kiir();
    List l3 = fesul_maskepp(l1, l2);
    l3.kiir();
}