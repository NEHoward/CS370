# C++ Makefile for HW5
#
# Replace the LastName-FirstName in the package section with
# your actual first and last name.

CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -fno-diagnostics-show-option

all: Scheduler.c 
	$(CC) $(CFLAGS) -o Scheduler Scheduler.c
		
clean:
	rm -f Scheduler *.o *.zip
	
package:
	zip Howard-Nick-HW5.zip README.txt Makefile Scheduler.c
