#include <iostream>
#include <cstring>
using namespace std;


// ? this pointer
// ! The this pointer is a special pointer that points to the object for which a member function is called.
// class Hero {
//     int health;

// public:
//     void setHealth(int h) {
//         this->health = h;
//     }

//     void printAddress() {
//         cout << "Address of this object: " << this << endl;
//     }
// };

// int main() {
//     Hero h1, h2;
//     h1.setHealth(100);
//     h2.setHealth(200);

//     h1.printAddress();  // this → points to h1
//     h2.printAddress();  // this → points to h2
// }



// ? OOPS concepts
// #include <iostream>
// #include <cstring>
// using namespace std;

// class Hero {
//     // ! Access Specifiers
//     // ! Private members can only be accessed by member functions of the class.
//     // ! Public members can be accessed from outside the class.
//     // ! Protected members can be accessed by derived classes.
// private:
//     int health;
//     char level;
//     char* name;

//     static int heroCount; // ! Static data member

// public:
//     // ! Default Constructor
//     Hero() {
//         name = new char[100];
//         cout << "Default Constructor called" << endl;
//         heroCount++;
//     }

//     // ! Parameterized Constructor
//     Hero(int h, char l, const char* n = "DefaultName") {
//         health = h;
//         level = l;
//         name = new char[strlen(n) + 1];
//         strcpy(name, n);
//         cout << "Parameterized Constructor called" << endl;
//         heroCount++;
//     }

//     // ! Copy Constructor (Deep Copy)
//     Hero(const Hero& other) {
//         health = other.health;
//         level = other.level;
//         name = new char[strlen(other.name) + 1];
//         strcpy(name, other.name);
//         cout << "Copy Constructor called (Deep Copy)" << endl;
//         heroCount++;
//     }

//     // ! Destructor
//     ~Hero() {
//         cout << "Destructor called for " << (name ? name : "Unnamed Hero") << endl;
//         delete[] name;
//         heroCount--;
//     }

//     // ! Static function to access static variable
//     static int getHeroCount() {
//         return heroCount;
//     }

//     // ! Setters and Getters
//     void setHealth(int h) { health = h; }
//     void setLevel(char l) { level = l; }
//     void setName(const char* n) { strcpy(name, n); }
    
    
//     char getLevel() const { return level; }
//     int getHealth() const { return health; }
//     const char* getName() const { return name; }

//     // ! Print function
//     // ! const is used to indicate that this function does not modify any member variables of the class.
//     void print() const {
//         cout << "Name: " << name << ", Health: " << health << ", Level: " << level << endl;
//     }
// };

// // ! Definition of static member
// int Hero::heroCount = 0;

// int main() {
//     cout << "Starting program..." << endl << endl;

//     // ! Object using default constructor
//     Hero hero1;
//     hero1.setHealth(100);
//     hero1.setLevel('A');
//     hero1.setName("Archer");
//     hero1.print();
//     cout << endl;

//     // ! Object using parameterized constructor
//     Hero hero2(80, 'B', "Blazer");
//     hero2.print();
//     cout << endl;

//     // ! Copy constructor
//     Hero hero3 = hero2;
//     hero3.setName("Crusader");
//     hero3.print();
//     hero2.print();
//     cout << endl;

//     // ! Static variable usage
//     cout << "Total number of Hero objects: " << Hero::getHeroCount() << endl << endl;

//     // ! Dynamically allocated object
//     Hero* h2 = new Hero(90, 'D', "Dynamo");
//     cout << "Health of h2: " << (*h2).getHealth() << endl;
//     cout << "Level of h2: " << h2->getLevel() << endl; // ! Using arrow operator
//     h2->print();
//     cout << endl;

//     // ! Deleting dynamic object (manual destructor call)
//     delete h2;
//     cout << endl;

//     // ! Final static check
//     cout << "Total number of Hero objects after deletion: " << Hero::getHeroCount() << endl;

//     cout << endl << "Program ending..." << endl;
//     return 0;
// }

// ? Using Dot (.) — when you have the object:
// [ h1 ]
//  └─> health = 100
//  └─> level = 'A'
//  └─> name = "Archer"
//  └─> heroCount = 1
//  └─> getHeroCount() = 1
//  └─> setHealth(100) and more ...

// ? Using Arrow (->) — when you have a pointer to object
// [ hPtr ] --(points to)--> [ Hero object ]
//                             └─> health = 200
//                             └─> level = 'B'
//                             └─> name = "Blazer"
//                             └─> heroCount = 1
//                             └─> getHeroCount() = 1
//                             └─> setHealth(200) and more ...


// ? encapsulation
// ! read only class
// class student {
//     private:
//         int roll_no;
//         char name[100];
//         char address[100];
    
//     public:
//         int getroll_no() {
//             return roll_no;
//         }
// };

// int main() {
//     student s1;
//     cout << "Hello World" << endl;
//     return 0;
// }


// ? inheritance
// class human {
//     public:
//         int height;
//         int weight;

//     public:
//         void setHeight(int h) {
//             height = h;
//         }
//         int getHeight() {
//             return height;
//         }
// };
// class male : public human {
//     public:
//         int age;
//         void setAge(int a) {
//             age = a;
//         }
//         int getAge() {
//             return age;
//         }
// };

// int main(){

//     male m1;
//     m1.setHeight(180);
//     m1.setAge(25);
//     cout << "Height: " << m1.getHeight() << endl; // ! height is inherited from human class
//     cout << "Age: " << m1.getAge() << endl; 
//     m1.weight = 70; 
//     cout << "Weight: " << m1.weight << endl; // ! weight is inherited from human class
//     return 0;    
// }


// ? polymorphism

// ? (1) compile time polymorphism

// ? (a) function overloading
// class A {

//     public:
//     // ! this function is not overloaded because just the return type is different
//     // int sayHello(char name , string n ) {
//     //     cout << "first function (overloading with different no. of parameters)" << endl;
//     // }

//     void sayHello(char name , string n ) {
//         cout << "first function (overloading with different no. of parameters)" << endl;
//     }
    
//     int sayHello(char name) {
//         cout << "second function" << endl;
//         return 1;
//     }

//     void sayHello(string name) {
//         cout << "third function" << name  << endl;
//     }
//     void sayHello(string name , int n = 0 , char c = 'a') {
//         cout << "fourth function " << name  << endl;
//     }
// };

// int main() {
//     A a;
//     a.sayHello('a', "Love Babbar");
//     a.sayHello('a'); 
//     // a.sayHello("Love Babbar"); // ! this seems to call the third function but it can actually calls 
//                                     // ! the fourth function because the other parameters are default
//                                       // ! so it will give error
//     a.sayHello("Love Babbar", 1, 'a');
//     return 0;
// }


// ? (b) operator overloading
// class Complex {
// private:
//     int real, imag;

// public:
//     Complex(int r = 0, int i = 0) {
//         real = r;
//         imag = i;
//     }

//     // This is automatically called when '+' is used with
//     // between two Complex objects
//     Complex operator + (Complex const & b) {
//         Complex a;
//         a.real = real + b.real;
//         a.imag = imag + b.imag;
//         return a;
//     }

//     void print() {
//         cout << real << " + i" << imag << endl;
//     }
// };

// int main() {
//     Complex c1(10, 5), c2(2, 4);
//     Complex c3 = c1 + c2; 
//     // An example call to "operator+"
//     c3.print();
// }


// ? (2) Run time polymorphism
// class Parent {    
// public:        
//     void show() {            
//         cout << "Inside parent class" << endl;        
//     }
// };

// class subclass1 : public Parent {    
// public: 
//     void show() {        
//         cout << "Inside subclass1" << endl;    
//     }
// };

// class subclass2 : public Parent {    
// public: 
//     void show() {        
//         cout << "Inside subclass2" << endl;    
//     }
// };
// class subclass3 : public Parent {    
// public: 
//     // ! not overriding so it will call parent class show function
// };

// int main() {    
//     subclass1 o1;    
//     subclass2 o2;    
//     subclass3 o3;    
//     o1.show();    
//     o2.show();
//     o3.show();
// }


// ? abstract class

// ? (1) classes using public anf private
// class Car {
// private:
//     int speed; // internal detail which is not needed to be exposed

// public:
//     void start() {
//         cout << "Car started\n";
//     }
// };

// ? abstract class (with pure virtual function)
class Animal {
public:
    virtual void sound() = 0; // Pure virtual function (abstraction)
};

class Cat : public Animal {
    // ! this function is not overriding the base class function so it will also remain an abstract class
};

class Dog : public Animal {
public:
    void sound() override { // ! here typing override is optional but its good practice 
        cout << "Dog barks\n";
    }
};

int main (){
    Dog d;
    d.sound(); // Calls the overridden function in Dog class
    // Car c; // ! this will give error because it is an abstract class
    // c.start();
    // Cat c1; // ! this will give error because it is an abstract class
    return 0;
}