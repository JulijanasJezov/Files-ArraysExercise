#include <stdio.h>

int main(int argc, char *argv[])
{

	FILE *fp;
	int numbers[5][10];
	int i, j, k;
	int firstNum, secondNum, total, largestTotal, largestFNum, largestSNum, largestLine; 
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
					firstNum = numbers[i][k];
					secondNum = numbers[i][j];
					newTotal[i] = total;
                		}
			}	
        	}
		if(largestTotal < newTotal[i])
		{
			largestLine = line;
			largestFNum = firstNum;
			largestSNum = secondNum;
			largestTotal = newTotal[i];
		}
	
		line++;
	}

	printf("Line %d: Largest pair is %d and %d, with a total of %d\n", largestLine, largestFNum, largestSNum, largestTotal);
}

