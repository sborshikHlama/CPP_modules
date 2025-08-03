//
// Created by Arsenii on 23.06.2025.
//

#ifndef HARL_H
#define HARL_H

#include <iostream>

typedef enum {DEBUG, INFO, WARNING, ERROR, FAILED_STATUS} LOG_LEVEL;

class Harl {
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    static LOG_LEVEL stringToLog(std::string level);
public:
    void complain(char *level);
};



#endif //HARL_H
