#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float coleman(string text);

int main(void)
{
    // Ask for text
    string text = get_string("Text: ");

    // Use coleman-lieu index to find average number of letters per 100 in the text

    // and find average number of words per sentence

    float grade = coleman(text);

    // Print grade of text

    int gradeInt = (int) round(grade);

    if (gradeInt > 16)
    {
        printf("Grade 16+\n");
    }

    else if (gradeInt < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %i\n", gradeInt);
    }
}

float coleman(string text)
{
    float grade = 0;
    float words = 0;
    float L = 0;
    float S = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];
        // Find number of letters in text
        if (isalpha(c))
        {
            L++;
        }

        // Find number of sentences in text

        else if (c == '.')
        {
            S++;
        }

        else if (c == '!')
        {
            S++;
        }

        else if (c == '?')
        {
            S++;
        }

        // find number of words in text

        else if (isblank(c))
        {
            words++;
        }
    }
    // Add +1 to words to account for final word
    words++;

    grade = 0.0588 * (L / words) * 100 - 0.296 * (S / words) * 100 - 15.8;

    return grade;
}
