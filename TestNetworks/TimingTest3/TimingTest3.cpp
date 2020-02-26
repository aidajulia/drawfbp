#pragma comment(lib, "CppFBPCore")
#pragma comment(lib, "CppFBPComponents")

// TimingTest3.cpp : TimingTest1 with subnets

#include "thxdef.h"

#include <stdio.h>
#define FILE struct _iobuf

/* This is not the THREADS internal structure - this 
is a structured representation of the free-form connection list
*/
void CppFBP(label_ent * label_blk, bool dynam,  FILE * fp, bool timereq);

THRCOMP ThGenIps(_anchor anch);
THRCOMP ThDrop(_anchor anch);

proc_ent P00 = {0, "Gen0", "ThGenIps", ThGenIps, 0, 0,  0, 0};
proc_ent P01 = {&P00, "Drop0", "ThDrop", ThDrop, 0, 0,  0, 0};
IIP I00 = {"1000000"};
cnxt_ent C00 = {0, "!", "", 0, "Gen0", "COUNT", 0, &I00, 0};
cnxt_ent C01 = {&C00, "Gen0", "OUT", 0, "Drop0", "IN", 0, 0, 50};

proc_ent P10 = {&P01, "Gen1", "ThGenIps", ThGenIps, 0, 0,  0, 0};
proc_ent P11 = {&P10, "Drop1", "ThDrop", ThDrop, 0, 0,  0, 0};
IIP I10 = {"1000000"};
cnxt_ent C10 = {&C01, "!", "", 0, "Gen1", "COUNT", 0, &I10, 0};
cnxt_ent C11 = {&C10, "Gen1", "OUT", 0, "Drop1", "IN", 0, 0, 50};

proc_ent P20 = {&P11, "Gen2", "ThGenIps", ThGenIps, 0, 0,  0, 0};
proc_ent P21 = {&P20, "Drop2", "ThDrop", ThDrop, 0, 0,  0, 0};
IIP I20 = {"1000000"};
cnxt_ent C20 = {&C11, "!", "", 0, "Gen2", "COUNT", 0, &I20, 0};
cnxt_ent C21 = {&C20, "Gen2", "OUT", 0, "Drop2", "IN", 0, 0, 50};

proc_ent P30 = {&P21, "Gen3", "ThGenIps", ThGenIps, 0, 0,  0, 0};
proc_ent P31 = {&P30, "Drop3", "ThDrop", ThDrop, 0, 0,  0, 0};
IIP I30 = {"1000000"};
cnxt_ent C30 = {&C21, "!", "", 0, "Gen3", "COUNT", 0, &I30, 0};
cnxt_ent C31 = {&C30, "Gen3", "OUT", 0, "Drop3", "IN", 0, 0, 50};

proc_ent P40 = {&P31, "Gen4", "ThGenIps", ThGenIps, 0, 0,  0, 0};
proc_ent P41 = {&P40, "Drop4", "ThDrop", ThDrop, 0, 0,  0, 0};
IIP I40 = {"1000000"};
cnxt_ent C40 = {&C31, "!", "", 0, "Gen4", "COUNT", 0, &I40, 0};
cnxt_ent C41 = {&C40, "Gen4", "OUT", 0, "Drop4", "IN", 0, 0, 50};


label_ent LABELTAB = {0, " ", "", &C41, &P41, 'L'};

void main() {
CppFBP(&LABELTAB, 0, 0, 1);  // time required
}
