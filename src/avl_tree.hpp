#pragma once

namespace trees {

template <typename value_t> class avl_tree {
  struct node {
    node *left, right;
    const value_t val;
    int count;
    int height;

    explicit node(const value_t &value)
        : val{value}, count{1}, height{1}, left{nullptr}, right{nullptr} {}

    void update_values() {}

    int balance_factor() {}
  };
};
}