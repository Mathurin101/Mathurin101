package SpaceInvaders;

import javax.swing.*; //import all from swing. instead of type out swing.somthing  

public class App {

	public static void main(String[] args) throws Exception{
		// Window variable
		int TileSize = 32; 
		int Rows = 16;
		int Columns = 16;
				
		int boardWidth = TileSize * Columns; //32 * 16 = 512 
		int boardHeight = TileSize * Rows; // 32 * 16 = 512 
				
		//Making the window/tab
		JFrame frame = new JFrame("Space Invaders"); //Name/title of the game
		
		//frame.setVisible(true); //So you can see the window spawn in
		frame.setSize(boardWidth, boardHeight); //512 x 512 pixels/px
		frame.setLocationRelativeTo(null); // will spawn the window in the center(null)
		frame.setResizable(false);//can't resize the window
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //if you "X" the Tab it closes the window
			
		//From the SpaceInvader class
		SpaceInvader spaceInvader = new SpaceInvader();
		frame.add(spaceInvader);
		frame.pack();
		
		spaceInvader.requestFocus();//request to listen 
		
		frame.setVisible(true); //put this code right here after you've add all components
		
		
	}

}
