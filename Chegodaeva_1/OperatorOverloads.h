#pragma once
#include "tube.h"
#include "cs.h"
#include "Checking.h"

ostream& operator << (ostream& out, const tube& NewTube);
ostream& operator << (ostream& out, const cs& NewCS);
ofstream& operator << (ofstream& fout, const tube& NewTube);
ofstream& operator << (ofstream& fout, const cs& NewCS);
ifstream& operator >> (ifstream& fin, tube& NewTube);
ifstream& operator >> (ifstream& fin, cs& NewCS);
istream& operator >> (istream& in, tube& NewTube);
istream& operator >> (istream& in, cs& NewCS);