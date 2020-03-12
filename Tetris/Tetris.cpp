#include <iostream>
#include <string>

// 1 - Create a desk
// 2 - Create game logic
// 3 - Check isGame end


// Game field 3x3
int** mField = nullptr;                      // ***         mField[0] = nullptr         mField[0] = 0x000F16          mField[0] = {0,0,0}
                                             // ***   ->    mField[1] = nullptr   ->    mField[1] = 0x000F17   ->     mField[1] = {0,0,0}
                                             // ***         mField[2] = nullptr         mField[2] = 0x000F18          mField[2] = {0,0,0}

// Store value which was entered
struct UserValue 
{
    int mValue = 0;
    int mX     = 0;
    int mY     = 0;
};

// Create game field 3*3
void createGameField();
void show();

UserValue  getUserValue();
bool checkUserValue(UserValue aUserValue);

int main()
{
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

    else if ((aUserValue.mValue != 0) || (aUserValue.mValue != 1))
    {
        std::cout << "You entered incorrect sign" << std::endl;
        return false;
    }        

    return true;
}