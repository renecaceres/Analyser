UTFSM Analysis Team Coding Conventions
======================================

This guide is a resumen (with a few modifications) of the [ROOT Coding Conventions](http://root.cern.ch/drupal/content/c-coding-conventions). Please edit this guide if something is missing.



## Naming conventions

For naming conventions we follow the [Taligent rules](http://pcroot.cern.ch/TaligentDocs/TaligentOnline/DocumentRoot/1.0/Docs/books/WM/WM_63.html#HEADING77).  They have written a very large body of C++ and their rules seem well thought out. No need to invent something new.


    Types                   Begin with a capital letter            Boolean

    Base classes            Begin with T                           TContainerView

    Mixin classes           Begin with M;                          MPrintable

    Enumeration types       Begin with E                           EFreezeLevel

    Virtual base classes    Begin with V                           VBaseClass

    Members                 Begin with f for field                 fViewList
                            Functions begin with a capital letter  DrawSelf()

    Static variables        Begin with g                           gDeviceList

    Static data members     Begin with fg;                         TView::fgTokenClient

    Locals and parameters   Begin with a lowercase letter          seed, port, maxArea

    Constants               Begin with k                           kMenuCommand

    Acronyms                All uppercase                          TNBPName, not TNbpName

    Template arguments      Begin with A                           AType
    
    Getters and setters     Begin with Set..., Get..., or Is...    SetLast(), GetNext()


The only addition/change we made is to append an `_t` to typedefs and simple structs, e.g.:

    typedef int Int_t;
    struct Simple_t { ..... };

The usage of a standard begin letter or token for the different types makes it easy to parse and search the code using simple tools.



## Class definition conventions

Also here the Taligent guide is quite reasonable. No class data member should ever be public. Make the data fields always private. Or protected, if you want to grant an inherited class direct access.


#### Inline

Add trivial get or setters directly in the class definition. Add more complex inlines (longer than one line) in a separate *-inc.h file.


#### Declaration Order

In the class definition we first declare all private data members, followed by the private static members, the private methods and the private static methods. Then the protected members and methods and finally the public methods (remember no public data members).


## Avoid raw C types

Avoid the use of raw C types like `int`, `long`, `float`, `double` when using data that might be written to disk. For portability reasons and consistent numerical results use the [typedefs provided by ROOT](http://root.cern.ch/root/html/ListOfTypes.html).


## Exception handling

No link time penalty but a run time penalty is incured (the run time needs to keep track of the resources to be freed when an exception is thrown). Do not let every method throw an exception when a simple error return code is often enough.



## Using comments to document the code

Using the information stored in the dictionary and the source files ROOT can automatically generate a hyperized version of the header and source files. By placing comments in a few strategic places a complete reference manual, including graphics, can be generated using the THtml class.


#### Data member description comments

Comments behind a data member definition in the header file:

    Float_t     fEnergy;     // the particle energy

The comment `the particle energy` will be put in the dictionary and used whenever `fEnergy` needs to be described.


#### Class description comments

A comment block at the top of the source file describing the class. This block has to be preceeded by a line containing a C++ comment token followed a delimiter string. All comment lines after this starting line are part of the class description:

    //______________________________________________________________________________
    //
    // TPrimitive
    //
    // This class is the abstract base class of geometric primitives.
    // Use this class by inheriting from it and overriding the
    // members, Draw() and List().
    //


#### Member function description comments

The first comment lines after the opening bracket of a member function are considered a description of the function:

    TList::Insert()
    {
        // Insert node into linked list.
        // To insert node at end of list use Add().
        ...
        ...
    }

Here the two comment lines after the `{` are used to describe the working and usage of the member function.

#### HTML directly in the source

In the class and member function description comments one can also insert "raw" HTML:

    TList::Insert()
    {
        // Insert node into linked list.
        // To insert node at end of list use Add().
        //Begin_Html
        /*
        
        */
        //End_Html
        ...
        ...
    }

Everything enclosed by the `//Begin_Html` and `//End_Html` lines is considered to be pure HTML (to not confuse the C++ compiler the HTML block has to be enclosed by C style (/* ... */) comments.



## Preferred Coding Style


#### Indentation

Use indentation of 4 spaces. No tabs since they give the code always a different look depending on the tab settings of the original coder.


#### Placing Braces and Spaces

The preferred way, as shown by the prophets Kernighan and Ritchie, is to put the opening brace last on the line, and put the closing brace first, thusly:

    if (x is true) {
        we do y
    }

However, there is one special case, namely functions: they have the opening brace at the beginning of the next line, thus:

    int function(int x)
    {
        body of function
    }


Note that the closing brace is empty on a line of its own, except in the cases where it is followed by a continuation of the same statement, ie a while in a do-statement or an else in an if-statement, like this:

    do {
        body of do-loop
    } while (condition);

and

    if (x == y) {
        ...
    } else if (x > y) {
        ...
    } else {
        ...
    }

Rationale: K&R.

Also, note that this brace-placement also minimizes the number of empty (or almost empty) lines, without any loss of readability. Thus, as the supply of new-lines on your screen is not a renewable resource (think 25-line terminal screens here), you have more empty lines to put comments on.

Notice also in the above examples the usage of spaces around keywords, operators and parenthesis/braces. Avoid the following free styles:

    if( x==y ){

or any derivative thereof.

In these cases `indent -kr -i3 -nut` is our best friend, for example code that we'll get looking like this:

    int aap(int inp) {
        if( inp>0 ){
            return   0;
            int a = 1;
            if (inp==0 &&a==1) {
                printf("this is a very long line that is not yet ending", a, inp, a, inp, a  , inp);
                a+= inp;
                return a;
            }
        }
        else {
            return 1; }
    
        if(inp==0)return -1;
        return 1;
    }

You will find back like this:

    int aap(int inp)
    {
        if (inp > 0) {
            return 0;
            int a = 1;
            if (inp == 0 && a == 1) {
                printf("this is a very long line that is not yet ending", a, inp,
                a, inp, a, inp);
                a += inp;
                return a;
            }
        } else {
            return 1;
        }
        
        if (inp == 0) return -1;
        return 1;
    }


#### Astyle

A much better alternative than indent is astyle. Get at least version 1.23 and use the following `~/.astylerc`:

    # UTFSM Analysis Team code formatting style
    --indent=spaces=4     # four spaces per indentation level
    --convert-tabs        # convert tabs into spaces
    
    --brackets=stroustrup # '{' on new line only for func
    
    --indent-switches # case block is indented wrt switch
    --indent-namespaces
    --indent-preprocessor # indent pp statements ending on '\'
    --max-instatement-indent=60 # if indentation of continuing line is <60, indent
    --min-conditional-indent=0 # no extra indent for continued conditions
    
    --pad-oper # space around operands
    --pad-header # add a space around () after if, while,...
    --unpad-paren # and remove all unwanted padding around parentheses
    
    --suffix=none # no backups - we have Git
    --recursive # so you can do astyle "core/*.cxx" "core/*.h"



## Where to go from here

For the rest read the [Taligent rules](http://pcroot.cern.ch/TaligentDocs/TaligentOnline/DocumentRoot/1.0/Docs/books/WM/WM_63.html#HEADING77) and use common sense.
