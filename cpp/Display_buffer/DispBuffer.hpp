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
	char* pointer(int column, int row); // pass x y and return the ptr value
	void searchString();			//search for word or char and returns [col][row] all instances that occur   

};
