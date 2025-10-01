//Course Grade Program

//Struct Definition
struct student {
  string name;
  int id;
  double average;
  char letterGrade;
}

/*
Function: getData
Purpose: To read the data from a file and store it in a struct
Parameters:
 - file: the file to read from
 - studentCnt: the number of students
 - testsCnt: the number of tests
Returns: a pointer to the array of structs
Preconditions: the file has been successfully opened
Postconditions: the data has been read and stored in the struct
*/

student* getData(ifstream& file, int& studentCnt, int& testsCnt);

/*
Function: calcAverage
Purpose: To calculate the average of the test grades and the course grade for each student
Parameters:
 - students[]: the array of structs
 - studentCnt: the number of students
 - testsCnt: the number of tests
Returns: None
Preconditions: the data has been read and stored in the struct
Postconditions: the average and course grade have been calculated and stored in the struct
*/

void calcAverage(student students[], int studentCnt, int testsCnt);

/*
Function: createReport
Purpose: To print a formatted report
Parameters:
 - students[]: the array of structs
 - studentCnt: the number of students
 - testsCnt: the number of tests
Returns: None
Preconditions: the data has been read and stored in the struct
Postconditions: a formatted report has been printed
*/

void createReport(student students[], int studentCnt, int testsCnt);

/*
Function: calcLetterGrade
Purpose: Calculates a letter grade from an average test score. This function is provided
with the test score and returns the letter grade.
Parameters:
 - average: The average test score
Returns: The letter grade as a char
Preconditions: The average must be a valid double.
Postconditions: The letter grade will be returned as a char.
*/

char calcLetterGrade(double average);


#include <iostream>

using namespace std;

int main() {

  
}



char calcLetterGrade(double average) {
  if (average >= 90) {
      return 'A';
  }
  else if (average >= 80) {
      return 'B';
  }
  else if (average >= 70) {
      return 'C';
  }
  else if (average >= 60) {
      return 'D';
  }
  else {
      return 'F';
  }
}