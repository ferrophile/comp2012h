/**********************************************************************
 *  Randomized Queues and Deques
 **********************************************************************/

Name: Hong Wing PANG
ID: 20315504
Login: hwpang
Hours to complete assignment (optional): Didnt count


/**********************************************************************
 *  Explain briefly how you implemented the randomized queue and deque.
 *  Which data structure did you choose (array, linked list, etc.)
 *  and why?
 **********************************************************************/
For deque, I chose linked list, as it is easier to add elements from
both the head or the end of the deque, and to remove them as well.
For randomized queue I used array. Its dequeue function require me to
remove randomly so using an array enables me to return a value at once.

/**********************************************************************
 *  Briefly describe why any sequence of N randomized queue operations,
 *  starting from an empty randomized queue, takes O(N) time.
 **********************************************************************/
The program need to enqueue all the N elements into the queue before
any operations can be done, so the execution time is proportional to
the number of elements in the queue.

/**********************************************************************
 *  Briefly describe why each Deque operation takes O(1) time.
 **********************************************************************/
Deque operations include adding and removing elements from either end
of the deque. The general procedure of changing next and previous
pointers of the node has nothing to do with the size of the deque, so
the time required for each operation is more or less constant.

/**********************************************************************
 *  How much memory (in bytes) does your data type use to store N items.
 *  Use tilde notation to simplify your answer. Use the memory requirements
 *  for a "typical machine" given in Lecture. In your analysis, don't include
 *  the memory for the items themselves (as this memory is allocated by
 *  the client and depends on the item type.
 *  For a typical machine, refer to page 11 of 
 *  https://www.cs.princeton.edu/courses/archive/spr10/cos226/lectures/02-14Analysis-2x2.pdf
 **********************************************************************/

RandomizedQueue:
object overhead - 8 bytes
int maxTop - 4 bytes
int Top - 4 bytes
T* values - 4 bytes assuming ptr same as int

Total - 20 bytes

Dequeue:
object overhead - 8 bytes
Node<T> *head - 4 bytes
Node<T> *tail - 4 bytes
int dequeSize - 4 bytes
2 pointers per node - 8*N bytes

Total - 8N+20 ~ 8N bytes


/**********************************************************************
 *  Known bugs / limitations.
 **********************************************************************/
I only implemented the operators required in the test programs supplied.
Hence, using the iterator on other operators will likely get undesirable
results.

/**********************************************************************
 *  List whatever help (if any) that you received and from whom,
 *  including help from staff members or lab TAs.
 **********************************************************************/
I discussed some ideas on how to implement certain functions with
friends, if that counts.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had some struggles with several bugs about segmentation fault due
to careless use of pointers. Nothing serious other than that.

/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
I wish I have more time to do a more complete and comprehensive
implementation of the ADTs and its iterators. =(
