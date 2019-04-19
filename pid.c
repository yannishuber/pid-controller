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

void pid_init(struct pid_controller *ctrl, uint8_t k_p, uint8_t k_i,
              uint8_t k_d)
{
    ctrl->k_p = k_p;
    ctrl->k_i = k_i;
    ctrl->k_d = k_d;

    ctrl->e_i = 0;
    ctrl->e_d = 0;
}

uint8_t pid_compute_output(struct pid_controller *ctrl, uint32_t t_set, uint32_t t_x) {}
