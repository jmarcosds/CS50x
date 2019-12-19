/**
 * crack.c
 *
 * Joao Marcos
 * joaomarcos@tuta.io
 *
 * Cracks passwords composed of up to 4 alphabetic characters using the hash of the password.
 * Passwords must have been hashed with C's DES-based crypt function, in order to work.
 *
 */

#define _XOPEN_SOURCE

// This constant is the same as 'A' to 'z', which gives 58 characters in total on the ASCII table
#define A_TO_z 58

#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int hashChecker(int argn, char *args[]);

void cracker(string hash);

int main(int argc, char *argv[])
{
    // Checks for no argument, more than 1 argument and argument with not exact 13 characters
    if (hashChecker(argc, argv) > 0)
    {
        return 1;
    }

    // Stores hash entered by user
    string hash = argv[1];

    cracker(hash);

    return 0;
}

int hashChecker(int argn, char *args[])
{
    // Returns an error if the user doesn't give an argument
    if (args[1] == NULL)
    {
        printf("This program needs an argument for the hash.\n"
               "Please use: ./crack <hash>\n"
               "For example: ./crack 50fkUxYHbnXGw\n");

        return 1;
    }
    // Returns an error if the user gives more than one argument
    else if (argn > 2)
    {
        printf("This program needs only one argument for the hash.\n"
               "Please use: ./crack <hash>\n"
               "For example: ./crack 50fkUxYHbnXGw\n");

        return 1;
    }

    // Returns an error if the user used a number in the keyword
    for (int i = 0, n = strlen(args[1]); i < n; i++)
    {
        if (strlen(args[1]) != 13)
        {
            printf("The hash needs to be exact 13 characters\n"
                   "Please use: ./crack <hash>\n"
                   "For example: ./crack 50fkUxYHbnXGw\n");

            return 1;
        }
    }
    return 0;
}

void cracker(char *hash)
{
    // Defines a char array (very important to be a char array and not a string array or char *) to store all the plaintexts
    // to be hashed and tried against the hash provided by the user
    char trythis[5] = {'A', '\0'};

    // Sequence of loops that will generate plaintext up to 4 characters, hash using the crypt function, and
    // check using "strcmp" string compare (don't know why == won't work) if hash created matches with user's hash
    // and print the generated plaintext in case it matches
    int a4 = 0;

    // Note that "A_TO_z" is the constant declared on the very top. It basically means the number 58, which will allow us
    // to iterate from capital 'A' to lowercase 'z'
    while (a4 < A_TO_z)
    {
        int a3 = 0;
        while (a3 < A_TO_z)
        {
            int a2 = 0;
            while (a2 < A_TO_z)
            {
                int a1 = 0;
                while (a1 < A_TO_z)
                {
                    trythis[0] = a1 + 'A';
                    a1++;

                    // Using the salt as 50, because all the passwords to be broken uses 50 as salt :)
                    string cs50salt = "50";

                    // Creates a hash based on the generated plain text
                    string hashme = crypt(trythis, cs50salt);

                    // Verifies if the plaintext hash matches with the user's hash and if it does, prints the plaintext,
                    // which should be the cracked password :)
                    if (strcmp(hashme, hash) == 0)
                    {
                        printf("%c%c%c%c%c\n", trythis[0], trythis[1], trythis[2], trythis[3], trythis[4]);
                    }
                }
                trythis[1] = a2 + 'A';
                a2++;

                string cs50salt = "50";
                string hashme = crypt(trythis, cs50salt);

                if (strcmp(hashme, hash) == 0)
                {
                    printf("%c%c%c%c%c\n", trythis[0], trythis[1], trythis[2], trythis[3], trythis[4]);
                }
            }
            trythis[2] = a3 + 'A';
            a3++;

            string cs50salt = "50";
            string hashme = crypt(trythis, cs50salt);

            if (strcmp(hashme, hash) == 0)
            {
                printf("%c%c%c%c%c\n", trythis[0], trythis[1], trythis[2], trythis[3], trythis[4]);
            }
        }
        trythis[3] = a4 + 'A';
        a4++;

        string cs50salt = "50";
        string hashme = crypt(trythis, cs50salt);

        if (strcmp(hashme, hash) == 0)
        {
            printf("%c%c%c%c%c\n", trythis[0], trythis[1], trythis[2], trythis[3], trythis[4]);
        }
    }
}
