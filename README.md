# Alien vs. Zombie

Alien vs. Zombie is a turn-based combat game. The player controls Alien to defeat a group of Zombies. Prior the game, the player can customize settings including game board dimensions and number of zombies. The player can also save a game into a file and load a game from a file. The Alien and Zombies are given with their own attributes. The player can move the Alien to attack the zombies to defeat them by giving commands. The game contain many game objects that Alien can interact with. 

![./Alien vs Zombie.png](https://github.com/NICHOLAS-1217/Starter-Kit-master/blob/master/Alien%20vs%20Zombie.png?raw=true)

[Video Demo](https://www.youtube.com/watch?v=-SVhHg94o3w).

## Compilation Instructions

```
g++ main.cpp 
g++ a.exe 
```

## User Manual

HOW TO PLAY:

Alien vs Zombie is a game that let the players to control the alien and attack the zombies in the gameboard.

1. The game will display the default game board and default setting to the player once the player runs the game.
2. Players can choose to use either the default settings for the game board and number of zombies or change the dimension of the game board and the number of zombies.
3. The game will then display the game board with the customised settings and show the attribute of the Alien and Zombie.
4. Players now can enter commands to operate the game. Players can enter "help" to check the list of commands that are present in the game. 
5. Players can enter other commands (i.e., up, down, left, right) to move the Alien.
6. It is stopped by one of the following events:
  -It hits the border of the game board (see Game Board).
  -It hits the Rock object (see Game Objects).
  -It hits and attacks Zombie, but Zombie survives the attack.
7. Alien attacks when it encounters Zombie on the move. If Zombie is defeated by the attack, Zombie will be 
removed from the game board while Alien continues to move.
8. After the you enter the command to move the Alien, the zombie will move randomly by the computer.
9. After a move, Zombie will attack Alien if Alien is with its attack range.
10. The process of Alien move and Zombie move will take turn occurs until the game end.
12. You can also end the game directly by typing "quit" in the command's section. 
13. You can also save and load the game. 

Here are some game objects that include inside the gameboard:-
1. Arrow 
-^ (up)
-v (down)
-< (left)
-> (right)
• Changes Alien’s direction of movement.
• Adds 20 attack to Alien.
2. Health 
-h 
• Adds 20 life to Alien.
3. Pod 
-p 
• Instantly inflicts 10 damage to Zombie when hit by Alien.
4. Rock 
-r 
• Hides a game object (except Rock and Trail)beneath it.
• Reveals the hidden game object when hit by Alien.
• Stops the Alien from moving.
5. Empty Space 
-
• Just an empty space on the board.
6. Trail 
-. 
• Left by Alien when it moves.
• Reset to a random game object (except the Trail) after Alien’s turn ends.

List of command:-
1. up - Alien to move up.
2. down - Alien to move down.
3. left - Alien to move left.
4. right - Alien to move right.
5. arrow - Switch the direction of an arrow object in the game board. (The player will be asked to enter the row and column of the arrow object
to switch, followed by the direction of the arrow object to switch to.) 
6. help - List and describe the commands that the player can use in the game.
7. save - Save the current game to a file. (The player will be asked to enter the name of the file to save to).
8. load - Load a saved game from a file. (The player will be asked to enter the name of the file to load from).
9. quit - Quit the game while still in play.

## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors 

- Lai Chi Nyet
- Nicholas Tan Zhi Xuan 


