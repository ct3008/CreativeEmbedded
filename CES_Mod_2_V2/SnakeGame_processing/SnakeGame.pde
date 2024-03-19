import processing.serial.*;
import ddf.minim.*;

Minim minim;
AudioPlayer soundEffect;

Serial myPort;  // Create object from Serial class
PVector food;
int speed = 10;
boolean dead = true;
int highscore = 0;
Snake snake;
int grid = 20;

void setup() {
  size(500, 500);
  snake = new Snake();
  food = new PVector();
  newFood();
  String portName = Serial.list()[4];
  myPort = new Serial(this, portName, 74880);
  minim = new Minim(this);
  soundEffect = minim.loadFile("./chomp.mp3");
  
  //frameRate(8);
}

void draw() {
  background(0);
  fill(255);
  
  if (!dead) {

    if (frameCount % speed == 0) {
      snake.update();
    }
    snake.show();
    snake.eat();
    
    
    fill(255, 0, 0);
    rect(food.x, food.y, grid, grid);
    textAlign(LEFT);
    textSize(15);
    fill(255);
    text("Score: " + snake.len, 10, 20);
    if (snake.len > highscore){
      highscore = snake.len;
      myPort.write("Highscore: " + highscore + "\n");
    }
  } else {
    textSize(25);
    textAlign(CENTER, CENTER);
    text("Snake Game\nPress joystick to start", width/2, height/2);
    //myPort.write("Highscore: " + highscore + "\n");
  }
  
  updateSnakeMovement();
}

void newFood() {
  food.x = floor(random(width));
  food.y = floor(random(height));
  food.x = floor(food.x/grid) * grid;
  food.y = floor(food.y/grid) * grid;
}

void mousePressed() {
  if (dead) {
    snake = new Snake();
    newFood();
    speed = 10;
    dead = false;
  }
}

void stop() {
  soundEffect.close();
  minim.stop();
  super.stop();
}

void updateSnakeMovement() {
  while (myPort.available() > 0) {
    String val = myPort.readStringUntil('\n');
    
    if (val != null) {
      try{
        val = val.trim();
        println("Received value: " + val); 
        int direction = Integer.parseInt(val);
        
        // Get the current direction of the snake
        int currentDirection = -1;
        if (snake.vel.x == 0 && snake.vel.y == -1) { // Up
          currentDirection = 0;
        } else if (snake.vel.x == 1 && snake.vel.y == 0) { // Right
          currentDirection = 1;
        } else if (snake.vel.x == 0 && snake.vel.y == 1) { // Down
          currentDirection = 2;
        } else if (snake.vel.x == -1 && snake.vel.y == 0) { // Left
          currentDirection = 3;
        }
        
        // Check if the new direction is opposite to the current direction
        if (direction == (currentDirection + 2) % 4) {
          // If it's the opposite direction, ignore the change
          continue;
        }
        
        // Update the snake's velocity based on the new direction
        switch (direction) {
          case 0: // Up
            snake.vel.x = 0;
            snake.vel.y = -1;
            break;
          case 1: // Right
            snake.vel.x = 1;
            snake.vel.y = 0;
            break;
          case 2: // Down
            snake.vel.x = 0;
            snake.vel.y = 1;
            break;
          case 3: // Left
            snake.vel.x = -1;
            snake.vel.y = 0;
            break;
          case 5: //Press middle key. Restarts game
            if (dead) {
              snake = new Snake();
              newFood();
              speed = 10;
              dead = false;
              myPort.write("Highscore: " + highscore + "\n");
            }
            break;
          case 6: //Press destroy
            dead=true;
            snake.update();
            myPort.write("Highscore: " + highscore + "\n");
            continue;
        }
      }catch(NumberFormatException e){
        println("highscore val");
      }
    }
  }
}
