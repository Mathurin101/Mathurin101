package TicTac;
import java.util.Scanner;
public class TicTacToeGame {
	String PlayerOne = "O";
	String PlayerTwo = "X";
	
	
	boolean TicTacToe = false;
	
	        //[row][column]
	public String[][] TacToe = new String[3][3];
	
	
	public  void xANDo() {//the game TicTacToe
		Scanner input = new Scanner(System.in);
		do {
			System.out.println();
			ShowChart();
			System.out.print("PlayerOne " + PlayerOne + " pick the Spot *first input(Row), second input(Column)): ");
			int Row1 = input.nextInt();
			int Column1 = input.nextInt();
			
			if((Row1 < 4) || (Row1 > 0) ) {//check user input something incorrect 
				
			}else if((Column1 < 4) || (Column1 > 0) ) {
				
			}
		
			TacToe[Row1 -1][Column1 -1] = PlayerOne;
			
			System.out.println();
			ShowChart();
			
			if(ChartCheck()) {
				continue;
			}
			
			System.out.print("PlayerTwo " + PlayerTwo + " pick the Spot *first input(Row), second input(Column)): ");
			int Row2 = input.nextInt();
			int Column2 = input.nextInt();
			
			if((Row2 < 4) || (Row2 > 0) ) {//check user input something incorrect 
				// throw HighLowNumberExpection (" the user row number is too high");
			}else if((Column2 < 4) || (Column2 > 0) ) {
				
			}
			
			TacToe[Row2  -1][Column2  -1] = PlayerTwo;
			System.out.println();
			ShowChart();
			ChartCheck();
			
		}while(!TicTacToe);
		
		
	}


	public void ShowChart() {//display current chart
  /*	  0 1 2
		0 _ _ _ 
		1 _ _ _
		2 _ _ _
		   display       */ 
		
		System.out.print("  1 2 3 \n");
		System.out.print("1 ");
		for(int i = 0; i < 3; i++) {//row one
			
			if(TacToe[0][i] == null) {
				System.out.print("_"+ " ");
			}else {
				System.out.print(TacToe[0][i] + " ");
			}
		}
		
		System.out.print("\n");
		System.out.print("2 ");
		for(int i = 0; i < 3; i++) {//row Two
			if(TacToe[1][i] == null) {
				System.out.print("_"+ " ");	
			}else {
				System.out.print(TacToe[1][i] + " ");
			}	
		}
		
		System.out.print("\n");
		System.out.print("3 ");
		for(int i = 0; i < 3; i++) {//row Three
			if(TacToe[2][i] == null) {
				System.out.print("_"+ " ");	
			}else {
				System.out.print(TacToe[2][i] + " ");
			}
			
		}
		System.out.print("\n");
	}
	
	public boolean ChartCheck() {//check if anyone won

		//diagonal L check for winner
			if((TacToe[0][0] == PlayerOne) && (TacToe[1][1] == PlayerOne) && (TacToe[2][2] == PlayerOne))  {
					
				System.out.print("PlayerOne got TicTacToe diagonally down to the left");
				this.TicTacToe = true;
			}//PlayerOne won
			
			if((TacToe[0][0] == PlayerTwo) && (TacToe[1][1] == PlayerTwo) && (TacToe[2][2] == PlayerTwo))  {
				
				System.out.print("PlayerTwo got TicTacToe diagonally down to the left");
				this.TicTacToe = true;
			}//PlayerTwo won
			
			
		//diagonal R check for winner
			if((TacToe[0][2] == PlayerOne) && (TacToe[1][1] == PlayerOne) && (TacToe[2][0] == PlayerOne))  {
					
				System.out.print("PlayerOne got TicTacToe diagonally down to the right");
				this.TicTacToe = true;
			}//PlayerOne won
			
			if((TacToe[0][2] == PlayerTwo) && (TacToe[0][2] == PlayerTwo) && (TacToe[0][2] == PlayerTwo))  {
				
				System.out.print("PlayerTwo got TicTacToe diagonally down to the right");
				this.TicTacToe = true;
			}//PlayerTwo won
			
			
		//row1 check for winner
			if((TacToe[0][0] == PlayerOne) && (TacToe[0][1] == PlayerOne) && (TacToe[0][2] == PlayerOne))  {
				
				System.out.print("PlayerOne got TicTacToe within the first row");
				this.TicTacToe = true;
			}
			if((TacToe[0][0] == PlayerTwo) && (TacToe[0][1] == PlayerTwo) && (TacToe[0][2] == PlayerTwo))  {
				
				System.out.print("PlayerTwo got TicTacToe within the first row");
				this.TicTacToe = true;
			}
				
		//row2 check for winner
			if((TacToe[1][0] == PlayerOne) && (TacToe[1][1] == PlayerOne) && (TacToe[1][2] == PlayerOne))  {
				
				System.out.print("PlayerOne got TicTacToe within the second row");
				this.TicTacToe = true;
			}
			if((TacToe[1][0] == PlayerTwo) && (TacToe[1][1] == PlayerTwo) && (TacToe[1][2] == PlayerTwo))  {
				
				System.out.print("PlayerTwo got TicTacToe within the second row");
				this.TicTacToe = true;
			}
		//row3 check for winner
			if((TacToe[2][0] == PlayerOne) && (TacToe[2][1] == PlayerOne) && (TacToe[2][2] == PlayerOne))  {
				
				System.out.print("PlayerOne got TicTacToe within the third row");
				this.TicTacToe = true;
			}
			if((TacToe[2][0] == PlayerTwo) && (TacToe[2][1] == PlayerTwo) && (TacToe[2][2] == PlayerTwo))  {
				
				System.out.print("PlayerTwo got TicTacToe within the third row");
				this.TicTacToe = true;
			}
			
		//Column1 check for winner
			if((TacToe[0][0] == PlayerOne) && (TacToe[1][0] == PlayerOne) && (TacToe[2][0] == PlayerOne))  {
				
				System.out.print("PlayerOne got TicTacToe within the first column");
				this.TicTacToe = true;
			}
			if((TacToe[0][0] == PlayerTwo) && (TacToe[1][0] == PlayerTwo) && (TacToe[2][0] == PlayerTwo))  {
				
				System.out.print("PlayerTwo got TicTacToe within the first column");
				this.TicTacToe = true;
			}
		//Column2 check for winner
			if((TacToe[0][1] == PlayerOne) && (TacToe[1][1] == PlayerOne) && (TacToe[2][1] == PlayerOne))  {
				
				System.out.print("PlayerOne got TicTacToe within the second column");
				this.TicTacToe = true;
			}
			if((TacToe[0][1] == PlayerTwo) && (TacToe[1][1] == PlayerTwo) && (TacToe[2][1] == PlayerTwo))  {
				
				System.out.print("PlayerTwo got TicTacToe within the second column");
				this.TicTacToe = true;
			}
		//Column3 check for winner
			if((TacToe[0][2] == PlayerOne) && (TacToe[1][2] == PlayerOne) && (TacToe[2][2] == PlayerOne))  {
				
				System.out.print("PlayerOne got TicTacToe within the third column");
				this.TicTacToe = true;
			}
			if((TacToe[0][2] == PlayerTwo) && (TacToe[1][2] == PlayerTwo) && (TacToe[2][2] == PlayerTwo))  {
				
				System.out.print("PlayerTwo got TicTacToe within the third column");
				this.TicTacToe = true;
			}
		
			return TicTacToe;
	}
	
}
