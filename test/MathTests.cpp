//
// Created by carlostojal on 08-06-2023.
//

#include <gtest/gtest.h>
#include <path_tracker/Math.h>

class MathTests : public ::testing::Test {

};
/* Tests calculateIncrement using a precalculated answer*/
TEST_F(MathTests, testIncrement) {

    ASSERT_DOUBLE_EQ(-0.25, path_tracker::Math::calculateIncrement(-1, 1.5, 4));
}
