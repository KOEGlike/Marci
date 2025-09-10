#include <iostream>
#include <vector>

using namespace std;

#define MAX_K 170
#define LEN MAX_K * 6 + 1

void eratoszteneszSzitaja(int n, int primek[])
{
    primek[0]=2;
    primek[1]=3;

    int db=2;

    for (int k = 1; k < MAX_K; k++)
    {
        for (int i = 0; i <= 1; i++)
        {
            int candidate = 6 * k + (i * 2 - 1);

            int j=0;
            for(; j<db; j++) {
                if(candidate%primek[j] == 0) {
                    break;
                }
            }
            if(j==db) {
                primek[db]=candidate;
                db++;
            }

            if(n==db) {
                return;
            }
        }
    }
}

void kiir(int n, int tomb[]) {
    for(int i=0; i<n; i++) {
        cout<<tomb[i]<<" ";
    }
}

int main()
{
    int primek[LEN], n;
    cout<<"n=";
    cin>>n;
    eratoszteneszSzitaja(n, primek);
    kiir(n, primek);

    return 0;
}