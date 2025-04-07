package AddingTwoNumInArray;
import java.util.ArrayList;
import java.util.Scanner;

public class SUMTWOnumbersinArry {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int[] nums = {2,7,11,15};
		
		
		for(int i = 0; i < 4; i++) {
			System.out.println("index " + i + " = " + nums[i]);
		}
		
		System.out.print("\nWhat is your target to add from the array: ");
		int UserInput = input.nextInt();
		
		addSum(nums,UserInput);
	}
	
	
	public static int addSum(int[] number,int target) {
		
		//big O (n^2): 2 for loops
		for(int i = 0 ;i < number.length; i++) {
			for(int j = 0; j < number.length; j++) {
				if(target == number[i] + number[j]) {
					System.out.println("index: "+ i +" and index: " + j);
					continue;
				}
			}
		}
		return 0;
	}
	
	
	
}
