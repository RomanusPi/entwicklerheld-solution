#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

#include <stdbool.h>
#include <string.h>


enum BEARING {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
};

struct Position {
    int x;
    int y;
};

struct Robot {
    struct Position position = {0, 0};
    enum BEARING bearing = NORTH;
};

struct Position get_position(struct Robot robot) {
   return robot.position;  
}

enum BEARING get_bearing(struct Robot robot) {
    return (robot.bearing);
}

void turn_right(struct Robot *robot) {
   
    
    if (robot->bearing == NORTH){ robot->bearing = EAST; return;} 
    if (robot->bearing == EAST){ robot->bearing = SOUTH; return;}
    if (robot->bearing == SOUTH){ robot->bearing = WEST; return;}
    if (robot->bearing == WEST){ robot->bearing = NORTH; return;}

}

void turn_left(struct Robot *robot) {
    if (robot->bearing == NORTH){ robot->bearing = WEST; return;}
    if (robot->bearing == WEST) { robot->bearing = SOUTH; return;}
    if (robot->bearing == SOUTH){ robot->bearing = EAST; return;}
    if (robot->bearing == EAST){ robot->bearing = NORTH; return;}
 
}

void advance(struct Robot *robot) {

if (robot->bearing == NORTH) robot->position.y++;
if (robot->bearing == SOUTH) robot->position.y--;
if (robot->bearing == EAST) robot->position.x++;
if (robot->bearing == WEST) robot->position.x--;


}

void execute_sequence(struct Robot *robot, char *sequence) {
   int i=0;
   while  (sequence[i] != '\0')
    {          
       if (sequence[i] =='L') turn_left( robot );
       if (sequence[i] =='R') turn_right( robot );
       if (sequence[i] =='A') advance( robot );
           
       //printf("%cb%dx%dy%d", sequence[i], robot->bearing, robot->position.x,robot->position.y);
    i++;

    }
}


#endif)
