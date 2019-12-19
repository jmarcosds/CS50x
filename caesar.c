/**
 * caesar.c
 *
 * Joao Marcos
 * joaomarcos@tuta.io
 *
 * Encrypts a text entered by the user using the Caesar's cipher encryption.
 * The program needs one argument, which is the secret key for the cipher.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int ErrorChecker(int arga, string argb[]);

int main(int argc, string argv[])
{
    // Checks for no argument, more than 1 argument and argument less than 0
    if (ErrorChecker(argc, argv) > 0)
    {
        return 1;
    }

    // Stores secret key entered by user and converts it to integer
    int key = atoi(argv[1]);

    // Gets message from user to be encrypted
    printf("plaintext: ");
    string msg = get_string();

    // Encrypts the message and prints it

    printf("ciphertext: ");
    for (int i = 0, n = strlen(msg); i < n; i++)
    {
        // Discard any punctuation or spaces from encription
        if (ispunct(msg[i]) || isblank(msg[i]))
        {
            printf("%c", msg[i]);
        }
        // Encription of uppercase character of the message
        else if (isupper(msg[i]))
        {
            int UpCipher = (((int) msg[i] - 'A' + key) % 26) + 'A';
            printf("%c", UpCipher);
        }
        // Encription of lowercase character of the message
        else if (islower(msg[i]))
        {
            int LwCipher = (((int) msg[i] - 'a' + key) % 26) + 'a';
            printf("%c", LwCipher);
        }
    }
    // Prints a line break at the end for redability
    printf("\n");
    return 0;
}

int ErrorChecker(int arga, string argb[])
{
    // Returns an error if the user doesn't give an argument
    if (argb[1] == NULL)
    {
        printf("This program needs an argument for the secret key number.\n"
               "Please use: ./caesar <secret key number>\n"
               "For example: ./caesar 13\n");

        return 1;
    }
    // Returns an error if the user gives more than one argument
    else if (arga > 2)
    {
        printf("This program needs only one argument for the secret key.\n"
               "Please use: ./caesar <secret key number>\n"
               "For example: ./caesar 13\n");

        return 1;
    }
    // Returns an error if user doesn't give a number bigger than 0
    if ((atoi(argb[1])) < 1)
    {
        printf("The secret key needs to be a number bigger than 0.\n");

        return 1;
    }
    return 0;
}
