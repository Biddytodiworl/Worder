/* Worder - Learning application geared towards French improvement
 * MIT License
 *
 * Copyright (c) 2018 Brendon Henry
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef SCORE_H
#define SCORE_H

#include <stdint.h>

/* These macros are codes for success and error */
#define SCORE_OK	0
#define SCORE_ERR	1
#define SCORE_FILE_ERR	2

/* This defines how many points each question is worth */
#define SCORE_QUANTITY 300

/* This function awards a fixed number of points to a point variable */
uint32_t Score_AwardPoints(uint32_t *);

/* This function changes how many points are awarded for each question */
// uint32_t Score_ChangePointQuantity(uint32_t *);

/* This function writes the number of points awarded to disk */
uint32_t Score_StorePointBalance(const uint32_t);

/* This function reads the number of points stored on disk and places
 * it in memory. */
uint32_t Score_RetrievePointBalance(uint32_t *);

#endif
