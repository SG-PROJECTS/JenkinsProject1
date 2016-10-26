#ifndef INCLUDED_STUDENTTEST_H
#define INCLUDED_STUDENTTEST_H

#include <cppunit\extensions\HelperMacros.h>

class StudentTest : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(StudentTest);
	CPPUNIT_TEST(TestConstructor);
	CPPUNIT_TEST(TestGrades);
	CPPUNIT_TEST(TestAverageGrade);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp() override;
	void tearDown() override;

	void TestConstructor();
	void TestGrades();
	void TestAverageGrade();

};

#endif //#ifndef INCLUDED_STUDENT_H
