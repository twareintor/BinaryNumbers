bin2dec() and dec2bin() functions in C

A set of functions taking as input/ output parameters an integer and a (pre-formatted) string, long enough to store the resulting sequence of '0' and '1'-s, including group separators, representing a binary for of the other long integer argument.
If the string is not long enough, the result is limited to its lenght and will represend a false representation or the other argument. If is null or invalid pointer the result is undefined.
When the format string is used as input, can have no separator or many consecutive separators as well. Every other character than '0' and '1' will be interpreted as separator, so, ignored from process.
