#pragma once
#include <stdio.h>

/*! enumeration colors and their corresponding ANSI values. */
#define BLACK "\033[0;30m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"
#define RED "\033[0;31m"
#define PURPLE "\033[0;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\e[0;33m"
#define RESET "\033[0m"


enum log_levels {

    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3

};

extern unsigned is_file_log_;
extern unsigned log_level_;
extern const char* file_name_;
extern FILE* file;


#define LOG(fmt, ...)                                                    \
do {                                                                     \
    if (log_level_ == DEBUG)                                             \
    {                                                                    \
        if (is_file_log_)                                                \
        {                                                                \
            fprintf(file, "DEBUG:  " fmt, __VA_ARGS__);                  \
        }                                                                \
        else                                                             \
        {                                                                \
            fprintf(stderr, CYAN "DEBUG:  " RESET fmt, __VA_ARGS__);     \
        }                                                                \
    }                                                                    \
    if (log_level_ == INFO)                                              \
    {                                                                    \
        if (is_file_log_)                                                \
        {                                                                \
            fprintf(file, "INFO:  " fmt, __VA_ARGS__);                   \
        }                                                                \
        else                                                             \
        {                                                                \
            fprintf(stderr, BLUE "INFO:  " RESET fmt, __VA_ARGS__);      \
        }                                                                \
    }                                                                    \
    if (log_level_ == WARNING)                                           \
    {                                                                    \
        if (is_file_log_)                                                \
        {                                                                \
            fprintf(file, "WARNING:  " fmt, __VA_ARGS__);                \
        }                                                                \
        else                                                             \
        {                                                                \
            fprintf(stderr, YELLOW "WARNING:  " RESET fmt, __VA_ARGS__); \
        }                                                                \
    }                                                                    \
    if (log_level_ == ERROR)                                             \
    {                                                                    \
        if (is_file_log_)                                                \
        {                                                                \
            fprintf(file, "ERROR:  " fmt, __VA_ARGS__);                  \
        }                                                                \
        else                                                             \
        {                                                                \
            fprintf(stderr, RED "ERROR:  " RESET fmt, __VA_ARGS__);      \
        }                                                                \
    }                                                                    \
                                                                         \
} while(0);                                                              \


void logger_init(unsigned is_file_log, const char* file_name);

void logger_set_level(unsigned level);

void logger_finalize(FILE* file);
