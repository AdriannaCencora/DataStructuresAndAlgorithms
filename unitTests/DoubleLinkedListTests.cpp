#include "../src/DoubleLinkedList.cpp"
#include <gtest/gtest.h>

class DoubleLinkedListTest : public testing::Test {
	public:
		DoubleLinkedListTest() {
			EXPECT_EQ(0, uut->getSize());
		}

		DoubleLinkedList* uut = new DoubleLinkedList();

		void assertStateEquals(int givenSize) {
			EXPECT_EQ(givenSize, uut->getSize());
		}
};

TEST_F(DoubleLinkedListTest, IfInsertFront4TimesExpectSize4) {
	uut->insert(0,66);
	assertStateEquals(1);

	uut->insert(0,55);
	assertStateEquals(2);

	uut->insert(0,44);
	assertStateEquals(3);

	uut->insert(0,33);
	assertStateEquals(4);
}

TEST_F(DoubleLinkedListTest, IfInsertBack4TimesExpectSize4) {
	uut->insert(0,66);
	assertStateEquals(1);

	uut->insert(1,55);
	assertStateEquals(2);

	uut->insert(2,44);
	assertStateEquals(3);

	uut->insert(3,33);
	assertStateEquals(4);
}

TEST_F(DoubleLinkedListTest, IfInsertAtPosition4TimesExpectSize4) {
	uut->insert(0,66);

	assertStateEquals(1);

	uut->insert(1,55);
	assertStateEquals(2);

	uut->insert(1,44);
	assertStateEquals(3);

	uut->insert(1,33);
	assertStateEquals(4);
}

TEST_F(DoubleLinkedListTest, IfFillWithRandom60TimesExpectSize60) {
	uut->fillWithRandomData(60, 100000);
	assertStateEquals(60);
}

TEST_F(DoubleLinkedListTest, IfRemoveOneElExpectSizeDecreaseAt1) {
	uut->fillWithRandomData(60, 100000);
	assertStateEquals(60);

	uut->insert(30,5);
	assertStateEquals(61);

	uut->remove(5);
	assertStateEquals(60);
}
