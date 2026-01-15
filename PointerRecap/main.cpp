#include <iostream>
#include <cstring>

using namespace std;

void kiir(char s[])
{
    for (char *p = s; *p != 0; p++)
    {
        cout << *p;
    }

    cout << '\n';
}

int stringLength(char s[])
{
    int len = 0;
    for (char *p = s; *p != 0; p++)
    {
        len++;
    }

    return len;
}

void stringCopy(char source[], char dest[])
{

    while (*source != 0)
    {
        *dest = *source;
        dest++;
        source++;
    }
}
void stringConcatenate(char source[], char dest[])
{

    while (*dest != 0)
    {
        dest++;
    }
    while (*source != 0)
    {
        *dest = *source;
        dest++;
        source++;
    }
}
void toUppercase(char s[])
{
    for (char *p = s; *p != 0; p++)
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *p = *p - 'a' + 'A';
        }
    }
}

int main()
{
    char s[100] = "szia";
    cout << s[4] << endl;
    for (int i = 0; s[i] != 0; i++)
    {
        cout << s[i] << endl;
    }

    char *p = s;
    cout << (s + 2) << endl;
    cout << (p + 2) << endl;

    char s2[100] = "geza kek az eg";
    kiir(s2);
    cout << stringLength(s2) << endl;
    char s3[100];
    stringCopy("szia", s3);
    cout << s3;
    cout << endl;
    stringConcatenate(s2, s3);
    cout << s3 << endl;
    toUppercase(s2);
    cout << s2 << endl;

    return 0;
}