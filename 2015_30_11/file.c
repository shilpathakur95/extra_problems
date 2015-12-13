//Print the last k lines of a file
//MissionRnD2015
//Shilpa Thakur,MGIT
#include<stdio.h>
void lastKLines(FILE* f, int k)
{
	FILE* ptr;
	fopen_s(&ptr,"file.txt", "r");
	int count = 0, travel = 0;
	int c = fgetc(f); 
	while ((c != EOF))
	{
		if (c == '\n')
			count++;
		c = fgetc(f);
	}
	if (count < k){
		c = fgetc(ptr);
		while (c != EOF){
			printf("%c", c);
			c = fgetc(ptr);
		}
		return;
	}
	travel = count - k;
	c = fgetc(ptr);
	while (travel != 0){
		if (c == '\n')
			travel--;
		c = fgetc(ptr);
	}
	do{
		printf("%c", c);
		c = fgetc(ptr);
	} while (c != EOF);

	fclose(ptr);
}
void main()
{
	int k;
	FILE *f;
	printf("Enter the number of lines to be printed");
	scanf_s("%d", &k);
	fopen_s(&f, "file.txt", "r");
	lastKLines(f, k);
}