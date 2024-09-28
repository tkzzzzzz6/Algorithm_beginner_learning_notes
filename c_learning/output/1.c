char a[5] = {'a','a','a','a','a'};
//random access
char x = a[1];
//change the member of array a
a[1] = 'b'; 
//danamic allocation of array
a = NULL;
char *a = NULL;
int n;
cin >> n;
a = new char[n];
//store something in the array
a[0] = 'a';
a[1] = 'b';
a[2] = 'c';
//when done,free the memory
//otherwise memory leak can happen
delete[] a;
// after delete array,you'd better assign NULL to it
a = NULL;
//if you use a afterwards,you can easily find the bug
 
//vector is almost the same as array
//the main difference is vector can automatically grow its size 
//new elements can be appended using push_back() in O(1) time on average

// the last element can be removed using pop_back() in O(1) time

vector <char> v = {
    'h',
    'e',
    'l',
    'l',
    'o',
};

//vector with dynamic size and contiguous memory
//random access
char x = v[1]; // x is 'e'

// assignment
v[0] = 'b';

//insert a new element to the end
v.push_back('s');

//delete the element in the end
v.pop_back(); // after execute this command the last element will be deleted and the pointer will point to the prior element

//delete an element in the middle
v.erase(v.begin() + 1); // the input of function is the location of the element we want to delete

// we'd better not do it because the time complexity is slow 

// vector capacity can grow 
// the size and capacity is different in the vector,let's take an example for it

vector<char> v(100);
cout << v.size();//print 100
cout << v.capacity();//print 100

v.push_back('x');
cout << v.size();//print 101
cout << v.capacity();//print 200

//the size of array of vector is capacity
// the number of element in array of vector is size 

//what happens when size is going to exceed capacity
//1.create a new array of capacity 200
//2.copy the 100 elements from the old array to the new
//3.put the new element in the 101st postion
//4.free the old array from the memory
// this process is a little slow, we should get rid of it  

//list
// the list of cpp have two pointer

//create a linked list

list < char > 1 = {'h', 'e', 'l', 'l', 'o'};
// the first and last element's pointer is NULL
//dynamic size and not contigious memory


//get the first element and last element
cout << list.front(); // print 'h'
cout << list.back(); // print 'o'

//to traverse the linked list we can use iterator

list<char>::iterator iter = list.begin();
cout << *iter;//print 'h'

iter++;

cout << *iter;//print 'e'

//assign element
*iter = 'a' // change 'e' to 'a'

// insert a new element at the end of  linked list
list.push_back('s');

//we can also insert new element in the front of the linked list

list.push_front('s');

//delete node
list.pop_back();
list.pop_front();