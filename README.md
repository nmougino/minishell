# minishell
Educational project

Basic command interpreter.

builtins:
echo [-n] [string ...]
	The echo utility writes any specified operands, separated by single blank characters and followed by a newline character, to the standard output.
	-n    Do not print the trailing newline character.
	Write env var preceded by a $.

env
	Display environment variables.

setenv name cont
	Put the env var 'name' value to 'cont'.
	If 'name' var does not exist in environment, create it.

unsetenv name
	Remove env var 'name'.

help
	Display this file

cd [tar]
	Change current directory to tar.
	if tar is not specified, then change current directory to HOME env var.

exit
	Exit minishell.
