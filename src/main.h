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

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include "data.h"
#include "prompt.h"
#include "score.h"

/* These macros are specifically used by and for the Main_ReadYesNo
* function */
#define MAIN_YES	1
#define MAIN_NO		0

/* These are the input options on the main screen */
#define MAIN_START 			1
#define MAIN_VIEW_DB		2
#define MAIN_VIEW_SCORE		3
#define MAIN_EXIT			4

/* These are the input options on the "View Database" screen */
#define VIEW_REFRESH 	1
#define VIEW_ADD		2
#define VIEW_MAINMENU	3

 /* This is the buffer size */
 #define BUF_SZ 50


 /* This function contains most of the app logic */
 void Main_PlayGame(uint32_t *);

 /* This function lists the words in the app */
 void Main_ListWords(void);

 /* This function reads a yes or no input */
 uint32_t Main_ReadYesNo(void);

 /* This function displays the score stored on record */
 void Main_ShowScore(void);

 /* This function deals with adding and removing words from the
  * second option. */
 void Main_ViewDatabase(void);
