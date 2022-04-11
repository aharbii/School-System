#ifndef _UI_H_
#define _UI_H_

#include <stdio.h>
#include <stdlib.h>
#include "TYPES.h"
#include "STRINGS.h"
#include "OPERATIONS.h"

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
void ui_splash_screen(void);
void ui_print_header(void);
void ui_student_print_grade(Student current_student, int class, int level);
void ui_student_print_numerical(Student current_student, int class, int level);
void ui_student_print_no_grades(Student current_student, int class, int level);
void ui_student_print(Student current_student, int class, int level, GradeSystem print_system);
void ui_school_print(School school);
int ui_menu(void);
void ui_level_print(School school, int level);
void ui_class_print(School school, int level, int class);
int ui_student_search_options(void);

#endif /* _UI_H_ */