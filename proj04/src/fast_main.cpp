/*
 * COMP2012H Project 4
 * Hong Wing PANG 20315504
 * fast_main.cpp
 */

//Standalone client without GUI.
//Do not include this file in the PointPlotter Qt makefile.

#include "fast.h"

int main(int argc, char ** argv) {
	Fast fastObj;
	fastObj.getCollinearPoints();
	return 0;
}
