-----------------------------------
CsoulUI
-----------------------------------

CsoulUI (Console User Interface) is a way for users to interact with the program through the console through fixed predecided commands. This document (README.txt) will cover:
- Initializing CsoulUI
- Creating Commands
- The User Side

Let's say for example that you want to have a program that saves a bunch of data into a file when the user wants to. You have a function for it already called void save(std::string file), but stuff in your main method is getting clunky as you constantly have to read in and parse the user input in the console. CsoulUI is designed to eliminate the potential clutter and repetitiveness that could arise from attempting to parse and manage user input from the console.

-------------------------
INITIALIZING CsoulUI
-------------------------

To start CsoulUI, use the following snippet:

CsoulUI c("PROGRAM_TITLE", "PROGRAM_VERSION");
// defining commands goes here
c.listen();

-------------------------
CREATING COMMANDS
-------------------------

In the scenario described originally, we could create a command as follows:

CsoulUI c("PROGRAM_TITLE", "PROGRAM_VERSION");
// defining commands goes here
c.createCommand("SAVE", "saves data", [](std::string f) { save(f); });
c.listen();

This could be run in a separate thread, and if the user ever enters "SAVE filename" into the console, CsoulUI will run save(filename). 

-------------------------
THE USER SIDE
-------------------------

Ok, that's all good and fine, but what will the user see? When CsoulUI starts, the following line will always be printed:
[CsoulUI]: Initializing PROGRAM_TITLE PROGRAM_VERSION

All CsoulUI output begins with "[CsoulUI]:". After this, the user will be able to enter any commands they wish.

HELP
-------------------------

The HELP command displays a list of commands. To the user, (in the above scenario) it will appear as follows:
HELP
[CsoulUI]: A List of Commands:
SAVE: saves data
HELP: displays a list of commands
SOULSLEEP: ends CsoulUI

Since everything is stored using an std::unordered_map, the commands will be displayed in no particular order. 

SOULSLEEP
-------------------------

This simply ends the program by stating:
[CsoulUI]: Terminating PROGRAM_TITLE PROGRAM_VERSION

OTHER COMMANDS
-------------------------

All other commands will start with [CsoulUI]: and will simply print out what is specified by the progrmmer. For example, the above function "SAVE" does not directly print anything (unless the save function itself does) so the output will simply be 
[CsoulUI]:

After every command, the line is ended. If a command (say COMMAND_NAME) is not recognized, 
[CsoulUI]: ERROR! Command COMMAND_NAME not recognized.
will be printed to the console. 

-----------------------------------

Overall, CsoulUI can be used quickly and easily to create commands that can be used by the user in the console.

BlueFlame
April 19, 2021