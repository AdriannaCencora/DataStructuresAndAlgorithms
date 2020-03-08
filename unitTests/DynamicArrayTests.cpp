#include "../src/DynamicArray.cpp"
#include <gtest/gtest.h>
#include <vector>

class DynamicArrayTest : public testing::Test {
	public:
		DynamicArrayTest() {
			EXPECT_EQ(0, uut->getSize());
			EXPECT_EQ(4, uut->getCapacity());
		}

		DynamicArray *uut = new DynamicArray();

		void assertStateEquals(int givenSize, int givenCapacity) {
			EXPECT_EQ(givenSize, uut->getSize());
			EXPECT_EQ(givenCapacity, uut->getCapacity());
		}

		void assertValuesEquals(std::vector<int> givenValues) {
			EXPECT_EQ(givenValues.size(), uut->getSize());
			for (int i{0}; i < uut->getSize(); ++i) {
				EXPECT_EQ(givenValues[i], uut->getDataAt(i));
			}
		}

};


TEST_F(DynamicArrayTest, IfInsertFront4TimesExpectSize4) {
	uut->insert(0,66);

	assertStateEquals(1, 4);
	assertValuesEquals({66});

	uut->insert(0,55);
	assertStateEquals(2, 4);
	assertValuesEquals({55, 66});

	uut->insert(0,44);
	assertStateEquals(3, 4);
	assertValuesEquals({44, 55, 66});

	uut->insert(0,33);
	assertStateEquals(4, 4);
	assertValuesEquals({33, 44, 55, 66});
}

TEST_F(DynamicArrayTest, IfInsertBack4TimesExpectSize4) {
	uut->insert(0,66);

	assertStateEquals(1, 4);
	assertValuesEquals({66});

	uut->insert(1,55);
	assertStateEquals(2, 4);
	assertValuesEquals({66, 55});

	uut->insert(2,44);
	assertStateEquals(3, 4);
	assertValuesEquals({66, 55, 44});

	uut->insert(3,33);
	assertStateEquals(4, 4);
	assertValuesEquals({66, 55, 44, 33});
}

TEST_F(DynamicArrayTest, IfInsertAtPosition4TimesExpectSize4) {
	uut->insert(0,66);

	assertStateEquals(1, 4);
	assertValuesEquals({66});

	uut->insert(1,55);
	assertStateEquals(2, 4);
	assertValuesEquals({66, 55});

	uut->insert(1,44);
	assertStateEquals(3, 4);
	assertValuesEquals({66, 44, 55});

	uut->insert(1,33);
	assertStateEquals(4, 4);
	assertValuesEquals({66, 33, 44, 55});
}

TEST_F(DynamicArrayTest, IfInsertOutOfCapacityExpectBadAlloc) {
	EXPECT_THROW(uut->insert(40,666), std::bad_alloc);
}

TEST_F(DynamicArrayTest, IfInsert16TimesExpectResizeTwice) {
	for (int i{0}; i <= 16; ++i) {
		uut->insert(0,i);
	}

	assertStateEquals(17,32);
}

TEST_F(DynamicArrayTest, IfRemoveOneElemExpectSizeDecreaseAt1) {
	uut->insert(0,66);

	assertStateEquals(1, 4);
	assertValuesEquals({66});

	uut->insert(0,55);
	assertStateEquals(2, 4);
	assertValuesEquals({55, 66});

	uut->insert(0,44);
	assertStateEquals(3, 4);
	assertValuesEquals({44, 55, 66});

	uut->insert(0,33);
	assertStateEquals(4, 4);
	assertValuesEquals({33, 44, 55, 66});

	uut->remove(0);
	assertStateEquals(3, 4);
	assertValuesEquals({44, 55, 66});

	uut->remove(1);
	assertStateEquals(2, 4);
	assertValuesEquals({44, 66});

	uut->remove(1);
	assertStateEquals(1, 4);
	assertValuesEquals({44});
}
