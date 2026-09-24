class Node:
    def __init__(self, key, value):
        self.key = key
        self.val = value
        self.freq = 1
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        # Sentinel dummy nodes to eliminate boundary edge cases
        self.dummy_head = Node(0, 0)
        self.dummy_tail = Node(0, 0)
        self.dummy_head.next = self.dummy_tail
        self.dummy_tail.prev = self.dummy_head
        self._size = 0

    def __len__(self):
        return self._size

    def append(self, node):
        """Adds a node right before the dummy tail (Most Recently Used)."""
        prev_node = self.dummy_tail.prev
        prev_node.next = node
        node.prev = prev_node
        node.next = self.dummy_tail
        self.dummy_tail.prev = node
        self._size += 1

    def pop_head(self):
        """Removes and returns the first actual node (Least Recently Used)."""
        if self._size == 0:
            return None
        first_node = self.dummy_head.next
        self.remove(first_node)
        return first_node

    def remove(self, node):
        """Removes a specific node from the linked list."""
        node.prev.next = node.next
        node.next.prev = node.prev
        self._size -= 1

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}             # key -> Node
        self.frequencies = {}       # freq -> DoublyLinkedList
        self.min_freq = 0

    def _update_frequency(self, node: Node):
        """Increments a node's frequency and shifts it to the correct DLL bucket."""
        old_freq = node.freq
        new_freq = old_freq + 1
        node.freq = new_freq
        
        # Remove from old frequency list
        self.frequencies[old_freq].remove(node)
        
        # If the old frequency list is empty and it was the min_freq, increment min_freq
        if old_freq == self.min_freq and len(self.frequencies[old_freq]) == 0:
            self.min_freq += 1
            
        # Add to the new frequency list
        if new_freq not in self.frequencies:
            self.frequencies[new_freq] = DoublyLinkedList()
        self.frequencies[new_freq].append(node)

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        
        node = self.cache[key]
        self._update_frequency(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if self.capacity == 0:
            return

        if key in self.cache:
            node = self.cache[key]
            node.val = value
            self._update_frequency(node)
        else:
            # Enforce eviction if at capacity
            if len(self.cache) >= self.capacity:
                # Evict the LRU node from the min_freq bucket
                evict_list = self.frequencies[self.min_freq]
                evicted_node = evict_list.pop_head()
                if evicted_node:
                    del self.cache[evicted_node.key]
            
            # Insert the new node
            new_node = Node(key, value)
            self.cache[key] = new_node
            self.min_freq = 1  # Reset min frequency to 1 for a new element
            
            if 1 not in self.frequencies:
                self.frequencies[1] = DoublyLinkedList()
            self.frequencies[1].append(new_node)
