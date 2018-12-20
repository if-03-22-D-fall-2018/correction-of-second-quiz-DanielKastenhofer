/*-----------------------------------------------------------------------------
*				HTBLA-Leonding / Class: <your class name here>
*-----------------------------------------------------------------------------
* Exercise Number: #exercise_number#
* File:			counter.cpp
* Author(s):	<your name here>
* Due Date:		#due#
*-----------------------------------------------------------------------------
* Description:
* A counter to count up and count down.
*-----------------------------------------------------------------------------
*/

/*NEW IMPLEMENTATION*/

#include "counter.h"


struct CounterImplementation{
  Direction direction;
  int value;
  int increment_value;
  bool used;
};

struct CounterImplementation Counter1 = {UNDEFINED, 0, 0};
struct CounterImplementation Counter2 = {UNDEFINED, 0, 0};
struct CounterImplementation Counter3 = {UNDEFINED, 0, 0};
struct CounterImplementation Counter4 = {UNDEFINED, 0, 0};
struct CounterImplementation Counter5 = {UNDEFINED, 0, 0};
struct CounterImplementation Counter6 = {UNDEFINED, 0, 0};
struct CounterImplementation Counter7 = {UNDEFINED, 0, 0};
struct CounterImplementation Counter8 = {UNDEFINED, 0, 0};

static CounterImplementation counters_so_far[COUNTER_COUNT] = {Counter1, Counter2, Counter3, Counter4, Counter5, Counter6, Counter7, Counter8};

void init_one_counter_pool_entry(CounterImplementation* counter){
  counter->direction = UNDEFINED;
  counter->value = 0;
  counter->increment_value = 0;
  counter->used = false;
}

void init()
{
  for (int i = 0; i < COUNTER_COUNT; i++) {
    init_one_counter_pool_entry(&counters_so_far[i]);
  }
}
Counter new_counter(enum Direction direction)
{
  for (int i = 0; i < COUNTER_COUNT; i++) {
    if (!counters_so_far[i].used) {
      counters_so_far[i].direction = direction;
      counters_so_far[i].increment_value = 1;
      counters_so_far[i].used = true;
      return &counters_so_far[i];
    }
  }
  return 0;
}
enum Direction get_direction(Counter c)
{
  return c->direction;
}
void set_direction(Counter c, enum Direction direction)
{
  c->direction = direction;
}
int get_increment_value(Counter c)
{
  return c->increment_value;
}
void set_increment_value(Counter c, int increment_value)
{
  if (increment_value >= 0) {
    c->increment_value = increment_value;
  }
}
void increment(Counter c)
{
  if (c->direction == UP) {
    c->value += c->increment_value;
  }
  else if (c->direction == DOWN) {
    c->value -= c->increment_value;
  }
}
int get_value(Counter c)
{
  return c->value;
}
bool set_value(Counter c, int value)
{
  if (c->direction == DOWN) {
    c->value = value;
    return true;
  }
  return false;
}
