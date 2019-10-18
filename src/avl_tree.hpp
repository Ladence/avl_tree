#pragma once

#include <algorithm>

namespace trees {

template <typename value_t> class avl_tree {
  /**
   * @struct node struct defines behaviour of underlying elements in AVL-tree
   */
  struct node {
    node *left, *right;
    const value_t val;
    int count;
    int height;

    /**
     * C'tor. Initalizes node with value
     * @param value value for V-field
     */
    explicit node(const value_t &value)
        : val{value}, count{1}, height{1}, left{nullptr}, right{nullptr} {}

    /**
     * Re-calculcates values for successors after rotation
     */
    void update_values() {
      count = (left ? left->count : 0) + (right ? right->count : 0) + 1;

      height = std::max(left ? left->height : 0, right ? right->height : 0) + 1;
    }

    /**
     * Balance factor shows which of subtrees is bigger.
     * @return balance factor value for current node
     */
    int balance_factor() {
      return (left ? left->height : 0) - (right ? right->height : 0);
    }

    /**
     * Left-rotation after insert/delete operation
     * @return changed root for this subtree
     */
    node *left_rotate() {
      auto R = right;
      right = right->left;
      R->left = this;

      update_values();
      R->update_values();

      return R;
    }

    /**
     * Right-rotation after insert/delete operation
     * @return changed root for this subtree
     */
    node *right_rotate() {
      auto L = left;
      left = left->right;
      L->right = this;

      update_values();
      L->update_values();

      return L;
    }
  };

public:
  /**
   * Inserts node with predefined value in tree
   * @param value value-field of insertable node
   */
  void insert(const value_t &value) { throw; }
  /**
   * Removes element with predefined value from tree
   * @param value value-field of deletable node
   */
  void erase(const value_t &value) { throw; }

  /**
   * Removes all elements from tree
   */
  void clear() { throw; }

  /**
   * Returns is the tree doesn't contain elements
   * @return true if no elements are present, else false
   */
  bool empty() const { return m_size == 0; }

  /**
   * Returns tree's actual size (count of elements or nodes in tree)
   * @return actual size of tree
   */
  std::size_t size() const { return m_size; }

  /**
   * Returns position (index) in tree of element with predefined value field
   * @param value desired value
   * @return idx of desired element in tree
   */
  std::size_t find(const value_t &value) const { throw; }

  /**
   * Returns an pos of the first element in tree that is >= value
   * @param value value to compare the elements to
   * @return pos of the first element that is value-field >= value.
   */
  std::size_t lower_bound(const value_t &value) const { throw; }

  /**
   * Returns an pos of the first element in tree that is <= value
   * @param value value to compare the elements to
   * @return pos of the first element that is value-field <= value
   */
  std::size_t upper_bound(const value_t &value) const { throw; }

  /**
   * Returns mutable value (const ref) of findable node by index
   * @param index index of element in tree
   * @return const reference to founded element
   */
  const value_t &operator[](std::size_t index) const { throw; }

private:
  std::size_t m_size;
  node *root;
};
}