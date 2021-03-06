#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int decrypt(char* plaintext, int key)
{
	char ciphertext[100];
	int ascii;

	for (int i=0; i<strlen(plaintext); i++)
	{
		plaintext[i] = tolower(plaintext[i]);
	}

	for (int i=0; i<strlen(plaintext); i++)
	{
		if (isalpha(plaintext[i]))
		{
			ascii = plaintext[i] - key;
			if (ascii <97)
			{
				ascii = ascii +26;
			}
			ciphertext[i]= ascii;
		}
		else
		{
			ciphertext[i] = plaintext[i];
		}

		printf("%c", ciphertext[i]);
	}
	return 0;
}
int encrypt(char* plaintext, int key)
{
	char ciphertext[100];
	int ascii;

	for (int i=0; i<strlen(plaintext); i++)
	{
		plaintext[i] = tolower(plaintext[i]);
	}

	for (int i=0; i<strlen(plaintext); i++)
	{
		if (isalpha(plaintext[i]))
		{
			ascii = plaintext[i] + key;
			if (ascii > 122)
			{
				ascii = ascii -26;
			}
			ciphertext[i]= ascii;
		}
		else
		{
			ciphertext[i] = plaintext[i];
		}

		printf("%c", ciphertext[i]);
	}
	return 0;
}


int main(int argc, char* argv[])
{
	char* plaintext;
	int key;
	char* choice;
	if (argc != 4)
	{
		printf("Please input plaintext and a key!");
	}
	else
	{
		plaintext = argv[1];
		key = atoi(argv[2]);
		choice = argv[3];
	}
	int decision = choice[0];
	if (decision == 69)
	{
		encrypt(plaintext, key);
	}
	else
	{
		decrypt(plaintext,key);
	}

	printf("\n");
}


