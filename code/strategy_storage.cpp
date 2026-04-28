#include "strategy_storage.h"
#include <Arduino.h>
#include "abstract_tool_strategy.h"
#include "drill_strategy.h"
#include "scoop_strategy.h"

AbstractToolStrategy** StrategyStorage::initialize_strategies(){
  AbstractToolStrategy** strategies = calloc(num_strategies, sizeof(AbstractToolStrategy*));
  // Initialize strategies here
  strategies[0] = new DrillStrategy();
  strategies[0]->name = "drill_strategy";
  strategies[1] = new ScoopStrategy();
  strategies[1]->name = "scoop_strategy";
  return strategies;
}

StrategyStorage::StrategyStorage(){
  this->strategy_list = initialize_strategies();
}

AbstractToolStrategy** StrategyStorage::get_strategies(){
  AbstractToolStrategy** strategies = calloc(num_strategies, sizeof(AbstractToolStrategy*));
  for(int i = 0; i < num_strategies; i++){
    strategies[i] = strategy_list[i];
  }
  return strategies;
}

int StrategyStorage::get_num_strategies(){
  return num_strategies;
}

AbstractToolStrategy* StrategyStorage::get_strategy_from_name(String name){
  for(int i = 0; i < num_strategies; i++){
    if(strategy_list[i]->name == name) return strategy_list[i];
  }
  return NULL;
}
