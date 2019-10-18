#include <iostream>

#include "avl_tree.hpp"

int main(int argc, char **argv) {
  trees::avl_tree<std::string> string_tree{};

  string_tree.insert("foo");
  string_tree.insert("bar");

  std::cout << string_tree.size() << std::endl;

  string_tree.clear();

  std::cout << string_tree.size() << std::endl;
  return 0;
}