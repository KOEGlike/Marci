#include <iostream>
#include <ctime>
#include <cstdlib>

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
        if (next != nullptr)
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
    List(const List &other)
    {
        head = tail = nullptr;
        for (ListElement *ptr = other.head; ptr != nullptr; ptr = ptr->next)
        {
            beszur_hatul(ptr->adat);
        }
    }
    ~List()
    {
        delete head;
        head = tail = nullptr;
    }
    List &operator=(const List &other)
    {
        if (this != &other)
        {
            this->~List();

            head = tail = nullptr;
            for (ListElement *ptr = other.head; ptr != nullptr; ptr = ptr->next)
            {
                beszur_hatul(ptr->adat);
            }
        }
        return *this;
    }

    friend List operator+(const List &a, List &b)
    {
        List c;
        c = a;
        for (ListElement *ptr = b.head; ptr != nullptr; ptr = ptr->next)
        {
            c.beszur_hatul(ptr->adat);
        }
        return c;
    }

    friend ostream &operator<<(ostream &os, const List &lista)
    {
        ListElement *i = lista.head;
        while (i)
        {
            os << i->adat << " ";
            i = i->next;
        }
        os << endl;
        return os;
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
        if (head == NULL)
        {
            head = tail = new ListElement(adat);
        }
        else
        {
            if (adat >= head->adat)
            {
                ListElement *tmp = new ListElement(adat);
                tmp->next = head;
                head = tmp;
            }
            else
            {
                ListElement *p;
                for (p = head; p->next != NULL && adat < p->next->adat; p = p->next)
                    ;

                ListElement *tmp = new ListElement(adat);
                tmp->next = p->next;
                p->next = tmp;
            }
        }
    }

    void rendez()
    {
        for (ListElement *pi = this->head; pi != NULL; pi = pi->next)
        {
            ListElement *pmin = pi;
            for (ListElement *pj = pi->next; pj != NULL; pj = pj->next)
            {
                if (pj->adat < pmin->adat)
                {
                    pmin = pj;
                }
            }
            if (pmin != pi)
            {
                swap(pmin->adat, pi->adat);
            }
        }
        /*ListElement *tmp = pmin->next;
        if(pmin->next!=NULL)
        {
            pmin->next = pmin->next->next;
        }
        tmp->next = head;
        head = tmp;*/
    }

    void kiir()
    {
        ListElement *i = head;
        while (i)
        {
            cout << i->adat << " ";
            i = i->next;
        }
        cout << endl;
    }
    friend List fesul(List list1, List list2);
};

void feltolt_rendez(List &l, int n)
{
    for (int i = 0; i < n; i++)
    {
        l.beszur_rendez(rand() % 100);
    }
}

void feltolt_elol(List &l, int n)
{
    for (int i = 0; i < n; i++)
    {
        l.beszur_elol(rand() % 100);
    }
}

List fesul(List list1, List list2)
{
    List list3;
    ListElement *p1head = list1.head;
    ListElement *p2head = list2.head;
    ListElement *p3head = list3.head;
    ListElement *p3tail = list3.tail;

    while (p1head != NULL && p2head != NULL)
    {
        if (p1head->adat > p2head->adat)
        {
            ListElement *tmp = new ListElement(p1head->adat);
            if (p3head == NULL)
            {
                p3head = p3tail = tmp;
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
            if (p3head == NULL)
            {
                p3head = p3tail = tmp;
            }
            else
            {
                p3tail->next = tmp;
                p3tail = tmp;
            }
            p2head = p2head->next;
        }
    }
    while (p1head != NULL)
    {
        p3tail->next = new ListElement(p1head->adat);
        p3tail = p3tail->next;
        p1head = p1head->next;
    }
    while (p2head != NULL)
    {
        p3tail->next = new ListElement(p2head->adat);
        p3tail = p3tail->next;
        p2head = p2head->next;
    }
    list3.head = p3head;
    list3.tail = p3tail;
    return list3;
}

int main()
{

    srand(time(0));
    int n = 20;

    List l1 = List(), l2 = List();
    feltolt_rendez(l1, n);
    l1.kiir();
    feltolt_rendez(l2, n);
    l2.kiir();
    List list3 = fesul(l1, l2);
    list3.kiir();

    List list4;
    feltolt_elol(list4, n);
    list4.kiir();
    list4.rendez();
    list4.kiir();

    List list5;
    list5 = list4;
    list5.kiir();

    List a, b;

    for (int i = 0; i < 6; i++)
    {
        a.beszur_hatul(i);
    }
    for (int i = 6; i < 11; i++)
    {
        b.beszur_hatul(i);
    }
    cout << a + b;
}
