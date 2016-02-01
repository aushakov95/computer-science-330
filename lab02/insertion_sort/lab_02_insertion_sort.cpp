/* Andrey Ushakov
*
*
* insertion sort
**************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>


using namespace std;


vector <int> insertion_sort(vector <int> v, int size){

	int j;
	int elem;

	for (int i = 1; i < size; i++){											//insertion sort
    	for (elem = v[i], j = i-1; j >=0 and elem < v[j]; j--){
        	v[j+1] = v[j];
			}
    	v[j+1] = elem;
	}
	return v;

}

int main()
{

ofstream myfile;
myfile.open("insertion_sort_output.txt");

int n;

cout <<"Testing time complexity for INSERTION sort. Please enter the size for a vector: ";

cin >> n;

cout << endl;
cout << endl;

vector <int> v(n);

cout << "Pushing " << n << " random numbers to vector...";

for (int i = 0; i < n; i++)
	v[i] = rand() % 1000000;

cout << "\tDone.\nSorting the vector...";

v = insertion_sort(v,n);

cout << "\tDone.\nWriting all vector elements to file...";

for (int i = 0; i < n; i++)
	myfile << v[i] << endl;

cout << "\tDone.\n\n\n";

myfile.close();
}
