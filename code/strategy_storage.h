#ifndef STRATEGY_STORAGE_H
#define STRATEGY_STORAGE_H
#include "abstract_tool_strategy.h"

class StrategyStorage{
  /*
  Stores references to all implemented strategies
  Must be manually updated when new ones are added by increasing num_strategies and adding the new strategy to initialize_strategies()
  */
  private:
    AbstractToolStrategy** strategy_list;
    int num_strategies = 2; // Number of implemented strategies; Update if more are added
    AbstractToolStrategy** initialize_strategies(); // Initializes all strategies that are implemented for the arm
  public:
    AbstractToolStrategy** get_strategies(); // Gets a fresh array pointing to each strategy
    void print_strategies(); // Prints all strategies in strategy_list
    int get_num_strategies(); // Returns num_strategies
    AbstractToolStrategy* get_strategy_from_name(String); // Given a string equal to the name of a strategy, returns a pointer to that strategy
    StrategyStorage(); // Automatically runs initialize_strategies() in the constructor
};

#endif