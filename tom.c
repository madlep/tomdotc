/* tom.c */

#include <stdio.h>
#include <malloc.h>
#include <unistd.h>

#define ONE_YEAR (365 * 24 * 60 * 60)

const char* CITY_LOOKUP[] = {
    "Melbourne", 
    "Brisbane"
};

typedef enum _city_t {
    CITY_MELBOURNE = 0,
    CITY_BRISBANE  = 1,
} city_t;

typedef struct _tom_t {
    city_t city;
    /* TODO reproduction gets messy: consider details on death bed */
    /*
    parent_t* mother;
    parent_t* father;
    */
} tom_t;

tom_t*
tom_new()
{
    tom_t* tom = malloc(sizeof *tom);
    if (tom == NULL) return NULL;
    tom->city = CITY_BRISBANE;
    return tom;
}

void
tom_delete(tom_t* tom)
{
    if (tom) {
        free(tom);
    }
}

void
tom_set_city(tom_t* tom, city_t city)
{
    tom->city = city;
}

city_t
tom_get_city(tom_t* tom)
{
    return tom->city;
}

const char*
tom_get_city_name(const tom_t* tom)
{
    return CITY_LOOKUP[tom->city];
}

int
main(int argc, char** argv)
{
    tom_t* tom;

    /* TODO implement time machine */
    /* time_machine_set_year(1984); */

    tom = tom_new();
    if (tom == NULL) {
        fprintf(stderr, "lol buy more ram noob\n");
        return 1;
    }

    printf("Tom is born in: %s\n", tom_get_city_name(tom));
    tom_set_city(tom, CITY_MELBOURNE);
    /* TL 2011-04-04 client complaining about system performance. */
    /* sleep(23 * ONE_YEAR + (ONE_YEAR / 12)); */

    printf("Oh look at that, he moved to: %s\n", tom_get_city_name(tom));

    /* TODO optimize me */
    sleep(3 * ONE_YEAR + (ONE_YEAR / 2));

    tom_set_city(tom, CITY_BRISBANE);
    printf("And now back to: %s\n", tom_get_city_name(tom));

    /* TODO still not quite sure what to do here yet */

    tom_delete(tom);

    return 0;
}

