/**********************************************************************
 *  Pattern Recognition readme.txt template
 **********************************************************************/

Name:             Hong Wing PANG
Login:            hwpang
Hours to complete assignment (optional):
Around 15 hours


/**********************************************************************
 *  Step 1.  Explain briefly how you implemented brute force.
 *           What method(s) did you add to the Point data type?
 **********************************************************************/
4 for loops.

I mostly did a lot of operator overloading, such as comparison
operators for the purpose of sorting, and (magnitude of) cross product
vector for doing Brute. These are mostly done in the Vector2D class
which Point inherits.


/**********************************************************************
 *  Step 2.  Explain briefly how you implemented the sorting solution.
 *           Did you sort by angle, slope, or something else?
 *           What method(s) did you add to the Point data type?
 *           What steps did you do to print a minimal representation?
 **********************************************************************/
I sorted by angles in radian, because firstly I can directly use atan()
in <cmath>, and secondly the opposite directions of a same line will
be represented by the same radian value. In Point, I also implemented a
radian getter for the aforementioned sorting algorithm.

Using the method outlined in course website will lead to the lines
recorded being duplicated, as each point in the line is being
checked once. Therefore I sorted the whole list to group duplicates
together, so that I can skip them and obtain unique entries.


/**********************************************************************
 *  Empirical    Fill in the table below with actual running times in
 *  Analysis     seconds when reasonable (say 180 seconds or less).
 *               You can round to the nearest tenth of a second.
 **********************************************************************/

      N       brute       sorting
---------------------------------
     10       0.001       0.000
     20       0.020       0.000
     40       0.368       0.000
     80       5.888       0.002
    100       14.38       0.004
    150       72.77       0.008
    200       >180        0.035
    400       >180        0.280
   1000       >180        4.375
   2000       >180        35.00
   4000       >180        >180
  10000       >180        >180  


/**********************************************************************
 *  Estimate how long it would take to solve an instance of size
 *  N = 1,000,000 for each of the two algorithms using your computer.
 **********************************************************************/
Brute: Using N=100: 1.438E17 sec -> 4.560E9 yrs
Sorting: Using N=1000: 4.375E9 sec -> 138.7 yrs


/**********************************************************************
 *  Theoretical   Give the worst-case running time of your programs
 *  Analysis      as a function of N. Justify your answer briefly.
 **********************************************************************/
Following analysis assume std::sort() as O(N^2).
Brute: ~O(N^4)
4 for loops give rise to O(N^4).
Sorting: ~O(N^3)
N^3 appears twice.
- For loop through each vertex, std::sort() for each one
- For loop through each line obtained, std::sort() to sort each line


/**********************************************************************
 *  Known bugs / limitations. For example, if your program prints
 *  out different representations of the same line segment when there
 *  are 5 or more points on a line segment, indicate that here.
 **********************************************************************/
For Brute I prefer using cross product as it does not involve floating
point numbers, compared to calculating the angles. The downside is if
the coordinates have greater values (~100000) it may cause overflow.


/**********************************************************************
 *  List whatever help (if any) that you received. Be specific with
 *  the names of lab TAs, classmates, or course staff members.
 **********************************************************************/
Tan Shuhao and his online repository, for me to kickstart my ideas and
inspire me to make a class specific for Vector2D (outside the contents
of this lab).
Also, a large amount of Stack Overflow websites as usual.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
1. For Fast.cpp it took me a while to think of a way to generate a list
without outputing duplicate lines. In the end I decided to take the easy
way out and go with multiple std::sort()s which seemed weird.
2. Time management issues (if it counts)


/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
SO CHUR
yet so enjoyable at the same time (?)
