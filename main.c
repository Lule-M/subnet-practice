#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct 
{
	int octets[4];
} Address;

Address GenerateRandomAddress(int min, int max)
{
	Address address;
	unsigned int seed = time(0);

	for (int i = 0; i < 4; i++)
	{
		address.octets[i] = rand_r(&seed) % (max - min + 1) + min;
	}

	return address;
}

int main(int argc, char **argv)
{

/*	if (argc != 3)
	{
		printf("Error: Expected exactly 2 arguments, recieved %d\n", argc-1);
		return 1;
	}
*/
	Address address = GenerateRandomAddress(10, 255);

	printf("%d.%d.%d.%d\n", address.octets[0], address.octets[1], address.octets[2], address.octets[3]);

	return 0;
}
