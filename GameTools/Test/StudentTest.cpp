#include "StudentTest.h"
#include <cppunit\config\SourcePrefix.h>
#include "Student.h"

void StudentTest::setUp()
{
	
}

void StudentTest::tearDown()
{

}

void StudentTest::TestConstructor()
{
	Student student("Shiva Gupta", "335382");

	std::string studentName = student.GetStudentName();
	CPPUNIT_ASSERT(studentName == "Shiva Gupta");

	std::string studentNumber = student.GetStudentNumber();
	CPPUNIT_ASSERT(studentNumber == "335382");
}

void StudentTest::TestGrades()
{
	Student student("Shiva Gupta", "335382");
	student.AssignGrade("VGP 221", 70);
	student.AssignGrade("VGP 421", 90);
	student.AssignGrade("VGP 124", 40);

	CPPUNIT_ASSERT_EQUAL(student.GetGrade("VGP 221"), 70);
	CPPUNIT_ASSERT_EQUAL(student.GetGrade("VGP 421"), 90);
	CPPUNIT_ASSERT_EQUAL(student.GetGrade("VGP 124"), 40);

	CPPUNIT_ASSERT_EQUAL(student.GetGrade("VGP 174"), -1);
}

void StudentTest::TestAverageGrade()
{
	Student student("Shiva Gupta", "335382");
	student.AssignGrade("VGP 221", 70);
	student.AssignGrade("VGP 421", 90);
	student.AssignGrade("VGP 124", 40);
	student.AssignGrade("VGP 174", 80);

	CPPUNIT_ASSERT_EQUAL(70.f, student.GetAverageGrade());
}

CPPUNIT_TEST_SUITE_REGISTRATION(StudentTest);