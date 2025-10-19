We have a game inspired by the classic "Tom and Jerry" where Jerry, the mouse, aims to complete each level by consuming all the cheese within it. Jerry begins with three lives, and if caught by a cat, loses one. If Jerry exhausts all lives, the game ends in defeat. Throughout the levels, there are various gifts that only Jerry can collect. These gifts offer different advantages, such as adding lives, opening doors, or adding extra time to the clock. The level concludes when Jerry successfully collects all the cheese before the timer runs out. If there are any issues with the game's functionality, they need to be addressed and fixed to ensure smooth gameplay. 


The documents that we have created:

1-Board.h :
it includes the class and the functions of the class Board

2-Board.cpp:
it includes the operations of the functions that we have created
in the class Board

3-SmartCat.h:
it includes the class and the functions of the class SmartCat

4-SmartCat.cpp:
it includes the operations of the functions that we have created
in the class SmartCat

5-Controller.h:
it includes the class and the constructor and the functions of the class Controller

6-Controller.cpp:
it includes the operations of the functions and the constructor that we have created
in the class Controller

7-Mouse.h:
it includes the class and the constructor and the functions of the class Mouse

8-Mouse.cpp:
it includes the operations of the functions and the constructor that we have created
in the class Mouse

9-DumbCat.h:
it includes the class and the functions of the class DumbCat

10-DumbCat.cpp:
it includes the operations of the functions that we have created
in the class DumbCat

11-Menu.h:
it includes the class and the functions of the class Menu

12-Menu.cpp:
it includes the operations of the functions that we have created
in the class Menu

13-Play.h:
it includes the class and the functions of the class Play

14-Play.cpp:
it includes the operations of the functions that we have created
in the class Play

15-MovinObjects.h:
it includes the class and the functions of the class MovingObjeccts

16-MovingObjeccts.cpp:
it includes the operations of the functions that we have created
in the class MovingObjeccts

17-StaticObjects.h:
it includes the class and the functions of the class StaticObjects

18-StaticObjects.cpp:
it includes the operations of the functions that we have created
in the class StaticObjects

19-Textures.h:
it includes the class and the functions of the class Textures

20-Textures.cpp:
it includes the operations of the functions that we have created
in the class Textures

21-Wall.h:
it includes the class and the functions of the class Wall

21-Wall.cpp:
it includes the operations of the functions that we have created
in the class Wall

22-Door.h:
it includes the class and the functions of the class Door

23-Door.cpp:
it includes the operations of the functions that we have created
in the class Door

24-Gift.h:
it includes the class and the functions of the class Gift

25-Gift.cpp:
it includes the operations of the functions that we have created
in the class Gift

26-Cheese.h:
it includes the class and the functions of the class Cheese

27-Cheese.cpp:
it includes the operations of the functions that we have created
in the class Cheese

28-Key.h:
it includes the class and the functions of the class Key

29-Key.cpp:
it includes the operations of the functions that we have created
in the class Key

30-Addlife.h:
it includes the class and the functions of the class Addlife

31-Addlife.cpp:
it includes the operations of the functions that we have created
in the class Addlife

32-Newtime.h:
it includes the class and the functions of the class Newtime

33-Newtime.cpp:
it includes the operations of the functions that we have created
in the class Newtime

34-Addlive.h:
it includes the class and the functions of the class Addlive

35-Addlive.cpp:
it includes the operations of the functions that we have created
in the class Addlive

36-Sounds.h:
it includes the class and the functions of the class Sounds

37-Sounds.cpp:
it includes the operations of the functions that we have created
in the class Sounds

39-Main.cpp:
it includes the main function of the program


Data structures and their purposes:
The player moves the mouse using the arrow keys.
Vectors - We used two vectors of unique_ptr to store dynamic objects and static objects.
Arrays- we used an array textures in order to save the pictures.


Algorithems:
The SmartCat::updateMovement function in the SmartCat class calculates the cat's movement towards a mouse, employing a method inspired by Dijkstra's algorithm.
This approach focuses on evaluating and comparing distances as costs.
The function initiates by retrieving the cat's current location.
Subsequently, it constructs a vector of pairs named directions.
Each pair in this vector comprises the distance to the mouse from a
potential next position (left, right, down, up) and an associated
direction index (0 for left, 1 for right, 2 for down, 3 for up).

Crucially, after determining these distance-cost pairs, the function
sorts the directions vector in ascending order based on these
distances, effectively organizing the movements from the least to
the most costly. This sorted list thus prioritizes moves that are
closer to the mouse, aligning with the strategy of minimizing
distance in the pursuit, akin to the principles of Dijkstra's
algorithm.



Design:
Menu - This class creates a menu that has 3 options to choose from: play, help, or exit.

Controller - This class controls the game.

Board - Class that reads files and prints the map as it appears in the files.

MovingObjects - This class controls and includes objects that move, such as the cat and the mouse.

StaticObjects - This class controls and includes objects that do not move, such as the cheese, door, wall, and gifts.
