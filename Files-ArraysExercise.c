#include <stdio.h>

int main(int argc, char *argv[])
{

	FILE *fp;
	int numbers[5][10];
	int i, j, k;
	int total, largestTotal, largestFNum[5], largestSNum[5], largestLine; 
	int newTotal[5];
	int line = 1;

	fp = fopen(argv[1], "r");
		for(i = 0; i < 5; i++)
		{	
			for(j = 0; j < 10; j++)
			{
			fscanf(fp, "%d,", &numbers[i][j]);
			}			
		} 
	fclose(fp);

	for(i=0; i < 5; i++)
	{
		newTotal[i] = 0;
		for(k = 0; k < 10; k++)
        	{
			for(j = 0; j < 10 ; j++)
			{
				if(numbers[i][k] != numbers[i][j])
				{
					total = numbers[i][k] + numbers[i][j];
				}
				if(total <= 50 && total > newTotal[i])
				{
					largestFNum[i] = numbers[i][k];
					largestSNum[i] = numbers[i][j];
					newTotal[i] = total;
                		}
			}	
        	}
		if(largestTotal < newTotal[i])
		{
			largestTotal = newTotal[i];
		}		
	}
	
	for(i = 0; i < 5; i++)
	{
		if(largestTotal == newTotal[i])
		{
			if(largestFNum[i] != 1)
			{
				printf("Line %d: Largest pair is %d and %d, with a total of %d\n", line, largestFNum[i], largestSNum[i], newTotal[i]);
			}
		}
		line++;
	}
}

