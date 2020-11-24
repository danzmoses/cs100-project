#include "gtest/gtest.h"

#include "entity_tests.hpp"
#include "Entity_test.h"
#include "Item_test.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
