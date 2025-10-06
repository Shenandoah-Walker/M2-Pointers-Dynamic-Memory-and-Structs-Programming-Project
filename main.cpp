//Course Grade Program


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


using namespace std;
//Struct Definition
struct student {
  string name;
  int id;
  double* testScores;
  double average;
  char letterGrade;
};

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

student* getData(ifstream& inputFile, int& studentCnt, int& testsCnt);

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



int main() {
    //Create the variables that hold the number of students and the number of tests
    int studentCnt, testsCnt;
    //Create the array of structs
    student* students;
    //Create the variables needed to read the data from the file
    ifstream inputFile;
    string fileName;

    /*Prompt the user to input the name of the file that contains the list of students, their ID numbers, and their test scores. Open the file and confirm that it was opened successfully. If the file was not opened successfully, end the program.*/
    cout << "Please enter the name of the file that contains the list of students, their ID numbers, and their test scores: ";
    cin >> fileName;
    inputFile.open(fileName);
    if (inputFile.fail()) {
        cout << "Error opening file. Please restart the program and enter a valid file name." << endl;
        return 1;  
    }

    //Call the getData function to read the data from the file and store it in the struct
    students = getData(inputFile, studentCnt, testsCnt);
    //Call the calcAverage function to calculate the average of the test grades and the course grade for each student
    calcAverage(students, studentCnt, testsCnt);
    //Call the createReport function to print a formatted report
    createReport(students, studentCnt, testsCnt);
    //Close the file
    inputFile.close();
    //Delete the array of structs
    delete[] students;
    //End the program
    return 0;  
}

student* getData(ifstream& inputFile, int& studentCnt, int& testsCnt) {
    inputFile >> studentCnt >> testsCnt;
    student* students = new student[studentCnt];
    for (int i = 0; i < studentCnt; i++) {
        inputFile >> students[i].name >> students[i].id;
        students[i].testScores = new double[testsCnt];
        for (int j = 0; j < testsCnt; j++) {
            inputFile >> students[i].testScores[j];
            }
    }
    return students;
    
}

void calcAverage(student students[], int studentCnt, int testsCnt) {
    for (int i = 0; i < studentCnt; i++) {
        students[i].average = 0;
        
        for (int j = 0; j < testsCnt; j++) {
            students[i].average += students[i].testScores[j];
            }
        students[i].average /= testsCnt;
        students[i].letterGrade = calcLetterGrade(students[i].average);
        delete[] students[i].testScores;
    }
}

void createReport(student students[], int studentCnt, int testsCnt) {
    cout << fixed << setprecision(1);
    cout << endl;
    cout << "Student Name" << setw(20) << "Student ID" << setw(25) << "Average Test Score" << setw(20) << "Letter Grade" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for (int count = 0; count < studentCnt; count++)
        cout << left << setw(25) << students[count].name << setw(20) << students[count].id << setw(15) << students[count].average << right << setw(12) << students[count].letterGrade << endl;
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