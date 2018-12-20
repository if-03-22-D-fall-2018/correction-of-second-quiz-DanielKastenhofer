/*-----------------------------------------------------------------------------
*				HTBLA-Leonding / Class: <your class name here>
*-----------------------------------------------------------------------------
* Exercise Number: #exercise_number#
* File:			counter.h
* Author(s):	<your name here>
* Due Date:		#due#
*-----------------------------------------------------------------------------
* Description:
* A counter to count up and count down.
*-----------------------------------------------------------------------------
*/
#ifndef ___COUNTER_H
#define ___COUNTER_H

#define COUNTER_COUNT 8

enum Direction{         //changed first Letter
  UP,
  DOWN,
  UNDEFINED,
};

typedef struct CounterImplementation* Counter;

//Deleted the Array

 void init();
 Counter new_counter(enum Direction direction);        //changed method
 enum Direction get_direction(Counter c);      //changed method
 void set_direction(Counter c, enum Direction direction);
 int get_increment_value(Counter c);
 void set_increment_value(Counter c, int value);
 void increment(Counter c);
 int get_value(Counter c);
 bool set_value(Counter c, int value);       //changed method

#endif
