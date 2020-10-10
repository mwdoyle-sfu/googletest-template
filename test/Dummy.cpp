#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../lib/simple/include/Parallelogram.h"
#include "../lib/simple/include/Matthews.h"
#include "../lib/simple/include/Awards.h"

using namespace testing;
using namespace shapes;
using namespace sequence;
using namespace awards;
using ::testing::AtLeast;


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

/*
    Task 2
    Now consider the function checkMatthewsOutcome() declared in Matthews.h and defined in Matthews.cpp.
    Create a set of related tests such that every statement in checkMatthewsOutcome() is executed by at
    least one test. The group name or test fixture for the tests should be called MatthewsTests. Make sure
    the name is correct.
 */

TEST(MatthewsTests, checkMatthewsOutcomeTest)
{
    // First consider the termination conditions.
    // remainder = 0
    EXPECT_EQ(MatthewsOutcome::ZERO,checkMatthewsOutcome(3));
    // number = -1
    EXPECT_EQ(MatthewsOutcome::MINUS_ONE_CYCLE,checkMatthewsOutcome(-1));
    // number = -2
    EXPECT_EQ(MatthewsOutcome::MINUS_TWO_CYCLE,checkMatthewsOutcome(-2));
    // number = -4
    EXPECT_EQ(MatthewsOutcome::MINUS_TWO_CYCLE,checkMatthewsOutcome(-4));

    // Then consider the continuation conditions.
    // remainder = 1
    EXPECT_EQ(MatthewsOutcome::ZERO,checkMatthewsOutcome(1));
    // number = 0
    EXPECT_EQ(MatthewsOutcome::ZERO,checkMatthewsOutcome(0));
}

/*
    Task 3
    Finally, consider the performAwardCeremony function declared in Awards.h and defined in Awards.cpp.
    This function reads a list of names from a sequence and awards medals to the first three names.
    Write a test case that makes sure the ceremony runs as intended. You will need to create a stub for
    RankList and a mock for AwardCeremonyActions. The methods of AwardCeremonyActions should be called
    exactly once each in the order: playAnthem(), awardBronze(), awardSilver(), awardGold(), and
    turnOffTheLightsAndGoHome(). The getNext() method of RankList should be called three times, and the
    names returned should be passed to awardBronze(), awardSilver(), and awardGold() in the same order
    they are read from the list. I highly recommend that you consult the Google Mock Dummies Guide in
    order to make sure that you (1) correctly create the test fakes, (2) validate that the methods were
    called, and (3) validate that they were called in the right order and with the right arguments. The
    group name or test fixture for the test should be called AwardsTests.
 */

struct MockAwardCeremonyActions : public AwardCeremonyActions
{
    MOCK_METHOD(void, playAnthem, (), (override));
    MOCK_METHOD(void, awardBronze, (std::string), (override));
    MOCK_METHOD(void, awardSilver, (std::string), (override));
    MOCK_METHOD(void, awardGold, (std::string), (override));
    MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));

};

struct MockRankList : public RankList
{
    MOCK_METHOD(std::string, getNext, (), (override));
};


TEST(AwardsTests, mockAwardsTest)
{
    MockRankList mockRankList;
    MockAwardCeremonyActions mockAwardCeremonyActions;

    EXPECT_CALL(mockAwardCeremonyActions, playAnthem());
    EXPECT_CALL(mockAwardCeremonyActions, awardBronze(mockRankList.getNext()));
    EXPECT_CALL(mockAwardCeremonyActions, awardSilver(mockRankList.getNext()));
    EXPECT_CALL(mockAwardCeremonyActions, awardGold(mockRankList.getNext()));
    EXPECT_CALL(mockAwardCeremonyActions, turnOffTheLightsAndGoHome());

    awards::performAwardCeremony(mockRankList, mockAwardCeremonyActions);
}