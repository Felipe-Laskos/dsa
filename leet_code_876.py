def middleNode(head):
    fast = head
    slow = head

    while(fast != None):
        if(fast["next"] != None):
            fast = fast["next"]["next"]
            slow = slow["next"]
        else:
            fast = fast["next"]

    return slow

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, value):
        if(self.head == None):
            self.head = {
                    "v": value,
                    "next": None
                    }

        else:
            aux = self.head

            while(aux["next"] != None):
                aux = aux["next"]

            aux["next"] = {
                    "v": value,
                    "next": None
                    }

    
l = LinkedList()

l.insert(1)

l.insert(2)

l.insert(3)

l.insert(4)

l.insert(5)

l.insert(6)

print(middleNode(l.head))
