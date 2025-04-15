 // oops in c++
 
//  object oriented programming 
//  objects are real world entities
//  class is blueprint of entities

// topics :-
// Encapsulation
// abstraction
// inheritance
// polymorphysim


// Access modifiers or specifiers :-

// 1.private  : data and method only accessible inside class;

//2.protected : data & methods accessible inside the class & to its derived classes

//3.public : data and methods are accessible to everyone


// Encapsulation :- it is wrapping up of data and member functionsin a single unit called class

// ex: car => (property of car like company , coloe  etc + functions of car )

// it helps us in hiding sensitive data by making the sensitive information private

// ex: A Bank account

// class account
// {
//     private:
    
//     double balance;
//     string password;
    
//     public:
//     string accountId;
//     string username;
//     double balance;
    
    
// };


// Constructors :- 
// It is the function that is envocked automatically when any object in c++ 
// is created, it intializes the object , when constructor is not created the compiler itself creates it
// it has same name as class name 
// it doesn't have any return type

// constructor is only called once for an object
// memory allocation occurs when object is created


// there are three types of constructors
// 1.non-parameterized constructor
// 2.parameterized constructor
// 3.copy constructor
// one class may have more than one parameteres , given they have different parameteres
// known as constructor overloading 


// this pointer :- it is a special type of pointer in c++ that points to current object
// ex: obj.func() = prop; or it can be written  like this -> prop or *(this).prop;

// copy constructor copy the properties of one object to another

// ex:
// obj(x);
//  here x is the object created before

// shallow Copy : A shallow copy of an object copies all of the member values from one object to another like pass by value does ex: copy constructors
//  Deep Copy : A deep copy,on the other hand, not only copies the member values but also makes copies of any dynamically allocated member that the member point topics
// 


// destructor is opposite of cinstructor same name as class name , automatically created  , it deallocates memory that is static ; 


// inheritance : the process of passing poperties & methods of base class to derived class .

// ex: sigle level inheritence

// #include<bits/stdc++.h>
// using namespace std;
// class person
// {
//     public:
    
//     string name ;
//     int age;
    
//     person(string name , int age)
//     {
//         this -> name = name ;
//         this -> age = age ;
//     }
// };






// ex: multilevel inheritence

// class person
// {
//     public:
    
//     string name ;
//     int age;
    
//     // person(string name , int age)
//     // {
//     //     this -> name = name ;
//     //     this -> age = age ;
//     // }
// };


// class students : public person 
// {
//     public:
//     // name and age of students will be inherited from  person class
//     int rollNo;
    
// //  students(string name , int age , int rollNo):person(name , age) // creating constructors of derived class
// //  {
// //      this -> name = name;
// //      this -> age = age;
// //      this -> rollNo = rollNo;
     
// //  }
    
//     void getInfo()
//     {
//         cout << name << " \n";
//         cout << age << "\n";
//         cout << rollNo << "\n";
//     }
// };


// class gradStudent : public students
// {
//     public:
//     string researchArea;
    
// };


// class students : public person 
// {
//     public:
//     // name and age of students will be inherited from  person class
//     int rollNo;
    
//  students(string name , int age , int rollNo):person(name , age) // creating constructors of derived class
//  {
//      this -> name = name;
//      this -> age = age;
//      this -> rollNo = rollNo;
     
//  }
    
//     void getInfo()
//     {
//         cout << name << " \n";
//         cout << age << "\n";
//         cout << rollNo << "\n";
//     }
// };
// #include<bits/stdc++.h>
// using namespace std;


// class teacher
// {
//     private:
//       double salary;
//     public: 
//      // properties or attributes
     
//      string name;
//      string dept;
   
     
//      // methods or functions or members
     
//      void setsalary(double s) // setter function can be used to set them publiclly
//      {
//          salary = s;
//      }
     
//      int getsalary() // setter function can be used to set them publiclly
//      {
//          return s;
//      }
     
//      void changeDept(string newDept)
//      {
//          dept = newDept;
//      }
// };


// // class students
// // {
// //     string name;
// //     int rollNo;
// // };


// multiple inheritence : when a class inherit property from more than one class 


// class person
// {
//     public:
    
//     string name ;
//     int age;
    
    // person(string name , int age)
    // {
    //     this -> name = name ;
    //     this -> age = age ;
    // }
// };


// class students : public person 
// {
//     public:
    // name and age of students will be inherited from  person class
    // int rollNo;
    
//  students(string name , int age , int rollNo):person(name , age) // creating constructors of derived class
//  {
//      this -> name = name;
//      this -> age = age;
//      this -> rollNo = rollNo;
     
//  }
    
//     void getInfo()
//     {
//         cout << name << " \n";
//         cout << age << "\n";
//         cout << rollNo << "\n";
//     }
// };


// class TA: public students : public person
// {
//     public:
   
    
// };


// int main()
// {
//     TA t1;
//      t1.name = "hii" ;
//      t1.age = 20;
//     t1.rollNo = 40;
//     cout <<  t1.name << endl;;
//     cout << t1.age << endl;;
//   cout <<  t1.rollNo << endl;;
//     // t1.dept = "ece";
//     // t1.salary = 2500;
     
// //   t1.getInfo();
   
// }