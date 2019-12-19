/**
 * credit.c
 *
 * Joao Marcos
 * joaomarcos@tuta.io
 *
 * Determines whether a provided credit card number
 * is valid according to Luhn’s algorithm.
 *
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declares the variable to store the credit card number
    long long cc;

    // Gets credit card number from user
    do
    {
        printf("Number: ");
        cc = get_long_long();
    }
    while (cc <= 0);

    // Get any other number (**variable numbering is right to left of cc number)
    long long n2 = (cc % 100) / 10;
    long long n4 = (cc % 10000) / 1000;
    long long n6 = (cc % 1000000) / 100000;
    long long n8 = (cc % 100000000) / 10000000;
    long long n10 = (cc % 10000000000) / 1000000000;
    long long n12 = (cc % 1000000000000) / 100000000000;
    long long n14 = (cc % 100000000000000) / 10000000000000;
    long long n16 = (cc % 10000000000000000) / 1000000000000000;

    // Sum all other digits multiplying than by 2 and
    // Making sure to sum individual digits when they are bigger than 9
    // e.g.: 12 = 1 + 2 and so on. This is done by doing % of 10 on each number
    // for separate units (12 = 2) and * 0.1 to separate the tens (12 = 1)
    int m2 = ((n2 * 2) % 10) + ((n2 * 2) * 0.1);
    int m4 = ((n4 * 2) % 10) + ((n4 * 2) * 0.1);
    int m6 = ((n6 * 2) % 10) + ((n6 * 2) * 0.1);
    int m8 = ((n8 * 2) % 10) + ((n8 * 2) * 0.1);
    int m10 = ((n10 * 2) % 10) + ((n10 * 2) * 0.1);
    int m12 = ((n12 * 2) % 10) + ((n12 * 2) * 0.1);
    int m14 = ((n14 * 2) % 10) + ((n14 * 2) * 0.1);
    int m16 = ((n16 * 2) % 10) + ((n16 * 2) * 0.1);

    int ao_sum = m2 + m4 + m6 + m8 + m10 + m12 + m14 + m16;

    // Get all the number not multiplied by 2
    long long n1 = (cc % 10);
    long long n3 = ((cc % 1000) / 100);
    long long n5 = ((cc % 100000) / 10000);
    long long n7 = ((cc % 10000000) / 1000000);
    long long n9 = ((cc % 1000000000) / 100000000);
    long long n11 = ((cc % 100000000000) / 10000000000);
    long long n13 = ((cc % 10000000000000) / 1000000000000);
    long long n15 = ((cc % 1000000000000000) / 100000000000000);

    // Sum the product of both digits groups: multiplied and not multiplied by 2
    int checksum = ao_sum + n1 + n3 + n5 + n7 + n9 + n11 + n13 + n15;

    // Verify if checksum is invalid and stop the program
    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // If the credit card is valid, check which credit card company it belongs to
    // by checking the credit card number's length and the first 2 digits

    // Mastercard or Visa(16 digits)
    int cc16dgt = n16 * 10 + n15;

    if (cc16dgt != 0)
    {
        if (cc16dgt > 50 && cc16dgt < 56)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (cc16dgt > 39 && cc16dgt < 50)
        {
            printf("VISA\n");
            return 0;
        }
    }

    // American Ex (15 digits)
    int cc15dgt = (n15 * 10) + n14;

    if (cc15dgt != 0)
    {
        if (cc15dgt == 34 || cc15dgt == 37)
        {
            printf("AMEX\n");
            return 0;
        }
    }

    // Visa(13 digit)

    if (n13 != 0)
    {
        if (n13 == 4)
        {
            printf("VISA\n");
            return 0;
        }
    }

    // No company code matches return Invalid
    else
    {
        printf("INVALID\n");
        return 0;
    }
}
