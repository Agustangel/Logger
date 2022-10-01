
#include <stdio.h>
#include <assert.h>

unsigned is_file_log_ = 0;
unsigned log_level_ = 0;
const char* file_name_ = NULL;
FILE* file = NULL;


void logger_init(unsigned is_file_log, const char* file_name)
{
    is_file_log_ = is_file_log;
    file_name_ = file_name;

    file = fopen(file_name_, "w");
    assert(file != NULL);
}

void logger_set_level(unsigned level)
{
    log_level_ = level;
    printf("log_level_ = %d\n", log_level_);
}

void logger_finalize(FILE* file)
{
    fclose(file);
}
