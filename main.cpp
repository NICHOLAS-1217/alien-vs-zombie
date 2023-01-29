// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT8L 
// Names: LAI CHI NYET | NICHOLAS TAN ZHI XUAN 
// IDs: 1211103412 | 1211104786
// Emails: 1211103412@student.mmu.edy.my |  1211104786@student.mmu.edu.my
// Phones: 01126693839 | 0177183063 
// ********************************************************* 

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;
// CLASS BOARD -------------------------------------------------------------------------------------------------------------------
class GameBoard
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_;          // to indicate private data
public:
    void init(int x_axis, int y_axis);
    void display() const;
    void setObject(int col, int row, char object);
};

// CREATE EMPTY ROWS & RESIZE IT AND PUT RANDOM CHAR INTO THE ARRAY VECTOR --------------------------------------------------------
void GameBoard::init(int x_axis, int y_axis)
{
    dimY_ = x_axis;
    dimX_ = y_axis;
    char objects[] = {' ', ' ', ' ', 'h', 'r', 'p', '>', '<', '^', 'v'};
    char alien[] = {'A'};
    int noOfObjects = 10; // number of objects in the objects array
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
    // alien at center
    int m;
    int n;
    m = (dimX_-1)/2;
    n = (dimY_-1)/2;
    map_[n][m] = alien[0];
    
}

// DISPLAY BOARD ---------------------------------------------------------------------------------------------------------------------
void GameBoard::display() const
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

// CALLING DISPLAY FUNCTION --------------------------------------------------------------------------------------------------------
void displayBoard(int x_axis, int y_axis)
{
    GameBoard board;
    board.init(x_axis,y_axis);
    board.display();
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
            cout << " Please enter ODD number only except 1! => ";
        }
    } while (a % 2 == 0 || a == 1);
    return;
}

// CHANGE SETTINGS ------------------------------------------------------------------------------------------------------------------------
void changeSettings(int &x_axis, int &y_axis, int &zombie)
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
    cin >> zombie;
    cout << endl;
    cout << "Settings Updated." << endl;
    system("pause");
}

// DEFAULT SETTINGS ----------------------------------------------------------------------------------------------------------------------
void displayMainMenu(int x_axis, int y_axis, int zombie)
{
    char answer;
    cout << "__________________________" << endl;
    cout << "Default Game Settings" << endl;
    cout << "--------------------------" << endl;
    cout << "Board Rows     :  " << x_axis << endl;
    cout << "Board Columns  :  " << y_axis << endl;
    cout << "Zombies Count  :  " << zombie << endl;
    cout << endl;
    cout << "Do you want to change the settings? (y/n) => ";
    cin >> answer;
    answer = toupper(answer);
    if (answer == 'Y' || answer == 'y')
    {
        changeSettings(x_axis, y_axis, zombie);
        displayMainMenu(x_axis, y_axis, zombie);
    }
    else if (answer == 'N' || answer == 'n')
    {
        displayBoard(x_axis, y_axis);
    }
    else
    {
        cout << "Input Error!" << endl;
        cout << endl;
        displayMainMenu(x_axis, y_axis, zombie);
    }
}

// MAIN ----------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    int x_axis = 5; // board row
    int y_axis = 9; // board column
    int zombie = 1; // num of zombies
    displayMainMenu(x_axis, y_axis, zombie);
}
