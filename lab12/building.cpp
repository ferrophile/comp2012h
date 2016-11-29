#define MY_NAME "My name"

//building.cpp

#include <iostream>  //Library file so uses <>
#include "building.h"      //User Defined so uses ""

using namespace std;

#define NUM_OF_FLOOR 3
#define NUM_OF_ROOM 5

building::building()
: names(NUM_OF_FLOOR, vector<string>(NUM_OF_ROOM)),
  ids(NUM_OF_FLOOR, vector<string>(NUM_OF_ROOM))
{
}

building::building(const char theName[], const char theID[])
: names(1, vector<string>(1)),
  ids(1, vector<string>(1))
{
  names[0][0] = theName;
  ids[0][0] = theID;
}

void building::Put(const char s[], const char ID[], int f, int n)
{
  if (!IsValid(f, n)) return;
  names[f][n] = s;
  ids[f][n] = ID;
}

void building::Empty(int f, int r)
{
  if (!IsValid(f, r)) return;
  names[f][r] = "";
  ids[f][r] = "";
}

void building::Display(int f, int r)
{
  if (IsValid(f, r)) {
    if (names[f][r] == "")
    {
      cout << "Room " << r << " on floor " << f << " is empty" << endl;
    }
    else 
    {
      cout << "Occupant of Room " << r << " on floor " << f;
      cout << " is " << names[f][r];
      cout << ", Identity number "  << ids[f][r] << endl;
    }
  }
}

void building::Display(int f)
{
  if (IsValidFloor(f)) {
    int nonEmptyRoom = 0;
    
    for(int r = 0; r < NUM_OF_ROOM; r++) {
      if (names[f][r] != "")
      {
        nonEmptyRoom++;
        cout << "Occupant of Room " << r << " on floor " << f;
        cout << " is " << names[f][r];
        cout << ", Identity number "  << ids[f][r] << endl;
      }
    }

    if (nonEmptyRoom == 0)
      cout << "Floor " << f << " is empty" << endl;
  }
}

void building::Display()
{
  int nonEmptyRoom = 0;
  for (int f = 0; f < NUM_OF_FLOOR; f++) {
    for(int r = 0; r < NUM_OF_ROOM; r++) {
      if (names[f][r] != "")
      {
        nonEmptyRoom++;
        cout << "Occupant of Room " << r << " on floor " << f;
        cout << " is " << names[f][r];
        cout << ", Identity number "  << ids[f][r] << endl;
      }
    }
  }
  if (nonEmptyRoom == 0)
    cout << "The building is empty" << endl;
}

int building::Vacancies(int f) const
{
  int ct = 0;
  if (IsValidFloor(f)) {
	  vector<string>::const_iterator i;
	  for (i = names[f].begin(); i != names[f].end(); ++i)
		  if (*i == "") ct++; 
  }
  return ct;
}

int building::Vacancies() const
{ 
  int bldct = 0;
  for (int b=0; b < NUM_OF_FLOOR; b++)
	  bldct += Vacancies(b);
  return bldct;
}

ostream& operator<<(ostream& os, const building& b) 
{
  vector< vector<string> >::const_iterator n;
  vector<string>::const_iterator i;
  for (n = b.names.begin(); n != b.names.end(); ++n)
    for (i = n->begin(); i != n->end(); ++i)
      os << *i << ' ';	
  return os;
}

bool operator==(const building& b1, const building& b2)
{
  return b1.Vacancies() == b2.Vacancies();
}

void building::Identify_Writer()
{
  cout << MY_NAME << "\t12345678\t1\t1A" << endl;
}

bool building::IsValidFloor(int f) const {
  bool valid = ((0 <= f) && (f < NUM_OF_FLOOR));
  if (! valid) {
    cerr << "Floor " << f << " is out of range!\n";
  }
  return valid;
};

bool building::IsValidRoom(int r) const {
  bool valid = ((0 <= r) && (r < NUM_OF_ROOM));
  if (! valid) {
    cerr << "Room " << r << " is out of range!\n";
  }
  return valid;
};

bool building::IsValid(int f, int r) const {
  return IsValidFloor(f) && IsValidRoom(r);
};
