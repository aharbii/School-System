#ifndef _TYPES_H_
#define _TYPES_H_

#define NAME_LEN 100
#define LEVELS_LEN 12
#define CLASSES_LEN 3
#define CLOSE_APP 100
#define NAME_NOT_FOUND -1
typedef enum bool
{
    false,
    true
} bool;

typedef enum GradeSystem
{
    NUMERICAL,
    GRADE,
    NOT_AVAILABLE
} GradeSystem;

typedef struct Score
{
    int math;
    int computer_science;
    int physics;
    int english;
    int chemistry;
} Score;

typedef struct Student
{
    char name[NAME_LEN];
    unsigned long long id;
    int age;
    Score scores;
    bool got_scores;
} Student;

typedef struct Class
{
    int students_count;
    bool initialized;
    Student *students;
} Class;

typedef struct Level
{
    bool initialized;
    Class classes[CLASSES_LEN];
} Level;

typedef struct School
{
    Level levels[LEVELS_LEN];
} School;

#endif /* _TYPES_H_ */