#include <iostream>

#include "avl_tree.hpp"

int main(int argc, char **argv) {
  trees::avl_tree<std::string> string_tree{};

  string_tree.insert("foo");
  string_tree.insert("bar");

  std::cout << string_tree.size() << std::endl;

  auto foo_pos = string_tree.find("foo");
  if (!foo_pos) {
    std::cout << "test failed!" << std::endl;
  } else {
    std::cout << "foo's pos = " << *foo_pos << std::endl;
  }
  return 0;
}