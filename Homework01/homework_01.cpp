/***********************************************************************
* Andrey Ushakov
* homework_01.cpp
* 1/30/16
* This program is designed to take in up to 100 float type numbers and
* calculate the average and the variance of them.
************************************************************************/

#include <iostream>
#include <array>

using namespace std;

float average(float *arr, float n){     //function to find the average of all numbers in the array.

  float sum;
  float average_result;

  if (n == 0 or n == 1){
    average_result = 2;
    return average_result;
  } else {

    for (int i = 0; i < n; i++)
      sum += arr[i];

    average_result = sum/n;
    return average_result;
         }
}

float variance(float *arr, float averageResult, float n){   //function to find the variance of all numbers in the array

  float sum_of_squares;
  float square;
  float average_of_squares;

  for (int i = 0; i < n; i++){
    square = arr[i] - averageResult;
    square = square * square;
    sum_of_squares += square;
  }

  average_of_squares = sum_of_squares/n;
  return average_of_squares;

}

int main()
{

  float n = 0;
  float input;
  float numbers[100];
  float averageResult;
  float varianceResult;
  int i = 0;

  while (!cin.eof()){
    cin >> input;
    numbers[i] = input;
    n++;
    i++;
  }

  if (n > 100)
    cout << "Error. You entered more than 100 numbers." << endl;

  else{
    averageResult = average(numbers, n);
    varianceResult = variance(numbers, averageResult, n);

    cout << "\nThe average is: " << averageResult << endl;
    cout << "The variance is: " << varianceResult << endl << endl;
      }

} //main
