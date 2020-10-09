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

TEST(ParallelogramTests, getKindTest)
{
    // getKind
    Parallelogram parallelogramSquareOne{Side{50}, Side{50}, Angle{90}};

    // every square is a rectangle but every rectangle is not a square
    // getKind returns a rectangle
    EXPECT_EQ(shapes::Parallelogram::Kind::SQUARE, parallelogramSquareOne.getKind());
}

TEST(ParallelogramTests, nonPerfectSquareTest)
{
    // test if is square works in edge case
    Parallelogram parallelogramSquareTwo{Side{50}, Side{50}, Angle{89.999999999999999}};

    // isSquare returns true even if the interior angle is not 90 degrees
    EXPECT_EQ(false, parallelogramSquareTwo.isSquare());
}



TEST(ParallelogramTests, isSquareTest)
{
    Parallelogram parallelogram{Side{50}, Side{50}, Angle{90}};
    // test if is square works with valid input
    ASSERT_EQ(true, parallelogram.isSquare());
}

TEST(ParallelogramTests, isRhombusTest)
{
    Parallelogram parallelogram{Side{50}, Side{50}, Angle{90}};
    // test if is square works with valid input
    ASSERT_EQ(true, parallelogram.isRhombus());
}

TEST(ParallelogramTests, invalidParallelogramTest)
{
    // inputs (x, y, z)
    Parallelogram parallelogram{Side{50}, Side{60}, Angle{70}};
    Parallelogram Rectangle{Side{50}, Side{60}, Angle{90}};
    Parallelogram rhombus{Side{50}, Side{50}, Angle{70}};

    EXPECT_EQ(shapes::Parallelogram::Kind::PARALLELOGRAM, parallelogram.getKind());
    EXPECT_EQ(shapes::Parallelogram::Kind::RECTANGLE, Rectangle.getKind());
    EXPECT_EQ(shapes::Parallelogram::Kind::RHOMBUS, rhombus.getKind());
}
