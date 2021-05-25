To build this program simply type make into the terminal. 
You could also type g++ main.cpp -o quickSort and get the same result.

    To compare strings, you look at each character. You can use the ascii table to see each characters decimal or hexadecimal equalvalent.
Looking at an integer representation of the character, the compiler can see which one come first alphbetically. In order to make your 
comparison case insensitive, you have to first test to see if a letter is capital. To do this you can use the isupper function, or you 
can simply use the ascii table. If a characters decimal equalvalent is between 64 and 91 it is a capital letter. You can convert it to 
lowercase by adding 32. Then you can compare the two strings. Once the comparison is done, substract 32 from the character you initially 
converted to make it capital again. 

    The complexity of comparing a string depends on how you do it. If you have you compare every characher of the strings then it is
O(n). This is because you must compare every corresponding character. If you only check the first character then the complexity is O(1).