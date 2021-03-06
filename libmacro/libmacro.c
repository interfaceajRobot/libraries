/******************************************************************************
 * Copyright (C) 2014-2018 Zhifeng Gong <gozfree@163.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with libraries; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 ******************************************************************************/
#include "libmacro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *memdup(void *src, size_t len)
{
    void *dst = calloc(1, len);
    if (dst) {
        memcpy(dst, src, len);
    }
    return dst;
}

struct iovec *iovec_create(size_t len)
{
    struct iovec *vec = CALLOC(1, struct iovec);
    vec->iov_len = len;
    vec->iov_base = calloc(1, len);
    return vec;
}

void iovec_destroy(struct iovec *vec)
{
    if (!vec || !vec->iov_base)
        return;
    free(vec->iov_base);
    free(vec);
}
