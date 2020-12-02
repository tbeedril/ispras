#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void do_addition(char *s1, int len1, char *s2, int len2)
{
    int len = max(len1, len2) + 1;
    char* s = malloc(len + 1);
    int i = 0;
    int sum = 0;
    int rem = 0;

    s[len] = 0;
    for (int j = 0; j < len; j++)
        s[j] = '0';
    while (len1 > 0 || len2 > 0 || rem) {
        if (len1 > 0 && len2 > 0) {
            sum = s1[len1 - 1] - '0' + s2[len2 - 1] - '0';
        } else if (len1 > 0) {
            sum = s1[len1 - 1] - '0';
        } else if (len2 > 0) {
            sum = s2[len2 - 1] - '0';
        }
        s[i] = (char)((sum + rem) % 10 + '0');
        rem = sum / 10;
        sum = 0;
        i++;
        len1--;
        len2--;
    }
    while (i > 0)
    {
        putchar(s[i - 1]);
        i--;
    }
    putchar('\n');
}

void do_subtraction(char *s1, int len1, char *s2, int len2)
{
    int len = max(len1, len2);
    char* s = malloc(len + 1);
    int i = 0;
    int sum = 0;
    int sign = 0;

    s[len] = 0;
    for (int j = 0; j < len; j++)
        s[j] = '0';
    if (len1 <= len2 && strcmp(s1, s2) < 0)
    {
        sign = 1;
        char* tmp = s1;
        s1 = s2;
        s2 = tmp;
        int t;
        t = len1;
        len1 = len2;
        len2 = t;
    }
    while (len1 > 0 || len2 > 0)
    {
        if (len1 > 0 && len2 > 0)
        {
            sum = s1[len1 - 1] - s2[len2 - 1];
        }
        else if (len1 > 0)
        {
            sum = s1[len1 - 1] - '0';
        }
        if (sum < 0)
        {
            sum += 10;
            int j = len1 - 1;
            while (j - 1 > 0 && s1[j - 1] == '0')
            {
                s1[j - 1] = '9';
                j--;
            }
            s1[j - 1]--;
        }
        s[i] = (char)(sum + '0');
        sum = 0;
        i++;
        len1--;
        len2--;
    }
    if (sign)
        putchar('-');
    while (i > 1 && s[i - 1] == '0')
        i--;
    while (i > 0)
    {
        putchar(s[i - 1]);
        i--;
    }
    putchar('\n');
}
int main(void)
{
    int len = 4;
    char* s1 = malloc(len + 1);
    s1[len] = 0;

    char c;
    int i = 0;
    while((c = getchar()) != '+' && c != '-' && c != '*')
    {
        if (len == i)
        {
            len *= 4;
            s1 = realloc(s1, len + 1);
        }
        s1[i] = c;
        i++;
    }
    s1 = realloc(s1, i + 1);
    s1[i] = 0;
    char operation = c;

    len = 4;
    char* s2 = malloc(len + 1);
    s2[len] = 0;

    int j = 0;
    while((c = getchar()) != '\n')
    {
        if (len == j)
        {
            len *= 4;
            s2 = realloc(s2, len + 1);
        }
        s2[j] = c;
        j++;
    }

    s2 = realloc(s2, j + 1);
    s2[j] = 0;

    if (operation == '+')
    {
        do_addition(s1, i, s2, j);
    }
    else if (operation == '-')
    {
       do_subtraction(s1, i, s2, j);
    }
    // else if (operation == '*')
    // {
    // do_multiplication(s1, s2);
    // }

    return 0;
}