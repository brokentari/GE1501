#include <iostream>
#include <sstream>

// Prints each of the random numbers and the letters associated with it
// (used to double check the logic)
void debug_mode(int rand_chars[6], char coded_chars[6])
{
    for (int i = 0; i <= 5; ++i)
    {
        std::cout << rand_chars[i];
        std::cout << (" -> ");
        std::cout << coded_chars[i] << std::endl;
    }
    std::cout << std::endl;
}

// Only prints the coded characters
void regular_mode(char coded_chars[6])
{
    for (int i = 0; i <= 5; ++i)
    {
        std::cout << coded_chars[i];
    }
}

int main()
{
    int test_mode = 1;
    int seed;

    // Ask user to input a number to be used as seed
    std::cout << ("enter a number: ");
    std::cin >> seed;

    std::cout << ("test mode? [(1) for regular mode || (2) for debug mode]  ");
    std::cin >> test_mode;
    std::cout << std::endl;

    srand(seed); // Set the user inputted number as seed

    // Initialize empty arrays for the code and rand. #s
    char coded_num[6] = {};
    int random_num[6] = {};

    // Creating array of random numbers, with seed set
    for (int a = 0; a < 5; a = a + 1)
    {
        random_num[a] = rand() % 200 + 1;
    }

    // Conditions for first letter
    if (random_num[0] % 2 == 0)
    {
        coded_num[0] = 'C';
    }
    else
    {
        coded_num[0] = 'E';
    }

    // Conditions for second letter
    if (random_num[1] > random_num[2])
    {
        coded_num[1] = 'G';
    }
    else
    {
        if (random_num[1] % 5 == 0)
        {
            coded_num[1] = 'E';
        }
        else
        {
            coded_num[1] = 'C';
        }
    }

    // Conditions for third letter
    if (random_num[2] < 34)
    {
        coded_num[2] = 'C';
    }
    else if (34 <= random_num[2] && random_num[2] <= 66)
    {
        coded_num[2] = 'B';
    }
    else
    {
        coded_num[2] = 'E';
    }

    // Conditions for fourth letter
    if (random_num[5] > random_num[0] && random_num[6] > random_num[1])
    {
        coded_num[3] = 'A';
    }
    else
    {
        coded_num[3] = 'F';
    }

    // Conditions for fifth letter
    if ((random_num[4] + random_num[5] >= (random_num[1] + random_num[3])) ||
        (random_num[3] >= 100))
    {
        coded_num[4] = 'G';
    }
    else
    {
        coded_num[4] = 'B';
    }

    // Conditions for sixth(last) letter
    if (random_num[5] < 100)
    {
        coded_num[5] = coded_num[0];
    }
    else if (150 >= coded_num[5] >= 100)
    {
        coded_num[5] = 'D';
    }
    else
    {
        coded_num[5] = 'G';
    }

    // Decides how to print out the final characters
    if (test_mode == 1)
    {
        regular_mode(coded_num);
    }
    else
    {
        debug_mode(random_num, coded_num);
    }

    std::cout << std::endl;

    return 0;
}
