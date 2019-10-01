#set is like a list but it removes repeated values

#1) Initializing: To create a set, we use the set function: set()
x = set([1,2,3,4,5])
z = {1,2,3}
#To create an empty set we use the following:
y = set()

#2) Adding a value to a set
x.add(3)
#The add function just works when we are inserting just 1 element into our set

#3) Adding more than one element to a set
x.update([34,45,56])
#To do this, we use the update function.
#We can also pass another set to the update function
y = {1,2,3}
a = {4,5,6}
y.update(a, [34,45,56])

#4) Removing a specific value from a set
#We can use two different functions to do this same action: remove() and discard()
a.remove(1) or a.discard(1)
#The problem with remove() is that if we are trying to remove a value that doesn`t exist in the set, we are going to get a key error.
#On the other hand, if we try to discard a value that doesn`t exist, then we don`t get any type of error. In other words, it works just fine.
So, ALWAYS use the discard() method.


s1 = {1,2,3}
s2 = {2,3,4}
s3 = {3,4,5}

#5) Intersection Method
s4 = s1.intersection(s2) # s4 = {2,3}
s4 = s1.intersection(s2, s3) # s4 = {3}

#6) Difference Method
s4 = s1.difference(s2) # s4 = {1}
s4 = s2.difference(s1) # s4 = {4}

#OBSERVATION: We can pass multiple sets as arguments to these different methods.

#7) Sym Difference
s4 = s1.symmetric_difference(s2)



