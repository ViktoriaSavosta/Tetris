#include <iostream>
#include <string>

// 1 - Create a desk
// 2 - Create game logic
// 3 - Check isGame end


// Game field 3x3
int** mField = nullptr;                      // ***         mField[0] = nullptr         mField[0] = 0x000F16          mField[0] = {0,0,0}
                                             // ***   ->    mField[1] = nullptr   ->    mField[1] = 0x000F17   ->     mField[1] = {0,0,0}
                                             // ***         mField[2] = nullptr         mField[2] = 0x000F18          mField[2] = {0,0,0}

// Current game state
int mCurrentGameState = -1;

// User sign
int mUserSign = -1;

// Game states
enum GameState
{
    startGame = 0,
    exitGame  = 1,
    endGame   = 2,
    restart   = 3
};


// Store value which was entered
struct UserValue 
{
    int mValue  = 0;
    int mX      = 0;
    int mY      = 0;
};

// Create game field 3*3
void createGameField();
void show();
void menu();
void chooseUserSign();

UserValue  getUserValue();
bool checkUserValue(UserValue aUserValue);

int main()
{
    chooseUserSign();
    menu();
    createGameField();
    show();

    UserValue userValue;
    userValue = getUserValue();
    std::cout << userValue.mX << std::endl << userValue.mY << std::endl << userValue.mValue << std::endl;

    return 0;
}

void createGameField()
{
    mField = new int* [3];

    for (int i = 0; i < 3; i++)
        mField[i] = new int[3];

    for (int x = 0; x < 3; x++) 
    {
        for (int y = 0; y < 3; y++)
            mField[x][y] = 0;
    }
}

void show()
{
    for (int y = 0; y < 3; y++) 
    {
        for (int x = 0; x < 3; x++) 
        {
            std::cout << mField[y][x];
        } 
        std::cout << std::endl;
    }
}

UserValue getUserValue()
{
    UserValue userValue;
    do
    {
        std::cout << "Enter x position : " << std::endl;
        std::cin >> userValue.mX;

        std::cout << "Enter y position : " << std::endl;
        std::cin >> userValue.mY;
 
        std::cout << "Enter sign : " << std::endl;
        std::cin >> userValue.mValue;
    } while (!checkUserValue(userValue));
    
    return userValue;
}

bool checkUserValue(UserValue aUserValue) 
{
    if (aUserValue.mX < 0 || aUserValue.mX > 2)
    {
        std::cout << "You entered incorrect value x" << std::endl;
        return false; 
    }
        

    else if (aUserValue.mY < 0 || aUserValue.mY > 2)
    {
        std::cout << "You entered incorrect value y" << std::endl;
        return false;
    }        

    else if (aUserValue.mValue < 0 || aUserValue.mValue > 1)
    {
        std::cout << "You entered incorrect sign" << std::endl;
        return false;
    }   

    return true;
}

// Step 1 : choose game state ( start game / exit )
// Step 2 : choose sign ( O / X )
// Step 3 : if you failed you can choose restart ( Do you want to restart? y/n )

void menu()
{
    int response = 0;
    
    std::cout << "0 - Start game" << std::endl << "1 - Exit" << std::endl << "2 - End" << std::endl << "3 - Restart" << std::endl;
    std::cin >> response;
    
    switch (response)
    {
    case(startGame):
        std::cout << "Start game" << std::endl;
        mCurrentGameState = startGame;
        break;

    case(exitGame):
        std::cout << "Goodbuy mothefucker!" << std::endl;
        mCurrentGameState = exitGame;
        break;

    case(endGame):
        std::cout << "Good bye!" << std::endl;
        mCurrentGameState = endGame;
        break;

    case(restart):
        std::cout << "You are starting new game!" << std::endl;
        mCurrentGameState = restart;
        break;
    }
}

void chooseUserSign() 
{
    bool isResponseCorrect = false;
    int  response          = -1;

    while (!isResponseCorrect)
    {
        std::cout << "Enter sign : ";
        std::cin >> response;

        // Если 
        if (response == 0)
        {
            mUserSign         = response;
            isResponseCorrect = true;
        }

        // Если то
        else if (response == 1) 
        {
            mUserSign = response;
            isResponseCorrect = true;
        }
        // В противном случае
        else 
        {
            std::cout << "Incorrect sign, try again!" << std::endl;
            isResponseCorrect = false;
        }
    }
}