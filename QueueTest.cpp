#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>

static const int NUMBER_COUNT = 50;
static const int DIGIT_COUNT = 10;

void radixSort(std::queue<int> *queues, int *numbers);

int main()
{
    // srand(time(0));
    
    std::queue<int> radixQueues[DIGIT_COUNT];

    int num[NUMBER_COUNT];

    for (int i = 0; i < NUMBER_COUNT; ++i)
    {
        num[i] = (rand() % 1000);
        if (num[i] < 889) num[i] += 111;
        std::cout <<num[i];
        if (i < NUMBER_COUNT) std::cout <<" ";
        if (i % 10 == 9) std::cout <<"\n";
    }
    
    std::cout <<"\n";
    radixSort(radixQueues, num);
    
    for (int i = 0; i < NUMBER_COUNT; ++i)
    {
        std::cout <<num[i];
        if (i < NUMBER_COUNT) std::cout <<" ";
        if (i % 10 == 9) std::cout <<"\n";
    }

    return 0;
}

void radixSort(std::queue<int> *queues, int *numbers)
{
    for (int i = 0; i < NUMBER_COUNT; ++i)
    {
        int rightSignificantDigit = 0;
        
        rightSignificantDigit = numbers[i] % 10;
        queues[rightSignificantDigit].push(numbers[i]);
    }
    
    int j = 0;
    for (int i = 0; i < DIGIT_COUNT; ++i)
    {
        while (!queues[i].empty())
        {
            numbers[j++] = queues[i].front();
            queues[i].pop();
        }
    }

    for (int i = 0; i < NUMBER_COUNT; ++i)
    {
        int rightSignificantDigit = 0;
        
        rightSignificantDigit = (numbers[i] % 100) / 10;
        queues[rightSignificantDigit].push(numbers[i]);
    }
    
    j = 0;
    for (int i = 0; i < DIGIT_COUNT; ++i)
    {
        while (!queues[i].empty())
        {
            numbers[j++] = queues[i].front();
            queues[i].pop();
        }
    }

    for (int i = 0; i < NUMBER_COUNT; ++i)
    {
        int rightSignificantDigit = 0;
        
        rightSignificantDigit = (numbers[i] % 1000) / 100;
        queues[rightSignificantDigit].push(numbers[i]);
    }
    
    j = 0;
    for (int i = 0; i < DIGIT_COUNT; ++i)
    {
        while (!queues[i].empty())
        {
            numbers[j++] = queues[i].front();
            queues[i].pop();
        }
    }
}