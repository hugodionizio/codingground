/*
 * MicroMundosLivre.h
 *
 *  Created on: 27/05/2011
 *      Author: Hugo Dionizio Santos
 */

#define width 800
#define height 600
#define depth 450
#define Standard widh,height,depth

typedef struct {
//	int projectSize;

}Standard;

typedef struct {
	char *name;
	int size[3];
	char *procedures;
} Project;

typedef struct {
	char *name;
	int pos[3];
	int heading[2];
	int color;
	int size[3];
	int penmode;
	int pensize;
	int visibility;
	char *instructions;
} Turtle;

typedef struct {
	char *name;
	int pos[3];
	int size[3];
	char text;
	int fontsize;
	int fontstyle;
	int fontcolor;
	int frame;
	int visibility;
} Textbox;

typedef struct {
	char *name;
	int size[3];
	int visibility;
	char *instructions;
} Button;

typedef struct {
	char *name;
	int size[3];
	int limit[2];
	int visibility;
} Slide;

enum color {
	transparent = -1
;
white = 0;
black = 9;
red = 15;
magenta = 25;
orange = 35;
yellow = 45;
green = 55;
turqueza = 65;
blue = 75;
cyan = 85;
violet = 95;
};

#define xcor object.pos[1]
#define ycor object.pos[2]
#define zcor object.pos[3]

int distance(char object1, char object2) {
int on = 1;

if (on == 1) {
	return pow(pow(object2.xcor-object1.xcor,2)+
	pow(object2.ycor-object1.ycor,2)+
	pow(object2.zcor-object1.xcor,2),0.5);
	on=0;
}
}

void fd(char object1, int dist) {
	int on = 1;

	if (on == 1) {
		object1.xcor= dist*cos(heading[1]);
		object1.ycor = dist*sin(heading[1]);
		object1.zcor = dist*cos(heading[2]);
		on=0;
	}
}

void bk(char object1, int dist) {
	int on = 1;

	if (on == 1) {
		object1.xcor= dist/cos(heading[1]);
		object1.ycor = dist/sin(heading[1]);
		object1.zcor = dist/cos(heading[2]);
		on=0;
	}
}

void rt(char object, int angle1, int angle2) {
	int on = 1;

	if (on == 1) {
		object1.heading[1]++;
		object1.heading[2]++;
		on = 0;
	}
}

void lt(char object, int angle1, int angle2) {
	int on = 1;

	if (on == 1) {
		object1.heading[1]--;
		object1.heading[2]--;
		on = 0;
	}
}

void show(char *tip) {
	int on = 1;

	if (on == 1) {
		char tip2[] = tip;
		printf("%s", tip2);
		on = 0;
	}
}

void repeat(int cycles) {
	int on = 1;
	int cycle;

	if (on == 1) {
		cycle = cycles;
		for (; cycle > 0; cycle--)
			on = 0;
	}
}

void forever(char process) {
	int cycle = 0;

	for (; cycle == 0;)
		process;
}

void cancel(char process) {

	if (cmp(process, "forever"))
		forever.cycle = 1;
	else
		process.on = 0;
}

void stopall() {
	forever.cycle = 1;
	onAll = 0;
}
