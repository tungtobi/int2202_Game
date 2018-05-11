#ifndef DATA_H_
#define DATA_H_

#include <iostream>
#include <fstream>
#include <ios>

const char* dataFile = "score.data";

int loadData()
{
    std::ifstream input(dataFile);
    unsigned int bestScore = 0;
    if (input)
    {
        input >> bestScore;
    }
    input.close();
    return bestScore;
}

void updateData(int score)
{
    std::ofstream output(dataFile);
    output << score;
    output.close();
}

#endif // DATA_H_
