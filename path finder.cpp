#include <iostream>
#include <string.h>
#include <fstream>

using namespace std ;

// GLOBAL VARIABLES
int Rows ; int Cols ;
int possibleWays = 0 ;


bool validCell(int x, int y)
{
	if (x < 0 || y < 0 || x >= Rows || y >= Cols)
		return false;

	return true;
}

// recursiveFunction
void Ways(int** Data, int n, int m, int** Mark)
{
    if (n == Rows- 1 && m == Cols - 1) 
	{
		possibleWays++;
		return;
	}
	
	*(*(Mark+n)+m) = 0 ;
	
	if (validCell(n, m) && *(*(Data+n)+m) == 0 ) 
	{
		if (m + 1 < Cols && Mark[n][m + 1] == 0)
		   Ways(Data , n, m+1, Mark) ; 
		if (n + 1 < Rows && Mark[n + 1][m] == 0)
		   Ways(Data , n+1, m, Mark) ;
	}
	
	*(*(Mark+n)+m ) = 1 ;
}

int main()
{
	int temp ;
	int** Data ;
	int** Mark ;	
		
	ifstream file ;
	file.open("maze.txt") ;
	file >> Rows ; file >> Cols ;
	file.close() ;
	
	Data = new int*[Rows] ; 
	for( int loop = 0 ; loop < Rows ; loop++)
	{
		*(Data+loop) = new int[Cols] ; 
	}
	ifstream nfile ;
	file.open("maze.txt") ;
	file >> temp ; file >> temp ;
	for( int i = 0 ; i < Rows ; i++)
	{
		for( int j = 0 ; j < Cols ; j++)
		{
			file >> *(*(Data+i)+j) ;
		}
	}
	nfile.close() ;

	
	Mark = new int*[Rows] ; 
	for( int loop = 0 ; loop < Rows ; loop++)
	{
		*(Mark+loop) = new int[Cols] ; 
	}
	for( int i = 0 ; i < Rows ; i++)
	{
		for( int j = 0 ; j < Cols ; j++)
		{
			*(*(Mark+i)+j) = 0 ;
		}
	}
	
	Ways(Data, 0, 0, Mark) ;
	
	cout << possibleWays ;
	
	

}

