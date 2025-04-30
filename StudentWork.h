#pragma once
#include <string>

/*
* This is the File where all your work should go.
* This lab is NOT interactive - that means there should be no
* calls to input or output for the user (no cout/cin)
*
* Info about the Lab:
*
*	The goal of the first part of the lab is for you to
*	demonstrate your understanding of selection (condition)
*	statements (if and switch). This means that each test
*	in the first part of the lab will require you to use
*	either a switch or an if statement for all solutions.
*
*	In the second part of the lab you will be taking these
*	demonstrations and combine them with what we did in
*	Lab 3 of method creation. You will create a method that
*	will be required to have selection (condition) statement
*	then call the method in the related Test.
*
* Additional reminders. In PG1:
*	1. Methods are not permitted to use more than 1 return statement
*	2. Please keep in mind the external use policy on FSO and on
*      Discord to make sure you are not using concepts that are not
*      allowed per policy.
*	3. Usage of AI, LLM, and other policy violations can result in
*      automatic 0s.
*/


class Submission
{
public:
	//DO NOT CHANGE THIS ENUM
	enum class MathOperator
	{
		Add = 0,
		Subtract,
		Multiply,
		Divide,
		Modulo
	};


	/* TODO: Test 1 - Proven or Denied
	* ==================
	* Use a condition statement to check the parameter and return
	* "Proven" or "Denied" based on the comparison.
	*
	* Parameters:
	*- input (bool)
	*
	* Returns:
	*- (std::string)
	*
	* Example input:
	* - true
	*
	* Expected output:
	* - "Proven"
	*
	* Tips:
	*	- The outputs are case sensitive so make sure you are assigning the string with the
	*	  casing show in the instructions above.
	*/
	std::string Test1(bool input)
	{
		std::string IsProvenDenied;
		if (input == true) {
			IsProvenDenied = "Proven";//if true
		}
		else {
			IsProvenDenied = "Denied";//if false
		}
		return { IsProvenDenied };
	}


	/* TODO: Test 2 - Weight conversion
	* ==================
	* Use a condition statement to decide if you need to convert
	* to kilograms or pounds. Return the converted value.
	*
	* Parameters:
	*	- input (double)
	*	- kiloToLb (bool)
	*
	* Returns:
	*	- (double)
	*
	* Example input:
	* - 2.75
	* - true
	*
	* Expected output:
	* - 6.05
	*
	* Tips:
	*	- The conversions are:
	*			1 kg = 2.2 lb
	*			1 lb = 0.45 kg
	*	- Use either multiplication or division depending on how you want to write your math
	*	  equation.
	*/
	double Test2(double input, bool kiloToLb)
	{
		double PoundKG = input;
		if (kiloToLb == true) {
			PoundKG *= 2.2;//lbs
		}
		else {
			PoundKG *= 0.45;//kgs
		}
		return { PoundKG };
	}


	/* TODO: Test 3 - Grade conversion
	* ==================
	* Use a condition statement to choose the letter grade
	* based on the numeric grade. Return the letter grade.
	*
	* Parameters:
	* - grade (int)
	*
	* Returns:
	* - (char)
	*
	* Example input:
	* - 80.5
	*
	* Example output:
	* - 'B'
	*
	* Tips:
	*	- Use if and if-else for this test
	*	- Remember that you need to do each comparison
	*	  separately. You cannot do 90 <= grade <= 100 as
	*	  that will not work.
	*	- If you need to combine statements for a range
	*	  there are key operators (symbols) that allow for that.
	*	- Use the following table to indicate which letter corresponds
	*	  to the provided grades.
	*			-----------------------------------
	*			|   Grade Range			|  Letter	|
	*			-----------------------------------
	*			| >= 90 and <= 100		|   'A'		|
	*			-----------------------------------
	*			| >= 80 and < 90		|   'B'		|
	*			-----------------------------------
	*			| >= 73 and < 80		|   'C'		|
	*			-----------------------------------
	*			| >= 70 and < 73		|   'D'		|
	*			-----------------------------------
	*			| >= 0 and < 70			|   'F'		|
	*			-----------------------------------
	*			| < 0 or > 100			|   '?'		|
	*			-----------------------------------
	*/
	char Test3(double grade)
	{
		char LetterGrade;
		if (grade >= 90 && grade <= 100) {

			LetterGrade = 'A';
		}
		else if (grade >= 80 && grade < 90) {

			LetterGrade = 'B';
		}
		else if (grade >= 73 && grade < 80) {

			LetterGrade = 'C';
		}
		else if (grade >= 70 && grade < 73) {

			LetterGrade = 'D';
		}
		else if (grade >= 0 && grade < 70) {

			LetterGrade = 'F';
		}
		else if (grade < 0 || grade > 100) {

			LetterGrade = '?';
		}
		return { LetterGrade };
	}



	/* TODO: Test 4 - Leap year
	* ==================
	* Use a condition statement to determine if the year
	* is a leap year or not. Return the resulting value.
	*
	* Parameters:
	*	- year (int)
	*
	* Returns:
	*	- (bool)
	*
	* Example input:
	* - 1979
	*
	* Example output:
	* - false
	*
	* Tips:
	*	- A leap year is a year divisible by 4, but not divisible by 100.
	*	- However, years divisible by 400 are also considered to be leap years.
	*	- Write this one out out paper/whiteboard to solve it.
	*		- Use the years 1200, 1700, and 2004 to test your paper logic.
	*/
	bool Test4(int year)
	{
		bool IsTrueOrNot = false;
		
		//if year can be divide 4 and year can not be divide by 100
		if (year % 4 == 0 && year % 100 != 0) {
			IsTrueOrNot = true;
		}
		else{
			IsTrueOrNot;
		}
		return { IsTrueOrNot };
	}


	/*
	* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!   IMPORTANT   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	* ============================================================================================
	* From this point on, you will need to create your own methods.
	*
	* See the example below.
	*
	* Once the method has been created, you will then need to
	* call the method in the related Test method. If you do not do
	* so you will not receive full credit for the lab.
	*
	* DO NOT alter any other part of the file as this could cause
	* unexpected output and would be considered academic dishonesty.
	* ============================================================================================
	* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!   IMPORTANT   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*/

	/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!   EXAMPLE   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	* ============================================================================================
	*
	* int Add (int x, int y)
	* {
	*		int result = x + y;
	*		return result;
	* }
	*
	* int TestMethod (int x, int y)
	* {
	*		int result = Add(x, y);
	*		return result;
	* }
	*
	* ============================================================================================
	*    * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!   EXAMPLE   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	*/


	/* TODO: Test 5 - Severity - Part 1
	* ==================
	* Create a method called Severity that accepts an integer that represents
	* the severity of an employee infraction.
	* Return the associated required action as a string.
	*
	* Parameters:
	* - (int)
	*
	* Returns:
	* - (string)
	*
	*	Use the table below to know what level is associated with what action.
	*   ------------------------------------------------------
	*   | Infraction Severity		|     Required Action	|
	*   ------------------------------------------------------
	*   |      Level 1				|     Verbal Reprimand	|
	*   ------------------------------------------------------
	*   |      Level 2				|     Formal Reprimand	|
	*   ------------------------------------------------------
	*   |      Level 3				|     Suspension		|
	*   ------------------------------------------------------
	*   |      Level 4				|     Termination		|
	*   ------------------------------------------------------
	*
	* Example input:
	* - 3
	*
	* Expected output:
	* - "Suspension"
	*
	* Tips:
	*	- Keep in mind, the returned required action is case sensitive and
	*	  must be spelled correctly (exactly as the table above)
	*/
	std::string Severity(int level) {
		std::string LeveledAction;

		switch (level) {
		case 1: 
			LeveledAction = "Verbal Reprimand";//level 1
			break;

		case 2: 
			LeveledAction = "Formal Reprimand";//level 2
			break;

		case 3: 
			LeveledAction = "Suspension";//level 3
			break;

		case 4: 
			LeveledAction = "Termination";//level 4
			break;
		}

		return LeveledAction;
	}

	/* TODO: Test 5 - Severity - Part 2
	* ==================
	* Call the method from Test 5 - Part 1.
	* Pass in the parameters as arguments for the method called.
	* Return the string value.
	*
	* Parameters:
	* - input (int)
	*
	* Returns:
	* - (string)
	*
	*/
	std::string Test5(int input)
	{
		std::string UserLevel = Severity(input);//assign level to UserLevel
		
		return { UserLevel };
	}


	/* TODO: Test 6 - Right Triangle - Part 1
	* ==================
	* Create a method called isRightTriangle that accepts three integers which represent
	* the three sides of a triangle.
	* Determine if the triangle is a right triangle.
	* Return true if the triangle is a right triangle, otherwise, return false.
	*
	* Parameters:
	* - (int)
	* - (int)
	* - (int)
	*
	* Returns:
	* - (bool)
	*
	* Example input:
	* - 6
	* - 4
	* - 7
	*
	* Expected output:
	* - false
	*
	* Tips:
	*		- A triangle where the sum of the squares of the two shortest sides (a and b)
	*		  is equal to the square of longest side (c) is a 'Right' triangle.
	*		 - The third parameter (c) will always be the longest side given.
	*/
	bool isRightTriangle(int a, int b, int c) {
		bool isTrue = false;

		//if a+b equal c then it is true
		if ( a+b == c) {
			isTrue = true;
		}
		else {
			isTrue;//is false
		}
		return isTrue;
	}

	/* TODO: Test 6 - Right Triangle - Part 2
	* ==================
	* Call the method created from Test 6 - Part 1.
	* Pass in the parameters as arguments for the method called.
	* Return the bool value.
	*
	* Parameters:
	* - a (int)
	* - b (int)
	* - c (int)
	*
	* Returns:
	* - (bool)
	*/
	bool Test6(int a, int b, int c)
	{
		bool IsItTrue = isRightTriangle(a, b, c);//assign the boolean to "IsItTrue"
		return { IsItTrue };
	}


	/* TODO: Test 7 - Enum value return - Part 1
	* =================================
	* Create a method called EnumReturn that accepts an integer value and returns
	* a MathOperator value.
	* The MathOperator will be based on the value of the parameter provided
	* using a switch statement.
	* Return the MathOperator value.
	*
	* Parameters:
	* - (int)
	*
	* Returns:
	* - (MathOperator)
	*
	* Example input:
	* - 1
	*
	* Expected output:
	* - MathOperator::Add
	*
	* Tips:
	*	- You do not need to worry about/handle any other possible
	*	  input values (the only values passed to the method
	*	  will be 0, 1, 2, 3, or 4)
	*	- You will use the enum created at the top of the file for this method.
	*	- Use the table below to know what numerical values is associated with which enum
	*	  value.
	*		-----------------------------------------------------------
	*		| Numerical Value				|        Enum Value		  |
	*		-----------------------------------------------------------
	*		|				0				|   MathOperator::Add	  |
	*		-----------------------------------------------------------
	*		|				1				|   MathOperator::Subtract|
	*		-----------------------------------------------------------
	*		|				2				|   MathOperator::Multiply|
	*		-----------------------------------------------------------
	*		|				3				|   MathOperator::Divide  |
	*		-----------------------------------------------------------
	*		|				4				|   MathOperator::Modulo  |
	*		-----------------------------------------------------------
	*/
	MathOperator EnumReturn(int UserValue) {
		MathOperator MathOP;

		switch (UserValue) {

		case 0: 
			MathOP = MathOperator::Add;//value: 0
			break;

		case 1: 
			MathOP = MathOperator::Subtract;//value: 1
			break;

		case 2: 
			MathOP = MathOperator::Multiply;//value: 2
			break;

		case 3: 
			MathOP = MathOperator::Divide;//value: 3
			break;

		case 4: 
			MathOP =MathOperator::Modulo;//value: 4
			break;

		}

		return MathOP;
	}

	/* TODO: Test 7 - Enum value return - Part 2
	* =================================
	* Call the  method from Test 7 - Part 1.
	* Pass in the parameters as arguments for the method called.
	* Return the MathOperator value.
	*
	* Parameters:
	*	- input (int)
	*
	* Returns:
	*	- (MathOperator)
	*/
	MathOperator Test7(int input)
	{
		MathOperator UserInput = EnumReturn(input);
		return { UserInput };
	}


	/* TODO: Test 8 - Preform Operation - Part 1
	* =====================
	* Create a method called Operation that accepts two integers and a MathOperator object.
	* Use the MathOperator parameter to decide what operation to perform on the two integer
	* parameter values provided.
	* Return the result of performing the chosen operation on the two integer values.
	*
	* Parameters:
	* - (int)
	* - (int)
	* - (MathOperator)
	*
	* Returns:
	* - (int)
	*
	* Example input:
	* - 5
	* - 2
	* - MathOperator::Multiply
	*
	* Expected output:
	* - 10
	*/
	int Operation(int FirstNumber, int SecondNumber, MathOperator Operate) {
		int Answer = 0;

		switch (Operate) {

		case MathOperator::Add: //enum value: 0
			Answer = FirstNumber + SecondNumber;
			break;

		case MathOperator::Subtract: //enum value: 1
			Answer = FirstNumber - SecondNumber;
			break;

		case MathOperator::Multiply: //enum value: 2
			Answer = FirstNumber * SecondNumber;
			break;

		case MathOperator::Divide: //enum value: 3
			Answer = FirstNumber / SecondNumber;
			break;

		case MathOperator::Modulo: //enum value: 4
			Answer = FirstNumber % SecondNumber;//Assign the remainder to Answer
			break;
		}

		return Answer;
	}

	/* TODO: Test 8 - Perform Operation - Part 2
	* =====================
	* Call the method from Test 8 - Part 1.
	* Pass in the parameters as arguments for the method called.
	* Return the int value.
	*
	* Parameters:
	* - number1 (int)
	* - number2 (int)
	* - operation (MathOperator)
	*
	* Returns:
	* - (int)
	*/
	int Test8(int number1, int number2, MathOperator operation)
	{
		//assigns the answer from the switch statement to "TheUserAnswer"
		int TheUserAnswer = Operation(number1, number2, operation);
		return { TheUserAnswer };
	}
};