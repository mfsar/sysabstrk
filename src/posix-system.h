#ifndef __SYSTEM_POSIX_H__
#define __SYSTEM_POSIX_H__

#include <system/base.h>
#include <system/task.h>

#include <time.h>
#include <stdbool.h>

void system_ticks_to_timespec(system_tick_t ticks, struct timespec *ts);
void system_delay_to_timespec(system_tick_t ticks, struct timespec *ts);
bool system_task_reg(task_t *t);

#endif /* __SYSTEM_POSIX_H__ */