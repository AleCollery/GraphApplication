#include "pch.h"
#include "CppUnitTest.h"
#include "../GraphApplication/Edge.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphApplicationUnitTests
{
	TEST_CLASS(EdgeTestCase)
	{
	public:

		TEST_METHOD(TestCalssInit)
		{
		
			Edge* k = Edge.initializeForTestCase();
			
		
			//Assert::IsTrue(nullptr == x->getOrigin());
			
		};

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(2, 2);
			/*Edge* testEdge = new Edge();
			Assert::IsTrue(testEdge->getOrigin() == nullptr);
			Assert::IsTrue(testEdge->getDestination() == nullptr);*/
		}
	};
}
