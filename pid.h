/*
 * This file is part of the pid-controller distribution
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
#pragma once
#ifndef _PID_H_
#define _PID_H_

#define PID_MAX_OUTPUT 100
#define PID_MIN_OUTPUT 0

#include <stdint.h>

struct pid_controller {
    int32_t sp;

    float cycle_time;

    float k_p;
    float k_i;
    float k_d;

    int32_t e_i;
    int32_t e_d;
};

/**
 * Initializes the PID controller withe the given coefficients.
 *
 * @param ctrl pointer to a pid controller
 * @param dt   sampling time
 * @param k_p  proportional coefficient value
 * @param k_i  integral coefficient value
 * @param k_d  derivative coefficient value
 */
extern void pid_init(struct pid_controller *ctrl, float dt, float k_p,
                     float k_i, float k_d);

/**
 * Initializes the goal set point for the given PID controller according to the
 * given set point.
 *
 * @param ctrl pointer to a pid controller
 * @param sp   set point temperature in degrees
 */
extern void pid_set_goal(struct pid_controller *ctrl, float sp);

/**
 * Computes the controller's output according to it's set point temperature
 * and the given actual measurement.
 *
 * @param ctrl  pointer to a pid controller
 * @param t_x   actual measurement in degrees celsius
 * 
 * @returns controller output value between PID_MIN_OUTPUT and
 *          PID_MAX_OUTPUT
 */
extern uint8_t pid_compute_output(struct pid_controller *ctrl, float t_x);

#endif /* _PID_H_ */
