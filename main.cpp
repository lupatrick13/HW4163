/* ----------------------------------------------------------*
 * Program name: PointManip;       Coded by: Patrick Lu      *
 * Date        : 9/28/2021;        Version : 0x1.0;          *
 * Status      : Tested;                                     *
 * Note        : 1. Compatible with Windows 10, need glut    *
 *               Youtube Installation Guide:                 *
 *               https://www.youtube.com/watch?v=qFlJXMpxAO4 *
 *               2. Linker Libraries: freeglut, opengl32,    *
 *               	glu32                                    *
 *               3. Eclipse IDE                              *
 * ----------------------------------------------------------*
 **/

#include "util.h"
using namespace std;

int main(int argc, char** argv)
{
	// Assignment 4 Q2
	point p1(10,10), p2(10,20);
	char input;
	while(input != 'x')
	{
		float input1, input2;
		cout << "Point 1: " << p1 << endl;
		cout << "Point 2: " << p2 << endl << endl;
		cout << "1. Change Point 1" << endl;
		cout << "2. Change Point 2" << endl;
		cout << "3. Translate points" << endl;
		cout << "4. Rotate points" << endl;
		cout << "5. Rotate with pre and post processing" << endl;
		cout << "X. Exit" << endl;
		cin >> input;
		switch(input)
		{
		case '1':
			cout << "Type in your x value: ";
			cin >> input1;
			cout << "\nType in your y value: ";
			cin >> input2;
			p1.x = input1;
			p1.y = input2;
			break;
		case '2':
			cout << "Type in your x value: ";
			cin >> input1;
			cout << "\nType in your y value: ";
			cin >> input2;
			p2.x = input1;
			p2.y = input2;
			break;
		case '3':
			cout << "Type in Deltax: ";
			cin >> input1;
			cout << "\nType in Deltay: ";
			cin >> input2;
			p1 = translate(p1, input1, input2);
			p2 = translate(p2, input1, input2);
			break;
		case '4':
			cout << "Type in degrees to rotate: ";
			cin >> input1;
			p2 = rotate(p2, input1);
			break;
		case '5':
			cout << "Type in degrees to rotate: ";
			cin >> input1;
			p2 = rotateWProc(p1, p2, input1);
			break;
		case 'x':
			cout << "Exiting..";
			break;
		default:
			cout << "Type in a valid option please." << endl;
		}
	}


    return 0;
}
