// Lab 04: Adding List-Based Integers
// In this lab, we are creating a linked list via a class and a class for nodes using OOP and then we are creating a function to sum the two lists, which are made of single integers that are put one digit after another in nodes so that they can hold larger numbers than is possible with typical data types. The function will sum the little endian lists and print it in big endian. 
#include <iostream>
#include <string>
#include "list.h"

using namespace std;

int main(int argc, char *argv[]) {
	string input1;
	string input2;
	while (cin >> input1) { //first of 2 numbers 
		cin >> input2; //second of two numbers
		list list1; //you can do this because the lists get cleared when out of scope at end of iteration of loop
		list list2;
		for (int i = 0; i <= (int)(input1.length()) - 1; i++) { //iterate through the cin input	
			list1.addNode(input1[i] - 48); //make it into a number via removing 48 from it, ascii
		}
		for (int i = 0; i <= (int)(input2.length()) - 1; i++) {
			list2.addNode(input2[i] - 48); 
		}
		list sum = list1.sumList(list2); //create 3rd list that is sum of them.
		sum.printList();  
		cout << endl;
	}
	
    return 0;
}


