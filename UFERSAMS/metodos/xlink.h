/*
 * xlink.h
 *
 *  Created on: 13/09/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef XLINK_H_
#define XLINK_H_

//  these functions link bit-level I/O
void arc_put1Int (int);
void arc_put8Int (int);
int arc_get1Int ();
int arc_get8Int ();

//  link bit-level I/O
void arc_put1Unsigned (unsigned);
unsigned arc_get1Unsineg ();

#endif /* XLINK_H_ */
