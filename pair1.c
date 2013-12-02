#include <stdio.h>

int main(int argc, char *argv[])
{

	FILE *fp;
	int numbers[10];
	int i, j;
	int firstNum, secondNum, total, newTotal = 0;
	int line = 1;
	fp = fopen(argv[1], "r");

	while(!feof(fp))
	{
		for(i = 0; i < 10; i++)
		{	
			fscanf(fp, "%d,", &numbers[i]);			
		}

		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10 ; j++)
			{
				if(numbers[i] != numbers[j])
				{
					total = numbers[i] + numbers[j];
				}
				if(total <= 50 && total > newTotal)
				{
					firstNum = numbers[i];
					secondNum = numbers[j];
					newTotal = total;
				}
			} 	
		}
	printf("Line %d: Largest pair is %d and %d, with a total of %d\n", line, firstNum, secondNum, newTotal);
	line++;
	newTotal = 0;
	} 
	fclose(fp);	
}

