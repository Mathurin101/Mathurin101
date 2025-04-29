#pragma once
#include <string>
/*
 * This is the File where all your work should go.
 *
 * Info about the Lab:
 *
 *		The goal of the first part of the lab
 *		is to learn how to write modular code
 *		by using the parameters given and performing
 *		a task with them. Then, returning the result of
 *		that task.
 *
 *		The goal of the second part of the lab
 *		is for you to create methods that you will
 *		then use in the related tests. This is to
 *		build your understanding of how methods are
 *		made, used, and the terminology surrounding
 *		them. Future Labs and Practicals will also
 *		expect you to create methods and use them
 *		as well.
 *
 * Additional reminders. In PG1:
 *	1. Methods are not permitted to use more than 1 return statement
 *	2. Please keep in mind the external use policy on FSO and on
 *     Discord to make sure you are not using concepts that are not
 *     allowed per policy.
 *	3. Usage of AI, LLM, and other policy violations can result in
 *     automatic 0s.
 */
class Submission
{
public:

	/* TODO: Test 1 - Years to Days
	* ==================
	* Convert the years into days and return the days.
	*
	* Parameters:
	* - years (int)
	*
	* Returns:
	* - (int)
	*
	* Example input:
	* - 5
	*
	* Expected output:
	* - 1,825
	*
	* Tips:
	*	- Break this down into a math problem on paper first.
	*	- Think about how many days are in a year and go
	*	  from there.
	*/

	int Test1(int years)
	{
		//years * 365 will give me the amount of days in said years
		int DaysInYear = years * 365;
		return { DaysInYear };
	}

	/* TODO: Test 2 - Division
	* ==================
	* Divide number1 by number2 and return the result.
	*
	* Parameters:
	* - number1 (double)
	* - number2 (double)
	*
	* Returns:
	* - (double)
	*
	* Example input:
	* - 5.00
	* - 2.00
	*
	* Expected output:
	* - 2.50
	*/

	double Test2(double number1, double number2)
	{
		double DiviTwoNumbers = number1 / number2;
		return { DiviTwoNumbers };
	}

	/* TODO: Test 3 - Remainder
	* ==================
	* Calculate the remainder of number1 divided by number2
	* and return the remainder.
	*
	* Parameters:
	* - number1 (int)
	* - number2 (int)
	*
	* Returns:
	* - (int)
	*
	* Example input:
	* - 7
	* - 2
	*
	* Expected output:
	* - 1
	*/

	int Test3(int number1, int number2)
	{
		int RemainderNumber = number1 % number2;
		return { RemainderNumber };
	}

	/* TODO: Test 4 - Square Root & Conversion
	* ==================
	* Find the square root of the input value using the sqrt() method
	* and return the result converted into a float using a cast.
	*
	* Parameters:
	* - input (double)
	*
	* Returns:
	* - (float)
	*
	* Example input:
	* - 36
	*
	* Expected output:
	* - 6
	*
	* References:
	*	- https://www.geeksforgeeks.org/sqrt-sqrtl-sqrtf-cpp/
	*	- https://cplusplus.com/reference/cmath/sqrt/
	*	- https://www.geeksforgeeks.org/type-conversion-in-c/
	*/

	float Test4(double input)
	{
		float InputSquared = (float) sqrt(input);
		return { InputSquared };
	}

	/* TODO: Test 5 - Raise to Power
	* ==================
	* Raise number to power using the pow() method
	* and return the result.
	*
	* Parameters:
	* - number (int)
	* - power (int)
	*
	* Returns:
	* - (double)
	*
	* Example input:
	* - 5
	* - 2
	*
	* Expected output:
	* - 25
	*
	* References:
	*	- https://cplusplus.com/reference/cmath/pow/
	*	- https://www.geeksforgeeks.org/power-function-c-cpp/
	*/

	double Test5(int number, int power)
	{
		double RaisedBy =(double) pow(number, power);
		return { RaisedBy };
	}

	/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!   IMPORTANT   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	* ============================================================================================
	* From this point on, you will need to create your own methods.
	*
	* See the above methods for an example.
	*
	* Once the method has been created, you will then need to
	* call the method in the related Test method. If you do not do
	* so, you will not receive full credit for the lab.
	*
	* DO NOT alter any other part of the file as this could cause an
	* unexpected output and would be considered academic dishonesty.
	* ============================================================================================
	* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!   IMPORTANT   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*/

	/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!   EXAMPLE   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	* ============================================================================================
	*
	* int Add(int x, int y)
	* {
	*		int result = x + y;
	*		return result;
	* }
	*
	* int TestMethod(int x, int y)
	* {
	*		int result = Add(x, y);
	*		return result;
	* }
	*
	* ============================================================================================
	* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!   EXAMPLE   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*/

	/* TODO: Test 6 - Concatenation - Part 1
	* ==================
	* Create a method named "Concat" and return the value of all three
	* parameters combined to form a question.
	*
	* Parameters:
	* - (string)
	* - (string)
	* - (string)
	*
	* Returns:
	* - (string)
	*
	* Example input:
	* - "Hey,"
	* - "what's up"
	* - "man"
	*
	* Expected output:
	* - "Hey, what's up man?"
	*
	* Tips:
	*	- You may use either concatenation or interpolation to complete this.
	*	- Make sure that the returned string matches the spacing and punctuation
	*	  of the expected result.
	*/
	std::string Concat(std::string FirstWord, std::string SecondWord, std::string ThirdWord) {

		std::string UserQuestion = FirstWord + " " + SecondWord + " " + ThirdWord + "?";
		return UserQuestion;
	}
	

	/* TODO: Test 6 - Concatenation - Part 2
	* ==================
	* Call the method from Test 6 - Part 1.
	* Pass in the parameters and return the string value.
	*
	* Parameters:
	* - input1 (string)
	* - input2 (string)
	* - input3 (string)
	*
	* Returns:
	* - (string)
	*/

	std::string Test6(std::string input1, std::string input2, std::string input3)
	{
		std::string ConCatFromTest6 = Concat(input1, input2, input3);
		return { ConCatFromTest6 };
	}

	/* TODO: Test 7 - Conversion - Part 1
	* ==================
	* Create a method named "Convert" and return the value of the
	* double parameter converted to a float, using a cast.
	*
	* Parameters:
	* - (double)
	*
	* Returns:
	* - (float)
	*
	* Example input:
	* - 5.25
	*
	* Expected output:
	* - 5.25f
	*
	* References:
	*	- https://www.geeksforgeeks.org/type-conversion-in-c/
	*/
	float Convert(double DoubleInput) {

		float ConvToFloat = (float) DoubleInput;
		return ConvToFloat;
	}
	

	/* TODO: Test 7 - Conversion - Part 2
	* ==================
	* Call the method from Test 7 - Part 1.
	* Pass in the parameters and return the float value.
	*
	* Parameters:
	* - input (double)
	*
	* Returns:
	* - (float)
	*/

	float Test7(double input)
	{
		float ValueInFloat = Convert(input);
		return {ValueInFloat};
	}

	/* TODO: Test 8 - Average - Part 1
	* ==================
	* Create a method named "Average" and return the average of the
	* three double parameters as a double.
	*
	* Parameters:
	* - (double)
	* - (double)
	* - (double)
	*
	* Returns:
	* - (double)
	*
	* Example input:
	* - 25.0
	* - 45.0
	* - 65.0
	*
	* Expected output:
	* - 45.0
	*/
	double Average(double FirstNumber, double SecondNumber, double ThirdNumber) {
		double averageNumber = (FirstNumber + SecondNumber + ThirdNumber) / 3;
		return averageNumber;
	}
	

	/* TODO: Test 8 - Average - Part 2
	* ==================
	* Call the method from Test 8 - Part 1.
	* Pass in the parameters and return the double value.
	*
	* Parameters:
	* - number1 (double)
	* - number2 (double)
	* - number3 (double)
	*
	* Returns:
	* - (float)
	*/

	double Test8(double number1, double number2, double number3)
	{
		float TheFloatAverage = (float) Average(number1, number2, number3);
		return { TheFloatAverage };
	}

	/* TODO: Test 9 - Area - Part 1
	* ==================
	* Create a method named "Area"
	* Determine the area of a triangle using the given values and
	* return the area as a double.
	*
	* Parameters:
	* - (double)
	* - (double)
	*
	* Returns:
	* - (double)
	*
	* Example input:
	* - 10, 7
	*
	* Expected output:
	* - 35
	*
	* Tips:
	*	- The formula for the area of a triangle is 1/2 * base * height.
	*	- This solution should not require any type of conversion.
	*	- 1/2 is two ints being divided and will not hold a decimal value.
	*	Think about what you need to change about that statement so you are
	*	using a decimal value.
	*
	* References:
	*	- https://www.cuemath.com/measurement/area-of-triangle/
	*/
	double Area(double number1, double number2) {
		double TheArea = (1.0 / 2.0) * (number1 * number2);
		return TheArea;
	}
	

	/* TODO: Test 9 - Area - Part 2
	* ==================
	* Call the method from Test 9 - Part 1.
	* Pass in the parameters and return the double value.
	*
	* Parameters:
	* - number1 (double)
	* - number2 (double)
	*
	* Returns:
	* - (double)
	*/

	double Test9(double number1, double number2)
	{
		double FormulaOfTri = Area(number1, number2);
		return { FormulaOfTri };
	}

	/* TODO: Test 10 - Division Overload - Part 1
	* ==================
	* Create an overload for Test2 that takes in 3 double parameters instead of 2
	* and return number1 divided by number2 divided by number3.
	*
	* Parameters:
	* - number1 (double)
	* - number2 (double)
	* - number3 (double)
	*
	* Returns:
	* - (double)
	*
	* Example input:
	* - 5.0
	* - 2.0
	* - 6.0
	*
	* Expected output:
	* - 4.167
	*
	* Tips:
	*	- Remember that a method overload is a different version of a method
	*   that has the same identifier but accepts different parameters,
	*   has a different return type, or both.
	*
	* References:
	*	- https://www.geeksforgeeks.org/function-overloading-c/
	*	- https://learn.microsoft.com/en-us/cpp/cpp/function-overloading?view=msvc-170
	*/
	double Test2(double number1, double number2, double number3)
	{
		double DiviThreeNumbers = number1 / number2 / number3;
		return { DiviThreeNumbers };
	}
	

	/* TODO: Test 10 - Division Overload - Part 2
	* ==================
	* Call the method from Test 10 - Part 1.
	* Pass in the parameters and return the double value.
	*
	* Parameters:
	* - number1 (double)
	* - number2 (double)
	* - number3 (double)
	*
	* Returns:
	* - (double)
	*/

	double Test10(double number1, double number2, double number3)
	{
		double ThreeNumbersDivi = Test2(number1, number2, number3);
		return { ThreeNumbersDivi };
	}
};