#pragma once

#include <algorithm>
#include <stack>
#include <vector>

namespace trees {

template <typename value_t> class avl_tree {
  /**
   * @struct node struct defines behaviour of underlying elements in AVL-tree
   */
  struct node {
    node *left, *right;
    value_t value;
    int count;
    int height;

    /**
     * C'tor. Initalizes node with value
     * @param value value for V-field
     */
    explicit node(const value_t &value)
        : value{value}, count{1}, height{1}, left{nullptr}, right{nullptr} {}

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

  /**
   * Does auto-balance tree after all operations
   */
  void balance(const std::vector<node *> &path) {
    std::reverse(path.begin(), path.end());

    for (auto indirect : path) {
      indirect->update_values();

      // left > left (right rotation)
      if (indirect->balance_factor() >= 2 &&
          indirect->left->balance_factor() >= 1) {
        indirect = indirect->right_rotate();
      } else if (indirect->balance_factor() >= 2) { // left > right
        indirect->left = indirect->left->left_rotate();
        indirect = indirect->right_rotate();
      } else if (indirect->balance_factor() <= -2 &&
                 indirect->right->balance_factor() <= 1) { // right > right
        indirect = indirect->left_rotate();
      } else if (indirect->balance_factor() <= -2) { // right < left
        indirect->right = indirect->right->right_rotate();
        indirect = indirect->left_rotate();
      }
    }
  }

public:
  avl_tree() : m_root{nullptr}, m_size{0} {}
  ~avl_tree() { clear(); }

  /**
   * Inserts node with predefined value in tree
   * @param value value-field of insertable node
   */
  void insert(const value_t &value) {
    auto indirect = m_root;
    std::vector<node *> path;

    while (indirect) {
      path.push_back(indirect);

      if (indirect->value > value) {
        indirect = indirect->left;
      } else {
        indirect = indirect->right;
      }
    }

    indirect = new node(value);
    path.push_back(indirect);

    balance(path);
    m_size++;
  }

  /**
   * Removes element with predefined value from tree
   * @param value value-field of deletable node
   */
  void erase(const value_t &value) { throw; }

  /**
   * Removes all elements from tree
   */
  void clear() {
    std::stack<node *> stack;

    if (m_root) {
      stack.push(m_root);
    }

    while (!stack.empty()) {
      auto node = stack.top();
      stack.pop();

      if (node->left) {
        stack.push(node->left);
      }

      if (node->right) {
        stack.push(node->right);
      }

      m_size--;
      delete node;
    }

    m_root = nullptr;
  }

  /**
   * Returns is the tree doesn't contain elements
   * @return true if no elements are present, else false
   */
  [[nodiscard]] bool empty() const { return m_size == 0; }

  /**
   * Returns tree's actual size (count of elements or nodes in tree)
   * @return actual size of tree
   */
  [[nodiscard]] std::size_t size() const { return m_size; }

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
  node *m_root;
};
}