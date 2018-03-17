#include <iostream>
#include <assert.h>
#pragma warning(disable : 4996)
using namespace std;
//Using files in a c way
struct Student {
	int studentId;
	int assignmentGrades[4];
};

void fillUp(FILE* output, Student* a);
void print(FILE* output, Student* a);


int main() {
	//open a file called output
	FILE* output = fopen("Output.txt", "wb+");
	//make a little array
	Student a[5];
	fillUp(output, a);
	print(output, a);
	fillUp(output, a);
	print(output, a);






	return 0;
}

void fillUp(FILE* output, Student* a) {
	for (int i = 0; i < 5; i++) {
		a[i].studentId = i;
		for (int j = 0; j < 4; j++) {
			cout << "Please enter grade " << j << " for student " << i << ": ";
			cin >> a[i].assignmentGrades[j];
		}
		cout << "\n";
	}
	//Albow said to put them in an array and write them all at once
	int b = fwrite(a, sizeof(Student), 5, output);
	//Check to see if it wrote it all
	assert(b == 5);
	//print out the number because why not
	cout <<"Students written " << b << "\n";
}

void print(FILE* output, Student* a) {
	//store the size of a student
	int size_of_student = sizeof(Student);
	//temp var for reading the values in
	Student s;
	//The value returned 
	int readValue;
	//Seek to the almost last value
	fseek(output, -1 * size_of_student, SEEK_CUR);
	//for all five students read them and print out their values
	for (int i = 0; i < 5; i++) {
		readValue = fread(&s, sizeof(Student), 1, output);
		assert(readValue == 1);
		cout << "Student ID: " << s.studentId << " Grades: " << s.assignmentGrades[0] << " " << s.assignmentGrades[1] << " " << s.assignmentGrades[2] << " " << s.assignmentGrades[3] << endl;
		fseek(output, -2 * size_of_student, SEEK_CUR);
	}
}