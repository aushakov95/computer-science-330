/*
Homework 1, Due Monday Feb 1.
Problem 8, page 21.
Use an array of 100 floats. Do not use a vector.
Input the numbers using cin until end-of-file (^D). This way you can input the numbers from either standard input (keyboard) or a file using input redirection.
As you input the numbers count number of numbers (n). Then make two calls to functions average() and variance(). Remember that the name of an array is a pointer to the base of the array and that is what you pass to the functions.
Your program must run correctly for the following input:
10
2
5
20
8
1
15
6
Be sure to handle end cases such as n = 0, 1, or greater than 100.
Hand in a printout of your program and typescript of the sample run for the above input.
*/

#include <iostream>
#include <array>

using namespace std;

float average(float *arr, float n){

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

float variance(float *arr, float averageResult, float n){

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
