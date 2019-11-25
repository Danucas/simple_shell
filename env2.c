/**
 *free_env - Get the value of an environment variable.
 *@envp: Environmet variable's list.
 *Return: Void.
 */
void free_env(line_t **envp)
{
	line_t *next;

	while (*envp != NULL)
	{
		next = (*envp)->next;
		free((*envp)->string);
		free(*envp);
		*envp = next;
	}
}
