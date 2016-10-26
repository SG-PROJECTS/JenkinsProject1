#ifndef INCLUDED_STUDENT_H
#define INCLUDED_STUDENT_H

#include <iostream>>
#include <string>
#include "Course.h"

const int MAXNUMCOURSES = 20;

class Student
{
public:
	Student(std::string name, std::string number);

	std::string GetStudentName() { return mName; }
	std::string GetStudentNumber() { return mNumber; }

	void AssignGrade(std::string courseName, int grade);
	int GetGrade(std::string courseName);
	float GetAverageGrade();

private:
	std::string mName;
	std::string mNumber;
	Course mCourses[MAXNUMCOURSES];
	int mNumCourses;
};


#endif // #ifndef INCLUDED_STUDENT_H