#include<ctype.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#define M_PI 3.14159265358979323846264338327950288419716939937510
#define false 0
#define true 1
const int BOARD_X = 31;
const int BOARD_Y = 28;
int board_array[BOARD_X][BOARD_Y] =
{ {8,5,5,5,5,5,5,5,5,5,5,5,5,1,1,5,5,5,5,5,5,5,5,5,5,5,5,7},
{6,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,6},
{6,0,8,1,1,7,0,8,1,1,1,7,0,2,4,0,8,1,1,1,7,0,8,1,1,7,0,6},
{6,0,2,11,11,4,0,2,11,11,11,4,0,2,4,0,2,11,11,11,4,0,2,11,11,4,0,6},
{6,0,9,3,3,10, 0,9,3,3,3,10,0,9,10,0,9,3,3,3,10,0,9,3,3,10,0,6},
{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
{6,0,8,1,1,7,0,8,7,0,8,1,1,1,1,1,1,7,0,8,7,0,8,1,1,7,0,6},
{6,0,9,3,3,10,0,2,4,0,9,3,3,11,11,3,3,10,0,2,4,0,9,3,3,10,0,6},
{6,0,0,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,0,0,6},
{9,5,5,5,5,7,0,2,11,1,1,7,0,2,4,0,8,1,1,11,4,0,8,5,5,5,5,10},
{0,0,0,0,0,6,0,2,11,3,3,10,0,9,10,0,9,3,3,11,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,0,0,0,0,0,0,0,0,0,2,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,8,5,5,1,1,5,5,7,0,2,4,0,6,0,0,0,0,0},
{5,5,5,5,5,10,0,9,10,0,6,0,0,0,0,0,0,6,0,9,10,0,9,5,5,5,5,5},
{0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0},
{5,5,5,5,5,7,0,8,7,0,6,0,0,0,0,0,0,6,0,8,7,0,8,5,5,5,5,5},
{0,0,0,0,0,6,0,2,4,0,9,5,5,5,5,5,5,10,0,2,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,0,0,0,0,0,0,0,0,0,2,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,8,1,1,1,1,1,1,7,0,2,4,0,6,0,0,0,0,0},
{8,5,5,5,5,10,0,9,10,0,9,3,3,11,11,3,3,10,0,9,10,0,9,5,5,5,5,7},
{6,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,6},
{6,0,8,1,1,7,0,8,1,1,1,7,0,2,4,0,8,1,1,1,7,0,8,1,1,7,0,6},
{6,0,9,3,11,4,0,9,3,3,3,10,0,9,10,0,9,3,3,3,10,0,2,11,3,10,0,6},
{6,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,6},
{2,1,7,0,2,4,0,8,7,0,8,1,1,1,1,1,1,7,0,8,7,0,2,4,0,8,1,4},
{2,3,10,0,9,10,0,2,4,0,9,3,3,11,11,3,3,10,0,2,4,0,9,10,0,9,3,4},
{6,0,0,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,0,0,6},
{6,0,8,1,1,1,1,11,11,1,1,7,0,2,4,0,8,1,1,11,11,1,1,1,1,7,0,6},
{6,0,9,3,3,3,3,3,3,3,3,10,0,9,10,0,9,3,3,3,3,3,3,3,3,10,0,6},
{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
{9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10} };
int pebble_array[BOARD_X][BOARD_Y] =
{ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
{0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
{0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,0},
{0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
{0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
{0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0},
{0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
{0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
GLubyte list[5];
int tp_array[31][28];
int pebbles_left;
double speed1 = 0.1;
double angle1 = 90;
double a = 13.5, b = 23;
bool animate = false;
int lives = 3;
int points = 0;
bool open_move[4];
bool gameover = false;
int num_ghosts = 4;
int start_timer = 3;
void keys();
void RenderScene();
unsigned char ckey = 'w';
void mykey(unsigned char key, int x, int y);
bool Open(int a, int b);
void Move()
{
    a += speed1 * cos(M_PI / 180 * angle1);
    b += speed1 * sin(M_PI / 180 * angle1);
    if (animate && ckey == GLUT_KEY_UP && (int)a - a > -0.1 && angle1 != 270) //w
    {
        if (Open(a, b - 1)) {
            animate = true;
            angle1 = 270;
        }
    }
    else if (animate && ckey == GLUT_KEY_DOWN && (int)a - a > -0.1 && angle1 != 90)// s
    {
        if (Open(a, b + 1))
        {
            animate = true;
            angle1 = 90;
        }
    }
    else if (animate && ckey == GLUT_KEY_LEFT && (int)b - b > -0.1 && angle1 != 180)//a
    {
        if (Open(a - 1, b))
        {
            animate = true;
            angle1 = 180;
        }
    }
    else if (animate && ckey == GLUT_KEY_RIGHT && (int)b - b > -0.1 && angle1 != 0)//d
    {
        if (Open(a + 1, b))
        {
            animate = true;
            angle1 = 0;
        }
    }
}
void Pac(void)
{
    //Draw Pacman
    glColor3f(1, 1, 0);
    glPushMatrix();                //tells OpenGL to store the current state that we are in. This then allows us to perform a bunch of different effects
    glTranslatef(a, -b, 0);
    glTranslatef(0.5, 0.6, 0);
    glTranslatef((float)BOARD_X / -2.0f, (float)BOARD_Y / 2.0f, 0.5);
    glutSolidSphere(0.5, 15, 10);
    glPopMatrix();                //Then when we want to go back to our previous state, we call glPopMatrix ().
}
//Monster Drawing And Moving Begins
class Ghost
{
public:
    bool transporting;
    float color[3];
    double speed;
    bool in_jail;
    int jail_timer;
    double angle;
    double x, y;
    Ghost(double, double);
    ~Ghost(void);                            //destructer
    void Move();                            //Move the Monster
    void Update(void);                     //Update Monster State
    void Chase(double, double, bool*);    //Chase Pacman
    bool Catch(double, double);          //collision detection
    void Reinit(void);
    void Draw(void);                   //Draw the Monster
    void game_over(void);
};
Ghost* ghost[4];
Ghost::~Ghost(void) {}
Ghost::Ghost(double tx, double ty)
{
    tx = x;
    ty = y;
    angle = 90;
    speed = 1;
    color[0] = 1;
    color[1] = 0;
    color[2] = 0;
    in_jail = true;
    jail_timer = 1000;
}
void Ghost::Reinit(void)
{
    in_jail = true;
    angle = 90;
}
//Move Monster
void Ghost::Move()
{
    //degree to rad conversion
    x += speed * cos(M_PI / 180 * angle);
    y += speed * sin(M_PI / 180 * angle);
    //it checks if the new position is inside a wall or outside the game area,
    //and if so, it adjusts the ghost's position to keep it inside the game area.
}
void Ghost::game_over() {}
void Ghost::Update(void)
{
    if ((int)x == 0 && (int)y == 14 && (!(transporting)))
    {
        angle = 180;
    }
    if (x < 0.1 && (int)y == 14)
    {
        x = 26.9;
        transporting = true;
    }
    if ((int)x == 27 && (int)y == 14 && (!(transporting)))
    {
        angle = 0;
    }
    if (x > 26.9 && (int)y == 14)
    {
        x = 0.1;
        transporting = true;
    }
    //Where to go after coming out of jail
    if (in_jail && (int)(y + 0.9) == 11)
    {
        in_jail = false;
        angle = 0; //right
    }
    if (in_jail && ((int)x == 13 || (int)x == 14))
    {
        angle = 270; //up
    }
    //if time in jail is up, position for exit
    if (jail_timer == 0 && in_jail)
    {
        //move right to exit
        if (x < 13)
            angle = 0;
        if (x > 14)
            angle = 180;
    }
    //decrement time in jail counter
    if (jail_timer > 0)
        jail_timer--;
}
bool Ghost::Catch(double px, double py)
{// Collision Detection
    //the Catch() function is used to detect collisions between 
    //the ghost and the player, by calculating the distance between 
    //them along the x and y axes and checking if both distances are 
    //within a certain threshold(-0.2,0.2).
    if (px - x < 0.2 && px - x > -0.2 && py - y < 0.2 && py - y > -0.2)
    {

        return true;
    }
    return false;
}
//px , py -> pac man position , possible moves for ghost
void Ghost::Chase(double px, double py, bool* open_move)
{

    int c = 1;
    bool moved = false;
    //Depending on the direction, the function checks the location of the player
    //and the availability of moves in the two directions perpendicular to the current direction
    //If there is an open move in the direction that will bring the ghost closer to the player,
    //the angle of movement is updated accordingly.
    if ((int)angle == 0 || (int)angle == 180)
    {
        if ((int)c * py > (int)c * y && open_move[1])
            angle = 90;
        else if ((int)c * py < (int)c * y && open_move[3])
            angle = 270;
    }
    else if ((int)angle == 90 || (int)angle == 270)
    {
        if ((int)c * px > (int)c * x && open_move[0])
            angle = 0;
        else if ((int)c * px < (int)c * x && open_move[2])
            angle = 180;
    }
    //Random Moves Of Monsters
    //If there is no available move in the direction that will bring 
    //the ghost closer to the player, the function will randomly choose
    //a direction for the ghost to move in by changing the angle of movement
    //to the first available direction in a clockwise direction.
    if ((int)angle == 0 && !open_move[0])
        angle = 90;
    if ((int)angle == 90 && !open_move[1])
        angle = 180;
    if ((int)angle == 180 && !open_move[2])
        angle = 270;
    if ((int)angle == 270 && !open_move[3])
        angle = 0;
    if ((int)angle == 0 && !open_move[0])
        angle = 90;
}
void Ghost::Draw(void)
{
    //ghost color
    glColor3f(color[0], color[1], color[2]);
    //save current matrix state
    glPushMatrix();
    //position the Ghost at its current (x,y) position within the game board.
    glTranslatef(x, -y, 0);
    //move the Ghost slightly upwardand forward from its(x, y) position in the game board.
    glTranslatef(0.5, 0.6, 0);
    //function call is used to center the Ghost at the middle of the game board.
    glTranslatef((float)BOARD_X / -2.0f, (float)BOARD_Y / 2.0f, 0.5);
    //radius -> 0.5 , slices(vertical divs) , stacks (horizontal rings)
    // slices -> the number of slices would determine the number of rings around 
    //the sphere from top to bottom.
    // stacks -> stacks would refer to the number of horizontal rings
    //that would be added around the sphere.
    glutSolidSphere(.5, 10, 10);

    glPopMatrix();
}
void tp_restore(void)
{
    for (int ISO = 0; ISO < BOARD_X; ISO++)
    {
        for (int j = 0; j < BOARD_Y; j++)
        {
            tp_array[ISO][j] = pebble_array[ISO][j];
        }
    }
    pebbles_left = 244;
}
void Draw(void)
{
    //split board drawing in half to avoid issues with depth
    for (int ISO = 0; ISO < BOARD_X; ISO++)
    {
        for (int j = 0; j < BOARD_Y / 2; j++)
        {
            int call_this = 0;
            glPushMatrix();
            glTranslatef(-(float)BOARD_X / 2.0f, -(float)BOARD_Y / 2.0f, 0);
            glTranslatef(j, BOARD_Y - ISO, 0);
            glPushMatrix();
            glTranslatef(0.5, 0.5, 0);
            switch (board_array[ISO][j])
            {
            case 4:
                glRotatef(90.0, 0, 0, 1);
            case 3:
                glRotatef(90.0, 0, 0, 1);
            case 2:
                glRotatef(90.0, 0, 0, 1);
            case 1:
                call_this = 1;
                break;
            case 6:
                glRotatef(90.0, 0, 0, 1);
            case 5:
                call_this = 2;
                break;
            case 10:
                glRotatef(90.0, 0, 0, 1);
            case 9:
                glRotatef(90.0, 0, 0, 1);
            case 8:
                glRotatef(90.0, 0, 0, 1);
            case 7:
                call_this = 3;
                break;
            }
            glScalef(1, 1, 0.5);
            glTranslatef(-0.5, -0.5, 0);
            glCallList(list[call_this]);
            glPopMatrix();
            //now put on the top of the cell
            if (call_this != 0 || board_array[ISO][j] == 11)
            {
                glTranslatef(0, 0, -0.5);
                glCallList(list[4]);
            }
            glPopMatrix();
            if (tp_array[ISO][j] > 0)
            {
                glColor3f(0, 300, 1 / (float)tp_array[ISO][j]);
                glPushMatrix();
                glTranslatef(-(float)BOARD_X / 2.0f, -(float)BOARD_Y / 2.0f, 0);
                glTranslatef(j, BOARD_Y - ISO, 0);
                glTranslatef(0.5, 0.5, 0.5);
                glutSolidSphere(0.1f * ((float)tp_array[ISO][j]), 6, 6);
                glPopMatrix();
            }
        }
    }
    int ISO;
    for (ISO = 0; ISO < BOARD_X; ISO++)
    {
        for (int j = BOARD_Y - 1; j >= BOARD_Y / 2; j--)
        {
            glColor3f(0, 0, 1);
            int call_this = 0;
            glPushMatrix();
            glTranslatef(-(float)BOARD_X / 2.0f, -(float)BOARD_Y / 2.0f, 0);
            glTranslatef(j, BOARD_Y - ISO, 0);
            glPushMatrix();
            glTranslatef(0.5, 0.5, 0);
            switch (board_array[ISO][j])
            {
            case 4:
                glRotatef(90.0, 0, 0, 1);
            case 3:
                glRotatef(90.0, 0, 0, 1);
            case 2:
                glRotatef(90.0, 0, 0, 1);
            case 1:
                call_this = 1;
                break;
            case 6:
                glRotatef(90.0, 0, 0, 1);
            case 5:
                call_this = 2;
                break;
            case 10:
                glRotatef(90.0, 0, 0, 1);
            case 9:
                glRotatef(90.0, 0, 0, 1);
            case 8:
                glRotatef(90.0, 0, 0, 1);
            case 7:
                call_this = 3;
                break;
            }
            glScalef(1, 1, 0.5);
            glTranslatef(-0.5, -0.5, 0);
            glCallList(list[call_this]);
            glPopMatrix();
            //now put on top
            if (call_this != 0 || board_array[ISO][j] == 11)
            {
                glTranslatef(0, 0, -0.5);
                glCallList(list[4]);
            }
            glPopMatrix();
            if (tp_array[ISO][j] > 0)
            {
                glColor3f(0, 300, 1 / (float)tp_array[ISO][j]);
                glPushMatrix();
                glTranslatef(-(float)BOARD_X / 2.0f, -(float)BOARD_Y / 2.0f, 0);
                glTranslatef(j, BOARD_Y - ISO, 0);
                glTranslatef(0.5, 0.5, 0.5);
                glutSolidSphere(0.1f * ((float)tp_array[ISO][j]), 6, 6);
                glPopMatrix();
            }
        }
    }
    Pac();
}
bool Open(int a, int b)
{
    if (board_array[b][a] > 0) {
        return false;
    }
    return true;
}

void mykey(unsigned char key, int x, int y)
{
    if (start_timer > 0)
    {
        start_timer--;
    }
}
//3 param-> key pressed , x , y coordinates of mouse cursor when key was pressed 
void specialDown(int key, int x, int y)
{
    if (start_timer > 0)
        start_timer--;
    ckey = key;
    //key == arrow key , ,not in up direction already
    if (key == GLUT_KEY_UP && (int)a - a > -0.1 && angle1 != 270) //w
    {
        //check if there is open path in the direction of key is pressed
        if (Open(a, b - 1))
        {
            animate = true;
            // 270 -> up 
            angle1 = 270;
        }
    }
    else if (key == GLUT_KEY_DOWN && (int)a - a > -0.1 && angle1 != 90)// s
    {
        if (Open(a, b + 1))
        {
            animate = true;
            //90 -> down
            angle1 = 90;
        }
    }
    else if (key == GLUT_KEY_LEFT && (int)b - b > -0.1 && angle1 != 180)//a
    {
        if (Open(a - 1, b))
        {
            animate = true;
            //180 -> left
            angle1 = 180;
        }
    }
    else if (key == GLUT_KEY_RIGHT && (int)b - b > -0.1 && angle1 != 0)//d
    {
        if (Open(a + 1, b))
        {
            animate = true;
            //0 -> right
            angle1 = 0;
        }
    }
}
void P_Reinit()
{
    a = 13.5;
    b = 23;
    angle1 = 90;
    animate = false;
    Pac();
}
void G_Reinit(void)
{
    start_timer = 3;
    //ghost initial starting positions
    int start_x[4] = { 11,12,15,16 };
    float ghost_colors[4][3] = { {255,0,0},{120,240,120},{255,200,200},{255,125,0} };
    for (int i = 0; i < num_ghosts; i++)
    {
        ghost[i]->Reinit();
        ghost[i]->x = start_x[i];
        ghost[i]->y = 14;
        ghost[i]->jail_timer = i * 33 + 66;
        ghost[i]->speed = 0.1 - 0.01 * (float)i;
        //colorize ghosts
        for (int j = 0; j < 3; j++)
            ghost[i]->color[j] = ghost_colors[i][j] / 255.0f;
    }
}
void Write(char* string)
{
    while (*string)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
}
//Display Function->This Function Is Registered in glutDisplayFunc
void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Through Movement->From One End To The Other
    //If PacMan reaches one end of the screen, he appears on the other side,
    //creating a wrap-around effect
    if ((int)a == 27 && (int)b == 14 && angle1 == 0)                 //go outside of box
    {
        a = 0;
        animate = true;
    }
    else if ((int)(a + 0.9) == 0 && (int)b == 14 && angle1 == 180)  
    {
        a = 27; //intial position
        animate = true;
    }
    //Collision Detection For PacMan
    if (animate)
        Move();
    if (!(Open((int)(a + cos(M_PI / 180 * angle1)), (int)(b + sin(M_PI / 180 * angle1)))) && a - (int)a < 0.1 && b - (int)b < 0.1)
        animate = false;
    if (tp_array[(int)(b + 0.5)][(int)(a + 0.5)] == 1)    //to calculate no of pebbles eaten
    {
        tp_array[(int)(b + 0.5)][(int)(a + 0.5)] = 0;
        pebbles_left--;
        points += 1;
    }
    //if all pebbles are eaten by pacman then game is reintialized
    if (pebbles_left == 0)
    {
        G_Reinit();
        P_Reinit();
        tp_restore();
        points = 0;
        lives = 3;
    }
    if (!gameover)
        Draw(); //draw pacman and game world
    for (int d = 0; d < num_ghosts; d++)
    {
        if (!gameover && start_timer == 0)
            ghost[d]->Update();
        //If the ghost is not in jail and has reached an intersection 
        //(determined by checking if its x and y positions are close to integer values),
        //the available open moves in its surroundings are determined by calling the
        //Open() function in each direction.
        if (!ghost[d]->in_jail && ghost[d]->x - (int)ghost[d]->x < 0.1 && ghost[d]->y - (int)ghost[d]->y < 0.1)
        {
            bool open_move[4];
            //Finding Moves
            for (int ang = 0; ang < 4; ang++)
            {
                open_move[ang] = Open((int)(ghost[d]->x + cos(M_PI / 180 * ang * 90)), (int)(ghost[d]->y + sin(M_PI / 180 * ang * 90)));
            }
            //Chase Pac Man
            //If the ghost is at an intersection, it chases Pac-Man by calling the Chase() 
            //function with the open move directions as an argument.
            if (ghost[d]->x - (int)ghost[d]->x < 0.1 && ghost[d]->y - (int)ghost[d]->y < 0.1)
                ghost[d]->Chase(a, b, open_move);
        }
        //If the ghost is in jail and its current direction would lead it to a wall, 
        //it turns around by changing its angle by 180 deg
        if (ghost[d]->in_jail && !(Open((int)(ghost[d]->x + cos(M_PI / 180 * ghost[d]->angle)), (int)(ghost[d]->y + sin(M_PI / 180 * ghost[d]->angle)))) && ghost[d]->jail_timer > 0 && ghost[d]->x - (int)ghost[d]->x < 0.1 && ghost[d]->y - (int)ghost[d]->y < 0.1)
        {
            ghost[d]->angle = (double)(((int)ghost[d]->angle + 180) % 360);
        }
        //If the game is not over and the start timer is zero, 
        //the ghost moves one step in its current direction using the Move() function
        if (!gameover && start_timer == 0)
            ghost[d]->Move();
        ghost[d]->Draw();
        bool collide = ghost[d]->Catch(a, b);
        //Monster Eats PacMan
        if (collide)
        {
            lives--;
            if (lives == 0)
            {
                gameover = true;
                lives = 0;
                ghost[d]->game_over();
            }
            P_Reinit();
            d = 4;
        }
    }
    char tmp_str[40];
    if (gameover == true)
    {
        glColor3f(1, 0, 1);
        glColor3f(1, 0, 0);
        glRasterPos2f(-5, 0.5);
        sprintf_s(tmp_str, "Game Over");
        Write(tmp_str);
    }
    glColor3f(1, 1, 0);
    glRasterPos2f(10, 18);
    sprintf_s(tmp_str, "Points: %d", points);
    Write(tmp_str);
    glColor3f(1, 0, 1);
    glRasterPos2f(-5, 18);
    sprintf_s(tmp_str, "PAC MAN");
    Write(tmp_str);
    glColor3f(1, 1, 0);
    glRasterPos2f(-12, 18);
    if (lives < 0)
    {
        lives = 0;
    }
    sprintf_s(tmp_str, "Lives: %d", lives);
    Write(tmp_str);
    //constantly called to avoid screen flickering and smooth animation 
    //window needs to be redrawn and calls glutDisplayFunc()
    glutPostRedisplay();      //glutPostRedisplay may be called within a window's display
    //display updated content
    glutSwapBuffers();                      //Performs a buffer swap on the layer in use for the current window
}

//walls of maze
void create_list_lib()
{
    //Set Up Maze Using Lists
    list[1] = glGenLists(1);
    glNewList(list[1], GL_COMPILE);   //relation between int type and drawing
    //North Wall
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 1.0);
    glEnd();
    glEndList();
    // 2 quads for north and south quad
    list[2] = glGenLists(1);
    glNewList(list[2], GL_COMPILE);
    glBegin(GL_QUADS);
    //North Wall
    glColor3f(0, 0, 1);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 1.0);
    //South Wall
    glColor3f(0, 0, 1);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();
    glEndList();
    //east wall to north wall
    list[3] = glGenLists(1);
    glNewList(list[3], GL_COMPILE);
    glBegin(GL_QUADS);
    //North Wall
    glColor3f(0, 0, 1);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 1.0);
    //East Wall
    glColor3f(0, 0, 1);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(1.0, 0.0, 0.0);
    glEnd();
    glEndList();
    //top wall of the maze -> orange 
    list[4] = glGenLists(1);
    glNewList(list[4], GL_COMPILE);
    glBegin(GL_QUADS);
    //Top Wall
    glColor3f(-1, 0.3, 0);
    glVertex3f(1, 1, 1.0);
    glVertex3f(0, 1, 1.0);
    glVertex3f(0, 0, 1.0);
    glVertex3f(1, 0, 1.0);
    glEnd();
    glEndList();
}
void init()
{
    glEnable(GL_NORMALIZE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();                        //Reset the co-ordinate system
    gluPerspective(60, 1.33, 0.005, 100);       //set up a perspective projection matrix : fovy,aspect,znear,zfar
    glMatrixMode(GL_MODELVIEW);              //For transformation
    glLoadIdentity();
    gluLookAt(-1.5, 0, 40, -1.5, 0, 0, 0.0f, 1.0f, 0.0f);  // //define a viewing transformation
}
int main(int argc, char** argv)
{
    //begining of glut program
    glutInit(&argc, argv);
    //rgba -> color buffer , glut_double -> double buffer is enabled , depth buffer is enabled
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    //wide , tall pixel
    glutInitWindowSize(1200, 780);
    //top left corner with x,y -> 0,0
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Pac GL 3D");
    //infinite loop for objeccts defined untill false condition is reached
    init();
    //create walls of the maze
    create_list_lib();
    //When the user presses a key on the keyboard, the GLUT library will call
    // the registered callback function, passing in the ASCII code of the key as an integer value,
    // along with the current mouse coordinatesand state.The programmer can then use this information 
    // to update the state of the application, such as changing the position of an object, or triggering
    //  some other action.
    glutKeyboardFunc(mykey);
    //it registers a callback function to handle special keys on the keyboard, such as the arrow keys, 
    //function keys, and other non - ASCII keys. 
    //special down -> explains the next move according to the key pressed
    glutSpecialFunc(specialDown);
    //called whenever the graphics window needs to be redrawn or refreshed
    glutDisplayFunc(RenderScene);
    //depth values are compared to the depth values already in the depth buffer
    //pixels that are closer to the viewer are actually drawn on the screen
    //ensure that objects are rendered in the correct order and appear to have the correct depth relationships
    glEnable(GL_DEPTH_TEST);

    int start_x[4] = { 11,12,15,16 };
    for (int ISO = 0; ISO < num_ghosts; ISO++)
    {
        //ghost x , y intial coordinates
        ghost[ISO] = new Ghost(start_x[ISO], 14);
    }
    //red , green , peach , orange
    float ghost_colors[4][3] = { {255,0,0},{120,240,120},{255,200,200},{255,125,0} };
    for (int ISO = 0; ISO < num_ghosts; ISO++)
    {
        ghost[ISO]->x = start_x[ISO];
        ghost[ISO]->y = 14;
        //intial speed of ghosts is in decreasing order 
        ghost[ISO]->speed = 0.1 - 0.01 * (float)ISO;
        //colorize ghosts
        for (int j = 0; j < 3; j++)
            //normailzing the color values to 0-1
            ghost[ISO]->color[j] = ghost_colors[ISO][j] / 255.0f;
    }
    //tp_array==pebble_array
    //board_x = 28 , board_y = 31
    for (int ISO = 0; ISO < BOARD_X; ISO++)
    {
        for (int j = 0; j < BOARD_Y; j++)
        {
            tp_array[ISO][j] = pebble_array[ISO][j];
        }
    }
    pebbles_left = 244;
    glutMainLoop();
    return 0;
}
