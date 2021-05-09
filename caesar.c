#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int n = 1;
string ci;

int main(int argc, string argv[])
{
    // if no argument is given don't run rest of the program (by returning non-zero value)
    if (argv[1] == 0)
    {
        printf("%s\n", "Usage: ./caesar key");
        return 1;
    }
    else
    {
        // go through each arg, starting from the first (int i = 1) arg
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; j < strlen(argv[i]); j++)
            {
                if (isdigit(argv[i][j]) && argc == 2)
                {
                    // printf("%c\n", argv[i][j]);
                }
                else
                {
                    printf("%s\n", "Usage: ./caesar key");
                    return 1;
                }
            }
            // printf("%s\n", "Success");
            int key = atoi(argv[n]);
            // printf("%i\n", key);

            do
            {
                key = key % 26;
            }
            while (key > 26);
            // printf("%c", key);

            // prompt for plaintext, prints a placeholder for each ciphertext letter that will be output
            string pi = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int k = 0; k < strlen(pi); k++)
            {
                if (isalnum(pi[k]))
                {
                    // rebase for capital (ascii 64-90) letters
                    if (isupper(pi[k]))
                    {
                        if (pi[k] + key > 90)
                        {
                            int rem = (pi[k] + key) % 90;
                            printf("%c", 64 + rem);
                        }
                        else
                        {
                            printf("%c", pi[k] + key);
                        }
                    }
                    // rebase for lower (ascii 96-122) letters
                    else if (islower(pi[k]))
                    {
                        if (pi[k] + key > 122)
                        {
                            int rem = (pi[k] + key) % 122;
                            printf("%c", 96 + rem);
                        }
                        else
                        {
                            printf("%c", pi[k] + key);
                        }
                    }
                }
                else
                {
                    printf("%c", pi[k]);
                }
            }
            printf("\n");
        }
    }
}
