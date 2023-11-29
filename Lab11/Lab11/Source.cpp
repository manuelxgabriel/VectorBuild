#include "TestSuite.h"
#include "DebugNewOp.h"
#include "MyVector.h"
#include <iostream>

int main() {
	TestSuite::runTestSuite();
	//new int{ 5 }; // create memory leak
	_CrtMemDumpAllObjectsSince(NULL); // for detecting memory leaks


	try {
		
		/*MyVector v1{ 1.2,3.6 };
		std::cout << v1[0] << '\n';

		MyVector v2 = v1;
		v2[1] = 4.9;

		std::cout << v2[1] << '\n';

		const MyVector v3 = v1;
		v3[0] = 3.2;*/

		
	}
	catch (std::length_error msg) {
		std::cout << msg.what();
	}
	catch (std::out_of_range msg) {
		std::cout << msg.what();
	}


	return 0;

}