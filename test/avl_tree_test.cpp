#include <gtest/gtest.h>

#include "avl_tree.hpp"

namespace test {
using namespace trees;

TEST(AvlTree, InsertIntTest) {
  avl_tree<int> testable{};
  testable.insert(5);
  ASSERT_EQ(1, testable.size());
}

TEST(AvlTree, IndexRevalidationTest) {
  avl_tree<int> testable{};
  testable.insert(5);
  testable.insert(6);
  testable.erase(testable[0]);
  ASSERT_EQ(6, testable[0]);
}

TEST(AvlTree, NotFoundExcTest) {
  avl_tree<std::string> testable{};
  testable.insert("foo");
  testable.insert("bar");
  EXPECT_THROW(
      {
        try {
          testable.erase("bazz");
        } catch (std::runtime_error &err) {
          EXPECT_STREQ("Element does not exist in tree", err.what());
          throw;
        }
      },
      std::runtime_error);
}
}