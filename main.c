#include "raylib.h"

//Definitions

#define SNAKE_LENGTH = 256
#define SQUARE_SIZE = 31

// Types and Structures

typedef struct Snake {
  Vector2 position;
  Vector2 size;
  Vector2 speed;
  Color color;
} Snake;

typedef struct Food {
  Vector2 position;
  Vector2 size;
  bool active;
  Color color;
} Food;

/*
 * Global Variable Definitions
 */

static const int screenWidth = 800;
static const int screenHeight = 450;

static int framesCounter = 0;
static bool gameOver = false;
static bool pause = false;

static Food fruit = { 0 };
static Snake snake[SNAKE_LENGTH] = { 0 };
static Vector2 snakePosition[SNAKE_LENGTH] = { 0 };
static bool allowMove = false;
static Vector2 offset = { 0 };
static int counterTail = 0;

/*
 * Module Declarations
 */

static void InitGame(void);
static void UpdateGame(void);
static void DrawGame(void);
static void UnloadGame(void);
static void UpdateDrawFrame(void);


/*
 * Main Entry Point
 */

int main(void)
{
  // General Game Definitions
  InitWindow(screenWidth, screenHeight, "Snake Clone");

  InitGame();

  SetTargetFPS(60);

  // Main Loop
  while (!WindowShouldClose())
  {
    UpdateDrawFrame();
  }

  UnloadGame();

  CloseWindow();

  return 0;

}

/*
 * Module Functions Definitions
 */


// Initialize Game Variables
void InitGame(void)
{
  framesCounter = 0;
  gameOver = false;
  pause = false;

  counterTail = 1;
  allowMove = false;

  offset.x = screenWidth%SQUARE_SIZE;
  offset.y = screenHeight%SQUARE_SIZE;

  for (int i = 1; i < SNAKE_LENGTH; i++)
  {

    snake[i].position = (Vector2){ offset.x/2, offset.y(2)};
    snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };

    if(i == 0) snake[i].color = DARKBLUE;
    else snake[i].color = BLUE; 
    
  }





}




