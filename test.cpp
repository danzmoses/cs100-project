#include "gtest/gtest.h"

#include "header/Entity_test.h"
#include "header/Item_test.h"
#include "header/prototypes/prototype_tests.h"
#include "header/inventory_tests.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
