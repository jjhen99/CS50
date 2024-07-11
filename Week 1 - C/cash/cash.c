#include <cs50.h>
#include <stdio.h>

int get_cents(void);
void calculate_coins(int cents);

int main(void)
{
    // Get number of cents from customer
    int cents = get_cents();

    // Calculate coins owed
    calculate_coins(cents);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    return cents;
}

void calculate_coins(int cents)
{
    int coins = 0;
    // Subtract 25 cents until an integer less than zero is reached
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }

    // Subtract 10 until an integer less than zero is reached
    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }

    // Subtract 5 until an integer less than zero is reached
    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }

    // Subtract 1 until an integer less than zero is reached
    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }

    printf("%i\n", coins);
}
