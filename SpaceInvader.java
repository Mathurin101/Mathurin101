package SpaceInvaders;
import java.awt.*; //import all from awt instead of type out awt.somthing;  
import java.awt.event.*; //used for the game
import java.util.ArrayList;//storing bullets and aliens/enemies
import java.util.Random;//will be using this to randomly pick a color for the aliens
import javax.swing.*;//used for the game

public class SpaceInvader extends JPanel implements ActionListener, KeyListener{
	//implemening KeyListener = helps listen/take key inputs like pressing the arow key
	//implemening ActionListener = using functions/methods to certain actions like repainting an image
	
	class Block{//could have used inheritance 
		int x;
		int y;
		int width;
		int height;
		Image img;
		boolean alive = true; //used for aliens
		boolean used = false; //used for bullets
		
		Block(int x, int y, int width, int height, Image img){
			this.x = x;
			this.y = y;
			this.width = width;
			this.height = height;
			this.img = img;
		}
	}
	
	
	//board
	int TileSize = 32; 
	int Rows = 16;
	int Columns = 16;
			
	int boardWidth = TileSize * Columns; //32 * 16 = 512 
	int boardHeight = TileSize * Rows; // 32 * 16 = 512 
	
	//adding the images
	Image ShipImg;
	Image alienImg; //the white alien
	Image alienCyanImg;
	Image alienMagentaImg;
	Image alienYellowImg;
	
	ArrayList<Image> alienImgArray; //stores the alien-images the in array to pick randomly 
	
	//ship size, making a rectangle
	int shipWidth = TileSize * 2; //64 px
	int shipHeight = TileSize; //32 px
	int shipX = TileSize * Columns/ 2 - TileSize; //put the ship in the center 8
	int shipY = boardHeight - TileSize * 2; //put the ship at row -> 14
	//the ships main point of location is the top left side of the ship image
	
	int shipVelocityX = TileSize; //ship moving speed left/right
	
	Block ship;
	
	
	//aliens
	ArrayList<Block> alienArry;//storing all the alien in an array
	int alienWidth = TileSize * 2; // two tiles wide
	int alienHeight = TileSize; //one tile tall
	int alienX = TileSize;//will spawn the first alien left side
	int alienY = TileSize;//will spawn the first alien to the top
	
	int alienRows = 2; //spawns two rows of aliens
	int alienColumns = 3;//spawns three aliens in one row //spawn six aliens altogether
	int alienCount = 0; //keeping track on how many aliens spawn in to defeat
	int alienVelocityX = 1;// alien moving speed
	
	//bulets
	ArrayList<Block> bulletArry;
	int bulletWidth = TileSize /8; //bulletWidth = 4
	int bulletHeight = TileSize /2;//bulletHeight = 16
	int bulletVelocityY = -10; // "-10 because the bullets are going up from the bottom which is going to reach zero
	
	
	Timer gameLoop;
	
	int score = 0;
	
	boolean gameOver = false;
	
	SpaceInvader(){//SpaceInvader constructor
		
		setPreferredSize(new Dimension(boardWidth, boardHeight)); //Will create a JPanel that is 512 x 512 pixel/px or the same size as the "app" ratio
		setBackground(Color.black); //make the back ground for the Jpanel black
		setFocusable(true); //wants this "SpaceInvader(){ JPanel" to listen to key presses
		addKeyListener(this);//will listen to key presses from this class only
		
		//Loading Images
		ShipImg = new ImageIcon(getClass().getResource("./ship.png")).getImage(); //"./ship.png" have to type the name of the file
		alienImg = new ImageIcon(getClass().getResource("./alien.png")).getImage(); //"./alien.png" have to type the name of the file
		alienCyanImg = new ImageIcon(getClass().getResource("./alien-cyan.png")).getImage(); //"./alien-cyan.png" have to type the name of the file
		alienMagentaImg = new ImageIcon(getClass().getResource("./alien-magenta.png")).getImage(); //"./alien-magenta.png" have to type the name of the file
		alienYellowImg = new ImageIcon(getClass().getResource("./alien-yellow.png")).getImage(); //"./alien-yellow.png" have to type the name of the file
		//new ImageIcon(...) = sets the image from the file to what's equal 
		//getClass() = from this class
		//getResource("./name of file.png")
		//.getImage(); just the image 
		
		//adding the images to a ArrayList
		alienImgArray = new ArrayList<Image>();
		alienImgArray.add(alienImg);
		alienImgArray.add(alienCyanImg);
		alienImgArray.add(alienMagentaImg);
		alienImgArray.add(alienYellowImg);
		
		ship = new Block(shipX, shipY, shipWidth, shipHeight, ShipImg);
		alienArry = new ArrayList<Block>();
		bulletArry = new ArrayList<Block>();
		
		//game Timer
		gameLoop = new Timer(1000/60, this);//1000 milliseconds(1 second)/60 = 60 frame per second (fps) or 16.6 milliseconds
		// new Timer(How many times to call this action, what is being repeated)		
		
		createAliens();
		
		gameLoop.start();//to start the loop
	}
	
	public void paintComponent(Graphics g) {//used the paintComponent function from inheriting JPanel 
		super.paintComponent(g);
		draw(g);
	}

	public void draw(Graphics g) {//draw function from inheriting JPanel, draws the image on the window 
		//Drawing the ship
		g.drawImage(ship.img, ship.x, ship.y, ship.width, ship.height, null); //place the ship image at the location listed 
		
		//Drawing the aliens
		for(int i = 0; i < alienArry.size(); i ++) {//loop through all the aliens
			Block alien = alienArry.get(i);
			if(alien.alive) {
				g.drawImage(alien.img, alien.x, alien.y, alien.width, alien.height, null);
			}
		}
		
		//bullets
		g.setColor(Color.white); //will change the color of the pen to white after this line of code
		for (int i = 0;i < bulletArry.size(); i++) {
			Block bullet = bulletArry.get(i);
			
			if(!bullet.used) {//if the bullet was not used then we will draw it
				g.drawRect(bullet.x, bullet.y, bullet.width, bullet.height);//g.drawRect(..) : creates a outline of a rectangle with said sizes
				g.fillRect(bullet.x, bullet.y, bullet.width, bullet.height);//g.fillRect(..) : fills the rectangle with said size
			}
		}
		//score color
		g.setColor(Color.green);
		g.setFont(new Font("Arial", Font.PLAIN, 32));
		
		if(gameOver) {//will draw gameover on the screen if it is true
			g.drawString("Game Over: " + String.valueOf(score), 10, 35);
		}else {
			g.drawString(String.valueOf(score), 10, 35);
		}
		
	}
	
	public void move() {//will be used for the movement of the aliens and the bullets
		//ailens
		for(int i = 0; i < alienArry.size(); i++) {
			Block alien = alienArry.get(i); 
			if(alien.alive) {//if the alien is alive then execute the movement
				alien.x += alienVelocityX;
				
				//if aliens touches the borders
				if(alien.x + alien.width >= boardWidth || alien.x <= 0) {
					//alien.x + alien.width >= boardWidth : making it so the aliens can not go off the board to the right because the boardWidth is the right side 
					//alien.x <= 0 : if alien.x is less than 0 then it will go off the screen to the left since "0" is the left side of the screen
					
					alienVelocityX *= -1; //will flip the sign: negative is moving the aliens to the left and the positive will move them to the right 
				    alien.x += alienVelocityX*2; //will have to times 2 to make the alien show up on screen when it touches the boundary instead of being off screen
				    
				    
				    //move the aliens down by one row
				    for(int j = 0; j < alienArry.size(); j++) {
				    	alienArry.get(j).y += alienHeight;//getting the aliens and moving them down by "j" since 0 is the top left side and the bottom of the screen is 16 "where the ship is"
				    }
				}
				
				if(alien.y >= ship.y) {//if the aliens is in the same lanes as the ship the it is game over
					gameOver = true;
				}
				
			}
		}
		
		//bullets
		for(int i = 0; i < bulletArry.size(); i++) {
			Block bullet = bulletArry.get(i);
			bullet.y += bulletVelocityY; //+= bulletVelocityY will make the bullet move upwards
			
			//bullet collision with aliens
			for(int j = 0; j < alienArry.size(); j++) {
				Block alien = alienArry.get(j);
				if(!bullet.used && alien.alive && detectCollision(bullet, alien)) {//if all of this is true reduce the alien count by 1
					bullet.used = true;
					alien.alive = false;
					alienCount--;
					score += 100;//once you take out an alien
				}
			}
		}
		
		//clear bullet
		while(bulletArry.size() > 0 && ( bulletArry.get(0).used || bulletArry.get(0).y < 0)) {
			//makes the bullet that leaves the screen disappear to reduce any frame drops
			bulletArry.remove(0);//removes the first element when it leaves the screen
		}
		
		//next level
		if(alienCount == 0) {//when all the aliens are gone 
			//increase the number of aliens in columns and rows by 1
			score += alienColumns * alienRows * 100;//gives bonus point when you clear all the aliens
			alienColumns = Math.min(alienColumns + 1, Columns/2 - 2);//limit the column at 16/2 - 2 = 6
			alienRows = Math.min(alienRows + 1, Rows - 6); //limit the rows at 16 - 6 = 10
			alienArry.clear();
			bulletArry.clear();//clears any left over bullets once you cleared the aliens 
			createAliens();
		}
	}
	
	public void createAliens() {
		Random random = new Random();//used to random the "alienArry" list of aliens
		
		for(int r = 0; r < alienRows; r++) {
			for(int c = 0; c < alienColumns; c++) {
				int randomImgIndex = random.nextInt(alienImgArray.size());//will get a random number  between 0 - 3  since there is only four alien images
			
				Block alien = new Block(
					alienX + c * alienWidth,//puts the alien to the right by two tiles of the alienWidth
					alienY + r * alienHeight,//puts the alien below by one tile of the alienHeight
					alienWidth,
					alienHeight,
					alienImgArray.get(randomImgIndex)
				);
				alienArry.add(alien);//add in the aliens created from this Block
			}
		}
		alienCount = alienArry.size();
	}
	
	public boolean detectCollision(Block a, Block b) {
		//collision detect formula
		return a.x < b.x + b.width && //a's top left corner doesn't reach b's top right corner
			   a.x + a.width > b.x && //a's top right corner passes b's top left corner
			   a.y < b.y + b.height && //a's top left corner doesn't reach b's bottom left corner
			   a.y + a.height > b.y; //a's bottom left corner passes b's top left corner
	}
	

	@Override
	public void actionPerformed(ActionEvent e) { //new Timer(1000/60, this) "this" is calling this method action performed
		move();//will update the aliens moving one pixel a second because of the "GameLoop" 
		repaint();//new Timer(1000/60, every 60 fps will repaint the image AGAIN and AGAIN
		
		if(gameOver) {//if game over is true the game loop will stop
			gameLoop.stop();
		}
	}

	@Override
	public void keyTyped(KeyEvent e) { //Takes what button the user typed Ex: if they typed "a" the input what recognized it as "a" 
		//This method is not needed	but has to be present so there is not errors
	}

	@Override
	public void keyPressed(KeyEvent e) {//Takes what button the user presses and hold down on the keyboard
		//This method is not needed but has to be present so there is not errors
		/*
		if(e.getKeyCode() == KeyEvent.VK_LEFT) { //if e.getKeyCode() == left arrow key
			ship.x -= shipVelocityX; //moves left by one tile (each tile is 32 pixels) (left side 0 - 512 right on the tile grid/set)
		}else if(e.getKeyCode() == KeyEvent.VK_RIGHT) {
			ship.x += shipVelocityX; //moves right by one tile (each tile is 32 pixels) (left side 0 - 512 right on the tile grid/set)
		}*/
		//I tried this and the ship went zoooom, becuase I was holding down the left or right 
	}

	@Override
	public void keyReleased(KeyEvent e) {//Takes what button the user lets go after they press and hold down on the keyboard
		if(gameOver) {//reset everything 
			ship.x = shipX;
			alienArry.clear();
			bulletArry.clear();
			score = 0;
			alienVelocityX = 1;
			alienColumns = 3;
			alienRows = 2;
			gameOver = false;
			createAliens();
			gameLoop.start();
			
		}else if(e.getKeyCode() == KeyEvent.VK_LEFT && ship.x - shipVelocityX >= 0) { //if e.getKeyCode() == left arrow key
			//shipVelocityX : the left side of the screen 
			//ship.x - shipVelocityX >= 0 : makes it so you can not go off the screen's boundary to the left
			
			ship.x -= shipVelocityX; //moves left by one tile (each tile is 32 pixels) (left side 0 - 512 right on the tile grid/set)
		
		}else if(e.getKeyCode() == KeyEvent.VK_RIGHT && ship.x + ship.width + shipVelocityX <= boardWidth) {
			//ship.width : the left side of the screen
			//ship.x + ship.width + shipVelocityX <= boardWidth : makes it so you can not go off the boardWidth to the right
			
			ship.x += shipVelocityX; //moves right by one tile (each tile is 32 pixels) (left side 0 - 512 right on the tile grid/set)
		
		}else if(e.getKeyCode() == KeyEvent.VK_SPACE) {//if the release the spacebar button then the bullet will spawn in front of the bullet
			Block bullet = new Block(ship.x + shipWidth * 15/32, ship.y, bulletWidth, bulletHeight, null);
			bulletArry.add(bullet);//storing bullets in the array
		}
		
	}
}
