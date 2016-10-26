#ifndef INCLUDED_COURSE_H
#define INCLUDED_COURSE_H

#include <string>

class Course
{
public:
	Course();
	Course(std::string name, int grade);

	std::string GetCourseName();

	int GetCourseGrade();

private:
	std::string mCourseName;
	int mGrade;
	
};

#endif //#ifndef INCLUDED_COURSE_H