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

void pid_init(struct pid_controller *ctrl, float dt, float k_p,
                     float k_i, float k_d)
{
    ctrl->cycle_time = dt;

    ctrl->k_p = k_p;
    ctrl->k_i = k_i;
    ctrl->k_d = k_d;

    ctrl->e_i = 0;
    ctrl->e_d = 0;
}

void pid_set_goal(struct pid_controller *ctrl, float sp)
{
    ctrl->sp = sp;

    ctrl->e_i = 0;
    ctrl->e_d = 0;
}

uint8_t pid_compute_output(struct pid_controller *ctrl, float t_x)
{
    // Compute proportional error
    signed int e_p = ctrl->sp - t_x;

    // Add proportional error to summed error
    ctrl->e_i = ctrl->e_i + e_p * ctrl->cycle_time;

    // Compute output for each term
    signed int proportional_ouput = ctrl->k_p * e_p;
    signed int integral_output = ctrl->k_i * ctrl->e_i;
    signed int derivative_output =
        ctrl->k_d * ((e_p - ctrl->e_d) / ctrl->cycle_time);

    // Update last error to the current proportional error
    ctrl->e_d = e_p;

    int output =
        proportional_ouput + integral_output + derivative_output;

    if (output > PID_MAX_OUTPUT)
        output = PID_MAX_OUTPUT;
    else if (output < PID_MIN_OUTPUT)
        output = PID_MIN_OUTPUT;

    return output;
}
