# Node<T>
### Description
node type used by this library, you can declare it as well, it has 3 members:<br>
pointer to next node, `next`<br>
pointer to previous node, `previous`<br>
the data, `data`<br>
### Declaration
```
#include <iostream>
#include "linkedlist.hpp"
...
linked::node<T> n;
linked::node<T> *nptr;
```
# LinkedList<T>
### Description
Doubly linked list library
### Declaration:
```
#include "linkedlist.hpp"
...
linked::linkedlist<type> name;
```
## Functions
## node<T> *operator[](unsigned long pos)
Returns: pointer to element in the position<br>
Time complexity: O(n/2 + 1) Where `n` is the size of the list<br>
Exceptions: std::invalid_argument if `pos` is larger than the list<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"

int main(){
  linked::linkedlist<int> ll;               //declaration
  for(int n = 0; n != 10; n++)
    ll.push_back(n);                        //inserting elements
  std::cout << ll[0] -> data << std::endl;  //prints 9
  std::cout << ll[9] -> data << std::endl;  //prints 0
  return 0;
}
```
## node<T> *push_back(T data)
Appends `data` to the beginning of the list<br>
Returns: pointer to inserted element<br>
Time complexity: O(1)<br>
Exceptions: none<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"

int main(){
  linked::linkedlist<int> ll;               //declaration
  for(int n = 0; n != 10; n++)
    ll.push_back(n);                        //inserting elements
  std::cout << ll[0] -> data << std::endl;  //prints 9
  std::cout << ll[9] -> data << std::endl;  //prints 0
  return 0;
}
```
## node<T> *push_front(T data)
Appends `data` to the end of the list<br>
Returns: pointer to inserted element<br>
Time complexity: O(1)<br>
Exceptions: none<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"

int main(){
  linked::linkedlist<int> ll;               //declaration
  for(int n = 0; n != 10; n++)
    ll.push_front(n);                        //inserting elements
  std::cout << ll[0] -> data << std::endl;  //prints 0
  std::cout << ll[9] -> data << std::endl;  //prints 9
  return 0;
}
```
## node<T> *back()
Returns: pointer to the beginning of the list<br>
Time complexity: O(1)<br>
Exceptions: none<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"
  
int main(){
  linked::linkedlist<int> ll;                   //declaration
  for(int n = 0; n != 10; n++)
    ll.push_front(n);                           //inserting elements
  std::cout << ll.back() -> data << std::endl;  //prints 0
}
```
## node<T> *front();
Returns: pointer to the end of the list<br>
Time complexity: O(1)<br>
Exceptions: none<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"
  
int main(){
  linked::linkedlist<int> ll;                    //declaration
  for(int n = 0; n != 10; n++)
    ll.push_front(n);                            //inserting elements
  std::cout << ll.front() -> data << std::endl;  //prints 9
}
```
## node<T> *search(T data);
Returns: pointer to first coincidence of `data`<br>
Time complexity: O(n) where `n` is the size of the list<br>
Exceptions: node<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"
  
int main(){
  linked::linkedlist<int> ll;                      //declaration
  for(int n = 0; n != 10; n++)
    ll.push_front(n);                              //inserting elements
  std::cout << ll.search(4) -> data << std::endl;  //prints 4
}
```
## node<T> *insert(T data, node<T> *index);
Inserts an element after `index`<br>
Returns: pointer to inserted element<br>
Time complexity: O(1)<br>
Exceptions: none<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"

int main(){
  linked::linkedlist<int> ll;
  ll.push_back(1)
  linked::node<int> *n = ll.push_back(2);
  ll.push_back(4);
  ll.insert(3, n);
  std::cout << ll[2] -> data << std::endl; //prints 3
}
```
## node<T> *insert(T data, unsigned long index);
Inserts an element after index<br>
Returns: pointer to inserted element<br>
Time complexity: O(1)<br>
Exceptions: none<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"

int main(){
  linked::linkedlist<int> ll;
  ll.push_back(1)
  ll.push_back(2);
  ll.push_back(4);
  ll.insert(3, 1);
  std::cout << ll[2] -> data << std::endl; //prints 3
}
```
## void pop_back();
Deletes element in the back of the list<br>
Returns: nothing
Time complexity: O(1)<br>
Exceptions: none<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"
  
int main(){
  linked::linkedlist<int> ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.pop_back(); // deletes 3
}
```
## void pop_front();
Deletes element in the front of the list<br>
Returns: nothing
Time complexity: O(1)<br>
Exceptions: none<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"
  
int main(){
  linked::linkedlist<int> ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.pop_front(); // deletes 1
}
```
## void remove(node<T> *target);
Deletes `target` from the list<br>
Returns: nothing<br>
Time complexity: O(1)<br>
Exceptions: none<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"
  
int main(){
  linked::linkedlist<int> ll;
  ll.push_back(1);
  ll.push_back(2);
  linked::node<int> *n = ll.push_back(3);
  ll.push_back(3);
  ll.push_back(4);
  ll.remove(n); // list ends like this: 4, 3, 2, 1
}
```
## void remove(T target);
Deletes all instances of `target` from the list<br>
Returns: nothing<br>
Time complexity: O(1)<br>
Exceptions: none<br>
Usage:
```
#include <iostream>
#include "linkedlist.hpp"
  
int main(){
  linked::linkedlist<int> ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(3);
  ll.push_back(4);
  ll.remove(3); // list ends like this: 4, 2, 1
}
```
## unsigned long size();
Returns size of list
## bool empty();
Returns whether or not list is empty
