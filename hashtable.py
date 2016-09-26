""" linked list node """
class ListNode:
	def __init__(self, value):
		self.next = None
		self.value = value

#linked list
class LinkedList:
	def __init__(self, root_value):
		root = ListNode(root_value)
		self.root = root

	def insert(self, value):
		new_node = ListNode(value)
		iter_node = self.root
		while iter_node.next != None:
			iter_node = iter_node.next
		iter_node.next = new_node
	
	def lookup(self,value):
		iter_node = self.root
                while True:
			if iter_node.value == value:
				return iter_node
			if iter_node.next == None:
				break
			iter_node = iter_node.next
		return None

	def print_val(self):
		iter_node = self.root
		print iter_node.value
		while iter_node.next != None:
			iter_node = iter_node.next
			print iter_node.value

class HashTable:
	def __init__(self, size):
		self.elems = [None] * size
		self.size = size

	def insert(self, value):
		index = hash(value) % self.size
		if self.lookup(value) != None:
			return
		if self.elems[index] == None:
			self.elems[index] = LinkedList(value)
			return
		self.elems[index].insert(value)
	
	def lookup(self, value):
		index = hash(value) % self.size
		if self.elems[index] == None:
			return None
		return self.elems[index].lookup(value)

#TODO remove value, free table
	def print_val(self):
		for elem in self.elems:
			if elem != None:
				elem.print_val()

t = HashTable(10)
t.insert(1)
t.insert(2)
t.insert(2)
t.print_val()
print t.lookup(2)
print t.lookup(3)
