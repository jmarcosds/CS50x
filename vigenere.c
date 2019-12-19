/**
 * vigenere.c
 *
 * Joao Marcos
 * joaomarcos@tuta.io
 *
 * Encrypts a text entered by the user using the Vigenère cipher encryption.
 * The program needs one argument, which is the secret key for the cipher.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int errorChecker(int argn, string args[]);

void encrypter(string keyword, string message);

int main(int argc, string argv[])
{
    // Checks for no argument, more than 1 argument and argument with number(s)
    if (errorChecker(argc, argv) > 0)
    {
        return 1;
    }

    // Stores secret keyword entered by user
    string skw = argv[1];

    // Gets message from user to be encrypted
    printf("plaintext: ");
    string msg = get_string();

    // Encrypts the message
    encrypter(skw, msg);

    return 0;
}

int errorChecker(int argn, string args[])
{
    // Returns an error if the user doesn't give an argument
    if (args[1] == NULL)
    {
        printf("This program needs an argument for the secret keyword.\n"
               "Please use: ./vigenere <secret keyword>\n"
               "For example: ./vigenere bacon\n");

        return 1;
    }
    // Returns an error if the user gives more than one argument
    else if (argn > 2)
    {
        printf("This program needs only one argument for the secret key.\n"
               "Please use: ./vigenere <secret keyword>\n"
               "For example: ./vigenere bacon\n");

        return 1;
    }

    // Returns an error if the user used a number in the keyword
    for (int i = 0, n = strlen(args[1]); i < n; i++)
    {
        if (isdigit(args[1][i]))
        {
            printf("The keyword cannot contain number(s).\n"
                   "Please use: ./vigenere <secret keyword>\n"
                   "For example: ./vigenere bacon\n");

            return 1;
        }
    }
    return 0;
}

void encrypter(string keyword, string message)
{
    // Stores the number of characters of keyword to be used as index
    int kwlen = strlen(keyword);

    // Changes the case of any uppercase char in the keyword to lowercase
    for (int i = 0; i < kwlen; i++)
    {
        keyword[i] = tolower(keyword[i]);
    }

    // Prints cyphertext
    printf("ciphertext: ");

    // Loop that will encript each relevant character
    for (int i = 0, j = 0, n = strlen(message); i < n; i++)
    {
        // Discard any punctuation or spaces from encription
        if (ispunct(message[i]) || isblank(message[i]))
        {
            printf("%c", message[i]);
        }
        // Encription of uppercase character of the message
        if (isupper(message[i]))
        {
            int kwidxmod = keyword[j % kwlen];
            printf("%c", (((kwidxmod - 'a' + (message[i] - 'A')) % 26) + 'A'));
            j++;
        }
        // Encription of lowercase character of the message
        if (islower(message[i]))
        {
            int kwidxmod = keyword[j % kwlen];
            printf("%c", (((kwidxmod - 'a' + (message[i] - 'a')) % 26) + 'a'));
            j++;
        }
    }
    // Prints a line break at the end for redability
    printf("\n");
}
