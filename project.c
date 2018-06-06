#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int decrypt(char* plaintext, char* key)
{
	char ciphertext[100];
	int shift[strlen(key)];
	int ctr;
	int ascii;

	for (int i=0; i<strlen(key); i++)
	{
		key[i] = tolower(key[i]);
		shift[i] = key[i] -97;
	}
	for (int i=0; i<strlen(plaintext); i++)
	{
		plaintext[i] = tolower(plaintext[i]);
	}

	for (int i=0; i<strlen(plaintext); i++)
	{
		if ( i >= strlen(key))
		{
			ctr = i %  strlen(key);
		}
		else
		{
			ctr = i;
		}

		if (isalpha(plaintext[i]))
		{
			ascii =((abs((plaintext[i]-97) - shift[ctr]))%26)+97;
			ciphertext[i]= ascii;
			
			int value = plaintext[i] - shift[ctr];
		/*	if (value < 0)
			{
			ascii =(((shift[ctr]-97) - plaintext[i])%26)+97;
			ciphertext[i]= ascii;
			}
			else
			{
			ascii =(((plaintext[i]-97) - shift[ctr])%26)+97;
			ciphertext[i]= ascii;
			}
	*/	}
		else
		{
			ciphertext[i] = plaintext[i];
		}

		printf("%c", ciphertext[i]);
	}
	return 0;
}

int encrypt(char* plaintext, char* key)
{
	char ciphertext[100];
	int shift[strlen(key)];
	int ctr;
	int ascii;

	for (int i=0; i<strlen(key); i++)
	{
		key[i] = tolower(key[i]);
		shift[i] = key[i] -97;
	}
	for (int i=0; i<strlen(plaintext); i++)
	{
		plaintext[i] = tolower(plaintext[i]);
	}

	for (int i=0; i<strlen(plaintext); i++)
	{
		if ( i >= strlen(key))
		{
			ctr = i %  strlen(key);
		}
		else
		{
			ctr = i;
		}

		if (isalpha(plaintext[i]))
		{
			ascii =(((plaintext[i]-97) + shift[ctr])%26)+97;
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
	char* key;
	if (argc != 3)
	{
		printf("Please input plaintext and a key!");
	}
	else
	{
		plaintext = argv[1];
		key = argv[2];
	}
//	encrypt(plaintext, key);
	decrypt(plaintext,key);
	printf("\n");
}


