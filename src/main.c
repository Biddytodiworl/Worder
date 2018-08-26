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

#include "main.h"

int main() {
	// Initialisation
	uint32_t num_entries;	// Number of entries
	uint32_t score = 0;	// The score during the app
	char buffer[BUF_SZ];	// Buffer for input
	uint32_t response;	// Response from buffer
	uint32_t ret;	// Return value from Data_CalculateWordEntries

	Prompt_GreetUser();

	while (1) {
		Prompt_ListOptions();

		fgets(buffer, 50, stdin);
		response = atoi(buffer);

		switch (response) {
			case MAIN_START:
				Main_PlayGame(&score);
				break;

			case MAIN_VIEW_DB:
				/* Calculate the number of entries in the database file */
				ret = Data_CalculateWordEntries(&num_entries);

				if (DATA_FILE_ERR == ret) {
					Prompt_DeclareNoDatabase();

					/* Receive confirmation to create new database file. */
					response = Main_ReadYesNo();
					printf("\n");

					if (MAIN_YES == response) {
						/* Create a new file */
						FILE *new_file = fopen("_database.txt", "w");

						if (NULL == new_file)
							puts("\nFailed to create database file.\n");
						else {
							puts("Successfully created database.\n");
							fclose(new_file);
						}
					}
				}
				else {
					// Main_ListWords();
					Main_ViewDatabase();
				}
				break;

			case MAIN_VIEW_SCORE:
				Main_ShowScore();
				break;

			case MAIN_EXIT:
				exit(EXIT_SUCCESS);
			default:
				Prompt_CallInputInvalid();
		}
	}

	exit(EXIT_SUCCESS);
}
