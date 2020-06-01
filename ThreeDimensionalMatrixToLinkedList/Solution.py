class SpecialNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.up = None
        self.down = None
        self.front = None
        self.back = None

    def extract_neightbors(self):
        lst = []#[self.val] 
        if self.front != None:
           lst.append(self.front.val)
        if self.back != None:
           lst.append(self.back.val)
        if self.left != None:
           lst.append(self.left.val)
        if self.right != None:
           lst.append(self.right.val)
        if self.up != None:
           lst.append(self.up.val)
        if self.down != None:
           lst.append(self.down.val)

        return lst


def matrix_to_linked_list(mat):
