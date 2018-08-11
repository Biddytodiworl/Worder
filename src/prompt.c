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

#include "prompt.h"
#include <stdio.h>

uint32_t Prompt_GreetUser(void) {
	/* Write the text */
	puts("Welcome to Worder! Sharpen up your French word skills!");

	return PROMPT_OK;
}

uint32_t Prompt_CallInputInvalid(void) {
	/* Write the text */
	puts("Invalid input. Try again\n");

	return PROMPT_OK;
}

uint32_t Prompt_ListOptions(void) {
	/* Write the text */
	puts("What do you want to do?\n");

	/* List the options. All others are invalid. */
	puts("1) Start");
	puts("2) View database");
	puts("3) View score");
	puts("4) Exit\n");

	return PROMPT_OK;
}

uint32_t Prompt_Congratulate(void) {
	/* Write the text */
	puts("You stated the correct answer!\n");

	return PROMPT_OK;
}

uint32_t Prompt_CallAnswerWrong(char *right_answer) {
	/* Check if parameter is a null pointer */
	if (NULL == right_answer) return PROMPT_ERR;

	/* Write the text and the correct answer */
	printf("You are wrong. The correct answer is: \'%s\'\n\n", right_answer);

	return PROMPT_OK;
}

uint32_t Prompt_DeclareDatabaseEmpty(void) {
	/* Write the text */
	puts("The database is currently empty. Do you want to add items"
	" (y/n)?\n");

	return PROMPT_OK;
}

uint32_t Prompt_DeclareNoDatabase(void) {
	/* Write the text */
	puts("There is currently no database file. Do you want to create one"
	" (y/n)?\n");

	return PROMPT_OK;
}
