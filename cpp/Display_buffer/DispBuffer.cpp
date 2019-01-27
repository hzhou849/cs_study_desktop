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
 */
class DispBuffer {
private:
	int x;
	int y;

public:
	DispBuffer(); // set somekinda of 2d array in heap memory.
	~DispBuffer();

	void bufferWrite();		//write to array
	void setCursorPosition(int x, int y);
	void resetCurorPosition();

	//getters
	void getCursorPosition();	// get the current cursor position
	void dumpBuffer();  		// dump the current buffer output.

};

#include <iostream>
#include <iomanip>
int main() {
	int rowCount = 100;
	int columnCount=100;
	char **a = new char*[rowCount];
	void *ptr= nullptr;
	
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