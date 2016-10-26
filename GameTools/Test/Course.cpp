#include "Course.h"

Course::Course()
{
	mCourseName = "";
	mGrade = -1;
}

Course::Course(std::string name, int grade)
	: mCourseName(name)
	, mGrade(grade)
{}

std::string Course::GetCourseName()
{
	return mCourseName;
}

int Course::GetCourseGrade()
{
	return mGrade;
}
