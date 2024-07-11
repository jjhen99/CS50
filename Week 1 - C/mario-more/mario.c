#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_blocks(int size);

int main(void)
{
    // Get number from user. Has to be between 1 and 8.
    int n = get_height();

    // Print blocks based on height
    print_blocks(n);
}

int get_height(void)
{
    int n;

    do
    {
        n = get_int("Size of tower: ");
    }
    while (n < 1 || n > 8);

    return n;
}

void print_blocks(int size)
{
    int space = size;
    int hashtag = 1;

    for (int j = 0; j < size; j++)
    {

        // Print the number of spaces
        for (int i = 0; i < (space - 1); i++)
        {
            printf(" ");
        }

        // Print the number of hashtags on left side
        for (int i = 0; i < hashtag; i++)
        {
            printf("#");
        }
        // Print the two spaces in the hole
        printf("  ");

        // Print the number of hashtags on right side
        for (int i = 0; i < hashtag; i++)
        {
            printf("#");
        }

        space--;
        hashtag++;
        printf("\n");
    }
}
