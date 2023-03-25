#include <iostream>   // standard console input/output

// global variables
int tack;              // 'tack' is a variable of integer type

int * ptr = nullptr;   // 'ptr' a pointer "*" of integer type; it is a number, the address to the beginning of a location in memory

int & tick = tack;     // 'tack' a reference "&" of integer type; it is 'another name for' a variable - it's a alias

// at this point you have a choice
// either define the function/methods here before 'main' ( so the compiler see's them ) or
// declare the function/methods here and define them after 'main' in the actual physical code text
void Incremental(int);     // using a variable, modifying the value locally - not globally
int  Increment(int);       // using a variable, modifying the value and returning the value
// although C/C++ will allow you to have the same name for function/method with different parameters, it can only handle so much
// an int, an int pointer or an int reference - are all still int
// void Incremental(int) - allowed
// void Incremental(char) - allowed
void Incrementptr(int *);  // using a pointer, modifying the value pointed to
void Incrementref(int &);  // using a reference, modifying the value referred to

int main()
{
    tack = 5;
    ptr = & tack; // assign memory address of "&" tack to the pointer
// tack = 5
    Incremental(tack); // using a variable, modifying the value locally - not globally
// tack is still 5
    tack = Increment(tack);  // passing a variable, modifying the value and returning the value, then assigning it back ( dumb )
// tack = 6
    Incrementptr(ptr);   // passing a pointer, modifying the value pointed to ( ptr or &tack )
// tack = 7
    tack = Increment(tack);     // passing a variable, modifying the value and returning the value, then assigning it back ( dumb )
// tack = 8
    Incrementref(tick);    // passing a reference, modifying the value referred to
// tack = 9
    tack = Increment(tack);       // passing a variable, modifying the value and returning the value, then assigning it back ( dumb )
// tack = 10
    std::cout << "                   the value of tack " << tack << std::endl;   // identified by variable name
    std::cout << "                 the address of tack " << & tack << std::endl;
    std::cout << "           the value located at tack " << * ptr << std::endl;  // identified by a pointer to the variable name
    std::cout << "  the address of the pointer to tack " << ptr << std::endl;
    std::cout << "         the value referring to tack " << tick << std::endl;   // identified by a reference to the variable name
    std::cout << "the address of the reference to tack " << & tick << std::endl;

    return 0;

}
// this is what you would like to do - since 'tack' is global, you'd think that doing something to 'tack' would work
// but it wont...because of the way the compiler works, compared to Cobol for example
// in Cobol, everything is global, and, the compile looks at everything and takes notes along the way
// if at the end something is not defined, only then does it issue an error
// hence, 'paragraphs', the name for functions/methods in Cobol don't need parameters or return values because everything is global
// the C/C++ compiler is top down, and the manner of defining functions/methods - forces you to declare or define things in advance
// this results in the creation of a new variable of local scope
void Incremental(int tack)    // using a variable, modifying the value locally - not globally
{             // here 'tack' is actually a new integer with the same name - allowed since it is 'scoped' locally to the function/method
// you can code whatever you'd like in this block - but - it's effects are local to this function/method

    std::cout << tack << std::endl;    //tack is local

    tack++;

}
// because or the rules for defining a function/method - this is am option you have, return a value and assigning it back
int Increment(int tack)    // accepting an integer and returning an integer
{

// because this function/method returns a value - it just 'looks' like it's updating a global variable - but it is not

    std::cout << tack << std::endl;    // tack is local

    tack++;

    return tack;
}
// So...here is option two; use a pointer
void Incrementptr(int * ptr)  // accepting a pointer and modifying the value pointed to - the global pointer 'ptr' is assigned to the local pointer 'ptr'
{
//  here is a new pointer - local to the function/method - no choice here
    std::cout << "value pointed to " << * ptr << std::endl;   // de-reference pointer to 'tack' is the value of 'tack'

    int local = * ptr;     // silly assignment - but- this demonstrates you can do stuff to 'local' starting from the current value of 'tack'

    std::cout << "local value from ptr " << local << std::endl;   // de-reference pointer to tack

    // ptr++;  this would increase the value of the pointer!!! - boom
    (* ptr) ++;   // de-reference ( refer to the value pointed to) then increment the value

}
// So...this leaves you with option three; use a reference
void Incrementref(int & tick)  // accepting a reference and modifying the value referred to
{
//      here 'tick'  is not new and not local - because 'tick' is a global reference this tells the compiler what you want
//      you want to do stuff to 'tack'. period. but because of the compiler, you need to use a reference

    std::cout << tick << std::endl;       // the word 'tick' "means" 'tack'

    tick++;

}
