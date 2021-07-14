#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H
#include <random>
#include <ctime>


class RandomNumber
{
public:
    RandomNumber();
    RandomNumber(int from, int to);
    RandomNumber(int to);
    ~RandomNumber();
    unsigned int getRandomNumber();
private:
    unsigned int randomNumber;
};

#endif // RANDOMNUMBER_H
