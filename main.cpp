#include <iostream>
#include <fstream>
#include <cmath>


#define MAX_VALUE (4096/4)-1

using namespace std;


void generateTable(int** tab, int tabSize)
{
	*tab=new int[tabSize];
	double frequency = (double)1/tabSize;
	for(int i=0; i<tabSize; ++i)
	{
		(*tab)[i]=sin((2*M_PI*(double)frequency*i))*(MAX_VALUE)+MAX_VALUE;	
	}
}


void saveTable(int *tab, int tabSize)
{
	ofstream file("sinusy",std::ofstream::out);
	file<<"sin["<<tabSize<<"]={";
	for(int i=0; i<tabSize; ++i)
	{
		file<<tab[i];
		if(i!=tabSize-1)
		{
			file<<", ";
		}
		else
		{
			file<<" ]";
		}
	}
	file.close();

}
int main()
{
  int* table;
  int tabSize;
  cin>>tabSize;
  generateTable(&table,tabSize);
/*  for(int i=0; i<tabSize; ++i)
  {
   cout<<table[i]<<" ";
  }
*/
 saveTable(table,tabSize);

  return 0;
}
