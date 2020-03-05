#include "DynamicArray.h"
#include "GenericStructure.h"
#include <gtest/gtest.h>

TEST(createDynamicArray, sizeEqualsTwo) {
	GenericStructure *uut = new DynamicArray(2);
	ASSERT_EQ(2, uut->logicalSize);
}
