[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-9f69c29eadd1a2efcce9672406de9a39573de1bdf5953fef360cfc2c3f7d7205.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=9238862)
# ProgrammingAssignment2
This is an individual assignment. Each checkpoint will be written by you, and you alone. You should not share code (aside from the code you have already written with your partner in PA1 if you choose to reuse it). The University's cheating and plagiarism rules are within this document. Please note that there is significant variation in possible solutions- you may choose to implement certain things differently than others. That isn't a reason to panic- if you've used it appropriately based on class discussion, you're good to go.  



## Project Goals
The goal of this project is to show proficiency with:
1.	Refactoring code;
2.  **Abstract base classes**;
3.  **Template Functions**;
4.  **Template Classes**;
5.  **Dynamic Memory**;
6.  Writing **UML** documentation and **design documents**;
7.  **Unit tests**.
### Important Notes:
1.	**Formatting**: Make sure that you follow the precise recommendations for the output content and formatting- you will need to run the provided executable to see what output should look like. For your testing purposes, the autograder will be comparing your output to that of the example executable.
2.	**Comments**: Header comments are required on all files and recommended for the rest of the program. Points will be deducted if no header comments are included.
3.  **Code Reuse**: PA2 depends on PA1! If you and your partner did not earn a grade that you are satisfied with, the solution is included in this repository. Each programming assignment checkpoint requires your code to be improved upon. Descriptions of checkpoint must haves are included in this document. You are free to reuse your code from previous check points, and you will likely have to modify it in some way to implement the added methodology.
4.  **Grading**: Each checkpoint lists new content that should be included (in addition to previous code checkpoints). These checkpoint requirements are the _bare minimum_ to satisfy the requirements for grading. On lab days with checkpoints, the class will have 10 minutes to ask your TA and TF questions about issues you ran into so that you can revise your code for that checkpoint before midnight. The 4th check point will be when the entire program (in running condition) is due so that your TA can grade it more thoroughly.
5.  **Unit Tests**: This assignment requires you to write _at least_ five unit tests of substance. I suggest writing them before or as you write your code, so that you can more easily check output. (NOTE: These will be covered the week of NOV 8, so don't panic, you'll know what a unit test is and how to write one before the deadline for them.)
6.  **Documentation**: This assignment requires you to create a design document that contains UML diagrams. The easiest way to do this is to use [doxygen](https://doxygen.nl/), but you can also make them by hand using draw.io, Microsoft Publisher, etc.
7. **Design**: You will notice that the description for this assignment is less detailed than the first assignment. You are responsible for making design choices to integrate the required components detailed below. You will likely need to do a bit of research on how to generate the documentation!


## Program
When complete, your project should include the following files from PA1 (again, if you did not do well on this portion, the solution is in the repo, or you may use your own code from PA1):
- driver.cpp
- patron.cpp
- patron.h
- ride.cpp
- ride.h
- magicCarpet.cpp
- magicCarpet.h
- teacups.cpp
- teacups.h
- worldTour.cpp
- worldTour.h
- makefile  

**You will need to add the following classes:**
- a money class. It should be able to handle money from the US and Madagascar. 
- a cost calculator template class. It should be able to take either US dollars or [Madagascan dollars](https://en.wikipedia.org/wiki/Malagasy_ariary) from the money class and calculate the total cost of a ticket order. A ticket bought with madagascan money costs 313 Ariarys, while a ticket bought with US money costs 0.75 dollars. You can calculate the total cost by computing the product of the ticket cost and the number of tickets, and multiplying it with the tax rate of 1.75%.

**You will need to add the following concepts by either extending code ability or by modifying existing code from PA1:**
- An abstract base class (where ever it makes sense to do so). You can revise any of the code in any of the files from PA1 to make this change. Remember, abstract base classes tend to be used when we have a parent with critical functionality that needs to be passed to children, but we don't want to be able to create an object out of the parent for whatever reason. Make sure that you keep that in mind when you choose the class you will make abstract.  
- New class objects, a cost calculation method, and change calculation method should be added to the driver. The cost calculation should be performed if a patron is purchasing tickets, after they input the number of tickets they'd like to purchase. This cost calculation method should first prompt for currency type provided by the patron (Ariarys or US dollars). The change calculation method should prompt the user to enter the amount of money given to them by the patron, calculate the difference between that money given and the ticket cost, and then display that amount of change to the user so that they can provide it to the patron.
- Refactor redundant functions in the driver so that they are a template function instead of passing in different parameters that do the same work.
- Dynamic memory allocation for the various arrays that you've created (rides::Patron, patrons::driver.cpp).


Your executable should be named ```carnivalComplete```
## Programming Problem
Write a program that loads existing patron data (see supplied patronList.txt for format) by providing the filename on the command line when running (./carnival patronList.txt FOR EXAMPLE). If a filename is not provided, an error message should be displayed to the user. If the file cannot be opened for reading, an error message should be displayed to the user.

If the file can be opened for reading, each student should be read from the student file and each instructor should be read from the instructor file. The program should display the menu to the screen. Further documentation can be found [here](./html/files.html). Please note that the documentation for driver.cpp is found under files (not classes), once you open the html link by double clicking on it.

The major behavior change in this version is that the program should now calculate ticket cost and output that cost so that the patron can be charged that much. The user should be able to input a number of tickets to add to a patron, calculate the total cost of those new tickets, and input the amount of money handed to them by the patron (either Ariarys or US dollars), and then calculate and display the amount of change that the user should hand off to the patron. 

Many of the changes that you will make (abstract base class, templates, etc) may not be visible to the program user -> they're just a different way to implement the same behavior.

### The example executable:
An example executable is provided in this repository. You should be able to run it from your project folder.
If you encounter a “permission denied” error when attempting to run the executable, type ```chmod u+x amusementParkComplete``` into the terminal and try running the executable again by doing ```./amusementParkComplete filename```

