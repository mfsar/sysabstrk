#include <system/system.h>
#include <system/smphr.h>
#include <system/task.h>
#include <system/time.h>

#include <stddef.h>
#include <stdio.h>

smphr_t s;

void* task(void* arg)
{
    uintptr_t id = (uintptr_t)arg;
    smphr_take(&s, 1000);

    printf("Task %d has the semaphore\n", (unsigned int)id);
    system_delay(500);
    printf("Task %d gives the semaphore\n", (unsigned int)id);
    smphr_give(&s);

    for(;;);
}

int main(void)
{
    task_t task1h;
    task_t task2h;

    printf("System abstraction test - POSIX implementation\n");
    printf("Semaphore example application\n");

    smphr_init(&s, 1);

    task_create(&task1h, task, (void*)1);
    task_create(&task2h, task, (void*)2);

    system_delay(5000);

    return 0;
}