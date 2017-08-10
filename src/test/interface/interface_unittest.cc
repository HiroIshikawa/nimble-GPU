#include "../../interface/Interface.h"
#include "/Users/hiro99ishikawa/Library/googletest/googletest/include/gtest/gtest.h"


TEST(ReadNumberTest, Negative) {
	Interface interface;
	EXPECT_EQ(-1, interface.readNumber());
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}