/***
 *       _____      _                 _    _____           _
 *      / ____|    | |               | |  / ____|         | |
 *     | (___   ___| |__   ___   ___ | | | (___  _   _ ___| |_ ___ _ __ ___
 *      \___ \ / __| '_ \ / _ \ / _ \| |  \___ \| | | / __| __/ _ \ '_ ` _ \
 *      ____) | (__| | | | (_) | (_) | |  ____) | |_| \__ \ ||  __/ | | | | |
 *     |_____/ \___|_| |_|\___/ \___/|_| |_____/ \__, |___/\__\___|_| |_| |_|
 *                                                __/ |
 *                                               |___/
 *
 * AUTHOR: Ahmed Harbi
 * DATE: March 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "TYPES.h"

int main()
{
    ui_splash_screen();
    int status = 1;
    School GIS;
    school_init(&GIS);
    do
    {
        status = manipulate_operations(&GIS);
    } while (status != CLOSE_APP);

    return 0;
}