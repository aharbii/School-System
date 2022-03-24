#include "OPERATIONS.h"

void student_add_score(Student *current_student)
{
    do
    {

        printf("Enter ");
        string_print(current_student->name);
        printf("'s score in Math: ");
        scanf("%d", &current_student->scores.math);
    } while (((current_student->scores.math > 100) || (current_student->scores.math < 0)) && printf("Score range is [0: 100], Please! enter a valid score\n"));

    do
    {

        printf("Enter ");
        string_print(current_student->name);
        printf("'s score in Computer Science: ");
        scanf("%d", &current_student->scores.computer_science);
    } while (((current_student->scores.computer_science > 100) || (current_student->scores.computer_science < 0)) && printf("Score range is [0: 100], Please! enter a valid score\n"));

    do
    {

        printf("Enter ");
        string_print(current_student->name);
        printf("'s score in Physics: ");
        scanf("%d", &current_student->scores.physics);
    } while (((current_student->scores.physics > 100) || (current_student->scores.physics < 0)) && printf("Score range is [0: 100], Please! enter a valid score\n"));

    do
    {

        printf("Enter ");
        string_print(current_student->name);
        printf("'s score in English: ");
        scanf("%d", &current_student->scores.english);
    } while (((current_student->scores.english > 100) || (current_student->scores.english < 0)) && printf("Score range is [0: 100], Please! enter a valid score\n"));

    do
    {
        printf("Enter ");
        string_print(current_student->name);
        printf("'s score in Chemistry: ");
        scanf("%d", &current_student->scores.chemistry);
    } while (((current_student->scores.chemistry > 100) || (current_student->scores.chemistry < 0)) && printf("Score range is [0: 100], Please! enter a valid score\n"));
}

void add_student(School *school)
{
    Student init_student = {.name = {0}, .id = 0, .age = 0, .scores = {0, 0, 0, 0, 0}, .got_scores = 0};
    bool confirmed_data = false;
    Student new_student;
    int level;
    int class;
    do
    {
        new_student = init_student;
        printf("Enter Student's Name: ");
        string_scan(new_student.name, NAME_LEN);

        printf("Enter ");
        string_print(new_student.name);
        printf(" ID: ");
        scanf("%llu", &new_student.id);

        printf("Enter ");
        string_print(new_student.name);
        printf(" Age: ");
        scanf("%d", &new_student.age);

        do
        {

            printf("Enter ");
            string_print(new_student.name);
            printf(" Level: ");
            scanf("%d", &level);
        } while (((level > 12) || (level < 1)) && printf("Leveles range is [1: 12], Please! enter a valid number\n"));

        do
        {

            printf("Enter ");
            string_print(new_student.name);
            printf(" Class: ");
            scanf("%d", &class);
        } while (((class > 3) || (class < 1)) && printf("Classes range is [1: 3], Please! enter a valid number\n"));

        printf("Do you want to give ");
        string_print(new_student.name);
        printf(" grades?\n\t0.No\n\t1.Yes\nEnter your choice: ");
        bool enter_scores;
        scanf("%d", &enter_scores);

        if (enter_scores)
        {
            new_student.got_scores = true;
            student_add_score(&new_student);
        }
        else
        {
            new_student.got_scores = false;
        }
        ui_student_print(new_student, class, level, NUMERICAL);

        printf("Do you want to confirm this data?\n\t0.No\n\t1.Yes\nEnter your choice: ");
        scanf("%d", &confirmed_data);
        fflush(stdin);
    } while (!confirmed_data);
    level -= 1;
    class -= 1;
    if (school->levels[level].initialized == false)
    {
        school->levels[level].initialized = true;
    }

    if (school->levels[level].classes[class].initialized == false)
    {
        school->levels[level].classes[class].initialized = true;
    }

    school->levels[level].classes[class].students_count += 1;
    school->levels[level].classes[class].students = (Student *)realloc(school->levels[level].classes[class].students, school->levels[level].classes[class].students_count * sizeof(Student));

    student_insert(school->levels[level].classes[class].students, school->levels[level].classes[class].students_count, new_student);
    printf("Data has been saved succesfully..\n\n");
}

void student_insert(Student *students_array, int students_count, Student new_student)
{
    students_count -= 1;
    int i = students_count - 1;
    while ((string_compare(students_array[i].name, new_student.name) == FIRST_BIGGER) && (i >= 0))
    {
        students_array[i + 1] = students_array[i];
        i--;
    }
    students_array[i + 1] = new_student;
}

void student_delete(Class class, int index)
{
    /* O(n) */
    if ((index >= 0) && (index <= class.students_count - 1))
    {
        Student init_student = {.name = {0}, .id = 0, .age = 0, .scores = {0, 0, 0, 0, 0}, .got_scores = 0};
        class.students[index] = init_student;
        for (int i = index; i < (class.students_count - 1); i++)
        {
            class.students[i] = class.students[i + 1];
        }
        class.students_count -= 1;
    }
}

void school_init(School *school)
{
    const Class init_class = {.students_count = 0, .initialized = false, .students = NULL};
    const Level init_level = {.classes = {0}, .initialized = false};
    for (int i = 0; i < LEVELS_LEN; i++)
    {
        school->levels[i] = init_level;
        for (int j = 0; j < CLASSES_LEN; j++)
        {
            school->levels[i].classes[j] = init_class;
        }
    }
}

char grade_numerical_conversion(int score)
{
    if (score >= 90)
    {
        return 'A';
    }
    else if (score >= 75)
    {
        return 'B';
    }
    else if (score >= 60)
    {
        return 'C';
    }
    else if (score >= 50)
    {
        return 'D';
    }
    return 'F';
}

int student_found(School school, char *to_find)
{
    int no_content = 1;
    for (int i = 0; i < LEVELS_LEN; i++)
    {
        if (school.levels[i].initialized == true)
        {
            for (int j = 0; j < CLASSES_LEN; j++)
            {
                if (school.levels[i].classes[j].initialized == true)
                {
                    for (int k = 0; k < school.levels[i].classes[j].students_count; k++)
                    {
                        int status = string_find(school.levels[i].classes[j].students[k].name, to_find);
                        if (status != NAME_NOT_FOUND)
                        {
                            if (no_content == 1)
                            {
                                ui_print_header();
                                no_content = 0;
                            }

                            ui_student_print_grade(school.levels[i].classes[j].students[k], j + 1, i + 1);
                        }
                    }
                }
            }
        }
    }
    if (no_content == 1)
    {
        printf("No result is found!\n\n");
    }
    return no_content;
}

int get_student(School school, unsigned long long id, int level, int class)
{
    int status = -1;
    for (int k = 0; k < school.levels[level].classes[class].students_count; k++)
    {
        if (school.levels[level].classes[class].students[k].id == id)
        {
            return k;
        }
    }
    if (status == -1)
    {
        printf("Something went wrong! Please, try again.\n\n");
    }
    return status;
}

void edit_class_grades(School *school, int level, int class)
{

    for (int i = 0; i < school->levels[level].classes[class].students_count; i++)
    {
        student_add_score(&school->levels[level].classes[class].students[i]);    
    }
    
}


void edit_level_grades(School *school, int level)
{
    for (int i = 0; i < CLASSES_LEN; i++)
    {
        edit_class_grades(school, level, i);
    }
    
}

void edit_school_grades(School *school)
{
    for (int i = 0; i < LEVELS_LEN; i++)
    {
        edit_level_grades(school, i);
    }
}

void edit_student(Student *student, int class, int level, School *school, int idx)
{

    printf("Edit Student Menu: \n");
    printf("1. Edit Name\n");
    printf("2. Edit Age\n");
    printf("3. Edit ID\n");
    printf("4. Edit Grades\n");
    printf("5. Change Class\n");
    printf("6. Change Level\n");
    printf("7. Delete Student\n");
    printf("8. Close this menu\n");

    Student temp;
    temp = *student;
    int status = 1;
    do
    {
        printf("Enter your choice: ");
        int choice = 0;
        do
        {
            scanf("%d", &choice);
        } while (((choice > 8) || (choice < 1)) && printf("Sorry, Invalid Input\n"));

        switch (choice)
        {
        case 1:
            printf("Enter Student's Name: ");
            string_scan(student->name, NAME_LEN);
            break;
        case 2:
            printf("Enter ");
            string_print(student->name);
            printf(" Age: ");
            scanf("%d", &student->age);
            break;
        case 3:
            printf("Enter ");
            string_print(student->name);
            printf(" ID: ");
            scanf("%llu", &student->id);
            break;
        case 4:
            student_add_score(student);
            break;
        case 5:
            printf("Enter new class: ");
            int new_class = 0;
            scanf("%d", &new_class);
            student_delete(school->levels[level].classes[class], idx);
            student_insert(school->levels[level].classes[new_class].students, school->levels[level].classes[new_class].students_count, temp);
            break;
        case 6:
            printf("Enter new Level: ");
            int new_level = 0;
            scanf("%d", &new_level);
            student_delete(school->levels[level].classes[class], idx);
            student_insert(school->levels[new_level].classes[class].students, school->levels[new_level].classes[class].students_count, temp);
            break;
        case 7:
            student_delete(school->levels[level].classes[class], idx);
            break;
        case 8:
            status = CLOSE_APP;
        default:
            break;
        }
    } while (status != CLOSE_APP);
}

int manipulate_operations(School *school)
{
    int option = ui_menu();
    int levelA = 0;
    int levelB = 0;
    int classB = 0;
    char to_find[100];
    int status = 0;
    int choice = 0;
    int levelC = 0;
    int classC = 0;
    int to_edit = 0;
    int choiceB = 0;
    int levelD = 0;
    int levelE = 0;
    int classE = 0;
    switch (option)
    {
    case 1:
        return CLOSE_APP;
        break;
    case 2:
        ui_school_print(*school);
        break;
    case 3:
        do
        {
            printf("Enter Level: ");
            scanf("%d", &levelA);
        } while (((levelA > 12) || (levelA < 1)) && printf("Leveles range is [1: 12], Please! enter a valid number\n"));
        levelA -= 1;
        ui_level_print(*school, levelA);
        break;
    case 4:
        do
        {
            printf("Enter Level: ");
            scanf("%d", &levelB);
        } while (((levelB > 12) || (levelB < 1)) && printf("Leveles range is [1: 12], Please! enter a valid number\n"));
        levelB -= 1;
        do
        {
            printf("Enter Class: ");
            scanf("%d", &classB);
        } while (((classB > 3) || (classB < 1)) && printf("Classes range is [1: 3], Please! enter a valid number\n"));
        classB -= 1;
        ui_class_print(*school, levelB, classB);
        break;
    case 5:
        add_student(school);
        break;
    case 6:
        printf("Enter Name to search with: ");
        string_scan(to_find, 100);
        status = student_found(*school, to_find);
        if (status != 1)
        {
            choice = ui_student_search_options();
            if (choice == 1)
            {
                do
                {
                    printf("Enter Level: ");
                    scanf("%d", &levelC);
                } while (((levelC > 12) || (levelC < 1)) && printf("Leveles range is [1: 12], Please! enter a valid number\n"));
                levelC -= 1;
                do
                {
                    printf("Enter Class: ");
                    scanf("%d", &classC);
                } while (((classC > 3) || (classC < 1)) && printf("Classes range is [1: 3], Please! enter a valid number\n"));
                classC -= 1;
                unsigned long long id = 0;
                printf("Enter ID: ");
                scanf("%llu", &id);
                int student_idx = get_student(*school, id, levelC, classC);
                if (id != -1)
                {
                    ui_print_header();
                    ui_student_print_grade(school->levels[levelC].classes[classC].students[student_idx], classC, levelC);
                    printf("Do you want to edit this student's data? \n");
                    printf("1. Yes\n");
                    printf("2. No\n");

                    printf("Enter your choice: ");
                    scanf("%d", &to_edit);
                    if (to_edit == 1)
                    {
                        edit_student(&school->levels[levelC].classes[classC].students[student_idx], classC, levelC, school, student_idx);
                    }
                }
            }
        }
        break;
    case 7:
        printf("Enter Grades Menu: \n");
        printf("1. Enter grades for all school\n");
        printf("2. Enter grades for a level\n");
        printf("3. Enter grades for a class\n");
        scanf("%d", &choiceB);
        switch (choiceB)
        {
        case 1:
            edit_school_grades(school);
            break;
        case 2:
            printf("Enter level number: ");
            scanf("%d", &levelD);
            edit_level_grades(school, levelD);
            break;
        case 3:
            printf("Enter level number: ");
            scanf("%d", &levelE);
            printf("Enter class number: ");
            scanf("%d", &classE);
            edit_class_grades(school, levelE, classE);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return 1;
}