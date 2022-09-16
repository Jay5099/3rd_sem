#include <math.h>
#include <stdio.h>
#include <string.h>
// 1st Question//

int binary(int num)
{
    int i = 0, j = 0;
    int b_num[20];
    for (i = 0; num != 0; i++)
    {
        b_num[i] = num % 2;
        num /= 2;
    }

    printf("The given number is : ");
    j = i;
    for (i = 0; i < j; i++)
    {
        printf("%d", b_num[j - i - 1]);
    }
    printf("\n");
    return 0;
}

// 2nd Question//

int decimal(int bin)
{
    int i = 0, dec_num = 0, bin_arr[100];
    if (bin == 0)
    {
        dec_num = 0;
    }
    else
    {
        for (i = 0; bin != 0; i++)
        {
            bin_arr[i] = bin % 10;
            bin /= 10;
            // printf("%d ", bin_arr[i]);

            dec_num += bin_arr[i] * pow(2, i);
        }
        printf(" The decimal number is : %d ", dec_num);
    }
    return 0;
}

// 3rd Question

long factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
}

// 4th Question

long long int btod(int a[], int k)
{
    int t = k;
    int i = 0;
    long long int v = 0;
    for (i = 0; i <= k; i++)
    {
        v += pow(2, t) * a[i];
        t--;
    }
    return v;
}

void addition_unsigned_binary_num_U21CS129(char s1[], char s2[], int l, int m)
{
    int a[100], b[100], c[100], i, j, k;
    for (i = 0; i < l; i++)
    {
        a[i] = s1[i] - 48;
    }
    for (i = 0; i < m; i++)
    {
        b[i] = s2[i] - 48;
    }
    int x = btod(a, strlen(s1) - 1);
    int y = btod(b, strlen(s2) - 1);
    int z = x + y;
    dtob4(z);
}
void dtob4(int x)
{
    int y = x;
    int a[100];
    int k, i = 0;
    while (y != 0)
    {
        int temp = y % 2;
        a[i] = temp;
        y = y / 2;
        i++;
    }
    printf("The addition of two unsigned binary is -->");
    for (k = i - 1; k >= 0; k--)
    {
        printf("%d", a[k]);
    }
    printf("<-----And in decimal its value is %d\n", x);
}

// 5th q

// to convert decimal to binary
void bin(int n)
{
    int size = sizeof(int) * 8;
    char _bin[size];
    int k;
    if (n < 0)
    {
        for (k = 0; k < size; k++)
            _bin[k] = '1';
        n = (-n) - 1;
    }
    else
    {
        for (k = 0; k < size; k++)
            _bin[k] = '0';
    }
    int j = size - 1;
    int i = 1;
    while (i <= n)
    {
        if (i & n)
            _bin[j] = (_bin[j] == '1') ? '0' : '1';
        j--;
        i <<= 1;
    }
    for (k = 0; k < size; k++)
        printf("%c", _bin[k]);
}

long long int dec(char *s, int len)
{
    long long int res = 0;

    long long int _pow = 1;
    while (len >= 0)
    {
        if (s[len] == '1')
        {
            res += _pow;
        }
        _pow *= 2;
        len--;
    }
    return res;
}

void addition_unsigned_binary_numbers_U21CS129(char *s1, char *s2, int size)
{
    // using header functions

    // long long int res=dec(s1,len1) + dec(s2,len2);
    // printf("%d\n",res);
    // bin(res);

    int len1 = strlen(s1) - 1;
    int len2 = strlen(s2) - 1;
    int carry = 0;
    char res[size + 1];
    int i;

    for (i = 0; i < size; i++)
        res[i] = '0';

    i = size - 1;
    int one, two;
    while (i >= 0 && (len1 >= 0 || len2 >= 0 || carry != 0))
    {
        one = (len1 >= 0) ? s1[len1] - '0' : 0;
        two = (len2 >= 0) ? s2[len2] - '0' : 0;
        res[i] = ((one + two + carry) % 2 == 0) ? '0' : '1';
        carry = (one + two + carry) / 2;
        len1--;
        len2--;
        i--;
    }
    res[size] = '\0';
    printf("%s\n", res);
}
void complement_2(char *s, int size)
{
    int i = size - 1;
    while (s[i] != '1')
        i--;
    i--;
    while (i >= 0)
    {
        s[i] = (s[i] == '1') ? '0' : '1';
        i--;
    }
}
void properbits(char *s, int size)
{
    int i = size - 1;
    int len = strlen(s) - 1;
    while (len > 0)
    {
        s[i] = s[len];
        len--;
        i--;
    }
    while (i > 0)
    {
        s[i] = '0';
        i--;
    }
    s[size] = '\0';
}
void addition_signed_binary_numbers_U21CS129(char *s1, char *s2, int size)
{
    properbits(s1, size);
    properbits(s2, size);
    // convert the -ve numbers to their unsigned equivalent
    if (s1[0] != '1' && s2[0] != '1')
    {
        addition_unsigned_binary_numbers_U21CS129(s1, s2, size);
    }
    else if (s1[0] == '1')
    {
        char *temp = s2;
        s2 = s1;
        s1 = temp;
    }
    complement_2(s2, size);
    addition_unsigned_binary_numbers_U21CS129(s1, s2, size);

    int len1 = strlen(s1) - 1;
    int len2 = strlen(s2) - 1;
    int carry = 0;
    char res[size + 1];
    int i;
    for (i = 0; i < size; i++)
        res[i] = '0';

    i = size - 1;
    int one, two;
    while (i > 0 && (len1 >= 0 || len2 >= 0 || carry != 0))
    {
        one = (len1 >= 0) ? s1[len1] - '0' : 0;
        two = (len2 >= 0) ? s2[len2] - '0' : 0;
        res[i] = ((one + two + carry) % 2 == 0) ? '0' : '1';
        carry = (one + two + carry) / 2;
        len1--;
        len2--;
        i--;
        // printf("%d %s\n",carry,res);
    }
    res[size] = '\0';
    if (!carry)
    {
        complement_2(res, size);
    }
    printf("%s\n", res);
}

// factroial
long long int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
}
