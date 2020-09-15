#
# Created on Tue Sep 15 2020
#
# Copyright (c) 2020 SaiReddy
#

class Node:
    def __init__(self,data):
        self.data=data;
        self.left=self.right=None;

def invertBinaryTree(root):
    if not root:
        return
    root.left,root.right=root.right,root.left
    invertBinaryTree(root.left)
    invertBinaryTree(root.right)

def inorder(root):
    if not root:
        return
    inorder(root.left)
    print(root.data,end=" ")
    inorder(root.right)



root=Node(3)
root.left=Node(4)
root.right=Node(5)
inorder(root)
invertBinaryTree(root)
print("\n")
inorder(root)


        
