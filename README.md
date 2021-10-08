# CPPND: Memory Management Chatbot

This project was an examination assigment for the for the third course in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213): Memory Management.
The source code provided as a course material was almost fully functional - with one bug to remove. But the main goal was to optimize the code with regard to the resource managment policy. The starter code was based purely on raw pointers usage for the memory management.
As a studuent I was given five task, completion of which optimized the project introducing smart pointers, move semantics and have restructured the overall resource managment policy.

<img src="images/chatbot_demo.gif"/>

The ChatBot code creates a dialogue where users can ask questions about some aspects of memory management in C++. After the knowledge base of the chatbot has been loaded from a text file, a knowledge graph representation is created in computer memory, where chatbot answers represent the graph nodes and user queries represent the graph edges. After a user query has been sent to the chatbot, the Levenshtein distance is used to identify the most probable answer.

## Dependencies for Running Locally

- cmake >= 3.11
  - All OSes: [click here for installation instructions](https://cmake.org/install/)
- make >= 4.1 (Linux, Mac), 3.81 (Windows)
  - Linux: make is installed by default on most Linux distros
  - Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  - Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
- gcc/g++ >= 5.4
  - Linux: gcc / g++ is installed by default on most Linux distros
  - Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  - Windows: recommend using [MinGW](http://www.mingw.org/)
- wxWidgets >= 3.0
  - Linux: `sudo apt-get install libwxgtk3.0-dev libwxgtk3.0-0v5`. If you are facing unmet dependency issues, refer to the [official page](https://wiki.codelite.org/pmwiki.php/Main/WxWidgets30Binaries#toc2) for installing the unmet dependencies.
  - Mac: There is a [homebrew installation available](https://formulae.brew.sh/formula/wxmac).
  - Installation instructions can be found [here](https://wiki.wxwidgets.org/Install). Some version numbers may need to be changed in instructions to install v3.0 or greater.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./membot`.

## Project Task Details resolved during the assignment given to the student.

In the starter code provided, the program crashed when the window was closed. There was a small bug hidden somewhere, which has something to do with improper memory management. So your first warm-up task was to find this bug and remove it.

Aside from the bug mentioned above, there were five additional major student tasks in the Memory Management chatbot project, which are:

### Task 1 : Exclusive Ownership 1

In file `chatgui.h` / `chatgui.cpp`, `_chatLogic` had to be made an exclusive resource to class `ChatbotPanelDialog` using an appropriate smart pointer. Where required, the changes to the code were introduced, such that data structures and function parameters reflect the new structure.

### Task 2 : The Rule Of Five

In file `chatbot.h` / `chatbot.cpp`, changes were made to the class `ChatBot` such that it complies with the Rule of Five. I made sure to properly allocate / deallocate memory resources on the heap and also copy member data where it makes sense. In each of the methods (e.g. the copy constructor), a string of the type "ChatBot Copy Constructor" is printed to the console so that you can see which method is called in later examples.

### Task 3 : Exclusive Ownership 2

In file `chatlogic.h` / `chatlogic.cpp`, the vector `_nodes` was adapted in a way that the instances of `GraphNodes` to which the vector elements refer are exclusively owned by the class `ChatLogic`. This was achieved with the use of an appropriate type of smart pointer. Where required, additional changes to the code were made.

### Task 4 : Moving Smart Pointers

In files `chatlogic.h` / `chatlogic.cpp` and `graphnode.h` / `graphnode.cpp` the ownership of all instances of `GraphEdge` was change in a way such that each instance of `GraphNode` exclusively owns the outgoing `GraphEdges` and holds non-owning references to incoming `GraphEdges`. This was achieved with the use of an appropriate smart pointers and additional changes to the program code based on move semantics.

### Task 5 : Moving the ChatBot

In file `chatlogic.cpp`, a local `ChatBot` instance was created on the stack at the bottom of function `LoadAnswerGraphFromFile`. Then, move semantics was used to pass the `ChatBot` instance into the root node. I made sure that `ChatLogic` has no ownership relation to the `ChatBot` instance and thus is no longer responsible for memory allocation and deallocation. When the program is executed, for the program workflow demonstration purposes, messages are printed, showing the part of the Rule of Five components of `ChatBot` in action.
