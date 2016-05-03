#ifndef ENUM_STRING_TYPE_H
#define ENUM_STRING_TYPE_H

enum type_ressource {LIVRE, REVUE, CD, VHS, DVD, RESSOURCE_NUM, ERROR_RES};
const std::string  type_string[]={"LIVRE", "REVUE", "CD", "VHS", "DVD", "RESSOURCE NUM"};

type_ressource enum_string_type(std::string str_type);
std::string enum_string_type(type_ressource enum_type);

#endif //ENUM_STRING_TYPE_H
