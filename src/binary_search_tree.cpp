#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    if (root_ == nullptr){
      root_ = new Node(key, value);
    }else{
      insert(key, value, root_);
    }
  }

  bool BinarySearchTree::Remove(int key) {
    if (root_ == nullptr) {
      return false;
    }
    if (remove(key, root_)){
      return true;
    }
  }

  void BinarySearchTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* found_node = find(key, root_);
    if (found_node == nullptr){
      return std::nullopt;
    }
    return found_node->value;
  }

  bool BinarySearchTree::Contains(int key) const {
    if (Find(key)){
      return true;
    }
    return false;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    Node* current_node = root_;
    if (current_node == nullptr){
      return std::nullopt;
    }
    while (current_node->left != nullptr){
      current_node = current_node->left;
    }
    return current_node->value;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    Node* current_node = root_;
    if (current_node == nullptr){
      return std::nullopt;
    }
    while (current_node->right != nullptr){
      current_node = current_node->right;
    }
    return current_node->value;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (key == node->key){
      node->value =value;
    }

    if (key < node->key){
      if (node->left == nullptr){
        Node* new_node = new Node(key, value);
        node->left = new_node;
      }
      else{
        return insert(key, value, node->left);
      }
    }
    if (key > node->key){
      if (node->right == nullptr){
        Node* new_node = new Node(key, value);
        node->right = new_node;
      }else{
        return insert(key, value, node->right);
      }
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    if (node == nullptr){
      return false;
    }
    if (key == node->key){
      if (node->left != nullptr and node->right != nullptr){
        Node* min_node = find_min(node->right);
        node->key = min_node->key;
        node->value = min_node->value;
        return remove(min_node->key, node->right);
      }
      if (node->left != nullptr and node->right == nullptr){
        Node* left_child = node->left;
        delete node;
        node = left_child;
        return true;
      }
      if (node->left == nullptr and node->right != nullptr){
        Node* right_child = node->right;
        delete node;
        node = right_child;
        return true;
      }
    }
    if (key < node->key){
      return remove(key, node->left);
    }
    if (key > node->key){
      return remove(key, node->right);
    }
  }

  void BinarySearchTree::clear(Node* node) {
    if (node != nullptr){
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr){
      return nullptr;
    }
    if (key == node->key){
      return node;
    }
    if (key < node->key){
      return find(key, node->left);
    }
    if (key > node->key){
      return find(key, node->right);
    }
    return nullptr;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    while (node->left != nullptr){
      node = node->left;
    }
    return node;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    // Write your code here...
    return nullptr;
  }

}  // namespace assignment