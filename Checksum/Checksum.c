#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10

unsigned short checksum(unsigned short *arrPtr, int count)
{
	int sum = 0;
	int i;

	// Sums all ten elements of array
	for (i = 0; i < count; i++)
		sum = sum + (*arrPtr + i);

	// Removes upper 16 bits of sum (if any), shifts bits right
	while (sum >> 16) sum = (sum & 0xFFFF) + (sum >> 16);

	// Return the one's compliment of sum
	return(~sum);
}

void main()
{
	unsigned short binSeq[SIZE];
	int i;

	//srand((unsigned)time(NULL));

	// Fills array with random 16-bit data
	for (i = 0; i < SIZE; i++)
	{
		binSeq[i] = rand();
		printf("Sequence number %d is: \r\n%04X", i+1, binSeq[i]);
		printf("\r\n");
	}

	printf("The checksum is: \r\n%04X", checksum(binSeq, SIZE));
	printf("\r\n");
}