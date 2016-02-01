/* Andrey Ushakov
*
*
* selection sort
**************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>


using namespace std;

vector <int> selection_sort(vector <int> v, int size){

	for (int i = 0; i < size-1; i++)
			for (int j = i+1; j < size; j++)
					if (v[i] > v[j])
							swap(v[i], v[j]);

	return v;
}

int main()
{

	ofstream myfile;
	myfile.open("selection_sort_output.txt");

	int n;

	cout <<"Testing time complexity for SELECTION sort. Please enter the size for a vector: ";

	cin >> n;

	cout << endl;
	cout << endl;

	vector <int> v(n);

	cout << "Pushing " << n << " random numbers to vector...";

	for (int i = 0; i < n; i++)
		v[i] = rand() % 1000000;

	cout << "\tDone.\nSorting the vector...";

	v = selection_sort(v,n);

	cout << "\tDone.\nWriting all vector elements to file...";

	for (int i = 0; i < n; i++)
		myfile << v[i] << endl;

	cout << "\tDone.\n\n\n";

	myfile.close();

}
