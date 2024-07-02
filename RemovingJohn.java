import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException; //throw statement
//import java.io.PrintWriter;

public class RemovingJohn {
											//throw statement
	public static void main(String[] args) throws FileNotFoundException {

		
								//The whole name of file
		File file = new File("C:\\Users\\Genties\\Documents\\Mathurin Genty Things\\src\\eclipse\\Lab13\\src\\Johns.txt");

		String NewName = " ";


		Scanner input = new Scanner(file);

		//Print what is in the file
		while(input.hasNext()) {

			//Will put each word in "name" with each loop
			String name = input.nextLine();

			//Will print each word in "name" with each loop
			System.out.println(name + " ");

			//Will put each word in "NewName" and will replace the word john with " " with each loop
			NewName = name.replace("John", "");

		}

		System.out.println(NewName);


		input.close();
	}


}
