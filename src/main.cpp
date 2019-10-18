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

    std::cout << "by this index = " << string_tree[*foo_pos] << std::endl;

    string_tree.erase(string_tree[*foo_pos]);

    std::cout << "size afte erase = " << string_tree.size() << std::endl;
  }

  return 0;
}