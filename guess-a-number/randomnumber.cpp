#include "randomnumber.h"


RandomNumber::RandomNumber()
{
    // Initialize our mersenne twister with a random seed based on the clock
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr))};

    // Create a reusable random number generator that generates uniform numbers between 1 and 100
    std::uniform_int_distribution<> die{1, 100};

    // Set a random number
    randomNumber = die(mersenne);
}

RandomNumber::RandomNumber(int from, int to)
{
    // Initialize our mersenne twister with a random seed based on the clock
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr))};

    // Create a reusable random number generator that generates uniform numbers between 1 and 100
    std::uniform_int_distribution<> die{from, to};

    // Set a random number
    randomNumber = die(mersenne);
}

RandomNumber::RandomNumber(int to)
{
    // Initialize our mersenne twister with a random seed based on the clock
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr))};

    // Create a reusable random number generator that generates uniform numbers between 1 and 100
    std::uniform_int_distribution<> die{1, to};

    // Set a random number
    randomNumber = die(mersenne);
}

RandomNumber::~RandomNumber()
{
}

unsigned int RandomNumber::getRandomNumber() {
    return randomNumber;
}
