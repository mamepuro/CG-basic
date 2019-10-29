#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void koch( double size, int order);

double x=0.0;
double y=0.0;
double theta=0.0;

FILE *fp;

int main(void)
{
	double size=243.0;
	int order=5;
	
	fp=fopen("koch.csv","w");
	
	printf("TitleText: Koch Order ");
	printf("%d\n", order);
	printf("Ticks: true\n");
	printf("BoundBox: on\n");
	printf("%f %f \n", 0.0, 0.0);

	koch(size, order);
	theta -= 2*M_PI/3.0;
	koch(size, order);
	theta -= 2*M_PI/3.0;
	koch(size, order);
	
	fclose(fp);
	
	rewind(stdin);
	getchar();
	return 0;	
}

void koch( double size, int order)
{
	if (order == 0){
		x += size * cos(theta);
		y += size * sin(theta);
 		printf("%f %f \n", x, y);
 		fprintf(fp,"%f,%f\n",x,y);
 	} else {
		koch(size/3.0, order-1);
		theta += M_PI/3.0;
		koch(size/3.0, order-1);
		theta -= 2.0*M_PI/3.0;
		koch(size/3.0, order-1);
		theta += M_PI/3.0;
		koch(size/3.0, order-1);
	}
}