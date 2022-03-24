#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include "STRINGS.h"
#include "TYPES.h"
#include "UI.h"
void student_add_score(Student *current_student);
void add_student(School *school);
void student_insert(Student *students_array, int students_count, Student new_student);
void student_delete(Class class, int index);
void school_init(School *school);
char grade_numerical_conversion(int score);
int student_found(School school, char *to_find);
int get_student(School school, unsigned long long id, int level, int class);
void edit_class_grades(School *school, int level, int class);
void edit_level_grades(School *school, int level);
void edit_school_grades(School *school);
void edit_student(Student *student, int class, int level, School *school, int idx);
int manipulate_operations(School *school);

#endif /* _OPERATIONS_H_ */