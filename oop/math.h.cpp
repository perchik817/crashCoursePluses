#include <iostream>
// # препроцессорное определение, суть заключаетс€ в том, что препроцессор идет по cpp файду и совершает над ним какие-то манипул€ции
#define AAA 0 //определить что-то, не занимает пространства и пам€ти, существует только на момент компил€ции
#define sub(a,b) ((a)-(b)) //макросы также исполльзуютс€ дл€ условной компил€ции, не дл€ кода с++, а дл€ компил€тора
//#error "hello loser"
//свойства - с++ - препроцессор
#pragma once //дл€ того чтобы при инклуде в других файлах не открывал несколько раз избежание повтора
int mult(int a, int b) {
	return a * b;
}
int add(int a, int b) {
	return a + b;
}
//global variable but it must be initialized in one cpp
extern int x;
//classes can be realized fully here
class Em {};