#include <map>
#include <string>
#include <iostream>

using namespace std;

#define MAX_FRAME 10
#define BOWLING_TRY1 "keyTries1"
#define BOWLING_TRY2 "keyTries2"
#define BONUS_SPARE "keyBonusTries1"
#define BONUS_STRIKE "keyBonusTries2"
#define BONUS_10TH_TRY "keyBonusTries3"
#define NEW_KEY "newKey"
static int gcount = 10;


class bowlingFrame {
private:
    std::map<std::string, int> myMapTries;
    std::map<std::string, int> myMapBonusTries;

public: // Or public, depending on desired access level
    void setMapTriesValue(const std::string& key, int value) {
        myMapTries[key] = value;
        cout << " setMapTriesValue print " << key << " : " << getMapTriesValue(key) << endl;
    }
    void setMapBonusTriesValue(const std::string& key, int value) {
        myMapBonusTries[key] = value;
        cout << " setMapBonusTriesValue print " << key << " : " << getMapBonusTriesValue(key) << endl;
    }
    int getMapTriesValue(const std::string& key) {
        cout << " getMapTriesValue print " << key << " : " << myMapTries[key] << endl;
        return myMapTries[key];
    }
    int getMapBonusTriesValue(const std::string& key) {
        cout << " getMapBonusTriesValue print " << key << " : " << myMapBonusTries[key] << endl;
        return myMapBonusTries[key];
    }

public:
    bowlingFrame() {
        myMapTries[BOWLING_TRY1] = 4;
        myMapTries[BOWLING_TRY2] = 5;

        myMapBonusTries[BONUS_SPARE] = 6;
        myMapBonusTries[BONUS_STRIKE] = 7;
        myMapBonusTries[BONUS_10TH_TRY] = 8;
    }

    void printMap() const {
        for (const auto& pair : myMapTries) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
        for (const auto& pair : myMapBonusTries) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};

class bowlingGame {
public:
    void updateMapTriesFromBG(int index, const std::string& key, int value) {
        bFrame[index].setMapTriesValue(key, value); // Call base class setter
    }
    void updateMapBonusTriesFromBG(int index, const std::string& key, int value) {
        bFrame[index].setMapBonusTriesValue(key, value); // Call base class setter
    }
    void createData();
    void printData();
    bowlingFrame bFrame[MAX_FRAME];
};

void bowlingGame::createData()
{
    int count = 0;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;   
    for(auto i:bFrame)
    {
        updateMapTriesFromBG(count, BOWLING_TRY1, count);
        updateMapTriesFromBG(count, BOWLING_TRY2, count);

        updateMapBonusTriesFromBG(count, BONUS_SPARE, count);
        updateMapBonusTriesFromBG(count, BONUS_STRIKE, count);
        updateMapBonusTriesFromBG(count, BONUS_10TH_TRY, count);
        count++;
    }
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;   
}
void bowlingGame::printData()
{
    int count = 0;
    cout << "############################################################################################" << endl;      
    for(auto i:bFrame)
    {
        i.printMap();
        count++;
    }
    cout << "############################################################################################" << endl;      
}

int main() {
    bowlingGame d;
    std::cout << "Original map:" << std::endl;
    d.createData();
    d.printData();

    std::cout << "\nUpdated map:" << std::endl;
    d.printData();

    return 0;
}