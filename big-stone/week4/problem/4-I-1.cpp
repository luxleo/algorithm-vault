#include <bits/stdc++.h>
using namespace std;

int bit, N, X;
char s[11];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf(" %s %d", s, &X);
        if (s[0] == 'a' && s[1] == 'd') bit |= (1 << X);
        else if (s[0] == 'r') bit &= ~(1 << X);
        else if (s[0] == 'c') printf("%d\n", (bit & (1 << X)) ? 1 : 0);
        else if (s[0] == 't') bit ^= (1 << X);
        else if (s[0] == 'a' && s[1] == 'l') bit = (1 << 21) - 1;
        else bit = 0;
    }
    return 0;
}