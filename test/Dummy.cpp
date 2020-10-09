#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../lib/simple/include/Parallelogram.h"

using namespace testing;
using namespace shapes;

/*
 * Task 1
 * Create three distinct and independent test cases that result in failure. You should reason about the correct and
 * incorrect states of the class, and the tests should indicate actual bugs in the above mentioned methods of the class.
 * Validate this by actually running the test cases. Make sure that the tests would pass if the bugs were fixed.
 * Grading may include runing your tests on corrected implementations to verify the behaviors.
*/

// for kind consider angles and sides
TEST(ParallelogramTests, getPerimeterTest)
{
    Parallelogram parallelogram{Side{50}, Side{60}, Angle{45}};

    // calculate the perimeter
    // 2*(s1 + s2) = 2(50 + 60) = 220

//    std::cerr << "getPerimeter = " << parallelogram.getPerimeter() << std::endl;
    // getPerimeter returns 200

    ASSERT_EQ(parallelogram.getPerimeter(), 220);
}


TEST(ParallelogramTests, getAreaTest)
{
    Parallelogram parallelogram{Side{50}, Side{60}, Angle{45}};

    // calculate the area
    // s1 * s2 * Sin(interior) = A
    // 50 * 60 * Sin(45) =~ 2121.3203435596425732025330863145471178545078130654221097650196069

//    std::cerr << "getArea = " << parallelogram.getArea() << std::endl;
    // getArea returns 2545.58

    // comparing doubles can cause issues so I used round
    ASSERT_EQ(round(parallelogram.getArea()), round(2121.32));
}

TEST(ParallelogramTests, isRectangleTest)
{
    // getKind
    Parallelogram parallelogramSquare{Side{50}, Side{50}, Angle{89.99999999999999999}};
    Parallelogram parallelogramRectangle{Side{50}, Side{60}, Angle{89.99999999999999999}};

    // test isRectangle
    // 0 is not rect
    // 1 is rectangle
//    std::cerr << "isRectangle = " << parallelogramSquare.getKind() << std::endl;
//    std::cerr << "isRectangle = " << parallelogramSquare.isRectangle() << std::endl;
//    std::cerr << "isRectangle = " << parallelogramRectangle.getKind() << std::endl;
//    std::cerr << "isRectangle = " << parallelogramRectangle.isRectangle() << std::endl;

    // every square is a rectangle but every rectangle is not a square
    EXPECT_EQ(false, parallelogramRectangle.isRectangle());
    EXPECT_EQ(false, parallelogramSquare.isRectangle());
}


//TEST(ParallelogramTests, ParallelogramTestsFour)
//{
//    EXPECT_TRUE(false);
//}
//
//TEST(ParallelogramTests, ParallelogramTestsFive)
//{
//    EXPECT_TRUE(false);
//}
//
//TEST(ParallelogramTests, ParallelogramTestsSix)
//{
//    EXPECT_TRUE(false);
//}