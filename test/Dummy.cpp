#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../lib/simple/include/Parallelogram.h"

using namespace testing;
using namespace shapes;

TEST(ParallelogramTests, ParallelogramTestZero)
{
    Parallelogram parallelogram{Side{5}, Side{5}, Angle{20}};
    std::cerr << "getArea = " << parallelogram.getArea() << std::endl;
    std::cerr << "isRectangle = " << parallelogram.isRectangle() << std::endl;
    std::cerr << "isRhombus = " << parallelogram.isRhombus() << std::endl;
    std::cerr << "isSquare = " << parallelogram.isSquare() << std::endl;
    //    std::cerr << "getKind = " << parallelogram.getKind() << std::endl;
    std::cerr << "getPerimeter = " << parallelogram.getPerimeter() << std::endl;

    EXPECT_TRUE(false);
}

/*
 * Task 1
 * Create three distinct and independent test cases that result in failure. You should reason about the correct and
 * incorrect states of the class, and the tests should indicate actual bugs in the above mentioned methods of the class.
 * Validate this by actually running the test cases. Make sure that the tests would pass if the bugs were fixed.
 * Grading may include runing your tests on corrected implementations to verify the behaviors.
*/

TEST(ParallelogramTests, ParallelogramTestOne)
{
    EXPECT_TRUE(false);
}

TEST(ParallelogramTests, ParallelogramTestTwo)
{
    EXPECT_TRUE(false);
}

TEST(ParallelogramTests, ParallelogramTestsThree)
{
    EXPECT_TRUE(false);
}

TEST(ParallelogramTests, ParallelogramTestsFour)
{
    EXPECT_TRUE(false);
}

TEST(ParallelogramTests, ParallelogramTestsFive)
{
    EXPECT_TRUE(false);
}

TEST(ParallelogramTests, ParallelogramTestsSix)
{
    EXPECT_TRUE(false);
}