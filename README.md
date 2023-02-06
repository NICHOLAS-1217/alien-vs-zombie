# Alien vs. Zombie

Alien vs. Zombie is a turn-based computer game in which the player controls Alien to defeat a group of Zombies. Prior the game, the player can customize settings including game board dimensions and number of zombies. The player can also save a game into a file and load a game from a file.

You may add one signature screenshot of your program here or above the title. Check out [this tutorial](https://www.digitalocean.com/community/tutorials/markdown-markdown-images) to learn how to do it.

[Video Demo](https://www.youtube.com/watch?v=-SVhHg94o3w).

## Compilation Instructions

For example:

```
g++ main.cpp (enter)
g++ a.exe (enter)
```

## User Manual

HOW TO PLAY:

This game purpose was letting the players to control the alien and attack the zombies in the gameboard.

From the beggining of the game, the default settings of the gameboard will be displayed to the players.

Players can choose to use the default settings of the gameboard or change the settings of the gameboard.

With the settings of the gameboard, player can choose to change the rows and columns or even the numbers of zombies inside the gameboard.

After changing the settings of the gameboard, the gameboard will generate a new row and column for players.

here are some game objects that include inside the gameboard:

Arrow 
-^ (up)
-v (down)
-< (left)
-> (right)

• Changes Alien’s direction of movement.
• Adds 20 attack to Alien.

Health 
-h 
• Adds 20 life to Alien.

Pod 
-p 
• Instantly inflicts 10 damage to Zombie when hit by Alien.

Rock 
-r 
• Hides a game object (except Rock and Trail)beneath it.
• Reveals the hidden game object when hit by Alien.
• Stops the Alien from moving.

Empty Space 
-
• Just an empty space on the board.

Trail 
-. 
• Left by Alien when it moves.
• Reset to a random game object (except the Trail) after Alien’s turn ends.

COMMAND:

up 
Alien to move up.

down 
Alien to move down.

left 
Alien to move left.

right 
Alien to move right.

arrow 
Switch the direction of an arrow object in the game board.
(The player will be asked to enter the row and column of the arrow object
to switch, followed by the direction of the arrow object to switch to.)

help 
List and describe the commands that the player can use in the game.
save Save the current game to a file.

(The player will be asked to enter the name of the file to save to).

load 
Load a saved game from a file

(The player will be asked to enter the name of the file to load from).

quit 
Quit the game while still in play.

(The player will be asked to confirm his/her decision)


## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

Please replace the following with your group members' names. 

- Lai Chi Nyet
- Nicholas Tan Zhi Xuan 


