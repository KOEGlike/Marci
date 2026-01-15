#include <iostream>

using namespace std;

int string_cmp(char s1[], char s2[])
{
    while (*s1 != 0 || *s2 != 0)
    {
        if (*s1 != *s2)
        {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int main()
{
    char s[] = "this is a lol";
    char ss[] = "this is a xd";
    cout << string_cmp(s, ss);
}