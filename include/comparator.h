/**
 * this function compares two values based off of the comparator function that is called, where,
 * the return value is 0  if they are the same,
 * the return value is 1  if alpha is greater than bravo,
 * the return value is -1 if alpha is less    than bravo
 *
 * @param alpha      a void pointer to a value
 * @param bravo      a void pointer to another value
 * @param comparator a pointer to a compare function
 * @return           a normalized sign of the difference between alpha & bravo
 */
int compare(void *alpha, void *bravo, int (*comparator)(void *, void *));

/**
 * this function compares two doubles based, where,
 * the return value is 0  if they are the same,
 * the return value is 1  if alpha is greater than bravo,
 * the return value is -1 if alpha is less    than bravo
 *
 * @param alpha      a void pointer to a value
 * @param bravo      a void pointer to another value
 * @param comparator a pointer to a compare function
 * @return           a normalized sign of the difference between alpha & bravo
 */
int compare_double(void *alpha, void *bravo);

/**
 * this function compares two strings (lexographically) based, where,
 * the return value is 0  if they are the same,
 * the return value is 1  if alpha is greater than bravo,
 * the return value is -1 if alpha is less    than bravo
 *
 * @param alpha      a void pointer to a value
 * @param bravo      a void pointer to another value
 * @param comparator a pointer to a compare function
 * @return           a normalized sign of the difference between alpha & bravo
 */
int compare_string(void *alpha, void *bravo);

/**
 * this function compares two floats based, where,
 * the return value is 0  if they are the same,
 * the return value is 1  if alpha is greater than bravo,
 * the return value is -1 if alpha is less    than bravo
 *
 * @param alpha      a void pointer to a value
 * @param bravo      a void pointer to another value
 * @param comparator a pointer to a compare function
 * @return           a normalized sign of the difference between alpha & bravo
 */
int compare_float(void *alpha, void *bravo);

/**
 * this function compares two floats chars, where,
 * the return value is 0  if they are the same,
 * the return value is 1  if alpha is greater than bravo,
 * the return value is -1 if alpha is less    than bravo
 *
 * @param alpha      a void pointer to a value
 * @param bravo      a void pointer to another value
 * @param comparator a pointer to a compare function
 * @return           a normalized sign of the difference between alpha & bravo
 */
int compare_char(void *alpha, void *bravo);

/**
 * this function compares two integers based, where,
 * the return value is 0  if they are the same,
 * the return value is 1  if alpha is greater than bravo,
 * the return value is -1 if alpha is less    than bravo
 *
 * @param alpha      a void pointer to a value
 * @param bravo      a void pointer to another value
 * @param comparator a pointer to a compare function
 * @return           a normalized sign of the difference between alpha & bravo
 */
int compare_int(void *alpha, void *bravo);