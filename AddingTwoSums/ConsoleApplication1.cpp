// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void SumOfTwoNumberArrys(std::vector<int> Number, int Target) {
    bool isTrue = false;

    for (int AddingThis = 0; AddingThis < Number.size(); AddingThis ++) {

        for (int ToThis = 0; ToThis < Number.size(); ToThis++) {

            //checking if two indexes equals the Target 
            if (Number[AddingThis] + Number[ToThis] == Target) {

                //if true it will print out the which two indexes equal the "Target"
                std::cout << "Index: " << AddingThis << " and index: " << ToThis << " equals " << Target << std::endl;

                isTrue = true;
                break;
            }
        }
        if (isTrue == true) {
            break;
        }
    }

}

int main()
{
    std::vector<int> RandomNumbers = { 2, 11, 9, 7, 15 };


    std::cout << "The vector list: " << std::endl;

    for (int i = 0; i < RandomNumbers.size(); i++) {
        std::cout << RandomNumbers[i] << " ";
    }

    int UserInput = 0;

    std::cout << "\nWhat number do you what to add up from the vector: ";
    std::cin >> UserInput;

    SumOfTwoNumberArrys(RandomNumbers, UserInput);


}
