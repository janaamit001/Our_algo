#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdint.h>
#include <stdbool.h>
#include"Our_algo_fun.h"

UC N, d, Statevector1[size];
int  a[ k ];

UC iSwap(UC *a, UC *b)
{
	UC temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

UC MaxcolStep( UC *Key5 )
{
	UC  l, j1 = 0, m = 0, p, t, flag = 0, flag1 = 0;
	short i;
	
	for( i = 0 ; i < size ; i++ )
		Statevector1[i] = i;

	p = d+(N-1)*k;
	for( i = 0 ; i < p ; i++ )
	{
		j1 = ( j1 + Statevector1[i] + Key5[i%k] ) % size ;
		l++;
		t = d+m*k;
		if( i == t )
		{
			if( i == d )
			{
				if( (j1 != d) )
					return i; 
			}
			else if( i < p-k )
			{
				if( ( j1 != t+k) )
					return i; 
			}
			else
			{
				if( j1 != t+k - 1 )
					return i; 
			}
		}
		else if( i < p-2 )
		{
			if( i < d )
			{
				if( ( j1 == d || j1 == d+1) )
					return i; 
			}
			else if( i == d+1 )
			{
				if( j1 != d+k )
					return i; 
			}
			else if( i < d+k )
			{
				if( j1 == d+k || j1 == d)
					return i; 
			}
			else if( i < p-k )
			{
				if( j1 == t+k || j1 == d )
					return i; 
			}
			else
			{
				if( j1 == t+k-1 || j1 == d)
					return i; 
			}
		}
		
		else
		{
			if( i == ( p-2 ) )
			{
				if( j1 != d )
					return i; 
			}
			
			else if( i == ( p-1 ) )
			{
				if( j1 != ( p-1 ) )
					return i; 
			}
		}
		if( i > d+k-2 )
		{
			if( flag1 == 0 )
			{
				m = 1;
				l = -1;
			}
			flag1 = 1;
			if( l == k-1 )
			{
				m++;
				l = -1;
			}
		}
		iSwap( &Statevector1[i] , &Statevector1[j1] );
	}
	return 255;
}


void Print_key(UC *arr)
{
	short k1;
	
	printf("\n");
	printf("keys are::\n");
	printf("\n");
	for( k1 = 0 ; k1 < k ; k1++ )
		printf("%d ,",arr[k1]);
	printf("\n");
}


void Print_Statevector()
{
	short i;
	
	printf("The statevector1 is:\n");
	printf("\n");
	for( i = 0 ; i < size ; i++ )
		printf("%d ",Statevector1[i]);
	printf("\n");
}


UC Round(UC q)
{
	
	return ((q+k-d-1)/k+1);
}



UC Search( UC Key1[] )
{
	UC S, MaxS = 0, temp = 0;
	short i, j;
	bool flag = 0;
	
	S = MaxcolStep( Key1 );
	if( S == 255 )
	{
		//Print_key(Key1);
		return 1;
	}
	
	MaxS = S;
	
	for( i = 0 ; i < d-2 ; i++ )
	{
		if(a[i] == 0)
		{
			for( j = 1 ; j <= size ; j++ )
			{
				Key1[i] = ( Key1[i] + 1 + 256)%256;
				Key1[(i+1)] = ( Key1[(i+1)] - 1 + 256 )%256;
				temp = MaxcolStep( Key1 );
				if( temp == 255)
				{
					//Print_key(Key1);
					return 1;
				}
				if( temp > MaxS )
				{
					MaxS = temp;
					a[i] = j;
					flag = 1;
				}
			}
			if(flag == 1)
			{
				Key1[ i ] = (Key1[ i ] + a[i])%256;
				Key1[ (i + 1) ] = (Key1[ (i + 1) ] - a[i])%256;
				flag = 0;
			}
		}
	}
	if( MaxS <= S )
	{
		/*if(MaxS > 230)
			printf("max possition is %d\n",MaxS);*/
		
		return 0;
	}
	return ( Search( Key1 ) );
}

UC pass_second_round(UC Key1[])
{
	short i, j;
	UC S, q, p;
	
	S = MaxcolStep( Key1 );
	while( S < (d+k) )
	{
		p = S;
		if( ((S%k) == d-2) || ((S%k) == d-1) || ((S%k) == d) || ((S%k) == d+1))
			return S;
		for( j = 1 ; j <= size ; j++ )
		{
			Key1[S%k] = ( Key1[S%k] + 1)%256;
			Key1[(S+1)%k] = ( Key1[(S+1)%k] - 1 + 256 )%256;
			q = MaxcolStep( Key1 );
			if(q > p)
			{
				a[S%k] = j;
				p = q;
			}
		}
		if(S >= p)
			return S;
		else
		{
			Key1[S%k] = ( Key1[S%k] + a[S%k])%256;
			Key1[(S+1)%k] = ( Key1[(S+1)%k] - a[S%k] + 256 )%256;
		}
		S = p;
	}
	
	for( j = 1 ; j < size ; j++ )
	{
		Key1[ k-1 ] = ( Key1[ k-1 ] + 1)%256;
		S = MaxcolStep( Key1 );
		if( S > d+k)
			return S;
	}
	return S;
}


UC KSA(UC Key1[])
{
	short i, j = 0;

	for(i = 0 ; i < size ; i++)
		Statevector1[i] = i;

	for(i = 0 ; i < d ; i++)
	{
		j = (j + Key1[i] + Statevector1[i]) % size;
		iSwap(&Statevector1[i], &Statevector1[j]);
	}
	
	return j;
}


void key_generation()
{
	UC i , j; 
	UC Key1[ k ], q, s;
	short count = 0;
	srand(time(NULL));
	
	while(1)
	{
		for( i = 0 ; i < k ; i++ )
			Key1[ i ] = rand()%256;
		
		
		Key1[ d-1 ] = ( (N-1)*k - d - 2 );
		Key1[ d+1 ] = k - d - 1;
		
		for( i = 0 ; i < k ; i++ )
			a[i] = 0;
		
		q = MaxcolStep( Key1 );
		
		while(q <= d-2)
		{
			for(j = 1; j < size; ++j)
			{
				Key1[q] = Key1[q] + 1;
				Key1[(q+1)] = Key1[(q+1)] - 1;
				s = MaxcolStep( Key1 );
				if(s > q)
				{
					a[q] = j;
					break;
				}
			}
			Key1[q] = ( Key1[q] + a[q])%256;
			Key1[(q+1)] = ( Key1[(q+1)] - a[q] + 256 )%256;
			q = s;
		}
		
		Key1[d] = 256-KSA(Key1);
		
		q = pass_second_round(Key1);
		
		if(q > d+k)
		{
			if( Search( Key1 ) == 1 )
			{
				count++;
				if( count == 1 )
					break;
			}
		}
		//printf("Generate new key...\n");
	}
			
}

void Number_of_round()
{
	d = k-3;
	if( ( size % k ) == 0 )
		N = size/k;
	else
		N = ( size + k - d -1 )/k;
	//printf("our algo, N = %d k = %d\n", N, k);
}

void avg_time()
{
	short i;
	double time = 0;
	
	for(i = 0; i < no_of_time; ++i)
	{
		clock_t tic = clock();
		key_generation();
		clock_t toc = clock();
		time = time+(double)(toc - tic) / (CLOCKS_PER_SEC);
		printf("count = %d\n", i);
	}
	printf("AVG TIME: %f seconds\n", time/no_of_time);
}

