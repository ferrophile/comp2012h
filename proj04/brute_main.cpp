/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * brute_main.cpp
 */

//Standalone client without GUI.
//Do not include this file in the PointPlotter Qt makefile.

#include "brute.h"

int main(int argc, char ** argv) {
	Brute bruteObj;
	bruteObj.getCollinearPoints();
	return 0;
}
