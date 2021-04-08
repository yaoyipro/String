// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
// this program shows all the permutations of a string.  There is 2 method, one used 2 additional strings, the other just use recursion to swap the elements of string around.
// Both work! :)


#include <iostream>
using namespace std;

void perm(char s[], int k)
{
    static int A[10] = { 0 };
    static char Res[10];
    int i;

    if (s[k] == '\0')
    {
        Res[k] = '\0', printf("%s\n", Res);
    }
    else 
        for (i = 0; s[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = s[i];
                A[i] = 1;
                perm(s, k + 1);
                A[i] = 0;
            }
        }
}

void permutation(char s[], int l, int h) 
{
    int i;
    if (l == h)
    {
        printf("%s \n", s);
    }
    else
    {
        for (i = l; i <= h; i++)
        {
            swap(s[l], s[i]);
            permutation(s, l + 1, h);
            swap(s[l], s[i]);
        }
    }

}

int main()
{
    char s[] = "ABC";
    int len = strlen(s);
    //perm(s, 0);
    permutation(s, 0, len-1);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
