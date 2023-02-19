// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT8L 
// Names: LAI CHI NYET | NICHOLAS TAN ZHI XUAN 
// IDs: 1211103412 | 1211104786
// Emails: 1211103412@student.mmu.edy.my | 1211104786@student.mmu.edu.my
// Phones: 01126693839 | 0177183063 
// ********************************************************* 

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

// ALIEN --------------------------------------------------------------------------------------------------------------------------
class Alien
{
public:
    int alien_health;
    int alien_attack;
    char name;
    bool alien_turn; // active turn

    Alien()
    {
    	name = 'A';
        alien_health = 100;
        alien_attack = 0;
        alien_turn = true;
        
    }

	//displays alien's character attribute
    void alien_attribute()
    {
    	cout << endl;
        if (alien_turn == true)
        {
            cout << " -> ";
        }
        else // alien_turn == false
        {
            cout << "    ";
        }
        cout << "Alien    : Life = "<<setw(3)<<alien_health;
        cout << ", Attack = "<<setw(3)<<alien_attack<<endl;
    }
};
// ZOMBIE ------------------------------------------------------------------------------------------------------------------------
class Zombie
{
public:
    int zombie_health, zombie_attack, zombie_range, zombie_row, zombie_move, zombie_column;
    int x, y;
    int zombie_name;
    bool zombie_alive;
    bool zombie_turn = false;

    Zombie()
    {
        zombie_health = rand() % 300;
        zombie_attack = rand() % 50;
        zombie_range = rand() % 3;
        zombie_alive = true;
    }
};
// CLASS BOARD -------------------------------------------------------------------------------------------------------------------
class GameBoard
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_, alien_x, alien_y, prev_x, prev_y;        // to indicate private data
    char z_name[9];
public:
	int noofzombie;
    // CREATE EMPTY ROWS & RESIZE IT AND PUT RANDOM CHAR INTO THE ARRAY VECTOR --------------------------------------------------------
    void init(int x_axis, int y_axis, Zombie zombie[], Alien alien, int numofzombie)
    {
        dimY_ = x_axis;
        dimX_ = y_axis;
        char objects[] = {' ', ' ', ' ', 'h', 'r', 'p', '>', '<', '^', 'v'};
        int noOfObjects = 10; // number of objects in the objects array
        
        for (int i=0; i<9; i++)
        {
            zombie[i].zombie_name = i+1; //0+1 = 1 (int)
            z_name[i] = zombie[i].zombie_name + '0'; 
        }
        // create dynamic 2D array using vector
        map_.resize(dimY_); // create empty rows
        for (int i = 0; i < dimY_; ++i)
        {
            map_[i].resize(dimX_); // resize each row
        }

        // put random characters into the vector array
        for (int i = 0; i < dimY_; ++i)
        {
            for (int j = 0; j < dimX_; ++j)
            {
                int objNo = rand() % noOfObjects;
                map_[i][j] = objects[objNo];
            }
        }
        // random zombie position
        for(int i=0; i < numofzombie; i++)
        {
            int a,b;
            a = rand() % dimY_;
            b = rand() % dimX_;
            int num = i;
            zombie[num].y = a;
            zombie[num].x = b;
            map_[a][b] = z_name[num];
        }

        // alien at center
        alien_x = (dimX_-1)/2;
        alien_y = (dimY_-1)/2;
        map_[alien_y][alien_x] = alien.name;
    }
    void display();
    void changes(string option, Alien a, Zombie z[])
    {
    	char discover;
    	
    	// detects what's up ahead on the alien's path
    	if (a.alien_turn == true)
    	{
    		if (option == "up")
			{
				discover = map_[alien_y-1][alien_x];
				
			} else if (option == "down") {
				
				discover = map_[alien_y+1][alien_x];
				
			} else if (option == "left") {
				
				discover = map_[alien_y][alien_x-1];
				
			} else if (option == "right") {
				
				discover = map_[alien_y][alien_x+1];
			}
	    	
	    	// determines the logic for all the objects or special characters
	    	if (discover == 'h')
	    	{
	    		cout<<"Alien finds a health pack"<<endl;
	    		cout<<"Alien's life is increased by 20"<<endl<<endl;
	    		if (a.alien_health < 100)
	    		{
	    			a.alien_health += 20;
	    			if (a.alien_health > 100)
	    			{
	    				a.alien_health = 100;
					}
				} 
	    		
			} //else if (discover == 'r') {
	//			
	//			
	//		} else if (discover == 'p') {
	//			
	//		
	//		} else if (discover == '<') {
	//			
	//			
	//		} else if (discover == '>') {
	//			
	//			
	//		} else if (discover == '^') {
	//			
	//			
	//		} else if (discover == 'v') {
	//			
	//			
	//		} 
		} 
		
		// randomises zombie's moves and displaying it
		for ( int i=0; i<noofzombie; i++)
		{
			if (z[i].zombie_turn == true)
			{
				string move;
				srand(time(0));
				z[i].zombie_move = (rand() % 4) + 1;
				if (z[i].zombie_move == 1)
				{
					move = "up";
				} else if (z[i].zombie_move == 2) {
					
					move = "down";
				} else if (z[i].zombie_move == 3) {
					
					move = "left";
				} else if (z[i].zombie_move == 4) {
					
					move = "right";
				}
				
				cout<<"Zombie "<<z[i].zombie_name<<" moves "<<move<<endl;
			}
		}
    	
	}
	
	//updates alien's or zombie's movement on gameboard
    void update(string option, Alien alien, Zombie z[])
	{
		prev_x = alien_x;
		prev_y = alien_y;
		
		// moves alien to designated and leaves trail behind
		if (alien.alien_turn == true)
		{
			if (option == "up")
			{
				map_[alien_y][alien_x] = '.';
				alien_y -= 1;
				map_[alien_y][alien_x] = alien.name;
			} else if (option == "down") {
				
				map_[alien_y][alien_x] = '.';
				alien_y += 1;
				map_[alien_y][alien_x] = alien.name;
			} else if (option == "left") {
				
				map_[alien_y][alien_x] = '.';
				alien_x -= 1;
				map_[alien_y][alien_x] = alien.name;
			} else if (option == "right") {
				
				map_[alien_y][alien_x] = '.';
				alien_x += 1;
				map_[alien_y][alien_x] = alien.name;
			}
		}
		
		// moves zombie up, down, left and right
		for (int i=0 ; i<noofzombie; i++)
		{
			if (z[i].zombie_turn == true)
			{
				if (z[i].zombie_move == 1)
				{
                    map_[z[i].y][z[i].x] = ' ';
					z[i].y -= 1;
					map_[z[i].y][z[i].x] = z_name[i];
					
				} else if (z[i].zombie_move == 2) { 
					
                    map_[z[i].y][z[i].x] = ' ';
					z[i].y += 1;
					map_[z[i].y][z[i].x] = z_name[i];
					
				} else if (z[i].zombie_move == 3) { 
					
                    map_[z[i].y][z[i].x] = ' ';
					z[i].x -= 1;
					map_[z[i].y][z[i].x] = z_name[i];
					
				} else if (z[i].zombie_move == 4) { 
					
                    map_[z[i].y][z[i].x] = ' ';
					z[i].x += 1;
					map_[z[i].y][z[i].x] = z_name[i];
				}
			}
		}
		
	}
	
	// observes alien's surroundings after movement
	void surrounding(string option, Alien a)
	{		
		if (option == "up" || option == "down" || option == "left" || option == "right")
		{
			map_[prev_y][prev_x] = ' ';
			if (alien_y == 0)
			{
				cout<<"Alien hits a border."<<endl;
				system("pause");
				system("cls");
				display();
			}
			cout<<"Alien's turn ends. The trails is reset"<<endl;
			system("pause");
			system("cls");
		}
		display();
	}
	
    void setObject(int col, int row, char object);
};
// COMMAND LIST ------------------------------------------------------------------------------------------------------------------
void displayCommandList()
{
    cout << "Commands" << endl;
    cout << "1. up     - Move up." << endl;
    cout << "2. down   - Move down." << endl;
    cout << "3. left   - Move left." << endl;
    cout << "4. right  - Move up." << endl;
    cout << "5. arrow  - Change the direction of arrow." << endl;
    cout << "6. help   - Display these user commands." << endl;
    cout << "7. save   - Save the game." << endl;
    cout << "8. load   - Load a game." << endl;
    cout << "9. quit   - Quit the game." << endl<<endl;
}
// COMMAND FUNCTIONS ----------------------------------------------------------------------------------------------------------------
string command()
{
    string command;
    cout << endl;
    cout << "Command> ";
    cin >> command;
    if (command == "help")
    {
        displayCommandList();
    }
    else if(command == "quit")
    {
        cout << "" << endl;
        cout<<"goodbye!!!"<<endl;
        exit(0);
    }
	return command;
}
// DISPLAY BOARD AND CHARACTER ATTRIBUTES ------------------------------------------------------------------------------------------------
void displayBoard(GameBoard board, Alien a, Zombie z[])
{
	board.display();
	a.alien_attribute();
	for (int i = 0; i < board.noofzombie; i++)
	{
		if (z[i].zombie_turn == true)
        {
            cout << " -> ";
        }
        else // alien_turn == false
        {
            cout << "    ";
        }
        cout << "Zombie   : Life = "<<setw(3)<<z[i].zombie_health;
        cout << ", Attack = "<<setw(3)<<z[i].zombie_attack;
        cout << ", Range = "<<setw(3)<<z[i].zombie_range<<endl;
	}
    cout<<endl;
}
// DISPLAY BOARD ---------------------------------------------------------------------------------------------------------------------
void GameBoard::display()
{
    cout << ".: ALIEN V/S ZOMBIE :." << endl;
    cout << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << "  ";                                   
        for (int j = 0; j < dimX_; ++j)                  
        {
            cout << "+-";
        }
        cout << "+" << endl;                             
        // display row number
        cout << setw(2) << (i + 1);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
         
    
}
// ACCEPT ODD NUMBERS ---------------------------------------------------------------------------------------------------------------
void oddNumbers(int &a)
{
    do
    {
        cin >> a;
        if(a & 2 != 0 && a != 1)
        {
            break;
        }
        else
        {
            cout << "Please enter ODD number only except 1! => ";
        }
    } while (a % 2 == 0 || a == 1);
    return;
}
// CHANGE SETTINGS ------------------------------------------------------------------------------------------------------------------------
int changeSettings(int &x_axis, int &y_axis, GameBoard board)
{
    cout << "_________________________________________" << endl;
    cout << "Board Settings" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Please enter odd numbers only except 1. " << endl;
    cout << "Enter rows =>  "; 
    oddNumbers(x_axis);
    cout << endl;
    cout << "Enter colums =>  ";
    oddNumbers(y_axis);
    
    cout << "_________________________________________" << endl;
    cout << "Zombies Settings" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Enter number of zombies =>  ";
    cin >> board.noofzombie;
    cout << endl;
    cout << "Settings Updated." << endl;
    system("pause");

    return board.noofzombie;
}
// DEFAULT SETTINGS ----------------------------------------------------------------------------------------------------------------------
char displayMainMenu(int x_axis, int y_axis, GameBoard board)
{
    char answer;
    cout << "__________________________" << endl;
    cout << "Default Game Settings" << endl;
    cout << "--------------------------" << endl;
    cout << "Board Rows     :  " << x_axis << endl;
    cout << "Board Columns  :  " << y_axis << endl;
    cout << "Zombies Count  :  " << board.noofzombie << endl;
    cout << endl;
    cout << "Do you want to change the settings? (y/n) => ";
    cin >> answer;
    answer = toupper(answer);
    return answer;
}
// MAIN ----------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    int x_axis = 5; // board row
    int y_axis = 9; // board column
    int numofzombie=1;
    string option;
    GameBoard board;
    Zombie z[9];
    Alien a;
    board.noofzombie = 1;
    board.init(x_axis,y_axis, z, a, numofzombie);
    board.display();
    system("pause");
    char answer = displayMainMenu(x_axis, y_axis, board);
    if (answer == 'Y' || answer == 'y')
    {
        numofzombie = changeSettings(x_axis, y_axis, board);
        board.noofzombie = numofzombie;
        answer = displayMainMenu(x_axis, y_axis, board);
        board.init(x_axis,y_axis, z, a, numofzombie);
    	board.display();
    }
    else if (answer == 'N' || answer == 'n')
    {
        //displayBoard(x_axis, y_axis, numofzombie);
    }
    else
    {
        cout << "Input Error!" << endl;
        cout << endl;
        displayMainMenu(x_axis, y_axis, board);
    }
    system("cls");
    displayBoard(board,a,z);
    do
    {
    	if (a.alien_turn == true) // alien's turn
    	{
    		option = command();
    		if (option == "help")
    		{
    			system("pause");
    			system("cls");
    			displayBoard(board,a,z);
    			option = command();
			}
    		system("pause");
	    	system("cls");
	    	displayBoard(board,a,z);
	    	board.changes(option, a, z);
	    	system("pause");
	    	system("cls");
	    	board.update(option, a, z);
	    	displayBoard(board,a,z);
	    	board.surrounding(option, a);
	    	
		} 
		a.alien_turn = false;
    	int x=0;
        z[x].zombie_turn = true;
	    	
		for (int i=0; i<board.noofzombie; i++)
		{
			if (z[i].zombie_turn == true)
			{
                board.changes(option, a, z);
                system("pause");
                system("cls");
                board.update(option,a,z);
                displayBoard(board,a,z);
				system("cls");
				displayBoard(board,a,z);
                z[i].zombie_turn = false;
                z[i+1].zombie_turn = true;
			}
		}
		a.alien_turn = true;
    	
	}while(option != "quit");
    
}

