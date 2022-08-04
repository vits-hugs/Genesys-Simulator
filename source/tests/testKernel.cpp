/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/testFiles/simpletest.cpp to edit this template
 */

/* 
 * File:   testKernel.cpp
 * Author: rlcancian
 *
 * Created on 3 de agosto de 2022, 21:27
 */

// based on https://micromouseonline.com/2016/02/08/googletest-with-netbeans/
// https://micromouseonline.com/2016/02/12/tdd-with-googletest-and-netbeans/

// to create tests in the source: https://www.youtube.com/watch?v=TS2CTf11k1U (compile gtest as a library)

#include <stdlib.h>
#include <iostream>
#include "../../source/gtest/gtest/gtest.h"
#include "Tests.h"
using namespace std;

TEST(TestKernel, testModel) {
    EXPECT_EQ(0,0);
}

TEST(TerminalApplication, SmartAssign) {
    EXPECT_EQ(2,2);
}

int main (int argc, char** argv)
{
  cout << "TESTING KERNEL" << endl;
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS();
}
