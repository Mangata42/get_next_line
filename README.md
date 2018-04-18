#GET NEXT LINE

Get Next Line is a little function used to read the content of any type of files directly into a buffer. 
It reads a file line by line (a line is defined as a string ended by a \n) and returns it directly to the buffer you've specified.
You can also adjust the number of bytes you want to read by changing the <code> BUFF_SIZE </code> macro in the header. 
Get Next Line works as follow : 
<ul>
	<li> Including the file </li>
		You must include the get_next_line.h file in your header and run it along with the libft. Then, call it as a regular function. You can find more instructions in the libft
		repository on my profile.
	<li> Calling the function </li>
		<code>get_next_line(int fd, char **line)</code> where <code>fd</code> is the file descriptor of your file (make sure that the rights allow you to read it) and <code>char **line</code> the buffer where you want to read the datas.
		Memory allocation and freeing of line are left to your own decision, still you must do it or segfaults are expected.
	<li> Returning values </li>
		GNL will return 1 when a line has been read successfully, 0 when it has reached the end of the file, -1 when an error has occured.
</ul>

GNL is memoryleaks free.
