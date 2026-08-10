/*
*	OnlineGDB Archive
*
*	Created			: 12/2/2022, 4:50:43 PM
*	Last Modified	: 12/2/2022, 5:11:51 PM
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define lli signed long long int

lli BinarySearch(lli *level, lli *carryMax, lli searchTo, lli searchFrom, lli comparator) 
{
	lli middleIndex;
	while ((searchFrom - searchTo) > 1) 
	{
		middleIndex = searchTo + (searchFrom - searchTo)/2;
		if (level[carryMax[middleIndex]] > comparator) 
		{
			searchFrom = middleIndex;
		}
		else 
		{
			searchTo = middleIndex;
		}
	}
	return searchFrom;
}

lli *MaxNonDecSubSeq(lli *level, lli n, lli *levelcount) 
{
	lli carryMin[200000];
	lli carryMax[200000];

    for (lli i = 0; i < 200000; i++)
    {
        carryMin[i] = -1;
        carryMax[i] = 0;
    }

	lli maxSize = 1;
	for (lli i = 1; i < n; i++) 
	{
		if (level[i] < level[carryMax[0]]) 
		{
			carryMax[0] = i;
		}
		
		else if (level[i] >= level[carryMax[maxSize - 1]]) 
		{
			carryMin[i] = carryMax[maxSize - 1];
			carryMax[maxSize++] = i;
		}
		
		else 
		{
			lli index = BinarySearch (level, carryMax, -1, maxSize - 1, level[i]);
			carryMin[i] = carryMax[index - 1];
			carryMax[index] = i;
		}
	}
	
	lli *maxNonDecSubSeq = malloc((maxSize + 1) * sizeof(lli));
	*levelcount = maxSize;

	lli carryCount = 0;
	for (lli i = carryMax[maxSize - 1]; i >= 0; i = carryMin[i]) {
		maxNonDecSubSeq[maxSize - 1 - carryCount] = level[i];
		carryCount++;
	}

	return maxNonDecSubSeq;
}

void WorldSeed(lli level[], lli levels, lli seed, lli multiplier, lli max_diff)
{
	for(lli i = 0; i < levels; i++)
	{
		seed = seed * multiplier % max_diff + 1;
		multiplier = (multiplier + seed) % max_diff + 1;
		level[i] = seed;
	}
}

int main()
{
    lli n;
    scanf (" %lli", &n);
    lli seed;
    scanf (" %lli", &seed);
    lli multiplier;
    scanf (" %lli", &multiplier);
    lli max_diff;
    scanf (" %lli", &max_diff);
	
	lli levelCount;
	
	lli *level = malloc(n * sizeof(lli));
	
	WorldSeed(level, n, seed, multiplier, max_diff);
	
	lli *maxNonDecSubSeq = MaxNonDecSubSeq(level, n, &levelCount);
	
	printf("Banyak Level : %lli\n", levelCount);
	
	for (lli i = 0; i < levelCount; i++) 
	{
		printf("%lli\n", maxNonDecSubSeq[i]);
	}
	
	return 0;
}
