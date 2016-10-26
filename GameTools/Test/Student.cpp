#include"Student.h"

Student::Student(std::string name, std::string number)
	: mName(name)
	, mNumber(number)
	, mNumCourses(0)
{
}


void Student::AssignGrade(std::string courseName, int grade)
{
	if (mNumCourses == MAXNUMCOURSES)
	{
		std::cout << " You have exceeded the maximum number of courses " << std::endl;
		return;
	}

	// create a new course
	Course course(courseName, grade);
	mCourses[mNumCourses++] = course;
}

int Student::GetGrade(std::string courseName)
{
	for (int i = 0; i < mNumCourses; ++i)
	{
		if (mCourses[i].GetCourseName() == courseName)
		{
			return mCourses[i].GetCourseGrade();
			
		}
	}
	return -1;
}

float Student::GetAverageGrade()
{
	int sum = 0;
	for (int i = 0; i < mNumCourses; ++i)
	{
		sum += mCourses[i].GetCourseGrade();
	}

	return (float)sum / mNumCourses;
}