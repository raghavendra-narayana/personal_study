//https://stackoverflow.com/questions/33421777/c-bowling-simulator-program
#include <iostream>
#include <vector>

// Simplified function to calculate bowling score for a given set of throws
int calculateBowlingScore(const std::vector<int>& throws) {
    int totalScore = 0;
    int throwIndex = 0;

    for (int frame = 0; frame < 10; ++frame) {
        if (throws[throwIndex] == 10) { // Strike
            totalScore += 10 + throws[throwIndex + 1] + throws[throwIndex + 2];
            throwIndex += 1; // Move to the next frame's first throw
        } else if (throws[throwIndex] + throws[throwIndex + 1] == 10) { // Spare
            totalScore += 10 + throws[throwIndex + 2];
            throwIndex += 2; // Move to the next frame's first throw
        } else { // Open frame
            totalScore += throws[throwIndex] + throws[throwIndex + 1];
            throwIndex += 2; // Move to the next frame's first throw
        }
    }
    return totalScore;
}

int main() {
    // Example throws for a perfect game (12 strikes)
    std::vector<int> perfectGameThrows = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}; 
    std::cout << "Perfect game score: " << calculateBowlingScore(perfectGameThrows) << std::endl;

    // Example throws for a spare in the first frame, then open frames
    std::vector<int> exampleThrows = {5, 5, 7, 2, 8, 1, 6, 3, 9, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
    std::cout << "Example game score: " << calculateBowlingScore(exampleThrows) << std::endl;

    return 0;
}