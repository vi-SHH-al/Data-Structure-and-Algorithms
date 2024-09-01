/*
deque::insert()	            Inserts an element. And returns an iterator that points to the first of the newly inserted elements.
deque::rbegin()	            Returns a reverse iterator which points to the last element of the deque (i.e., its reverse beginning).
deque::rend()	            Returns a reverse iterator which points to the position before the beginning of the deque (which is considered its reverse end).
deque::cbegin()	            Returns a constant iterator pointing to the first element of the container, that is, the iterator cannot be used to modify, only traverse the deque.
deque::max_size()	        Returns the maximum number of elements that a deque container can hold.
deque::assign()	            Assign values to the same or different deque container.
deque::resize() 	        Function which changes the size of the deque.
deque::push_front()	        It is used to push elements into a deque from the front.
deque::push_back() 	        This function is used to push elements into a deque from the back.
deque::pop_front()          pop_front() function is used to pop or remove elements from a deque from the front. 
deque::pop_back()           pop_back() function is used to pop or remove elements from a deque from the back.
deque::front()  	        front() function is used to reference the first element of the deque container. 
deque::back()               back() function is used to reference the last element of the deque container.
deque::clear()   	        clear() function is used to remove all the elements of the deque container, thus making its size 0. 
deque::erase()              erase() function is used to remove elements from a container from the specified position or range.
deque::empty()  	        empty() function is used to check if the deque container is empty or not. 
deque::size()               size() function is used to return the size of the deque container or the number of elements in the deque container.
deque::operator=            operator is used to assign new contents to the container by replacing the existing contents.
deque::operator[]           operator[] operator is used to reference the element present at position given inside the operator.
deque::at()  	            at() function is used reference the element present at the position given as the parameter to the function.
deque::swap()               swap() function is used to swap the contents of one deque with another deque of same type and size.
deque::begin() 	            begin() function is used to return an iterator pointing to the first element of the deque container. 
deque::end                  end() function is used to return an iterator pointing to the last element of the deque container.
deque::emplace_front()  	emplace_front() function is used to insert a new element into the deque container. The new element is added to the beginning of the deque. 
deque::emplace_back()       emplace_back() function is used to insert a new element into the deque container. The new element is added to the end of the deque.
*/

#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> d;
    d.push_front(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_front(0);
    
    return 0;
}