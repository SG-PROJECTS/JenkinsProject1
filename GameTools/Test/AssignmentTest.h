#ifndef INCLUDED_ASSIGNMENTTEST_H
#define INCLUDED_ASSIGNMENTTEST_H

#include <cppunit\extensions\HelperMacros.h>

class AssignmentTest : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(AssignmentTest);
	CPPUNIT_TEST(TestVector3Constructor);
	CPPUNIT_TEST(TestDistance);
	CPPUNIT_TEST(TestPointRemoval);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp() override;
	void tearDown() override;

	void TestVector3Constructor();
	void TestDistance();
	void TestPointRemoval();

};

#endif //#ifndef INCLUDED_ASSIGNMENTTEST_H
