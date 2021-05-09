#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // prompt to input string
    string sentence = get_string("Text: ");
    printf("%s\n", sentence);
    // print total number of alnum chars
    int len = strlen(sentence);
    printf("%i\n", len);
    // initialise private variables for the upcoming enumeration
    int i = 0;
    float l = 0;
    float w = 1;
    float s = 0;
    // iterate through each char of string
    for (i = 0; i < len ; i++)
    {
        if (isalpha(sentence[i]))
        {
            printf("%c", sentence[i]);
            l += 1;
        }
        else if (isspace(sentence[i]))
        {
            printf("%c", sentence[i]);
            w += 1;
        }
        // remember when comparing chars you must put comparator in single quote ''
        else if (sentence[i] == '.' || sentence[i] == '!' || sentence[i] == '?')
        {
            printf("%c", sentence[i]);
            s += 1;
        }
    }
    printf("\n");
    // print total number of alpha after variable l finishes iterating through the chars of the sentence
    int lr = round(l);
    int wr = round(w);
    int sr = round(s);
    printf("%i letter(s)\n", round(l));
    printf("%i word(s)\n", wr);
    printf("%i sentence(s)\n", sr);
    float L = (l / w) * 100;
    printf("%f\n", L);
    float S = (s / w) * 100;
    printf("%f\n", S);
    int g = round(0.0588 * L - 0.296 * S - 15.8);
    printf("%i\n", g);
    if (g < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (g >= 16)
    {
        printf("Grade 16+\n");
    }
    else //if (g > 1)
    {
        printf("Grade %i\n", g);
    }
}