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
