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

#ifndef DATA_H
#define DATA_H

#include <stdint.h>

#define DATA_OK		0
#define DATA_ERR	1

typedef struct Word_ {
	char		french[30];		// The French word to be translated. It is the question asked
	char		english[30];	// The English translation. It is the expected answer
	uint32_t	index;
} Word;

/* Stores a word entry to disk. This entry can later be pulled during
 * the questionning. */
uint32_t Data_StoreWord(const Word *);

/* Retrieves a word entry and places it in memory. It selects the word
 * based on the given index number. */
uint32_t Data_RetrieveWord(Word *, const uint32_t);

/* Counts the number of Word entries in the dict.txt file. It does so by
 * counting the number of lines until it reaches the EOF marker. */

uint32_t Data_CalculateWordEntries(uint32_t *);
#endif
