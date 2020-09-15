#
# Created on Sun Sep 13 2020
#
# Copyright (c) 2020 SaiReddy
#


class Node:
    def __init__(self, number):
        self.left = None
        self.right = None
        self.data = number
        self.data = number

    def display(self):
        lines, *_ = self._display_aux()
        for line in lines:
            print(line)

    # https://stackoverflow.com/a/54074933/11652193
    def _display_aux(self):
        """Returns list of strings, width, height, and horizontal coordinate of the root."""
        # No child.
        if self.right is None and self.left is None:
            line = "%s" % self.data
            width = len(line)
            height = 1
            middle = width // 2
            return [line], width, height, middle

        # Only left child.
        if self.right is None:
            lines, n, p, x = self.left._display_aux()
            s = "%s" % self.data
            u = len(s)
            first_line = (x + 1) * " " + (n - x - 1) * "_" + s
            second_line = x * " " + "/" + (n - x - 1 + u) * " "
            shifted_lines = [line + u * " " for line in lines]
            return [first_line, second_line] + shifted_lines, n + u, p + 2, n + u // 2

        # Only right child.
        if self.left is None:
            lines, n, p, x = self.right._display_aux()
            s = "%s" % self.data
            u = len(s)
            first_line = s + x * "_" + (n - x) * " "
            second_line = (u + x) * " " + "\\" + (n - x - 1) * " "
            shifted_lines = [u * " " + line for line in lines]
            return [first_line, second_line] + shifted_lines, n + u, p + 2, u // 2

        # Two children.
        left, n, p, x = self.left._display_aux()
        right, m, q, y = self.right._display_aux()
        s = "%s" % self.data
        u = len(s)
        first_line = (x + 1) * " " + (n - x - 1) * "_" + s + y * "_" + (m - y) * " "
        second_line = (
            x * " " + "/" + (n - x - 1 + u + y) * " " + "\\" + (m - y - 1) * " "
        )
        if p < q:
            left += [n * " "] * (q - p)
        elif q < p:
            right += [m * " "] * (p - q)
        zipped_lines = zip(left, right)
        lines = [first_line, second_line] + [a + u * " " + b for a, b in zipped_lines]
        return lines, n + m + u, max(p, q) + 2, n + u // 2


def insert(root, number):
    if root is None:
        root = Node(number)
        print(root.data)
        return root
    current = root
    parent = None
    while current:
        parent = current
        if current.data > number:
            current = current.left
        else:
            current = current.right

    if parent.data > number:
        parent.left = Node(number)
    else:
        parent.right = Node(number)


def inorder(root):
    if root == None:
        return
    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)


def search(root, number):
    current = root
    while current:
        if current.data == number:
            print("Number Found")
            return
        elif current.data > number:
            current = current.left
        else:
            current = current.right

    print("Number not Found")


def deleteNode(root, number):

    if root is None:
        return root

    if number < root.data:
        root.left = deleteNode(root.left, number)

    elif number > root.data:
        root.right = deleteNode(root.right, number)

    else:

        if root.left is None:
            temp = root.right
            root = None
            return temp

        elif root.right is None:
            temp = root.left
            root = None
            return temp

        temp = minValueNode(root.right)

        root.data = temp.data

        root.right = deleteNode(root.right, temp.data)

    return root


def minValueNode(node):
    current = node
    while current.left is not None:
        current = current.left

    return current


if __name__ == "__main__":

    root = None
    root = insert(root, 50)
    insert(root, 30)
    insert(root, 20)
    insert(root, 40)
    insert(root, 70)
    insert(root, 60)
    insert(root, 80)
    inorder(root)

    print("\n")
    root.display()
    # search(root,20)
    # search(root,21)
    # print("\n")
    deleteNode(root, 60)
    root.display()
    deleteNode(root, 20)
    # inorder(root)
    root.display()
    print("\n")
    deleteNode(root, 30)
    # inorder(root)
    root.display()
    print("\n")
    deleteNode(root, 50)
    # inorder(root)
    root.display()
    print("\n")
    deleteNode(root, 70)
    # inorder(root)
    root.display()

    print("\n")
    deleteNode(root, 80)
    # inorder(root)
    root.display()

