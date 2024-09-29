#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int networks[4];
	int computers[4];
} Tasks;

typedef struct 
{
	char class;
	int octets[4];
} Address;

Address GenerateRandomAddress(int min, int max)
{
	Address address;
	unsigned int seed = time(0);

	for (int i = 0; i < 4; i++)
	{
		int generatedAddress = 0;
		do
		{
			generatedAddress = rand_r(&seed) % (max - min + 1) + min;
		} while ((generatedAddress == 127 || generatedAddress > 224) && i == 0);
		address.octets[i] = generatedAddress;
	}

	if (address.octets[0] < 127)
		address.class = 'A';
	else if (address.octets[0] < 192)
		address.class = 'B';
	else
		address.class = 'C';

	return address;
}

Tasks GenerateTasks()
{
	unsigned int seed = time(0);
	
	Tasks tasks;

	for (int i = 0; i < 4; i++)
	{
		tasks.networks[i] = rand_r(&seed) % (3 - 1 + 1) + 1;

		if (i == 3)	// the last task is always a point-to-point network
			tasks.computers[i] = 2;
		else
			tasks.computers[i] = rand_r(&seed) % (255 - 3 + 1) + 3;
	}

	return tasks;
}

int main(int argc, char **argv)
{
	Address address = GenerateRandomAddress(10, 255);

	Tasks tasks = GenerateTasks();
	printf("Kompanija X poseduje opseg adresa klase %c, %d.%d.%d.%d. Treba napraviti šemu podmrežavanja tako da se obezbedi:\n", address.class, address.octets[0], address.octets[1], address.octets[2], address.octets[3]);
	for (int i = 0; i < 4; i++)
		if (tasks.networks[i] == 1)
		printf("- %d podmreža sa %d računara\n", tasks.networks[i], tasks.computers[i]);
		else
		printf("- %d podmreže sa %d računara\n", tasks.networks[i], tasks.computers[i]);
	return 0;
}
