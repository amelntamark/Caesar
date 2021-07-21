#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 

bool valid_key(string user_input);

int main(int argc, string argv[])
{
    // Confirm user entered two strings
    
    string user_key = argv[1];
    int key;
    string plaintext;
    
    if (argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return false;
    }
    if (argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1; 
    }
    // Confirm user entered valid numerical key and cast the string to an int
    else if (argc == 2)
    {
        valid_key(user_key);
    }
    
    key = atoi(user_key);
    
    // Get plaintext from user
    if (key == 0)
    {
        return false;
        printf("Usage: ./caesar key\n");
    }
    else if (key > 0)
    {
        plaintext = get_string("plaintext: ");
    }
    
    // Encrypt plaintext and print ciphertext 
    printf("ciphertext: ");
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] - 65) + key) % 26) + 65);
            }
            if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] - 97) + key) % 26) + 97);
            }
        }
        else if (isspace(plaintext[i]))
        {
            printf(" ");
        }
        else if (isdigit(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        else if (ispunct(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        else 
        {
            i++;
        }
    }
    printf("\n");
   
    
}


// Custom function: ensures user entered a numerical value as a key
bool valid_key(string user_input)
{
    for (int i = 0, len = strlen(user_input); i < len; i++)
    {   
        if (isalpha(user_input[i]))
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
        else if (ispunct(user_input[i]))
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
        else
        {
            i++;
        }
    }
    
    return true;
}



