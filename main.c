/*
 * This file is part of the pid-ctrl distribution
 * (https://github.com/yannishuber/pid-controller).
 *
 * Copyright (c) 2019 Yannis Huber.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "pid.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{

    float k_p;
    float k_i;
    float k_d;

    float sp;

    struct pid_controller *pid = malloc(sizeof(struct pid_controller));

    printf("Simple PID Controller\n");
    printf("Enter a value for K_p\n");
    scanf("%f", &k_p);
    printf("Enter a value for K_i\n");
    scanf("%f", &k_i);
    printf("Enter a value for K_d\n");
    scanf("%f", &k_d);
    printf("Enter a set point\n");
    scanf("%f", &sp);

    pid_init(pid, 0.5, k_p, k_i, k_d);
    pid_set_goal(pid, sp);

    while (1) {
        float current;
        printf("Enter a temperature\n");
        scanf("%f", &current);
        printf("result %d\n", pid_compute_output(pid, current));
    }
    return 0;
}