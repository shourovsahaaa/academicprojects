/*
Author: Shourov Saha
Course: CSCI-136
Instructor: Melissa Lynch
Assignment: Lab10B 

Takes two times,
calculates the minutes since midnight, 
and calculates the time elapsed between the
two times.

Creates a movies addon to the code.
Creates a class movies which includes
name, genre, and duration.

Creates a timeslot using the name of a movie
and the time it begins playing.
*/
#include <iostream>
using namespace std;

class Time 
{ 
public:
    int h;
    int m;
};

void printTime(Time time) 
{
    cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time)
{
    int minutes = 0;
    minutes += time.h * 60;
    minutes += time.m;
    return minutes;
}

int minutesUntil(Time earlier, Time later)
{
    int minutes = 0;
    int hoursdifference = later.h - earlier.h;
    minutes += hoursdifference * 60;
    minutes += later.m - earlier.m;
    return minutes;
}

Time addMinutes(Time time0, int min)
{
    time0.m += min;
    while (time0.m >= 60)
    {
        time0.m -= 60;
        time0.h += 1;
    }
    return time0;
}

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie 
{ 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot 
{ 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

void printMovie(Movie mv)
{
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{
    Time time1 = ts.startTime;
    Movie placeholder = ts.movie;
    int x = placeholder.duration;
    printMovie(ts.movie); 
    cout << " [starts at " << time1.h <<":"<<time1.m<<", ends by ";
    Time time2 = addMinutes(time1, x);
    cout << time2.h <<":"<<time2.m<<"]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    Movie placeholder = ts.movie;
    Time time1 = ts.startTime;
    int x = placeholder.duration;
    ts.movie = nextMovie;
    ts.startTime = addMinutes(time1, x);
    return ts;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    Time time1 = ts1.startTime;
    Time time2 = ts2.startTime;
    int min = minutesSinceMidnight(time1);
    int min2 = minutesSinceMidnight(time2);
    Movie placeholder = ts1.movie;
    int x = placeholder.duration;
    Movie placeholder2 = ts2.movie;
    int x2 = placeholder2.duration;
    if (min + x < min2 || min2 + x2 < min)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}
int main()
{
    

    return 0;
}
