/*
 * @Author: tkzzzzzz6
 * @Date: 2026-04-08 00:18:30
 * @LastEditors: tkzzzzzz6
 * @LastEditTime: 2026-04-08 00:26:36
 */
#include <iostream>
using namespace std;

class MyLinkedList {
public:
  class Node {
  public:
    int val;
    Node *next;
    Node(int _val) : val(_val), next(NULL) {}
  };

  MyLinkedList() {
    _dummyHead = new Node(0);
    _size = 0;
  }

  int get(int index) {
    if (index < 0 || index >= _size) {
      return -1;
    }
    Node *cur = _dummyHead;
    while (index--) {
      cur = cur->next;
    }
    return cur->next->val;
  }

  void addAtHead(int val) {
    Node *nodeTemp = new Node(val);
    nodeTemp->next = _dummyHead->next;
    _dummyHead->next = nodeTemp;
    _size++;
  }

  void addAtTail(int val) {
    Node *nodeTemp = new Node(val);
    Node *cur = _dummyHead;
    while (cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = nodeTemp;
    _size++;
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > _size) {
      return;
    }
    Node *cur = _dummyHead;
    Node *nodeTemp = new Node(val);
    while (index--) {
      cur = cur->next;
    }
    nodeTemp->next = cur->next;
    cur->next = nodeTemp;
    _size++;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= _size) {
      return;
    }
    Node *cur = _dummyHead;
    while (index--) {
      cur = cur->next;
    }
    Node *nodeTemp = cur->next;
    cur->next = cur->next->next;
    delete nodeTemp;
    _size--;
  }

private:
  Node *_dummyHead;
  int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
