#include "UI.h"

void ui_splash_screen(void)
{
    printf("   _____      _                 _    _____           _                 \n  / ____|    | |               | |  / ____|         | |                \n | (___   ___| |__   ___   ___ | | | (___  _   _ ___| |_ ___ _ __ ___  \n  \\___ \\ / __| '_ \\ / _ \\ / _ \\| |  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n  ____) | (__| | | | (_) | (_) | |  ____) | |_| \\__ \\ ||  __/ | | | | |\n |_____/ \\___|_| |_|\\___/ \\___/|_| |_____/ \\__, |___/\\__\\___|_| |_| |_|\n                                            __/ |                      \n                                           |___/                       \n");
    printf("\n\n");
}

void ui_print_header(void)
{
    printf("+--------------------------------------------------+--------------------+-----+-------+-------+--------------------+\n");
    printf("|                     Name                         |        ID          | Age | Class | Level |        Grade       |\n");
    printf("+--------------------------------------------------+--------------------+-----+-------+-------+--------------------+\n");
}

void ui_student_print_grade(Student current_student, int class, int level)
{
    if (current_student.got_scores == false)
    {
        ui_student_print_no_grades(current_student, class, level);
        return;
    }

    printf("|%-50s|%-20s|%-5s|%-7s|%-7s|%-16s: %2c|\n", " ", " ", " ", " ", " ", "Maths", grade_numerical_conversion(current_student.scores.math));
    printf("|%-50s|%-20s|%-5s|%-7s|%-7s|%-16s: %2c|\n", " ", " ", " ", " ", " ", "Computer Science", grade_numerical_conversion(current_student.scores.computer_science));
    printf("|%-50s|%-20llu|%-5d|%-7d|%-7d|%-16s: %2c|\n", current_student.name, current_student.id, current_student.age, class, level, "Physics", grade_numerical_conversion(current_student.scores.physics));
    printf("|%-50s|%-20s|%-5s|%-7s|%-7s|%-16s: %2c|\n", " ", " ", " ", " ", " ", "English", grade_numerical_conversion(current_student.scores.english));
    printf("|%-50s|%-20s|%-5s|%-7s|%-7s|%-16s: %2c|\n", " ", " ", " ", " ", " ", "Chemistry", grade_numerical_conversion(current_student.scores.chemistry));
    printf("+--------------------------------------------------+--------------------+-----+-------+-------+--------------------+\n");
}

void ui_student_print_numerical(Student current_student, int class, int level)
{
    if (current_student.got_scores == false)
    {
        ui_student_print_no_grades(current_student, class, level);
        return;
    }

    
    printf("|%-50s|%-20s|%-5s|%-7s|%-7s|%-16s: %2d|\n", " ", " ", " ", " ", " ", "Maths", current_student.scores.math);
    printf("|%-50s|%-20s|%-5s|%-7s|%-7s|%-16s: %2d|\n", " ", " ", " ", " ", " ", "Computer Science", current_student.scores.computer_science);
    printf("|%-50s|%-20llu|%-5d|%-7d|%-7d|%-16s: %2d|\n", current_student.name, current_student.id, current_student.age, class, level, "Physics", current_student.scores.physics);
    printf("|%-50s|%-20s|%-5s|%-7s|%-7s|%-16s: %2d|\n", " ", " ", " ", " ", " ", "English", current_student.scores.english);
    printf("|%-50s|%-20s|%-5s|%-7s|%-7s|%-16s: %2d|\n", " ", " ", " ", " ", " ", "Chemistry", current_student.scores.chemistry);
    printf("+--------------------------------------------------+--------------------+-----+-------+-------+--------------------+\n");
}

void ui_student_print_no_grades(Student current_student, int class, int level)
{
    printf("|%-50s|%-20llu|%-5d|%-7d|%-7d|%-20s|\n", current_student.name, current_student.id, current_student.age, class, level, "N/A");
    printf("+--------------------------------------------------+--------------------+-----+-------+-------+--------------------+\n");
}

void ui_student_print(Student current_student, int class, int level, GradeSystem print_system)
{
    ui_print_header();
    switch (print_system)
    {
    case NUMERICAL:
        ui_student_print_numerical(current_student, class, level);
        break;
    case GRADE:
        ui_student_print_grade(current_student, class, level);
        break;
    default:
        break;
    }
}

void ui_school_print(School school)
{
    for (int i = 0; i < LEVELS_LEN; i++)
    {
        if (school.levels[i].initialized == true)
        {
            printf("%s%d%s Level\n", KRED, i + 1, ORDERIAL_NUMBER(i + 1));
            for (int j = 0; j < CLASSES_LEN; j++)
            {
                if (school.levels[i].classes[j].initialized == true)
                {
                    printf("%s%d%s Class\n", KGRN, j + 1, ORDERIAL_NUMBER(j + 1));
                    printf("%s", KBLU);
                    ui_print_header();
                    printf("%s", KNRM);
                    for (int k = 0; k < school.levels[i].classes[j].students_count; k++)
                    {
                        ui_student_print_grade(school.levels[i].classes[j].students[k], j + 1, i + 1);
                    }
                    printf("%s\n\n", KNRM);
                }
            }
        }
    }
}

int ui_menu(void)
{
    printf("Welcome to School Management App\n");
    printf("1. Close App\n");
    printf("2. View School Data\n");
    printf("3. View Level Data\n");
    printf("4. View Class Data\n");
    printf("5. Add New Student\n");
    printf("6. Search for Student\n");
    printf("7. Add Grades\n");
    printf("8. Clear Console\n");


    printf("Enter your choice: ");
    int choice = 0;
    do
    {
        scanf("%d", &choice);
    } while (((choice > 9) || (choice < 1)) && printf("Sorry, Invalid Input\n"));
    return choice;
}

void ui_level_print(School school, int level)
{
        if (school.levels[level].initialized == true)
        {
            printf("%s%d%s Level\n", KRED, level + 1, ORDERIAL_NUMBER(level + 1));
            for (int j = 0; j < CLASSES_LEN; j++)
            {
                if (school.levels[level].classes[j].initialized == true)
                {
                    printf("%s%d%s Class\n", KGRN, j + 1, ORDERIAL_NUMBER(j + 1));
                    printf("%s", KBLU);
                    ui_print_header();
                    printf("%s", KNRM);
                    for (int k = 0; k < school.levels[level].classes[j].students_count; k++)
                    {
                        ui_student_print_grade(school.levels[level].classes[j].students[k], j + 1, level + 1);
                    }
                    printf("%s\n\n", KNRM);
                }
            }
        }
}

void ui_class_print(School school, int level, int class)
{
    if (school.levels[level].initialized == true)
    {
        printf("%s%d%s Level\n", KRED, level + 1, ORDERIAL_NUMBER(level + 1));
        if (school.levels[level].classes[class].initialized == true)
        {
            printf("%s%d%s Class\n", KGRN, class + 1, ORDERIAL_NUMBER(class + 1));
            printf("%s", KBLU);
            ui_print_header();
            printf("%s", KNRM);
            for (int k = 0; k < school.levels[level].classes[class].students_count; k++)
            {
                ui_student_print_grade(school.levels[level].classes[class].students[k], class + 1, level + 1);
            }
            printf("%s\n\n", KNRM);
        }
    }
}

int ui_student_search_options(void)
{
    printf("Do you want to edit any of these results!\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    int choice = 0;
    do
    {
        scanf("%d", &choice);
    } while (((choice > 2) || (choice < 1)) && printf("Sorry, Invalid Input\n"));
    return choice;
}