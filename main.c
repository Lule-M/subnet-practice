#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	/*int task1[2];
	int task2[2];
	int task3[2];
	int task4[2];*/
	int tasks[4][2];

} Tasks;

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

Tasks GenerateAssignmentTasks()
{
	unsigned int seed = time(0);
	
	Tasks tasks;
/*
 *					TASK
 *	a - # of networks	b - # of computers on each network
 *	
 *	i\j  0	  1
 *
 *	0	{a1, b1}
 *	1	{a2, b2}
 *	2	{a3, b3}
 *	3	{a4, b4}	this task is always point-to-point
 *
 */

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 2; j++)
		{
			if (i == 3 && j == 1)
			{
				tasks.tasks[i][j] = 2;
				continue;
			}

			if (j % 2 == 0)	// ensure we don't have a crazy ammount of networks
				tasks.tasks[i][j] = rand_r(&seed) % (3 - 1 + 1) + 1;
			else
				tasks.tasks[i][j] = rand_r(&seed) % (255 - 3 + 1) + 3;
		}
	return tasks;
}

int main(int argc, char **argv)
{

	Address address = GenerateRandomAddress(10, 255);

	//printf("%d.%d.%d.%d\n", address.octets[0], address.octets[1], address.octets[2], address.octets[3]);

	Tasks tasks = GenerateAssignmentTasks();
	printf("Kompanija X poseduje opseg adresa klase B, %d.%d.%d.%d. Treba napraviti šemu podmrežavanja tako da se obezbedi:\n", address.octets[0], address.octets[1], address.octets[2], address.octets[3]);
	for (int i = 0; i < 4; i++)
		printf("- %d podmreže sa %d računara\n", tasks.tasks[i][0], tasks.tasks[i][1]);		

	return 0;
}
