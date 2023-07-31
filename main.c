#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define Stepbreaker 0.0
#define downstep(min , step , multiplier) (min + (step*multiplier))
#define upstep(min , step , multiplier) (min + (step*(multiplier+1)))



void get_array(float a[] , int len);
float maxi(float a[] , int len);
float mini(float a[] , int len);
float step_maker(float maxi , float mini);
int Bu_sort(float a[] , int len);
void p_array(float a[] , int len);


int main()
{
	int len;
	printf("Please enter array len:\t");
	scanf("%d", &len);

	float array[len];

	get_array(array, len);
	printf("array before sorting:\n");
	p_array(array, len);
	printf("______________________\n");
	printf("array after sorting:\n");
	Bu_sort(array, len);
	p_array(array, len);

	return 0;
	}





void get_array(float a[] , int len)
	{
		 int i;

		for(i=0 ; i<len ; i++ )
		{
			printf("Enter a[%d]:\t" , i);
			scanf("%f" , &a[i]);
		}
	}


int Bu_sort(float a[] , int len)
	{
	    int  i , j , multiplier , u;
		float max , min , step;

		float S[10][len];
		int flage[10];

		for(i=0 ;i<10;i++)
		{
			flage[i]=-1;
		}

		max = maxi(a, len);
		min = mini(a, len);

		step = step_maker(max, min);

		if(step== Stepbreaker)
		{
			return 1;
		}


			multiplier= 0;

			for( multiplier; multiplier<10 ;multiplier++)
			{
				j=0;
				for( i=0 ; i<len ; i++)
				{
					if(((downstep(min, step, multiplier)<= a[i]) && (a[i] < upstep(min, step, multiplier)) ) )
					{
						flage[multiplier]++;
						S[multiplier][flage[multiplier]]= a[i];
					}
				}
			}

			for( i=0 ; i<10 ; i++ )
			{
				Bu_sort(&(S[i][0]), flage[i]+1);
			}

			u=0;
			for( i=0 ; i<10 ; i++)
			{
				for(j=0 ; j<flage[i]+1 ;j++)
				{
					a[u]= S[i][j];
					u++;
				}
			}


		}


float maxi(float a[] , int len)
	{
		int i;
		float max = a[0];

		for( i=0 ; i<len ; i++)
		{
			if(a[i]>= max)
			{
				max = a[i];
			}
		}

		return max;
	}

float mini(float a[] , int len)
	{
		int i;
		float min = a[0];

		for( i=0 ; i<len ; i++)
		{
			if(a[i]<= min)
			{
				min = a[i];
			}
		}

		return min;
	}

float step_maker(float maxi , float mini)
	{
		float step;


		if(maxi == mini)
		{
			return Stepbreaker;
		}

		step= (maxi - mini) / 9;

		return step;
	}



void p_array(float a[] , int len)
	{
		int i;

		for(i=0;i<len;i++)
		{
			printf("a[%d]= %2.2f\n" , i , a[i]);
		}
	}
