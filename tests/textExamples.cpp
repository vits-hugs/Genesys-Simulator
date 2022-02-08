/*
 * The MIT License
 *
 * Copyright 2022 rlcancian.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: rlcancian
 *
 * Created on 7 de fevereiro de 2022, 21:00
 */

#include <stdlib.h>
#include <iostream>

#include "../examples/smarts/Smart_AssignWriteSeizes.h"
#include "../examples/smarts/Smart_BatchSeparate.h"
#include "../examples/smarts/Smart_CppForG.h"
#include "../examples/smarts/Smart_Delay.h"
#include "../examples/smarts/Smart_Dummy.h"
#include "../examples/smarts/Smart_HoldSignal.h"
#include "../examples/smarts/Smart_ModelInfoModelSimulation.h"
#include "../examples/smarts/Smart_ODE.h"
#include "../examples/smarts/Smart_OnEvent.h"
#include "../examples/smarts/Smart_Parser.h"
#include "../examples/smarts/Smart_ParserModelFunctions.h"
#include "../examples/smarts/Smart_Plugin.h"
#include "../examples/smarts/Smart_Process.h"
#include "../examples/smarts/Smart_ProcessSet.h"
#include "../examples/smarts/Smart_RouteStation.h"
#include "../examples/smarts/Smart_SeizeDelayRelease.h"
#include "../examples/smarts/Smart_SeizeDelayReleaseMany.h"
#include "../examples/smarts/Smart_Sequence.h"
//#include "../examples/smarts/"
//#include "../examples/smarts/"
#include "../examples/book/Book_Cap02_Example01.h"
#include "../examples/teaching/AnElectronicAssemblyAndTestSystem.h"
#include "../examples/teaching/FullSimulationOfComplexModel.h"
#include "../examples/teaching/OperatingSystem02.h"
#include "../examples/teaching/OperatingSystem03.h"

/*
 * Simple C++ Test Suite
 */

void example_smart_test1() {
	try {
		Smart_AssignWriteSeizes m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 1" << std::endl;

	}
}

void example_smart_test2() {
	try {
		Smart_AssignWriteSeizes m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 2" << std::endl;

	}
}

void example_smart_test3() {
	try {
		Smart_BatchSeparate m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 3" << std::endl;

	}
}

void example_smart_test4() {
	try {
		Smart_CppForG m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 4" << std::endl;

	}
}

void example_smart_test5() {
	try {
		Smart_Delay m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 5" << std::endl;

	}
}

void example_smart_test6() {
	try {
		Smart_Dummy m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 6" << std::endl;

	}
}

void example_smart_test7() {
	try {
		Smart_HoldSignal m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 7" << std::endl;

	}
}

void example_smart_test8() {
	try {
		Smart_ModelInfoModelSimulation m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 8" << std::endl;

	}
}

void example_smart_test9() {
	try {
		Smart_ODE m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 9" << std::endl;

	}
}

void example_smart_test10() {
	try {
		Smart_OnEvent m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 10" << std::endl;

	}
}

void example_smart_test11() {
	try {
		Smart_Parser m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 11" << std::endl;

	}
}

void example_smart_test12() {
	try {
		Smart_ParserModelFunctions m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 12" << std::endl;

	}
}

void example_smart_test13() {
	try {
		Smart_Plugin m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 13" << std::endl;

	}
}

void example_smart_test14() {
	try {
		Smart_Process m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 14" << std::endl;

	}
}

void example_smart_test15() {
	try {
		Smart_ProcessSet m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 15" << std::endl;

	}
}

void example_smart_test16() {
	try {
		Smart_RouteStation m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 16" << std::endl;

	}
}

void example_smart_test17() {
	try {
		Smart_SeizeDelayRelease m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 17" << std::endl;

	}
}

void example_smart_test18() {
	try {
		Smart_SeizeDelayReleaseMany m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 18" << std::endl;

	}
}

void example_smart_test19() {
	try {
		Smart_Sequence m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST 19" << std::endl;

	}
}

void example_book_test1() {
	try {
		Book_Cap02_Example01 m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST BOOK 1" << std::endl;

	}
}

void example_teaching_test1() {
	try {
		AnElectronicAssemblyAndTestSystem m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST TEACHING 1" << std::endl;

	}
}

void example_teaching_test2() {
	try {
		FullSimulationOfComplexModel m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST TEACHING 2" << std::endl;

	}
}

void example_teaching_test3() {
	try {
		OperatingSystem02 m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST TEACHING 3" << std::endl;

	}
}

void example_teaching_test4() {
	try {
		OperatingSystem03 m;
		m.main(0, 0);
	} catch (...) {
		std::cout << "ERROR IN TEST TEACHING 4" << std::endl;

	}
}

int __main(int argc, char** argv) {
	example_smart_test1();
	example_smart_test2();
	example_smart_test3();
	example_smart_test4();
	example_smart_test5();
	example_smart_test6();
	example_smart_test7();
	example_smart_test8();
	example_smart_test9();
	example_smart_test10();
	example_smart_test11();
	example_smart_test12();
	example_smart_test13();
	example_smart_test14();
	example_smart_test15();
	example_smart_test16();
	example_smart_test17();
	example_smart_test18();
	example_smart_test19();
	example_book_test1();
	example_teaching_test1();
	example_teaching_test3();
	example_teaching_test4();
	example_teaching_test2();
	return (EXIT_SUCCESS);
}

