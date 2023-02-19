# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtube.com).

## Minimum Requirements

### Completed

1. Game board with the dimensions must be odd number
2. Customise settings including game board dimensions and number of zombies
3. Game objects are present in the game board and alien always start at the centre of board
4. All atributes of Alien and Zombie are initialized with a random number before the game begins
5. Alien movement (i.e., up, down, left, right)
6. Zombie movement (i.e., up, down, left, right)
7. When hits the boarder of the game board, the game will stop
8. Multiple zombies with a maximum of 9
9. Game objects functions (health, empty, trail) are worked
10. Game controls (up, down, left, right, help, quit) are worked

### To Do

1. Alien and zombie attack
2. Game objects functions (arrow, pod, rock)
3. Game controls (help, save, load)
4. Save and load game

## Additional Features

No additional features is being implemented. 

## Contributions

### Lai Chi Nyet

1. Display default settings
2. Display change setting
3. Initialize the atributes for alien and zombie with randon number before the game begins
4. Alien movement (up, down, left, right)
5. Move alien to designated and leaves trail behind
6. Game controls (up, down, left, right, help, quit)

### Nicholas Tan Zhi Xuan

1. Compile the code among the members
2. Generate the game board
3. Multiple zombies
4. Movement of zombies (up, down, left, right)
5. When hit the boarder of the game board, the game will stop
6. Game objects function for health

## Problems Encountered & Solutions

1. After committing the code with GitHub by clicking the run button in Visual Studio Code, the output is not the full version of what is expected to be displayed. We solved this problem  by running the code through the terminal instead of directly pressing the run button in Visual Studio Code. 
2. When we run the program we discover that the output for row and column are inversely shown in the game board. We read through the code again and discover that we have put the dimension wrong and we have change it. 
3. We saw that rand() function is keep giving the same output (which is not random) exp: 2 2 2 2 2. To solve this problem we found out that use srand() is more better to randomize the zombie movment.
4. we found that when displaying the zombie it is showing the smiley face instead of a number character. The root of the problem is because we tried to display an integer value into a char vector, which then causes this problem. To solve this, we converted the integer value to a character value, so that it can be put into the char vector.
