//
//  main.cpp
//  Final
//
//  Created by Robert Bradford on 5/8/18.
//  Copyright © 2018 Robert Bradford. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <srand>
#include "Queue.h"
#include <iomanip>

using namespace std;



int main()
{
    int timeForWash,
        minute,
        timeEnteredQueue,
        carsWashed = 0,
        totalQueueMin = 0,
        timeLeftOnCar = 0;
    float probOfArrival;
    
    Qobj carQueue;
    
    cout << "Enter Time to wash one car: ";
    cin >> timeForWash;
    cout << endl << "Enter the probability of arrival in any minute as a percent:";
    cin >> probOfArrival;
    
    carsWashed = 0;
    totalQueueMin = 0;
    timeLeftOnCar = 0;
    
    int n = 0;
    int total =0;
    double carMin = 0;
    
    srand(time(0));
    
    for ( minute = 1; minute <= 600 ; ++minute)
    {
        if ((rand() % 100) +1 <= probOfArrival)
        {
            carQueue.enQueue(minute);
        }
        
        if ((timeLeftOnCar== 0) && !carQueue.isEmpty())
        {
            timeEnteredQueue = carQueue.front();
            carQueue.deQueue();
            totalQueueMin = totalQueueMin + (minute - timeEnteredQueue);
            ++carsWashed;
            timeLeftOnCar = timeForWash;
        }
        
        if  ((timeLeftOnCar== 0) && carQueue.isEmpty())
            n++;
        
        if (timeLeftOnCar != 0)
            --timeLeftOnCar;
        
    }
    
    if (timeLeftOnCar != 0)
        total = (carsWashed + 1);
    else
        total = carsWashed;
    
    cout << endl << carsWashed << " cars were completely washed" << endl;
    cout << setiosflags(ios::fixed | ios::showpoint);
    cout << "Average wait in queue: "  << setprecision(2)
    << totalQueueMin/600  << endl;
    cout << carQueue.length() << " cars were left in the Queue" << endl;
    cout << "Time left on car in wash: " << timeLeftOnCar << endl;
    cout << "Total cars washed: " << total << endl;
    cout << "Total Wash Idle Time: " << n << " minutes" << endl;
    cout << "Total average for All cars: "
    << float(totalQueueMin)/(carsWashed+carQueue.length()) << endl << endl << endl;

    return 0;
}
