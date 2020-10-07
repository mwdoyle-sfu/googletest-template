# googletest-template

rm -rf build

sudo mkdir build; cmake ../googletest-template; make

cd test/

./runAllTests

test functions:

ASSERT_TRUE(condition);

ASSERT_FALSE(condition);

ASSERT_EQ(expected,actual);

ASSERT_NE(val1,val2);

ASSERT_LT(val1,val2);

ASSERT_LE(val1,val2);

ASSERT_GT(val1,val2);

ASSERT_GE(val1,val2);

EXPECT_TRUE(condition);

EXPECT_FALSE(condition);

EXPECT_EQ(expected,actual);

EXPECT_NE(val1,val2);

EXPECT_LT(val1,val2);

EXPECT_LE(val1,val2);

EXPECT_GT(val1,val2);

EXPECT_GE(val1,val2);
