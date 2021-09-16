# get_next_line_2021+ version
<br>
get_next_line was changed<br>
<br>

back then we use function form like...<br>
```c
int get_next_line(int fd, char **line);
```
So, meanwhile... It should be use fd, char **line which will get a multiple lines of string and return success or failed.
<br>
<br>
but after that, we using like this<br>

```c
char *get_next_line(int fd);
```
Yes, It should be return the line which is explited by '\n'
<br>
<br>
so i have to change my code as fast as i can<br>
<br>

# Directory
get_next_line_old / get_next_line_old2 -> it's just past testing files<br>
get_next_line -> it's really success files.<br>
<br>

# Grade
It's all of 125%.<br>
<br>

# Tester
At the first time I try to finish this project without any of Tester. Beacuse any of the Tester is working!
<br>
After 2 months, there is a good tester<br>
<br>

[https://github.com/Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)<br>
<br>

# reference from
I usually refer to below git repository.<br>
<br>

[https://github.com/Surfi89/get_next_line](https://github.com/Surfi89/get_next_line)
