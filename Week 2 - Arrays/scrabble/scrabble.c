#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calculate_score(string word);

int main(void)
{
    // Ask Player 1 for a word
    string word1 = get_string("Player 1: ");
    // Ask Player 2 for a word
    string word2 = get_string("Player 2: ");

    // Calculate score for player 1
    int score1 = calculate_score(word1);
    // Calculate score for player 2
    int score2 = calculate_score(word2);

    // Check winner

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }

    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }

    else if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int calculate_score(string word)
{
    int score = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char c = toupper(word[i]);

        switch (c)
        {

            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                score = score + 1;
                break;

            case 'D':
            case 'G':
                score = score + 2;
                break;

            case 'B':
            case 'C':
            case 'M':
            case 'P':
                score = score + 3;
                break;

            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                score = score + 4;
                break;

            case 'K':
                score = score + 5;
                break;

            case 'J':
            case 'X':
                score = score + 8;
                break;

            case 'Q':
            case 'Z':
                score = score + 10;
                break;
        }
    }

    return score;
}
