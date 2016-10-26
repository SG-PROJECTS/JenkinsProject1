#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main()
{
	CPPUNIT_NS::Test* suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();
	CppUnit::TextUi::TestRunner runner;

	std::ofstream fs("Result.xml");
	CppUnit::XmlOutputter* outputter = new CppUnit::XmlOutputter(&runner.result(), fs);
	runner.setOutputter(outputter);

	runner.addTest(suite);
	bool wasSuccessful = runner.run();

	return wasSuccessful ? 0 : 1;
}