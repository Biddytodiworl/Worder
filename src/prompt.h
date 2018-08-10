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

#ifndef PROMPT_H
#define PROMPT_H

#include <stdint.h>

/* These macros define OK and error returns for the functions */
#define PROMPT_OK	0
#define PROMPT_ERR	1

/* Prints text to greet the user. */
uint32_t Prompt_GreetUser(void);

/* Prints text to call the user's input invalid. */
uint32_t Prompt_CallInputInvalid(void);

/* Prints the options the user has. */
uint32_t Prompt_ListOptions(void);

/* Commends the user for entering the correct answer. */
uint32_t Prompt_Congratulate(void);

/* Tells the user that the answer given is wrong. Then tells the correct
 * answer. */
uint32_t Prompt_CallAnswerWrong(char *);

#endif
