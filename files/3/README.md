# Q1
Q1 //std::cout  
Non-parameterized constructor //Default Constructor is called, hence the output  
o1.v_.size(): 0 //v_ is empty  
Destructor //Destructor is called as we leave scope  
--------------------------------------------------------------- //std::cout  
# Q2  
Q2  //std::cout  
Non-parameterized constructor   //Default Constructor is called, hence the output  
Parameterized constructor //Parameter Constructor is called due to MyClass o2(1, 3);  
Copy constructor //Copy Constructor is called due to MyClass o3 = o1;  
//Three Destructor calls for o1, o2, o3 as we leave scope  
Destructor   
Destructor  
Destructor  
---------------------------------------------------------------  //std::cout  
# Q3
Q3  //std::cout  
Non-parameterized constructor //Default Constructor for o  
//DoSomething1 is called. 
Copy constructor //Due to 'MyClass o = o' in function header  
Something 1.  
Destructor //Object o created in DoSomething1 is destroyed as we leave scope of the function.  
Destructor  //Object o in main() is destroyed as we leave scope.  
---------------------------------------------------------------  //std::cout  
# Q4 
Q4  //std::cout  
Non-parameterized constructor   //Default Constructor for o  
Something 2. //std::cout within DoSomething2   
Destructor //Object o in main() is destroyed as we leave scope.  
---------------------------------------------------------------  //std::cout  
# Q5
Q5  //std::cout  
Non-parameterized constructor   //Default Constructor for o  
Something 3. //std::cout within DoSomething3  
Destructor //Object o in main() is destroyed as we leave scope.  
---------------------------------------------------------------  //std::cout  
# Q6
Q6  //std::cout  
Non-parameterized constructor   //Default Constructor for o  
Copy constructor    //Due to 'MyClass o2 = o' within DoSomething4  
Something 4.  
Destructor //MyClass o2 within DoSomething4 is destroyed as we leave scope as we leave function.  
Destructor  //MyClass o within main() is destroyed as we leave scope.  
---------------------------------------------------------------  //std::cout  
# Q7
Q7  //std::cout  
Parameterized constructor //Due to MyClass(1, 2) in std::pair<MyClass, int> p1 = {MyClass(1, 2), 0};  
Copy constructor //MyClass(1, 2) is copied within std::pair p1  
Destructor  //MyClass(1, 2) within {MyClass(1, 2), 0} is destroyed  
p1.first.v_.size(): 0 //std::cout  
p1.second: 0 //std::cout  
Copy constructor //A copy of MyClass(1, 2) is created within std::pair p2  
p2.first.v_.size(): 0 //std::cout  
p2.second: 0  
//MyClass(1, 2) within p1 and p2 is destroyed {MyClass(1, 2), 0}  
Destructor   
Destructor  
---------------------------------------------------------------  //std::cout  
# Q8  
Q8  //std::cout    
Parameterized constructor //MyClass(1, 2) created within for()  
Copy constructor // MyClass(1, 2) is copied within std::pair  
Destructor //MyClass(1, 2) within p = {MyClass(1, 2), 0} is destroyed  
Something 2.  
Something 2.  
Something 2.  
Destructor //MyClass(1, 2) created within for() is destroyed as we leave the scope  
---------------------------------------------------------------  //std::cout  
# Q9  
Q9  //std::cout  
Parameterized constructor // Called due to new MyClass(1, 2);  
//Destructor not called as Object created on Heap. Can cause Memory Leak. 'delete o;' must have been called.  
---------------------------------------------------------------  //std::cout  
# Q10  
Q10  //std::cout  
Parameterized constructor // Called due to new MyClass(1, 2);  
Destructor //MyClass(1, 2) created on Heap is destroyed by 'delete 0;'  
---------------------------------------------------------------  //std::cout  
# Q11  
Q11  //std::cout  
Non-parameterized constructor //Default Constructor is called for MyClass() in {0, MyClass()}  
Copy constructor //MyClass() is copied within std::pair  
Parameterized constructor //Constructor is called for MyClass(1, 2) in {3, MyClass(1, 2)}  
Copy constructor //MyClass(1, 2) is copied within std::pair  
Parameterized constructor //Constructor is called for MyClass(3, 4) in {5, MyClass(3, 4)}  
Copy constructor //MyClass(3, 4) is copied within std::pair  
Copy constructor //MyClass() is copied within std::map  
Copy constructor //MyClass(1, 2) is copied within std::map  
Copy constructor //MyClass(3, 4) is copied within std::map  
Destructor // Called for MyClass() as we leave the scope {0, MyClass()}  
Destructor // Called for MyClass(1, 2) as we leave the scope {3, MyClass(1, 2)}  
Destructor // Called for MyClass(3, 4) as we leave the scope {5, MyClass(3, 4)}  
Destructor // Called for MyClass() within std::pair  
Destructor  // Called for MyClass(1, 2) within std::pair  
Destructor  // Called for MyClass(3, 4) within std::pair  
Copy constructor // Called for auto e = MyClass()  
Destructor  // Called for auto e = MyClass()  
Copy constructor    // Called for auto e = MyClass(1, 2)  
Destructor  // Called for auto e = MyClass(1, 2)  
Copy constructor    // Called for auto e = MyClass(3, 4)  
Destructor  // Called for auto e = MyClass(3, 4)  
Destructor  // Called for MyClass() within std::map  
Destructor  // Called for MyClass(1, 2) within std::map  
Destructor  // Called for MyClass(3, 4) within std::map  
---------------------------------------------------------------  //std::cout  
# Q12  
Q12  //std::cout  
Non-parameterized constructor   //Default Constructor is called for MyClass() in {0, MyClass()}  
Copy constructor    //MyClass() is copied within std::pair  
Parameterized constructor   //Constructor is called for MyClass(1, 2) in {3, MyClass(1, 2)}  
Copy constructor    //MyClass(1, 2) is copied within std::pair  
Parameterized constructor   //Constructor is called for MyClass(3, 4) in {5, MyClass(3, 4)}  
Copy constructor //MyClass(3, 4) is copied within std::pair  
Copy constructor //MyClass() is copied within std::map  
Copy constructor //MyClass(1, 2) is copied within std::map  
Copy constructor //MyClass(3, 4) is copied within std::map  
Destructor // Called for MyClass() as we leave the scope {0, MyClass()}  
Destructor // Called for MyClass(1, 2) as we leave the scope {3, MyClass(1, 2)}  
Destructor // Called for MyClass(3, 4) as we leave the scope {5, MyClass(3, 4)}  
Destructor // Called for MyClass() within std::pair  
Destructor  // Called for MyClass(1, 2) within std::pair  
Destructor  // Called for MyClass(3, 4) within std::pair  
Destructor  // Called for MyClass() within std::map  
Destructor  // Called for MyClass(1, 2) within std::map  
Destructor  // Called for MyClass(3, 4) within std::map  
---------------------------------------------------------------  //std::cout  
# Q13  
Q13  //std::cout  
Parameterized constructor   // Called due to new MyClass(1, 2);  
Destructor  //MyClass(1, 2) created on Heap is destroyed by 'delete 0;'  
---------------------------------------------------------------  //std::cout  
# Q14  
Q14  //std::cout  
Parameterized constructor // Called for o  
Operation took: 2037 milliseconds //MyClass(int i) is O(n) operation. Approx each step takes (2037/  100000000) seconds  
Copy constructor //Copy Constructor called within For Loop for i = 0  
Copy constructor    //Copy Constructor called within DoSomething1  
Something 1.  
Destructor  //Destructor called within DoSomething1  
o2.v_.size(): 100000000  
Destructor  //Destructor called after loop i=0  
Copy constructor    //Copy Constructor called within For Loop for i = 1  
Copy constructor    //Copy Constructor called within DoSomething1  
Something 1.  
Destructor  //Destructor called within DoSomething1  
o2.v_.size(): 100000000  
Destructor  //Destructor called after loop i=1  
Operation took: 732 milliseconds  
Destructor  //Destructor called for o  
---------------------------------------------------------------  //std::cout  
# Q15
Q15  //std::cout  
Parameterized constructor   // Called for o  
Operation took: 2005 milliseconds   //Similar times as Q14  
Copy constructor    //Copy Constructor called within For Loop for i = 0  
Something 2.  
o2.v_.size(): 100000000  
Destructor  //Destructor called after loop i=0  
Copy constructor    //Copy Constructor called within For Loop for i = 1  
Something 2.  
o2.v_.size(): 100000000  
Destructor  //Destructor called after loop i=1  
Operation took: 365 milliseconds    //[Compared to Q14, this operation took less time as DoSomething2 takes a reference as an input instead of a copy of a variable.]  
Destructor  //Destructor called for o  
---------------------------------------------------------------  //std::cout  
# Q16  
Q16  
Parameterized constructor    // Called for MyClass(10000000)  
Parameterized constructor   // Called for MyClass(20000000)  
Parameterized constructor   // Called for MyClass(30000000)  
Parameterized constructor   // Called for MyClass(40000000)  
Parameterized constructor   // Called for MyClass(50000000)  
Parameterized constructor   // Called for MyClass(60000000)  
Parameterized constructor   // Called for MyClass(70000000)  
Copy constructor    //Copy of MyClass(10000000) created within std::vector  
Copy constructor    //Copy of MyClass(20000000) created within std::vector  
Copy constructor    //Copy of MyClass(30000000) created within std::vector  
Copy constructor    //Copy of MyClass(40000000) created within std::vector  
Copy constructor    //Copy of MyClass(50000000) created within std::vector  
Copy constructor    //Copy of MyClass(60000000) created within std::vector  
Copy constructor    //Copy of MyClass(70000000) created within std::vector  
Destructor  //Called for MyClass(10000000) when {} of std::vector is left  
Destructor  //Called for MyClass(20000000) when {} of std::vector is left  
Destructor  //Called for MyClass(30000000) when {} of std::vector is left  
Destructor  //Called for MyClass(40000000) when {} of std::vector is left  
Destructor  //Called for MyClass(50000000) when {} of std::vector is left  
Destructor  //Called for MyClass(60000000) when {} of std::vector is left  
Destructor  //Called for MyClass(70000000) when {} of std::vector is left  
Operation took: 6246 milliseconds [//Operation took a lot of time due to large sizes of MyClass   objects and O(n) time for Parameterized Construction.]  
Copy constructor    //Called for auto e = MyClass(10000000)  
e.v_.size(): 10000000  
Destructor  //Called for auto e = MyClass(10000000)  
Copy constructor    //Called for auto e = MyClass(20000000)  
e.v_.size(): 20000000  
Destructor  //Called for auto e = MyClass(20000000)  
Copy constructor    //Called for auto e = MyClass(30000000)  
e.v_.size(): 30000000  
Destructor  //Called for auto e = MyClass(30000000)  
Copy constructor    //Called for auto e = MyClass(40000000)  
e.v_.size(): 40000000  
Destructor  //Called for auto e = MyClass(40000000)  
Copy constructor    //Called for auto e = MyClass(50000000)  
e.v_.size(): 50000000  
Destructor  //Called for auto e = MyClass(50000000)  
Copy constructor    //Called for auto e = MyClass(60000000)  
e.v_.size(): 60000000  
Destructor  //Called for auto e = MyClass(60000000)  
Copy constructor    //Called for auto e = MyClass(70000000)  
e.v_.size(): 70000000  
Destructor  //Called for auto e = MyClass(70000000)  
Operation took: 530 milliseconds  
e.v_.size(): 10000000  
e.v_.size(): 20000000  
e.v_.size(): 30000000  
e.v_.size(): 40000000  
e.v_.size(): 50000000  
e.v_.size(): 60000000  
e.v_.size(): 70000000  
Operation took: 0 milliseconds //[Operation took 0 sec instead of 530 because in for loop, the loop variable was a reference to each element in the vector. No copy constructor called.]  
Destructor  // Called for MyClass(10000000)  
Destructor  // Called for MyClass(20000000)  
Destructor  // Called for MyClass(30000000)  
Destructor  // Called for MyClass(40000000)  
Destructor  // Called for MyClass(50000000)  
Destructor  // Called for MyClass(60000000)  
Destructor  // Called for MyClass(70000000)  
---------------------------------------------------------------  //std::cout  
Done!  //std::cout  
