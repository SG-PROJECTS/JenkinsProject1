#include "AssignmentTest.h"
#include <cppunit\config\SourcePrefix.h>
#include "Vector3.h"

void AssignmentTest::setUp()
{

}

void AssignmentTest::tearDown()
{

}

void AssignmentTest::TestVector3Constructor()
{
	Vector3 vec1;
	Vector3 vec2(20.f, 30.f, 70.f);
	CPPUNIT_ASSERT_EQUAL(vec1.x, 0.0f);
	CPPUNIT_ASSERT_EQUAL(vec1.y, 0.f);
	CPPUNIT_ASSERT_EQUAL(vec1.z, 0.f);
	CPPUNIT_ASSERT_EQUAL(vec2.x, 20.f);
	CPPUNIT_ASSERT_EQUAL(vec2.y, 30.f);
	CPPUNIT_ASSERT_EQUAL(vec2.z, 70.f);
}

void AssignmentTest::TestDistance()
{
	
	Vector3 vec1;
	Vector3 vec2(20.f, 30.f, 70.f);
	Vector3 vec3(10.f, 40.f, 80.f);

	float dist1 = DistanceSquare(vec1, vec2);
	float dist2 = DistanceSquare(vec3, vec2);

	CPPUNIT_ASSERT_EQUAL(dist1, 6200.f);
	CPPUNIT_ASSERT_EQUAL(dist2, 300.f );
	
}

void AssignmentTest::TestPointRemoval()
{
	std::vector<Vector3> nodes;
	nodes.push_back(Vector3(1.f, 1.f, 1.f));
	nodes.push_back(Vector3(1.f, 2.f, 1.f));
	nodes.push_back(Vector3(4.f, 5.f, 1.f));
	nodes.push_back(Vector3(7.f, 8.f, 1.f));
	nodes.push_back(Vector3(4.f, 6.5f, 1.f));
	nodes.push_back(Vector3(3.f, 1.f, 9.f));
	nodes.push_back(Vector3(4.f, 4.f, 1.f));

	float delta = 2;

	RemoveDuplicates(nodes, delta);

	CPPUNIT_ASSERT_EQUAL(nodes.size(), (size_t)5);

}

CPPUNIT_TEST_SUITE_REGISTRATION(AssignmentTest);