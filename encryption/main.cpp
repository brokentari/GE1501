#include <iostream>
#include <string>

// ASCII alphabet - A-z (65-90)
// lowercase        a-z (97-122)

std::string encrypt(std::string decrypted, int seed)
{
    srand(seed);

    int encrypted_ascii;
    int shifts[decrypted.size()];
    char encrypted_message[decrypted.size()];
    char encrypted_character;

    for (int i = 0; i < decrypted.size(); i++)
    {
        shifts[i] = rand() % 30 + 1;
        int ascii_temp = decrypted[i] - 65;
        if (ascii_temp < 0 || ascii_temp > 57)
        {
            encrypted_ascii = ascii_temp + 65;
        }
        else
        {
            if (ascii_temp <= 25)
            {
                int modified_ascii = (ascii_temp + shifts[i]) % 26;
                encrypted_ascii = modified_ascii + 65;
            }
            else
            {
                ascii_temp = decrypted[i] - 97;
                int modified_ascii = (ascii_temp + shifts[i]) % 26;
                encrypted_ascii = modified_ascii + 97;
            }
        }

        encrypted_character = encrypted_ascii;
        encrypted_message[i] = encrypted_character;

        // debugging purposes
        // std::cout << decrypted[i] << " -> " << encrypted_character << " shift: " << shifts[i] << std::endl;
    }
    encrypted_message[decrypted.size()] = '\0'; // Adds a null character at the end of the string to prevent strange characters

    std::string encrypted_message_string = encrypted_message;

    return encrypted_message_string;
}

std::string decrypt(std::string encrypted, int seed)
{
    srand(seed);

    int shifts[encrypted.size()];
    char decrypted_message[encrypted.size()];
    int decrypted_ascii;
    char decrypted_character;

    for (int i = 0; i < encrypted.size(); i++)
    {
        shifts[i] = rand() % 30 + 1;
        int ascii_temp = encrypted[i] - 65;

        if (ascii_temp < 0 || ascii_temp > 57)
        {
            decrypted_ascii = ascii_temp + 65;
        }
        else
        {
            if (ascii_temp <= 25)
            {
                int modified_ascii = (ascii_temp - shifts[i]) % 26;
                decrypted_ascii = modified_ascii + 65;
            }
            else
            {
                ascii_temp = encrypted[i] - 97;
                int modified_ascii = (ascii_temp - shifts[i]) % 26;
                if (modified_ascii < 0)
                {
                    modified_ascii = modified_ascii + 26;
                }
                decrypted_ascii = modified_ascii + 97;
            }
        }

        decrypted_character = decrypted_ascii;
        decrypted_message[i] = decrypted_character;

        // debugging purposes
        // std::cout << encrypted[i] << " -> " << decrypted_character << " shift: " << shifts[i] << std::endl;
    }
    decrypted_message[encrypted.size()] = '\0'; // Adds a null character at the end of the string to prevent strange characters
    std::string decrypted_message_string = decrypted_message;

    return decrypted_message_string;
}

int main()
{
    int check = 0;
    int seed;
    char enc_or_dec;
    std::string input_message;

    std::cout << ("message?: ") << std::endl;
    std::getline(std::cin, input_message);
    std::cout << std::endl;

    std::cout << ("code key: ");
    std::cin >> seed;
    std::cout << std::endl;

    std::cout << ("(e)ncryption or (d)ecryption?:  ");
    std::cin >> enc_or_dec;
    std::cout << std::endl
              << std::endl;

    if (enc_or_dec == 'e')
    {
        std::cout << "your encrypted message is: " << encrypt(input_message, seed) << std::endl;
    }
    else if (enc_or_dec == 'd')
    {
        std::cout << "your decrypted message is: " << decrypt(input_message, seed) << std::endl;
    }
}
