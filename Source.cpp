/*
Program name: NumDays.cpp
Programmer: Tyler Davies
Date: 10-9-21
Version: 1.0
Description: This program contains a class called NumDays, which stores a value representing the
             number of work hours and converts it to number of days. The main program tests the
             NumDays class.
*/

#include<iostream>

using namespace std;

/*
NumDays class has a constructor that accepts number of hours, member functions for updating and
retrieving hours and days, and overloaded functions for the addition, subtraction, and incremental/
decremental prefix and postfix operators.
*/
class NumDays
{
private:
    int hours;
    float days;
    float hoursToDays(int h)    //There are 8 hours in one work day.
        { return h / 8.0F; }    //Appended F tells compiler to store/handle value as a float (Gaddis, Starting Out With C++, pg. 55)
public:
    NumDays()
    {
        hours = 0;
        days = hoursToDays(hours);
    }
    NumDays(int h)    //This constructor accepts number of hours.
    {
        hours = h;
        days = hoursToDays(hours);
    }
    //This function updates hours, and updates days automatically.
    void setHours(int h)
    {
        hours = h;
        days = hoursToDays(hours);
    }
    /*
    This function updates days, then outputs a warning to the user that the hours listed is no
    longer valid. Depending on the user's input (since hours is an integer for incremental/
    decremental purposes), hours cannot be updated based on the input value for days (a float).
    */
    void setDays(float d)
    {
        days = d;
        cout << "Warning: Days manually updated; Hours listed is no longer valid!" << endl;
    }
    int getHours()
        { return hours; }
    float getDays()
        { return days; }
    NumDays operator+(const NumDays&);
    NumDays operator-(const NumDays&);
    NumDays operator++();
    NumDays operator++(int);
    NumDays operator--();
    NumDays operator--(int);
    ~NumDays() {}
};

/*
This function overrides the addition (+) operator. Since it is a member of the class, it uses one
object to call the function and passes the other object's reference as a constant; this saves memory
(over pass-by-value), and const keyword ensures the original value is not changed. When two NumDays 
objects are added together, this operator returns an object with the sum of the two objects’ hours members. 
*/
NumDays NumDays::operator+(const NumDays& obj)
{
    NumDays temp;
    temp = this->hours + obj.hours;
    temp.hoursToDays(hours);
    return temp;
}

/*
This function overrides the subtraction (-) operator.  Since it is a member of the class, it uses one
object to call the functionand passes the other object's reference as a constant; this saves memory (over
pass - by - value), and const keyword ensures the original value is not changed. When one NumDays object
is subtracted from another, this operator returns an object with the difference of the two objects’ hours members.
*/
NumDays NumDays::operator-(const NumDays& obj)
{
    NumDays temp;
    temp = this->hours - obj.hours;
    temp.hoursToDays(hours);
    return temp;
}

//This function overrides the prefix incremental (++) operator. It increments the number of hours
//stored in the object, and automatically recalculates number of days.
NumDays NumDays::operator++()
{
    ++hours;
    days = hoursToDays(hours);
    return *this;
}

//This function overrides the postfix incremental (++) operator. It increments the number of hours
//stored in the object, and automatically recalculates number of days.
NumDays NumDays::operator++(int val)
{
    NumDays temp(hours);
    hours++;
    days = hoursToDays(hours);
    return temp;
}

//This function overrides the prefix decremental (--) operator. It decrements the number of hours
//stored in the object, and automatically recalculates number of days.
NumDays NumDays::operator--()
{
    --hours;
    days = hoursToDays(hours);
    return *this;
}

//This function overrides the postfix decremental (--) operator. It decrements the number of hours
//stored in the object, and automatically recalculates number of days.
NumDays NumDays::operator--(int val)
{
    NumDays temp(hours);
    hours--;
    days = hoursToDays(hours);
    return temp;
}

//The main function tests the NumDays class. It outputs the code statements tested,
//then outputs the objects' hours and days.
int main()
{
    NumDays empl1(40), empl2(10), empl3;    //empl is a general abbreviation for employee

    cout << "Statement: NumDays empl1(40)" << endl;
    cout << "empl1:" << endl;
    cout << "\tHours = " << empl1.getHours() << endl;
    cout << "\tDays = " << empl1.getDays() << endl << endl;

    cout << "Statement: NumDays empl2(10)" << endl;
    cout << "empl2:" << endl;
    cout << "\tHours = " << empl2.getHours() << endl;
    cout << "\tDays = " << empl2.getDays() << endl << endl;

    cout << "Statement: empl3 = empl1 + empl2" << endl;
    empl3 = empl1 + empl2;
    cout << "empl3:" << endl;
    cout << "\tHours = " << empl3.getHours() << endl;
    cout << "\tDays = " << empl3.getDays() << endl << endl;

    cout << "Statement: empl3 = empl1 - empl2" << endl;
    empl3 = empl1 - empl2;
    cout << "empl3:" << endl;
    cout << "\tHours = " << empl3.getHours() << endl;
    cout << "\tDays = " << empl3.getDays() << endl << endl;
        
    cout << "Statement: empl3 = empl1++" << endl;
    empl3 = empl1++;
    cout << "empl1:" << endl;
    cout << "\tHours = " << empl1.getHours() << endl;
    cout << "\tDays = " << empl1.getDays() << endl;
    cout << "empl3:" << endl;
    cout << "\tHours = " << empl3.getHours() << endl;
    cout << "\tDays = " << empl3.getDays() << endl << endl;

    cout << "Statement: empl3 = ++empl2" << endl;
    empl3 = ++empl2;
    cout << "empl2:" << endl;
    cout << "\tHours = " << empl2.getHours() << endl;
    cout << "\tDays = " << empl2.getDays() << endl;
    cout << "empl3:" << endl;
    cout << "\tHours = " << empl3.getHours() << endl;
    cout << "\tDays = " << empl3.getDays() << endl << endl;

    cout << "Statement: empl3 = empl1--" << endl;
    empl3 = empl1--;
    cout << "empl1:" << endl;
    cout << "\tHours = " << empl1.getHours() << endl;
    cout << "\tDays = " << empl1.getDays() << endl;
    cout << "empl3:" << endl;
    cout << "\tHours = " << empl3.getHours() << endl;
    cout << "\tDays = " << empl3.getDays() << endl << endl;

    cout << "Statement: empl3 = --empl2" << endl;
    empl3 = --empl2;
    cout << "empl2:" << endl;
    cout << "\tHours = " << empl2.getHours() << endl;
    cout << "\tDays = " << empl2.getDays() << endl;
    cout << "empl3:" << endl;
    cout << "\tHours = " << empl3.getHours() << endl;
    cout << "\tDays = " << empl3.getDays() << endl << endl;

    cout << "Statement: empl3.setHours(60)" << endl;
    empl3.setHours(60);
    cout << "empl3:" << endl;
    cout << "\tHours = " << empl3.getHours() << endl;
    cout << "\tDays = " << empl3.getDays() << endl << endl;

    cout << "Statement: empl3.setDays(6)" << endl;
    empl3.setDays(6);
    cout << "\tHours = " << empl3.getHours() << endl;
    cout << "\tDays = " << empl3.getDays() << endl << endl;

    exit(0);
}