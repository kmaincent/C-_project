//#ifndef INCLUDE_H
//#define INCLUDE_H
#include "include.h"
#include "mediatheque.h"


enum list_function {BYE, ADD, LOAD, SAVE, SEARCH, CLEAR, LIST, SHOW, DELETE, RESET, CONCHITA, ERROR};
const std::string list_function_str[]={"BYE", "ADD", "LOAD", "SAVE", "SEARCH", "CLEAR", "LIST", "SHOW", "DELETE", "RESET","CONCHITA" };

int id_function(mediatheque& media, utilisateur user, std::string str, std::string param);

//#endif // INCLUDE_H
