/* Display GUI 
 *
 *  Two Dimensional array is essentially an array of pointers to arrays, which can be initialized in a loop like:
 *  int **a = new int*[rowcount];
 * 
 * for (int i = 0; i < rowcount; ++i) {
 * 		a[i] = new int[100 * (sizeof(int))]
 * }
 * 
 * a[0] ----> a[0][0]  a[0][1]  a[0][2]
 * a[1] ----> a[1][0]  a[1][1]  a[1][2]
 * a[2] ----> a[2][0]  a[2][1]  a[2][2]
 * 
 * 
 * rember to free heap memory!!!
 * for (int i=0; i < rowcount; ++i) {
 * 		delete [] a[i]; // delete each sub-array 
 * }
 * delete []a; // delete the main array
 * 
 *   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
 * 0 x
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * 7
 * 8
 * 9
 * 10
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#ifndef _DISPBUFFER_H_
#define _DISPBUFFER_H_
class DispBuffer {
private:
	int x;
	int y;

public:
	DispBuffer(); // set somekinda of 2d array in heap memory.
	~DispBuffer();

	void bufferWriteLine(std::string s);		//write to array
	void bufferWriteLine(std::string s, int offset_x); // start position on x offset
	void setCursorPosition(int x, int y);
	void resetCurorPosition();


	//getters
	void getCursorPosition();	// get the current cursor position
	void dumpBuffer();  		// dump the current buffer output.
	char* pointer(int column, int row); // pass x y and return the ptr value
	void searchString();			//search for word or char and returns [col][row] all instances that occur   

};
#endif //_DISPBUFFER_H_


int main() {
	int rowCount = 100;
	int columnCount=100;
	char **a = new char*[rowCount];
	void *ptr= nullptr;
	 char const *str = new char[10 +1]; // +1 for null terminator
	str = "ta-dah";

	str = "adfasf";


	std::cout << str << std::endl;
	// strcpy(str, "somethingelse");
	std::cout << str << std::endl;
	
	for (int i=0; i < rowCount; i++){
		a[i] = new char [columnCount *(sizeof(char))];
	}

	a[0][0] = 'a';
	a[0][1] = 'b';
	a[1][1] ='c';
	a[0][2] = '\0' ;
	//print array
	for (int i =0; i< 5; i++) {
		
		for (int j=0; j < 5; j++){
			ptr= static_cast<void*>(std::addressof(a[i][j]));
			std::cout << "a["<<i << "]" << "[" << j<<"]: " << a[i][j]<< " "<< ptr<< " "; // debug statement
			// std::cout << static_cast<void*>(std::addressof(a[i][j])); // get the address of
			// std::cout << a[i][j];
			if ( (j==4) ) 
				std::cout <<std::endl;
		}
	}

	
	



	// free memory
	for (int i=0; i < rowCount; i++) {
		delete [] a[i];
	}
	delete [] a;
	
}