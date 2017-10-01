#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "baseclss.h"
#include "arrclss.h"
#include "listclss.h"

using namespace std;

int main()
{
Sequence <int> *p = new ListSequence<int>;
int test = 0;
if (p->Getlength() == 0) test++;
p->Append(23);
if (p->Getlength() == 1) test++;
if (p->GetFirst() == 23) test++;
if (p->GetLast() == 23) test++;
if (p->Get(0) == 23) test++;
try {
	p->Get(-1);
}
catch (...) {
	test++;
};
try {
	p->Get(1);
}
catch (...) {
	test++;
}
p->Append(43);
if (p->Getlength() == 2) test++;
if (p->GetFirst() == 23) test++;
if (p->GetLast() == 43) test++;
if (p->Get(0) == 23) test++;
if (p->Get(1) == 43) test++;
try {
	p->Get(-1);
}
catch (...) {
	test++;
}
try {
	p->Get(2);
}
catch (...) {
	test++;
}
p->Prepend(53);
if (p->Getlength() == 3) test++;
if (p->GetFirst() == 53) test++;
if (p->GetLast() == 43) test++;
if (p->Get(0) == 53) test++;
if (p->Get(1) == 23) test++;
try {
	p->Get(-1);
}
catch (...) {
	test++;
}
try {
	p->Get(3);
}
catch (...) {
	test++;
}
Sequence<int> *tester = &p->GetSubsequence(1, 1);
if (tester->Getlength() == 1) test++;
if (tester->GetFirst() == 23 && tester->GetLast() == 23) test++;
if (test == 23)
cout << "Good work with List" << endl;
else  cout << "Something is uncorrect" << endl;

test = 0;

p = new ArraySequence<int>;
if (p->Getlength() == 0) test++;
p->Append(23);
if (p->Getlength() == 1) test++;
if (p->GetFirst() == 23) test++;
if (p->GetLast() == 23) test++;
if (p->Get(0) == 23) test++;
try {
	p->Get(-1);
}
catch (...) {
	test++;
};
try {
	p->Get(1);
}
catch (...) {
	test++;
}
p->Append(43);
if (p->Getlength() == 2) test++;
if (p->GetFirst() == 23) test++;
if (p->GetLast() == 43) test++;
if (p->Get(0) == 23) test++;
if (p->Get(1) == 43) test++;
try {
	p->Get(-1);
}
catch (...) {
	test++;
}
try {
	p->Get(2);
}
catch (...) {
	test++;
}
p->Prepend(53);
if (p->Getlength() == 3) test++;
if (p->GetFirst() == 53) test++;
if (p->GetLast() == 43) test++;
if (p->Get(0) == 53) test++;
if (p->Get(1) == 23) test++;
try {
	p->Get(-1);
}
catch (...) {
	test++;
}
try {
	p->Get(3);
}
catch (...) {
	test++;
}
tester = &p->GetSubsequence(1, 1);
if (tester->Getlength() == 1) test++;
if (tester->GetFirst() == 23 && tester->GetLast() == 23) test++;
if (test == 23)
cout << "Good work with Array" << endl;
else  cout << "Something is uncorrect" << endl;

getchar();
return 0;
}