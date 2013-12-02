#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

FILE *fp;
int x[40];
int i = 0, j;
char c;
int firstNum, secondNum, total, newTotal = 0;
int line, loopCounter, loopUntil;
fp = fopen("items.txt", "r");
	while(i < 40)
	{
		fscanf(fp, "%d,", &x[i]);
		i++;
				
	}
fclose(fp);
line = 1;
loopUntil = 10;
for(i = 0; i < 40; i++)
{

	for(j = loopCounter; j < loopUntil ; j++)
	{
		if(x[i] != x[j])
		{
			total = x[i] + x[j];
		
			if(total <= 50 && total > newTotal)
			{
				firstNum = x[i];
				secondNum = x[j];
				newTotal = total;
			}
		} 
	}
        if(i == loopUntil || i == 39)
        {
                loopCounter = loopCounter + 10;
                loopUntil = loopUntil + 10;
                printf("Line %d: Largest pair is %d and %d, with a total of %d\n", line, firstNum, secondNum, newTotal);
                line++;
                newTotal = 0;
        }
	
}
}
