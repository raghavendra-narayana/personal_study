#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()

using namespace std;

#define MAX_FRAME 10
#define MAX_BONUS 10
#define BOWLING_TRY1 0xAAAA
#define BOWLING_TRY2 0xBBBB
#define BONUS_STRIKE 0xCCCC
#define BONUS_SPARE 0xDDDD
#define BONUS_10TH_TRY 0xEEEE

#define USE_STATIC_DATA
#ifdef USE_STATIC_DATA
#define STATIC_TRY_INDEX 0
#define STATIC_VALUE_INDEX 1
int BOWLING_GAME_DATA[][2] {     \
    {BOWLING_TRY1, 1},          \
    {BOWLING_TRY2, 4},          \
                                \
    {BOWLING_TRY1, 4},          \
    {BOWLING_TRY2, 5},          \
                                \
    {BOWLING_TRY1, 6},          \
    {BOWLING_TRY2, 4},          \
                                \
    {BOWLING_TRY1, 5},          \
    {BOWLING_TRY2, 5},          \
                                \
    {BOWLING_TRY1, 10},          \
    {BOWLING_TRY2, 0},          \
                                \
    {BOWLING_TRY1, 0},          \
    {BOWLING_TRY2, 1},          \
                                \
    {BOWLING_TRY1, 7},          \
    {BOWLING_TRY2, 3},          \
                                \
    {BOWLING_TRY1, 6},          \
    {BOWLING_TRY2, 4},          \
                                \
    {BOWLING_TRY1, 10},         \
    {BOWLING_TRY2, 0},          \
                                \
    {BOWLING_TRY1, 2},          \
    {BOWLING_TRY2, 8},          \
    {BOWLING_TRY1, 6}          \
};
#endif //USE_STATIC_DATA

class bowlingFrame{
public:
    int numberOfTries; //??
    int bonusNumberOfTries; //??

    //value pair for two tries
    map<int, int> tries;
    //value pair for bonus tries
    map<int, int> bonusTries;

    bool strike = false;
    bool spare = false;
    bool final10thTry = false;


public:
    bowlingFrame(){
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;   
        //initial pin values set to 0
        setMapTriesValue(BOWLING_TRY1, 0);
        setMapTriesValue(BOWLING_TRY2, 0);
        //initial bonus values set to 0
        setMapBonusTriesValue(BONUS_SPARE, 0);
        setMapBonusTriesValue(BONUS_STRIKE, 0);
        setMapBonusTriesValue(BONUS_10TH_TRY, 0);
        strike = false;
        spare = false;
        final10thTry = false;
        cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;   
    }

    ~bowlingFrame(){
        tries.clear();
        bonusTries.clear();
    }   

    void setMapTriesValue(int key, int value) {
        tries[key] = value;
        cout << " setMapTriesValue KEY " << std::hex << key << " : Data " << std::dec << tries[key]  << endl;
        if((!strike && key == BOWLING_TRY1) && (value == MAX_BONUS)){
            strike = true;
            setMapBonusTriesValue(BONUS_STRIKE, MAX_BONUS);
            cout << " setMapTriesValue Strike KEY " << std::hex << key << " : Data " << std::dec << tries[key]  << endl;
        }
        else if(!spare && !strike && (key == BOWLING_TRY2) && 
            ((tries[BOWLING_TRY1] + tries[BOWLING_TRY2]) == MAX_BONUS)){
            spare = true;
            setMapBonusTriesValue(BONUS_SPARE, MAX_BONUS);
            cout << " setMapTriesValue Spare KEY " << std::hex << key << " : Data " << std::dec << tries[key]  << endl;
        }
    }

    void setMapBonusTriesValue(int key, int value) {
        bonusTries[key] = value;
        cout << " setMapBonusTriesValue KEY " << std::hex << key << " : Data " << std::dec << bonusTries[key]  << endl;
    }

    int getMapTriesValue(int key) {
        cout << " getMapTriesValue KEY " << std::hex << key << " : Data " << std::dec << tries[key] << endl;
        return tries[key];
    }

    int getMapBonusTriesValue(int key) {
        cout << " getMapBonusTriesValue KEY " << std::hex << key << " : Data " << std::dec << bonusTries[key] << endl;
        return bonusTries[key];
    }

    void setfinal10thTry() {
        final10thTry = true;
    }

    bool getfinal10thTry() {
        return final10thTry;
    }

    void printMap() const {
        for (const auto& pair : tries) {
            std::cout << std::hex << pair.first << ": " << pair.second << std::endl;
        }
        for (const auto& pair : bonusTries) {
            std::cout << std::hex << pair.first << ": " << pair.second << std::endl;
        }
        if(final10thTry)
            std::cout << std::dec << "final10thTry" << ": " << final10thTry << std::endl;
    }  
};

class bowlingGame {
public:
    bowlingFrame bFrame[MAX_FRAME];
    void createData();
    void printData();
    void updateMapTries(int index, int key, int value) {
        bFrame[index].setMapTriesValue(key, value);
    }
    int getMapTries(int index, int key) {
        return bFrame[index].getMapTriesValue(key);
    }
    int getMapBonusTries(int index, int key) {
        return bFrame[index].getMapBonusTriesValue(key);
    }
    void setfinal10thTry(int index) {
        bFrame[index].setfinal10thTry();
    }
    //Generate random number less than 10
    int generateRandomNumber() {
        return (rand() % 11);
    }
    //Generate random number whose total is less than 10
    void generateRandomNumber(int& num1, int& num2) {
        // Seed the random number generator using the current time
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);

        // Define a uniform distribution for integers between 1 and 10 (inclusive)
        std::uniform_int_distribution<int> distribution(1, 10);

        // Loop until two numbers are generated whose sum is less than or equal to 10
        do {
            num1 = distribution(generator);
            num2 = distribution(generator);
        } while (num1 + num2 > 10);
        return;
    }
    void totalPointsPerFrame();
};


#ifdef USE_STATIC_DATA
void bowlingGame::createData()
{
    int index = 0;
    int arr_index = 0;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;   
    for(auto i:bFrame)
    {
        cout << "Begin index " << index << endl;
        if(index == (MAX_FRAME-1))
            setfinal10thTry(index);
        
        updateMapTries(index, BOWLING_TRY1, BOWLING_GAME_DATA[arr_index][STATIC_VALUE_INDEX]);
        updateMapTries(index, BOWLING_TRY2, BOWLING_GAME_DATA[arr_index+1][STATIC_VALUE_INDEX]);
        //if(BOWLING_GAME_DATA[arr_index][STATIC_VALUE_INDEX] == MAX_BONUS){ //BONUS_STRIKE
        if(getMapBonusTries(index, BONUS_STRIKE) == MAX_BONUS){ //BONUS_STRIKE
            updateMapTries(index, BOWLING_TRY1, BOWLING_GAME_DATA[arr_index+2][STATIC_VALUE_INDEX]);
            updateMapTries(index, BOWLING_TRY2, BOWLING_GAME_DATA[arr_index+3][STATIC_VALUE_INDEX]);
        }
        /*else if( (BOWLING_GAME_DATA[arr_index][STATIC_VALUE_INDEX] + 
            BOWLING_GAME_DATA[arr_index+1][STATIC_VALUE_INDEX]) == MAX_BONUS){ //BONUS_SPARE*/
        else if( getMapBonusTries(index, BONUS_SPARE) == MAX_BONUS){ //BONUS_SPARE
            updateMapTries(index, BOWLING_TRY1, 0);
            updateMapTries(index, BOWLING_TRY2, BOWLING_GAME_DATA[arr_index+2][STATIC_VALUE_INDEX]);
        }
        index++;arr_index += 2;
        cout << "ending index " << index << endl;
    }
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;   
}
#else
#if 0
void bowlingGame::createData()
{
    int index = 0;
    int count = 1;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;   
    for(auto i:bFrame)
    {
        cout << "Begin index " << index << endl;
        if(index == (MAX_FRAME-1))
            setfinal10thTry(index);
        
        updateMapTries(index, BOWLING_TRY1, generateRandomNumber());
        updateMapTries(index, BOWLING_TRY2, generateRandomNumber());
        if(getMapBonusTries(index, BONUS_STRIKE) == MAX_BONUS){ //BONUS_STRIKE
            updateMapTries(index, BOWLING_TRY1, generateRandomNumber());
            updateMapTries(index, BOWLING_TRY2, generateRandomNumber());
        }
        else if(getMapBonusTries(index, BONUS_SPARE) == MAX_BONUS){ //BONUS_SPARE
            updateMapTries(index, BOWLING_TRY1, 0);
            updateMapTries(index, BOWLING_TRY2, generateRandomNumber());
        }
        index++;count++;
        cout << "ending index " << index << endl;
    }
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;   
}
#else
void bowlingGame::createData()
{
    int index = 0;
    int count = 1;
    bool generateNextCycleNumbers = false;
    int num1, num2;
    generateRandomNumber(num1, num2);
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;   
    for(auto i:bFrame)
    {
        cout << "Begin index " << index << endl;

        if(index == (MAX_FRAME-1))
            setfinal10thTry(index);
        
        updateMapTries(index, BOWLING_TRY1, num1);
        updateMapTries(index, BOWLING_TRY2, num2);

        //Generate next round of data
        generateRandomNumber(num1, num2);

        if(getMapBonusTries(index, BONUS_STRIKE) == MAX_BONUS){ //BONUS_STRIKE
            updateMapTries(index, BOWLING_TRY1, num1);
            updateMapTries(index, BOWLING_TRY2, num2);
        }
        else if(getMapBonusTries(index, BONUS_SPARE) == MAX_BONUS){ //BONUS_SPARE
            updateMapTries(index, BOWLING_TRY1, 0);
            updateMapTries(index, BOWLING_TRY2, num1);
        }
        index++;count++;
        cout << "ending index " << index << endl;
    }
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;   
}
#endif
#endif

void bowlingGame::printData()
{
    int index = 0;
    cout << "##########################################################################################" << endl;   
    for(auto i:bFrame)
    {
        i.printMap();   
        cout << "#######" << endl  << endl;    
        index++;
    }
    cout << "##########################################################################################" << endl;    
}

void bowlingGame::totalPointsPerFrame()
{
    int index = 0;
    int totalBG = 0;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;   
    for(auto i:bFrame)
    {
        totalBG += getMapBonusTries(index, BONUS_STRIKE) + 
        getMapBonusTries(index, BONUS_SPARE) + 
        getMapTries(index, BOWLING_TRY1) +
        getMapTries(index, BOWLING_TRY2);
        cout << "^^^^^^^^^ totalBG " << std::dec << totalBG << endl;
        index++;
    }
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;   
}

int main()
{
    bowlingGame bG;

    //Passing fixed value pair data
    bG.createData();

    bG.printData();
    bG.totalPointsPerFrame();
    
    return 0;
}