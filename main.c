#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 *	PROGRAM FOR GENERATING RANDOMISED PRACTICE TASKS
 *	IN THE AREA OF IP SUBNETTING
 */

/*
 *	TODO	BETTER RANDOM NUMBER GENERATOR FUNCTION
 *			FUNCTION FOR MAKING ADDRESSES
 */

int RandomNumber(int min, int max)
{
	static long int passageNumber = 0;
	++passageNumber;
	unsigned int seed = time(passageNumber);
	return rand_r(&seed) % (max - min + 1) + min;	
}

int main(int argc, char **argv)
{

/*	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}
*/
	if (argc != 3)
	{
		printf("Error: Expecting exactly 2 arguments, recieved %d\n", argc-1);
		return 1;
	}

//	printf("Testing random number functionality...");


	int	firstOctet = RandomNumber(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10));
	int	secondOctet = RandomNumber(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10));
	int	thirdOctet = RandomNumber(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10));
	int	fourthOctet = RandomNumber(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10));


	printf("%d.%d.%d.%d\n", firstOctet, secondOctet, thirdOctet, fourthOctet);

	return 0;
}
