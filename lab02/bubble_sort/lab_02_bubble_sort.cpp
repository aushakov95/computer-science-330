/* Andrey Ushakov
*
*
* bubble sort
**************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>


using namespace std;

vector <int> bubble_sort(vector <int> v, int size){

	for (int i = size-1; i > 0; i--)				//bubble sort
	    for (int j = 0; j < i; j++)
	        if (v[j] > v[j+1])
	            swap(v[j], v[j+1]);
	return v;
}

int main()
{

ofstream myfile;
myfile.open("bubble_sort_output.txt");

int n;

cout <<"Testing time complexity for BUBBLE sort. Please enter the size for a vector: ";

cin >> n;

cout << endl;
cout << endl;

vector <int> v(n);

cout << "Pushing " << n << " random numbers to vector...\t";


for (int i = 0; i < n; i++)
	v[i] = rand() % 1000000;

cout << "\tDone.\nSorting the vector...";

v = bubble_sort(v,n);

cout << "\tDone.\nWriting all vector elements to file...";

for (int i = 0; i < n; i++)
	myfile << v[i] << endl;

cout << "\tDone.\n\n\n";

myfile.close();
}
