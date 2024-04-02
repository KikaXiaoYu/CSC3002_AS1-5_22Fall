/* Q1:
 * File: calendar.cpp
 * ------------------
 * This file implements the calendar.h interface
 */

#include <string>
#include <iostream>
#include "csc300222fall/assignment2/lib.h"
#include "csc300222fall/assignment2/calendar.h"

using namespace std;

Month stringToMonth(string s)
{
   if (s == "JANUARY") {
      return JANUARY;
   }
   if (s == "FEBRUARY") {
      return FEBRUARY;
   }
   if (s == "MARCH") {
      return MARCH;
   }
   if (s == "APRIL") {
      return APRIL;
   }
   if (s == "MAY") {
      return MAY;
   }
   if (s == "JUNE") {
      return JUNE;
   }
   if (s == "JULY") {
      return JULY;
   }
   if (s == "AUGUST") {
      return AUGUST;
   }
   if (s == "SEPTEMBER") {
      return SEPTEMBER;
   }
   if (s == "OCTOBER") {
      return OCTOBER;
   }
   if (s == "NOVEMBER") {
      return NOVEMBER;
   }
   if (s == "DECEMBER") {
      return DECEMBER;
   }
}

/* TODO PART:
 * Implementation notes: monthToString
 * -----------------------------------
 * The monthToString function must return some value if the month does not
 * match any of the enumeration constants.  Here, as in the Direction
 * type, the function returns ???.
 */
string monthToString(Month month)
{
   // TO DO - Finished
   switch (month) {
      case JANUARY:
         return "JANUARY";
      case FEBRUARY:
         return "FEBRUARY";
      case MARCH:
         return "MARCH";
      case APRIL:
         return "APRIL";
      case MAY:
         return "MAY";
      case JUNE:
         return "JUNE";
      case JULY:
         return "JULY";
      case AUGUST:
         return "AUGUST";
      case SEPTEMBER:
         return "SEPTEMBER";
      case OCTOBER:
         return "OCTOBER";
      case NOVEMBER:
         return "NOVEMBER";
      case DECEMBER:
         return "DECEMBER";
      default:
         return "???";
   }
}

Month operator++(Month &month, int)
{
   // TODO - Finished
   if (month == DECEMBER) {
      month = JANUARY;
   } else {
      month = Month(month + 1);
   }
   return month;
}


/*
 * Implementation notes: Constructors
 * ----------------------------------
 * There are three constructors for the Date class.  The default
 * constructor creates a Date with a zero internal value that must
 * be assigned a new value before it is used.  The others initialize
 * the date from the arguments by calling the private initDate method.
 */

Date::Date()
{
   initDate(1, JANUARY, 1900);
}

Date::Date(int day, Month month, int year)
{
   initDate(day, month, year);
}

Date::Date(Month month, int day, int year)
{
   initDate(day, month, year);
}

/*
 * TODO function
 * Implementation notes: getDay, getMonth
 * --------------------------------------
 * In this implementation of the Date class, the day and the month are
 * not stored explicitly but must instead be computed from the dayInYear
 * field.
 */

int Date::getDay()
{
   // TODO - Finished
   return day;
}

/*
 * TODO function
 * Method: getMonth
 * Usage: Month month = date.getMonth();
 * -------------------------------------
 * Returns the month.
 */

Month Date::getMonth()
{
   // TODO - Finished
   return month;
}

int Date::getYear()
{
   // TODO - Finished
   return year;
}

/*
 * TODO function
 * Implementation notes: toString
 * ------------------------------
 * The toString method uses the getters to perform the translation into
 * day/month/year values.
 */

string Date::toString()
{
   // TODO - Finished
   string day_str = to_string(getDay());
   string month_str = capitalize(monthToString(getMonth()));
   string year_str = to_string(getYear());
   while (year_str.length() < 4) {
      year_str = "0" + year_str;
   }
   string res = day_str + "-" + month_str + "-" + year_str;
   return res;
}

string Date::capitalize(string str)
{
   // TODO - Finished
   switch (month) {
      case JANUARY:
         return "Jan";
      case FEBRUARY:
         return "Feb";
      case MARCH:
         return "Mar";
      case APRIL:
         return "Apr";
      case MAY:
         return "May";
      case JUNE:
         return "June";
      case JULY:
         return "Jul";
      case AUGUST:
         return "Aug";
      case SEPTEMBER:
         return "Sep";
      case OCTOBER:
         return "Oct";
      case NOVEMBER:
         return "Nov";
      case DECEMBER:
         return "Dec";
      default:
         return "???";
   }

}

void Date::initDate(int day, Month month, int yyyy)
{
   // TODO -Finished
   this->day = day;
   this->month = month;
   this->year = yyyy;
   int res = 0;
   for (int i = 1; i != month; i++) {
      res += daysInMonth(Month(i), yyyy);
   }
   res += day;
   this->dayInYear = res; 
}

Date operator+(Date date, int delta)
{
   int day = date.getDay();
   Month month = date.getMonth();
   int year = date.getYear();
   int delta_day = delta;
   int total_day = day + delta_day;

   while (true) {
      int day_in_month = daysInMonth(month, year);
      if (total_day > day_in_month) { // exceed the maximun
         total_day -= day_in_month; // reduce the rest of month
         if (month == DECEMBER) { 
            year++; // the next year
            month = JANUARY;
         } else {
            month++; // the next month
         }
      } else {
         break;
      }
   }
   day = total_day;
   return Date(day, month, year);

}

Date operator-(Date date, int delta)
{
   int day = date.getDay();
   Month month = date.getMonth();
   int year = date.getYear();
   int delta_day = delta;
   int total_day = day - delta_day;

   while (true) {
      int day_in_month = daysInMonth(month, year);
      if (total_day <= 0) { // exceed the minimun
         if (month == JANUARY) { 
            month = DECEMBER;
            year--; // the next year
         } else {
            month = Month((month - 1)); // the next month
         }
         total_day += daysInMonth(month, year); // reduce the rest of month
      } else {
         break;
      }
   }
   day = total_day;
   return Date(day, month, year);
}

int operator-(Date d1, Date d2)
{
   Date big_d = d1;
   Date small_d = d2;
   if (big_d.getYear() < small_d.getYear()) {
      Date tmp = big_d;
      big_d = small_d;
      small_d = tmp;
   }
   // get the idx of d1
   int idx1 = 0;
   for (int i = 1; i < small_d.getMonth(); i++) {
      idx1 += daysInMonth(Month(i), small_d.getYear());
   }
   idx1 += small_d.getDay();
   // get the idx of d2
   int idx2 = 0;
   for (int i = 1; i < big_d.getMonth(); i++) {
      idx2 += daysInMonth(Month(i), big_d.getYear());
   }
   idx2 += big_d.getDay();
   // get the final diff
   int res = 0;
   res += idx2 - idx1;
   for (int i = small_d.getYear(); i < big_d.getYear(); i++) {
      res += 365;
      if (isLeapYear(i)) {
         res++;
      }
   }
   return (res);


}

Date &operator+=(Date &date, int delta)
{
   Date new_date = date + delta;
   date = Date(new_date.getDay(), new_date.getMonth(), new_date.getYear());
   return date;

}

Date &operator-=(Date &date, int delta)
{
   Date new_date = date - delta;
   date = Date(new_date.getDay(), new_date.getMonth(), new_date.getYear());
   return date;
  
}

Date operator++(Date &date)
{
   Date new_date = date + 1;
   date = Date(new_date.getDay(), new_date.getMonth(), new_date.getYear());
   return date;

}

Date operator++(Date &date, int)
{
   Date old_date = Date(date.getDay(), date.getMonth(), date.getYear());
   Date new_date = date + 1;
   date = Date(new_date.getDay(), new_date.getMonth(), new_date.getYear());
   return old_date;
}

Date operator--(Date &date)
{
   Date new_date = date - 1;
   date = Date(new_date.getDay(), new_date.getMonth(), new_date.getYear());
   return date;
}

Date operator--(Date &date, int)
{
   Date old_date = Date(date.getDay(), date.getMonth(), date.getYear());
   Date new_date = date - 1;
   date = Date(new_date.getDay(), new_date.getMonth(), new_date.getYear());
   return old_date;
}

bool operator==(Date d1, Date d2)
{
   if (d1.getYear() == d2.getYear()) {
      if (d1.getMonth() == d2.getMonth()) {
         if (d1.getDay() == d2.getDay()) {
            return true;
         }
      }
   }
   return false;
}

bool operator!=(Date d1, Date d2)
{
   return !(d1 == d2);
}

bool operator<(Date d1, Date d2)
{
   if (d1.getYear() > d2.getYear()) {
      return false;
   }
   if (d1.getYear() < d2.getYear()) {
      return true;
   }
   if (d1.getMonth() > d2.getMonth()) {
      return false;
   }
   if (d1.getMonth() < d2.getMonth()) {
      return true;
   }
   if (d1.getDay() >= d2.getDay()) {
      return false;
   } else {
      return true;
   }
}

bool operator<=(Date d1, Date d2)
{
   return (d1 < d2) || (d1 == d2); 
}

bool operator>(Date d1, Date d2)
{
   return !(d1 <= d2);
}

bool operator>=(Date d1, Date d2)
{
   return !(d1 < d2);
}


std::ostream &operator<<(std::ostream &os, Date date){
   os << date.toString();
   return os;
}

/*
 * TODO function
 * Implementation notes: daysInMonth
 * ---------------------------------
 * This function is a reasonably literal translation of the old rhyme:
 *
 *    Thirty days has September
 *    April, June, and November
 *    All the rest have 31
 *    Excepting February alone
 *    Which has 28 in fine
 *    And each leap year 29
 */

int daysInMonth(Month month, int year)
{
   // TODO - Finished
   switch (month) {
      case JANUARY: case MARCH: case MAY:
      case JULY: case AUGUST: case OCTOBER:
      case DECEMBER:
         return 31;
      case FEBRUARY:
         if (isLeapYear(year)) {
            return 29;
         } else {
            return 28;
         }
      case APRIL: case JUNE: 
      case SEPTEMBER: case NOVEMBER:
         return 30;
      default:
         return 0;
   return 0;
   }
}

/* TODO PART:
 * Implementation notes: isLeapYear
 * --------------------------------
 * This function simply encodes the rule for determining leap years:
 * a leap year is any year divisible by 4, except for years ending in 00,
 * in which case the year must be divisible by 400.
 */

bool isLeapYear(int year)
{
   // TO DO - Finished
   if (year % 4 == 0 && year % 100 != 0) {
      return true;
   }
   return false;
}

/* DO NOT modify this main() part */
int main()
{
   int id;
   cin >> id;
   int day, year;
   string mon;
   cin >> day >> mon >> year;

   if (id == 1)
   {
      for (Month month = JANUARY; month <= DECEMBER; month = Month(month + 1))
      {
         cout << monthToString(month) << " has " << daysInMonth(month, year)
              << " days." << endl;
      }
   }
   else if (id == 2)
   {  
      Date moonLanding(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding.toString() << endl;
   }
   else if (id == 3)
   {
      Date moonLanding(day, stringToMonth(mon), year);
      cin >> mon >> day >> year;
      Date kennedyAssassination(stringToMonth(mon), day, year);
      cin >> mon >> day >> year;
      Date newYearsEve(stringToMonth(mon), day, year);
      cin >> day >> mon >> year;
      Date inaugurationDay(day, stringToMonth(mon), year);
      cin >> day >> mon >> year;
      Date electionDay(day, stringToMonth(mon), year);
      cout << "moonLanding = " << moonLanding << endl;
      cout << "kennedyAssassination = " << kennedyAssassination << endl;
      cout << boolalpha;
      cout << "moonLanding < kennedyAssassination = "
           << (moonLanding < kennedyAssassination) << endl;
      cout << "moonLanding > kennedyAssassination = "
           << (moonLanding > kennedyAssassination) << endl;
      cout << "moonLanding == kennedyAssassination = "
           << (moonLanding == kennedyAssassination) << endl;
      cout << "moonLanding == moonLanding = "
           << (moonLanding == moonLanding) << endl;
      cout << "inaugurationDay - electionDay = "
           << (inaugurationDay - electionDay) << endl;
      Date day = newYearsEve;
      cout << "New Year's Eve = " << day++ << endl;
      cout << "New Year's Day = " << day << endl;
      for (Date d = electionDay; d <= inaugurationDay; d++)
      {
         cout << d << endl;
      }
   }
}

